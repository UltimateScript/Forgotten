/*!$@FOG@$!
 *	Generated at Wed Sep 30 06:41:10 2020
 *
 *	by fog 0.1.a of 12:17:36 Sep 29 2020
 *
 *	from
 *		../../src/Com/Abstract.fog
 *		../../src/Com/Algorithm.fog
 *		../../src/Com/Com.fog
 *		../../src/Com/Container.fog
 *		../../src/Com/Environment.fog
 *		../../src/Com/Hash.fog
 *		../../src/Com/Lang.fog
 *		../../src/Com/Macros.fog
 *		../../src/Com/Meta.fog
 *		../../src/Com/Native.fog
 *		../../src/Com/Prim.fog
 *		../../src/Com/Random.fog
 *		../../src/Com/Shared.fog
 *		../../src/Com/Text.fog
 *		ComTest.mfog
 */

#ifndef GLOBAL_CXX
#define GLOBAL_CXX

#include <new>

#ifndef GLOBAL_HXX
#include <Global.hxx>
#endif

extern "C"
{
#line 117 "../../src/Com/Meta.fog"
    int main(int argc, const char **argv)
    {
#line 118
        Com::Env & e = Com::Env::Local();
        e.Init(argc, argv);
        Main::App().Run();
        return e.Deinit();
    };
    
};

#endif