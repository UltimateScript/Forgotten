#ifndef _Com_Com_h_
#define _Com_Com_h_


#ifdef WINSOCK_HACK_FIX
	#define _WS2DEF_
	#define _WINSOCK2API_
	#define _WS2IPDEF_
	#define _WS2TCPIP_H_

#else
	#ifdef flagWIN32
		#include <ws2tcpip.h>
		#include <Windows.h>
		#include <winsock2.h>
		#if defined flagAMP
			#include <amp.h>
			#include <amp_math.h>
			#include <amp_graphics.h>
			#include <dxgi.h>
			#include <d3dcommon.h>
			#include <d3d9types.h>
			#include <d3d11.h>
			#include <d3dcompiler.h>
			#include <directxmath.h>
		#endif
	#endif
#endif




#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include <stdint.h>

#if defined flagPOSIX
	#include <unistd.h>
#endif

#if defined flagMSC
	#include <string.h> // memcmp
#endif

#include <functional>
#include <chrono>
#include <initializer_list>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <shared_mutex>
#include <algorithm>
#include <tuple>
#include <shared_mutex>
#include <atomic>
#include <functional>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <codecvt>
#include <random>

#include <emmintrin.h>

#undef near
#undef far


#ifdef flagGLM
#include <plugin/glm/glm.hpp>
#include <plugin/glm/gtc/type_ptr.hpp>
#include <plugin/glm/gtx/transform.hpp>
#include <plugin/glm/gtx/intersect.hpp>
#include <plugin/f/gtx/matrix_decompose.hpp>
#include <plugin/glm/gtx/euler_angles.hpp>
#include <plugin/glm/gtc/matrix_transform.hpp>
#include <plugin/glm/gtc/type_ptr.hpp>
#include <plugin/glm/trigonometric.hpp>
#include <plugin/glm/gtx/quaternion.hpp>

using namespace glm;
#endif

using namespace std::chrono;



#ifdef __GNUG__
#include <cstdlib>
#include <memory>
#include <cxxabi.h>
#endif


#define DLOG(x) LOG(x)

#define NAMESPACE_LANG_BEGIN	namespace  Lang {
#define NAMESPACE_LANG_END		}
#define NAMESPACE_COM_BEGIN		namespace  Com {
#define NAMESPACE_COM_END		}


namespace Lang {

template <class T> struct Ptr;

int StringLength(const char* c, int max_len);
int StringLength(const short* c, int max_len);

struct AtomicBool {
	std::atomic<bool> value;
	
	AtomicBool();
	AtomicBool(bool b);
	AtomicBool(const AtomicBool& ai);
	operator bool();
	bool operator = (bool b);
};

struct AtomicInt {
	std::atomic<int> value;
	
	AtomicInt();
	AtomicInt(int i);
	AtomicInt(const AtomicInt& ai);
	operator int() const;
	int operator = (int i);
	int operator++();
	int operator--();
	int operator++(int);
	int operator--(int);
};

class ConditionalVar {
	std::mutex m;
	std::condition_variable cv;
	bool ready = false;
	
public:
	ConditionalVar();
	void Wait();
	void SetReady(bool b=true);
	bool IsReady() const;
	
};


}

#include "Defs.h"

NAMESPACE_COM_BEGIN

struct Console {
	
	static int Get(char* buf, int size);
	static void Put(const char* msg);
	
	
};


NAMESPACE_COM_END

#endif