import os
import hashlib
import shutil
import curses
import curses.wrapper

from progressBar import progressBar

# Something went wrong during installation
class InstallerException(Exception):
	def __init__(self, value):
		self.parameter = value
	def __str__(self):
		return repr(self.parameter)

class Installer:

	def __init__(self, stdscr, package, filesdir = "./files", installdir = "./install"):
		self.stdscr = stdscr
		self.filesdir = filesdir
		self.installdir = installdir
		self.packageName = package

	def setupCurses(self):

		self.titlewin = self.stdscr.subwin(1, 80, 0, 0)
		self.mainwin = self.stdscr.subwin(23, 80, 1, 0)
		self.progwin = self.stdscr.subwin(10, 60, 6, 10)
		self.statwin = self.stdscr.subwin(1, 80, 24, 0)

		self.progBar = progressBar(0, 100, 56)

		curses.init_pair(1, curses.COLOR_BLACK, curses.COLOR_WHITE)
		curses.init_pair(2, curses.COLOR_WHITE, curses.COLOR_CYAN)
		curses.init_pair(3, curses.COLOR_YELLOW, curses.COLOR_WHITE)
		curses.init_pair(4, curses.COLOR_RED, curses.COLOR_WHITE)
		curses.init_pair(5, curses.COLOR_WHITE, curses.COLOR_BLACK)

		self.titlewin.bkgd(' ', curses.color_pair(1))
		self.statwin.bkgd(' ', curses.color_pair(1))
		self.mainwin.bkgd(' ', curses.color_pair(2))

		self.titlewin.addstr(0, 0, "Installing " + self.packageName)
		self.statwin.addstr(0, 0, "Please wait...")

		self.resetProgWin()

		self.stdscr.refresh()

	def resetProgWin(self):
		self.progwin.clear()
		self.progwin.bkgd(' ', curses.color_pair(1))
		self.progwin.box()

		self.stdscr.move(24, 79)

	def statusUpdate(self, msg):
		self.statwin.clear()
		self.statwin.addstr(0, 1, msg)
		self.statwin.refresh()

	def drawAlert(self, msg, title, colour_pair):

		# split the message into more manageable chunks
		msgLines = msg.rstrip().split("\n")

		height = len(msgLines) + 4
		errwin = self.mainwin.subwin(height, 50, (24 / 2) - (height / 2), 15)
		errwin.overlay(self.progwin)
		errwin.clear()
		errwin.bkgd(' ', curses.color_pair(1))
		errwin.box()
		errwin.addstr(0, 2, " " + title + " ", curses.color_pair(colour_pair))

		self.statusUpdate("Press ENTER to acknowledge")

		y = 2
		for i in msgLines:
			if(len(i) > 50):
				firstPart = i[0:46]
				secondPart = i[46:]
				errwin.addstr(y, 2, firstPart)
				y += 1
				errwin.addstr(y, 2, secondPart)
			else:
				errwin.addstr(y, 2, i)
			y += 1

		errwin.refresh()

		# Wait for ENTER
		while 1:
			c = self.stdscr.getch()
			if(c == 13 or c == 10):
				break

		self.mainwin.clear()
		self.mainwin.refresh()
		self.resetProgWin()

	def drawError(self, msg, title = "Error"):
		self.drawAlert(msg, title, 4)

	def drawWarning(self, msg, title = "Warning"):
		self.drawAlert(msg, title, 3)

	def drawProgress(self, action, fileName, progress):
		self.progwin.addstr(1, 2, action + ", please wait...")
		self.progwin.addstr(3, 2, fileName)

		self.progBar.updateAmount(progress)
		self.progwin.addstr(5, 2, str(self.progBar))

		self.progwin.refresh()

		self.resetProgWin()

	def InstallerPage(self, msg):
		introwin = self.mainwin.subwin(20, 70, 3, 5)
		introwin.clear()
		introwin.box()
		introwin.bkgd(' ', curses.color_pair(1))

		msgLines = msg.split("\n")
		msgNum = len(msgLines)

		y = (20 / 2) - (msgNum / 2)
		for i in msgLines:
			introwin.addstr(y, (70 / 2) - (len(i) / 2), i)
			y += 1

		introwin.refresh()

		self.waitForKeyPress()

		self.mainwin.clear()
		self.mainwin.refresh()

	def introPage(self):

		msg = "Welcome to the " + self.packageName + " installation!"
		msg += "\n\n\n"
		msg += "The next steps will guide you through the installation of " + self.packageName + "."
		msg += "\n\n"
		msg += "Press ENTER to continue."
		self.InstallerPage(msg)

	def done(self):

		msg = self.packageName + " is now installed!"
		msg += "\n\n\n"
		msg += "Remove the CD from the disk drive and press any key to reboot."
		self.InstallerPage(msg)

	def selectDest(self):
	
		self.statusUpdate("Select a partition to install to and press ENTER to continue...")

		# Potential destinations are stored in the "ramfs:/mount.tab" file.
		f = open("ramfs:/mount.tab", "r")
		data = f.read()
		f.close()
		
		self.resetProgWin()
		self.progwin.addstr(1, 2, "Select a partition to install Forgotten to:")
		
		# List box...
		listBoxHeight = 7
		listBoxContentsHeight = 5
		listbox = self.progwin.subwin(listBoxHeight, 56, 8, 12)
		listbox.box()
		
		listEntries = data.rstrip().split("\n")
		
		self.progwin.refresh()
		
		# Top of the list (y value)
		topListY = 0
		selectedItem = 0
		
		while 1:
			# Visible set
			visibleSet = listEntries[topListY:topListY + listBoxContentsHeight]
			
			# Add the entries
			itemNum = topListY
			listY = 1
			listX = 1
			for entry in visibleSet:
				if(selectedItem == itemNum):
					listbox.addstr(listY, listX, entry, curses.color_pair(5))
				else:
					listbox.addstr(listY, listX, entry, curses.color_pair(1))
				itemNum += 1
				listY += 1
			listbox.refresh()
			
			c = self.stdscr.getch()
			if(c == 13 or c == 10):
				break
			elif(c == 258):
				if(selectedItem < (len(listEntries) - 1)):
					selectedItem += 1
					
					# Ok, so we want to have the box showing the item
					# but it should only show in blocks of
					# listBoxContentsHeight...
					
					if((selectedItem % listBoxContentsHeight) == 0):
						if(topListY < len(listEntries)):
							topListY += listBoxContentsHeight
			elif(c == 259):
				if(selectedItem > 0):
					if((selectedItem % listBoxContentsHeight) == 0):
						if(topListY > 0):
							topListY -= listBoxContentsHeight
						if(topListY < 0):
							topListY = 0
							
					selectedItem -= 1

		self.installdir = listEntries[selectedItem] + ":"
		self.resetProgWin()
    
    # Simply put, removes whitespace, comments, and all that other stuff
    # Also ensures that newlines are consistent
	def sanitizeFile(self, fileData):
		fileLines = fileData.strip().split("\n")
		ret = ""
		for line in fileLines:
			# Don't strip leading whitespace, because we actually give meaning to it!
			line = line.rstrip()
			if(len(line) == 0):
				continue
			if(line[0] == '#'):
				continue
			ret += line + "\n"
		return ret

	def installFiles(self):
		# Open the file listing. This file contains information about each file that
		# we are to install.
		try:
			fileList = open(self.filesdir + "/filelist.txt")
		except:
			# Pass it up to the caller
			self.drawError("Couldn't open file list for reading.")
			raise

		self.statusUpdate("Please wait...")

		# Start copying files
		fileData = fileList.read()
		fileLines = self.sanitizeFile(fileData).split("\n")
		nFiles = len(fileLines)
		currFileNum = 0
		myProgress = 0
		for line in fileLines:
			
			# Remove trailing whitespace and split on spaces
			# File format:
			# <source path> <dest path> <md5> <compulsory>
			set = line.split(" ")
			
			# Check for a valid format
			if(len(set) != 4):
				self.drawError("Bad set in file list:\n" + line + "\nThis set only has " + str(len(set)) + " entries")
				continue
			
			# * saves duplication
			if(set[1] == "*"):
				set[1] = set[0]

			# Create directory structure if required
			dirSplit = filter(lambda x: len(x) > 0, set[1].split("/"))
			dirSplit = dirSplit[:-1]
			if(len(dirSplit) > 0):
				currPath = "/"
				for dir in dirSplit:
					currPath += dir
					createPath = self.installdir + currPath
					if(os.path.exists(createPath) == False):
						os.mkdir(createPath)
					currPath += "/"

			# Update the progress
			currFileNum += 1
			myProgress = (currFileNum / float(nFiles)) * 100.0
			self.drawProgress("Copying files", self.installdir + set[1], myProgress)

			# Some files are meant to be empty, but present
			if(len(set[0]) == 0):
				f = open(self.installdir + set[1], "w")
				f.close()
				continue

			# Copy the file
			shutil.copyfile(self.filesdir + set[0], self.installdir + set[1])

			if(set[2] != "none"):
				# MD5 the newly copied file
				newFile = open(self.installdir + set[1])
				hex = hashlib.md5(newFile.read()).hexdigest()
				newFile.close()

				# Ensure the MD5 matches
				if(hex != set[2]):
					if(set[3] == "yes"):
						self.drawError("Compulsory file failed verification:\n" + self.installdir + set[1])
						raise
					else:
						self.drawWarning("File " + str(currFileNum) + " failed verification, continuing anyway:\n" + self.installdir + set[1])

		fileList.close()

		self.statusUpdate("Copy complete.")

	def postInstall(self):
		self.statusUpdate("Please wait...")

		# Files copied, run post-install scripts now
		try:
			postInstallFile = open(self.filesdir + "/postinstall.txt")
			contents = postInstallFile.read()
			contents.rstrip()
			if(len(contents)):
				num = 0
				for line in contents.split("\n"):
					num += 1
					self.drawProgress("Running script", line, (num / float(len(contents))) * 100.0)
					try:
						p = os.popen(line)
						print p.read()
						p.close()
					except:
						self.drawWarning("Post-install script '" + str(line) + "' failed, continuing")
			else:
				raise
			postInstallFile.close()
		except:
			self.statusUpdate("Post-install scripts complete.")

	def waitForKeyPress(self):
		self.stdscr.getch()
