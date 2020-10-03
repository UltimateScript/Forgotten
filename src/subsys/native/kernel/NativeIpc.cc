/*
 * Copyright (c) 2011 Matthew Iselin
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#include <process/Ipc.h>
#include <ipc/Ipc.h>

#include <utilities/Tree.h>
#include <utilities/Pair.h>
#include <utilities/String.h>

typedef Pair<uint64_t, ForgottenIpc::IpcMessage *> PerProcessUserPointerPair;

/// Lookup between userspace message pointers and the kernel-side heap pointer
/// that actually contains the relevant information for IPC.
Tree<Pair<uint64_t, ForgottenIpc::IpcMessage *>, Ipc::IpcMessage *> __msg_lookup;

inline uint64_t getPid()
{
    return Processor::information().getCurrentThread()->getParent()->getId();
}

uintptr_t createStandardMessage(ForgottenIpc::IpcMessage *pMessage)
{
    PerProcessUserPointerPair p = makePair(getPid(), pMessage);

    Ipc::IpcMessage *pKernelMessage = new Ipc::IpcMessage();
    Ipc::IpcMessage *pCheck = __msg_lookup.lookup(p);
    if(pCheck)
    {
        FATAL("Inserting an already allocated IPC message [createStandardMessage].");
    }
    __msg_lookup.insert(p, pKernelMessage);

    return reinterpret_cast<uintptr_t>(pKernelMessage->getBuffer());
}

uintptr_t createSharedMessage(ForgottenIpc::IpcMessage *pMessage, size_t nBytes, uintptr_t handle)
{
    PerProcessUserPointerPair p = makePair(getPid(), pMessage);

    Ipc::IpcMessage *pKernelMessage = new Ipc::IpcMessage(nBytes, handle);
    __msg_lookup.insert(p, pKernelMessage);

    return reinterpret_cast<uintptr_t>(pKernelMessage->getBuffer());
}

void *getIpcSharedRegion(ForgottenIpc::IpcMessage *pMessage)
{
    PerProcessUserPointerPair p = makePair(getPid(), pMessage);

    Ipc::IpcMessage *pKernelMessage = __msg_lookup.lookup(p);
    if(pKernelMessage)
        return pKernelMessage->getHandle();

    return 0;
}

void destroyMessage(ForgottenIpc::IpcMessage *pMessage)
{
    PerProcessUserPointerPair p = makePair(getPid(), pMessage);

    Ipc::IpcMessage *pKernelMessage = __msg_lookup.lookup(p);
    if(pKernelMessage)
    {
        __msg_lookup.remove(p);
        delete pKernelMessage;
    }
}

bool sendIpc(ForgottenIpc::IpcEndpoint *pEndpoint, ForgottenIpc::IpcMessage *pMessage, bool bAsync)
{
    PerProcessUserPointerPair p = makePair(getPid(), pMessage);

    Ipc::IpcMessage *pKernelMessage = __msg_lookup.lookup(p);
    if(pKernelMessage)
    {
        return Ipc::send(reinterpret_cast<Ipc::IpcEndpoint*>(pEndpoint), pKernelMessage, bAsync);
    }

    return false;
}

void *recvIpcPhase1(ForgottenIpc::IpcEndpoint *pEndpoint, bool bAsync)
{
    Ipc::IpcMessage *pMessage = 0;
    bool ret = Ipc::recv(reinterpret_cast<Ipc::IpcEndpoint*>(pEndpoint), &pMessage, bAsync);
    if(!ret)
        return 0;

    return reinterpret_cast<void*>(pMessage);
}

uintptr_t recvIpcPhase2(ForgottenIpc::IpcMessage *pUserMessage, void *pMessage)
{
    PerProcessUserPointerPair p = makePair(getPid(), pUserMessage);

    Ipc::IpcMessage *pKernelMessage = reinterpret_cast<Ipc::IpcMessage*>(pMessage);
    Ipc::IpcMessage *pCheck = __msg_lookup.lookup(p);
    if(pCheck)
    {
        FATAL("Inserting an already allocated IPC message [recvIpcPhase2].");
    }
    __msg_lookup.insert(p, pKernelMessage);

    return reinterpret_cast<uintptr_t>(pKernelMessage->getBuffer());
}

void createEndpoint(const char *name)
{
    String temp(name);
    Ipc::createEndpoint(temp);
}

void removeEndpoint(const char *name)
{
    String temp(name);
    Ipc::removeEndpoint(temp);
}

ForgottenIpc::IpcEndpoint *getEndpoint(const char *name)
{
    String temp(name);
    return reinterpret_cast<ForgottenIpc::IpcEndpoint *>(Ipc::getEndpoint(temp));
}
