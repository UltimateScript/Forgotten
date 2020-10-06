#ifndef MAIN_CXX
#define MAIN_CXX

#include <new>

#ifndef MAIN_HXX
#include <Main.hxx>
#endif

namespace Main
{
#line 273 "ComTest.mfog"
    void App::TestShared()
    {
#line 283
        Shared::Ptr < Dumb > s0a;
#line 285
        ;
        {
#line 286
            Shared::Ptr < Dumber > s1a;
            Shared::Ptr < Dumb > s1b;
#line 289
            ;
            ;
            s1b = Shared::Ptr < Dumb > ().WrapObject(new Dumb);
#line 293
            ;
            s1a = s1b.As < Dumber > ();
#line 296
            ;
            {
                Shared::Ptr < Dumber > s2;
#line 300
                ;
#line 300
                s2 = s1a;
#line 302
                ;
#line 302
                s0a = s2.As < Dumb > ();
#line 304
                ;
            }
            ;
        }
        ;
    };
    
#line 266
    App::Dumber::~Dumber()
    {
#line 266
        ;
    };
    
#line 76 "../../src/Com/Meta.fog"
    App::SomeRefTuple2::SomeRefTuple2(int& a, double& b)
    :
        a(a),
        b(b)
    {};
    
#line 77
    Text::String App::SomeRefTuple2::AsString() const
    {
#line 77
        return Text::ToString(a) + ", " + Text::ToString(b);
    };
    
#line 57
    Text::String App::SomeTuple2::AsString() const
    {
#line 57
        return Text::ToString(a) + ", " + Text::ToString(b);
    };
    
#line 33 "ComTest.mfog"
    App::VirtualBase::~VirtualBase() {};
    
};

#endif
