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

#ifndef CONTAINER_CXX
#define CONTAINER_CXX

#include <new>

#ifndef CONTAINER_HXX
#include <Container.hxx>
#endif

namespace Container
{
#line 64 "../../src/Com/Container.fog"
    template < class _1 >
    _1 *One < _1 >::operator-> ()
    {
        {
#line 64
            if (!(obj))
            {
#line 64
                Lang::SysBreak("Assertion failed: obj");
            }
        }
#line 64
        ;
#line 64
        return obj;
    };
    
#line 65
    template < class _1 >
    const _1 *One < _1 >::operator-> () const
    {
        {
#line 65
            if (!(obj))
            {
#line 65
                Lang::SysBreak("Assertion failed: obj");
            }
        }
#line 65
        ;
#line 65
        return obj;
    };
    
#line 75
    template < class _1 >
    One < _1 >::operator ConstT & () const
    {
        {
#line 75
            if (!(obj))
            {
#line 75
                Lang::SysBreak("Assertion failed: obj");
            }
        }
#line 75
        ;
#line 75
        return *obj;
    };
    
#line 74
    template < class _1 >
    One < _1 >::operator _1 & ()
    {
        {
#line 74
            if (!(obj))
            {
#line 74
                Lang::SysBreak("Assertion failed: obj");
            }
        }
#line 74
        ;
#line 74
        return *obj;
    };
    
#line 71
    template < class _1 >
    _1 *One < _1 >::Detach()
    {
        {
#line 71
            if (!(obj))
            {
#line 71
                Lang::SysBreak("Assertion failed: obj");
            }
        }
#line 71
        ;
#line 71
        _1 * tmp = obj;
#line 71
        obj = 0;
#line 71
        return tmp;
    };
    
#line 124
    template < class _1 >
    Optional < _1 >::Optional(const Optional& opt)
    :
        obj(0)
    {
#line 124
        if (opt.obj)
#line 124
            this -> obj = new _1(*opt.obj);
    };
    
    template < class _1 >
    Optional < _1 >::Optional(const PickT& n)
    :
        obj(0)
    {
#line 127
        *this = n;
    };
    
#line 125
    template < class _1 >
    Optional < _1 >::Optional(const _1& obj)
    :
        obj(0)
    {
#line 125
        this -> obj = new _1(obj);
    };
    
#line 139
    template < class _1 >
    _1 *Optional < _1 >::operator-> ()
    {
        {
#line 139
            if (!(obj))
            {
#line 139
                Lang::SysBreak("Assertion failed: obj");
            }
        }
#line 139
        ;
#line 139
        return obj;
    };
    
#line 134
    template < class _1 >
    void Optional < _1 >::operator= (const Optional& o)
    {
#line 134
        Clear();
#line 134
        if (!o.IsEmpty())
        {
#line 134
            this -> obj = new _1(*o.obj);
        }
    };
    
#line 135
    template < class _1 >
    void Optional < _1 >::operator= (const PickOpt& n)
    {
#line 135
        Clear();
#line 135
        if (!n.Get().IsEmpty())
        {
#line 135
            Pick(n.Get());
        }
    };
    
#line 136
    template < class _1 >
    void Optional < _1 >::Pick(Optional& o)
    {
#line 136
        obj = o.obj;
#line 136
        o.obj = 0;
    };
    
};

#endif