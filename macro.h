
#define PP_CAT2(_1, _2) _PP_INTERNAL_CAT2(_1, _2)
#define _PP_INTERNAL_CAT2(_1, _2) _1##_2


PP_IF--------------------------------------------------

#define PP_IF(_Cond, _Then, _Else) PP_CAT2(_PP_INTERNAL_IF_, _Cond)(_Then, _Else)
#define _PP_INTERNAL_IF_1(_Then, _Else) _Then
#define _PP_INTERNAL_IF_0(_Then, _Else) _Else


PP_IF(0, 1, 2)
PP_IF(1, 1, 2)

PP_STRINGIZE--------------------------------------------------

#define PP_STRINGIZE(...) _PP_INTERNAL_STRINGIZE(__VA_ARGS__)
#define _PP_INTERNAL_STRINGIZE(...) #__VA_ARGS__


PP_STRINGIZE(int)  ==> "int"
PP_STRINGIZE(int,   123)  ==> "int, 123"

_PP_INTERNAL_STRINGIZE(int)  ==> "int"
_PP_INTERNAL_STRINGIZE(int,   123)  ==> "int, 123"

#define X1 int
PP_STRINGIZE(X1)  ==> "int"
_PP_INTERNAL_STRINGIZE(X1)  ==> "X1"


PP_NARG--------------------------------------------------

#define PP_NARG(...) _PP_INTERNAL_17TH(_, ##__VA_ARGS__, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define PP_HAS_COMMA(...) _PP_INTERNAL_17TH(_, ##__VA_ARGS__, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0)
#define _PP_INTERNAL_17TH(_, _15, _14, _13, _12, _11, _10, _9, _8, _7, _6, _5, _4, _3, _2, _1, _0, ...) _0

PP_NARG()  ==> 0
PP_NARG(a)  ==> 1
PP_NARG(a, b)  ==> 2
PP_NARG(a, b, int c)  ==> 3
PP_NARG(a, b, int c, void (*d)(int))  ==> 4

PP_HAS_COMMA()  ==> 0
PP_HAS_COMMA(a)  ==> 0
PP_HAS_COMMA(a, b)  ==> 1
PP_HAS_COMMA(a, b, int c)  ==> 1
PP_HAS_COMMA(a, b, int c, void (*d)(int))  ==> 1

PP_HEAD--------------------------------------------------


#define PP_HEAD(...) _PP_INTERNAL_HEAD(__VA_ARGS__)
#define PP_TAIL(...) _PP_INTERNAL_TAIL(__VA_ARGS__)
#define _PP_INTERNAL_HEAD(_1, ...) _1
#define _PP_INTERNAL_TAIL(_1, ...) __VA_ARGS__


PP_HEAD(a, b, int c, void (*d)(int))  ==> a
PP_TAIL(a, b, int c, void (*d)(int))  ==> b, int c, void (*d)(int)


PP_VARIADIC_CALL--------------------------------------------------

#define PP_VARIADIC_CALL(_Macro, ...) PP_CAT2(_Macro, PP_NARG(__VA_ARGS__))(__VA_ARGS__)

PP_VARIADIC_CALL(X, int a, char b, double c)

PP_CAT--------------------------------------------------

#define PP_CAT(...) PP_VARIADIC_CALL(___PP_CAT_, __VA_ARGS__)
#define ___PP_CAT_2(_1,_2) PP_CAT2(_1,_2)
#define ___PP_CAT_3(_1,_2,_3) PP_CAT2(___PP_CAT_2(_1,_2),_3)
#define ___PP_CAT_4(_1,_2,_3,_4) PP_CAT2(___PP_CAT_3(_1,_2,_3),_4)
#define ___PP_CAT_5(_1,_2,_3,_4,_5) PP_CAT2(___PP_CAT_4(_1,_2,_3,_4),_5)
#define ___PP_CAT_6(_1,_2,_3,_4,_5,_6) PP_CAT2(___PP_CAT_5(_1,_2,_3,_4,_5),_6)
#define ___PP_CAT_7(_1,_2,_3,_4,_5,_6,_7) PP_CAT2(___PP_CAT_6(_1,_2,_3,_4,_5,_6),_7)
#define ___PP_CAT_8(_1,_2,_3,_4,_5,_6,_7,_8) PP_CAT2(___PP_CAT_7(_1,_2,_3,_4,_5,_6,_7),_8)
#define ___PP_CAT_9(_1,_2,_3,_4,_5,_6,_7,_8,_9) PP_CAT2(___PP_CAT_8(_1,_2,_3,_4,_5,_6,_7,_8),_9)
#define ___PP_CAT_10(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10) PP_CAT2(___PP_CAT_9(_1,_2,_3,_4,_5,_6,_7,_8,_9),_10)
#define ___PP_CAT_11(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11) PP_CAT2(___PP_CAT_10(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10),_11)
#define ___PP_CAT_12(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12) PP_CAT2(___PP_CAT_11(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11),_12)
#define ___PP_CAT_13(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13) PP_CAT2(___PP_CAT_12(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12),_13)
#define ___PP_CAT_14(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14) PP_CAT2(___PP_CAT_13(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13),_14)
#define ___PP_CAT_15(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15) PP_CAT2(___PP_CAT_14(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14),_15)

PP_CAT(a, b)
PP_CAT(a, b, c)
PP_CAT(a, b, c, d)
PP_CAT(a, b, c, d, e)
PP_CAT(a, b, c, d, e, f)
PP_CAT(a, b, c, d, e, f, g)
PP_CAT(a, b, c, d, e, f, g, h)
PP_CAT(a, b, c, d, e, f, g, h, i)
PP_CAT(a, b, c, d, e, f, g, h, i, j)
PP_CAT(a, b, c, d, e, f, g, h, i, j, k)
PP_CAT(a, b, c, d, e, f, g, h, i, j, k, l)
PP_CAT(a, b, c, d, e, f, g, h, i, j, k, l, m)
PP_CAT(a, b, c, d, e, f, g, h, i, j, k, l, m, n)
PP_CAT(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o)

PP_INC--------------------------------------------------

#define PP_INC(_i) PP_CAT2(_PP_INTERNAL_INC_, _i)

#define _PP_INTERNAL_INC_0 1
#define _PP_INTERNAL_INC_1 2
#define _PP_INTERNAL_INC_2 3
#define _PP_INTERNAL_INC_3 4
#define _PP_INTERNAL_INC_4 5
#define _PP_INTERNAL_INC_5 6
#define _PP_INTERNAL_INC_6 7
#define _PP_INTERNAL_INC_7 8
#define _PP_INTERNAL_INC_8 9
#define _PP_INTERNAL_INC_9 10
#define _PP_INTERNAL_INC_10 11
#define _PP_INTERNAL_INC_11 12
#define _PP_INTERNAL_INC_12 13
#define _PP_INTERNAL_INC_13 14
#define _PP_INTERNAL_INC_14 15
#define _PP_INTERNAL_INC_15 16

PP_INC(0)  ==> 1
PP_INC(1)  ==> 2
PP_INC(3)  ==> 4

PP_COMMA_IF--------------------------------------------------

#define PP_COMMA_IF(_i) PP_CAT2(_PP_INTERNAL_COMMA_IF_, _i)

#define _PP_INTERNAL_COMMA_IF_0 
#define _PP_INTERNAL_COMMA_IF_1 ,
#define _PP_INTERNAL_COMMA_IF_2 ,
#define _PP_INTERNAL_COMMA_IF_3 ,
#define _PP_INTERNAL_COMMA_IF_4 ,
#define _PP_INTERNAL_COMMA_IF_5 ,
#define _PP_INTERNAL_COMMA_IF_6 ,
#define _PP_INTERNAL_COMMA_IF_7 ,
#define _PP_INTERNAL_COMMA_IF_8 ,
#define _PP_INTERNAL_COMMA_IF_9 ,
#define _PP_INTERNAL_COMMA_IF_10 ,
#define _PP_INTERNAL_COMMA_IF_11 ,
#define _PP_INTERNAL_COMMA_IF_12 ,
#define _PP_INTERNAL_COMMA_IF_13 ,
#define _PP_INTERNAL_COMMA_IF_14 ,
#define _PP_INTERNAL_COMMA_IF_15 ,

PP_COMMA_IF(0) ==> 
PP_COMMA_IF(1) ==> ,
PP_COMMA_IF(2) ==> ,
PP_COMMA_IF(3) ==> ,



PP_FOREACH--------------------------------------------------

// Expands to _Macro(0, _Data, e1) _Macro(1, _Data, e2) ... _Macro(K -1, _Data, eK) as many of GMOCK_INTERNAL_NARG0 _Tuple.
// Requires: * |_Macro| can be called with 3 arguments.
//           * |_Tuple| expansion has no more than 15 elements.
#define PP_FOREACH(_Macro, _Data, _Tuple) \
  PP_CAT2(_PP_INTERNAL_FOR_EACH_IMPL_, PP_NARG _Tuple)(0, _Macro, _Data, _Tuple)

// Expands to _Macro(0, _Data, ) _Macro(1, _Data, ) ... _Macro(K - 1, _Data, )
// Empty if _K = 0.
// Requires: * |_Macro| can be called with 3 arguments.
//           * |_K| literal between 0 and 15
#define PP_REPEAT(_Macro, _Data, _N) \
  PP_CAT2(_PP_INTERNAL_FOR_EACH_IMPL_, _N) (0, _Macro, _Data, (, , , , , , , , , , , , , , , ))


#define _PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, _element) _Macro(_i, _Data, _element)
#define _PP_INTERNAL_FOR_EACH_IMPL_0(_i, _Macro, _Data, _Tuple)
#define _PP_INTERNAL_FOR_EACH_IMPL_1(_i, _Macro, _Data, _Tuple) \
            _PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, PP_HEAD _Tuple)
#define _PP_INTERNAL_FOR_EACH_IMPL_2(_i, _Macro, _Data, _Tuple) \
            _PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, PP_HEAD _Tuple) \
        _PP_INTERNAL_FOR_EACH_IMPL_1(PP_INC(_i), _Macro, _Data, (PP_TAIL _Tuple))
#define _PP_INTERNAL_FOR_EACH_IMPL_3(_i, _Macro, _Data, _Tuple) \
            _PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, PP_HEAD _Tuple) \
        _PP_INTERNAL_FOR_EACH_IMPL_2(PP_INC(_i), _Macro, _Data, (PP_TAIL _Tuple))
#define _PP_INTERNAL_FOR_EACH_IMPL_4(_i, _Macro, _Data, _Tuple) \
            _PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, PP_HEAD _Tuple) \
        _PP_INTERNAL_FOR_EACH_IMPL_3(PP_INC(_i), _Macro, _Data, (PP_TAIL _Tuple))
#define _PP_INTERNAL_FOR_EACH_IMPL_5(_i, _Macro, _Data, _Tuple) \
            _PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, PP_HEAD _Tuple) \
        _PP_INTERNAL_FOR_EACH_IMPL_4(PP_INC(_i), _Macro, _Data, (PP_TAIL _Tuple))
#define _PP_INTERNAL_FOR_EACH_IMPL_6(_i, _Macro, _Data, _Tuple) \
            _PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, PP_HEAD _Tuple) \
        _PP_INTERNAL_FOR_EACH_IMPL_5(PP_INC(_i), _Macro, _Data, (PP_TAIL _Tuple))
#define _PP_INTERNAL_FOR_EACH_IMPL_7(_i, _Macro, _Data, _Tuple) \
            _PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, PP_HEAD _Tuple) \
        _PP_INTERNAL_FOR_EACH_IMPL_6(PP_INC(_i), _Macro, _Data, (PP_TAIL _Tuple))
#define _PP_INTERNAL_FOR_EACH_IMPL_8(_i, _Macro, _Data, _Tuple) \
            _PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, PP_HEAD _Tuple) \
        _PP_INTERNAL_FOR_EACH_IMPL_7(PP_INC(_i), _Macro, _Data, (PP_TAIL _Tuple))
#define _PP_INTERNAL_FOR_EACH_IMPL_9(_i, _Macro, _Data, _Tuple) \
            _PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, PP_HEAD _Tuple) \
        _PP_INTERNAL_FOR_EACH_IMPL_8(PP_INC(_i), _Macro, _Data, (PP_TAIL _Tuple))
#define _PP_INTERNAL_FOR_EACH_IMPL_10(_i, _Macro, _Data, _Tuple)\
            _PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, PP_HEAD _Tuple) \
        _PP_INTERNAL_FOR_EACH_IMPL_9(PP_INC(_i), _Macro, _Data, (PP_TAIL _Tuple))
#define _PP_INTERNAL_FOR_EACH_IMPL_11(_i, _Macro, _Data, _Tuple)\
            _PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, PP_HEAD _Tuple) \
        _PP_INTERNAL_FOR_EACH_IMPL_10(PP_INC(_i), _Macro, _Data, (PP_TAIL _Tuple))
#define _PP_INTERNAL_FOR_EACH_IMPL_12(_i, _Macro, _Data, _Tuple)\
            _PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, PP_HEAD _Tuple) \
        _PP_INTERNAL_FOR_EACH_IMPL_11(PP_INC(_i), _Macro, _Data, (PP_TAIL _Tuple))
#define _PP_INTERNAL_FOR_EACH_IMPL_13(_i, _Macro, _Data, _Tuple)\
            _PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, PP_HEAD _Tuple) \
        _PP_INTERNAL_FOR_EACH_IMPL_12(PP_INC(_i), _Macro, _Data, (PP_TAIL _Tuple))
#define _PP_INTERNAL_FOR_EACH_IMPL_14(_i, _Macro, _Data, _Tuple)\
            _PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, PP_HEAD _Tuple) \
        _PP_INTERNAL_FOR_EACH_IMPL_13(PP_INC(_i), _Macro, _Data, (PP_TAIL _Tuple))
#define _PP_INTERNAL_FOR_EACH_IMPL_15(_i, _Macro, _Data, _Tuple)\
            _PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, PP_HEAD _Tuple) \
        _PP_INTERNAL_FOR_EACH_IMPL_14(PP_INC(_i), _Macro, _Data, (PP_TAIL _Tuple))


PP_FOREACH(X, _, (1,2,3,4,5,6,7,8,9))
PP_REPEAT(Y, _, 9)

