#pragma once
#include "BasicClasses.h"
#include "BasicMacros.h"
#include "DataTypes.h"

#ifdef FLEXSIM_ENGINE_COMPILE
#include "CommandList.h"
#include "Modelling.h"
#endif

#include <string>

#if defined FLEXSIM_ENGINE_COMPILE && defined _WINDOWS
	#include <excpt.h>
#endif


namespace FlexSim {
#undef COMPARE_NUMBER_TYPES
#undef COMPARE_NUMBER



#define PP_IIF_0(t, f) f
#define PP_IIF_1(t, f) t
#define PP_IIF_I(bit, t, f) PP_IIF_II(PP_IIF_ ## bit(t, f))
#define PP_IIF_II(id) id
#define PP_IIF(bit, t, f) PP_IIF_I(bit, t, f)

#define PP_CAT_II(p, res) res
#define PP_CAT_I(a, b) PP_CAT_II(~, a ## b)
#define PP_CAT(a, b) PP_CAT_I(a, b)

#define PP_NOT_EQUAL_CHECK_PP_NIL 1

#define PP_NOT_EQUAL_CHECK_PP_NOT_EQUAL_0(c, y) 0
#define PP_NOT_EQUAL_CHECK_PP_NOT_EQUAL_1(c, y) 0
#define PP_NOT_EQUAL_CHECK_PP_NOT_EQUAL_2(c, y) 0
#define PP_NOT_EQUAL_CHECK_PP_NOT_EQUAL_3(c, y) 0
#define PP_NOT_EQUAL_CHECK_PP_NOT_EQUAL_4(c, y) 0
#define PP_NOT_EQUAL_CHECK_PP_NOT_EQUAL_5(c, y) 0
#define PP_NOT_EQUAL_CHECK_PP_NOT_EQUAL_6(c, y) 0
#define PP_NOT_EQUAL_CHECK_PP_NOT_EQUAL_7(c, y) 0
#define PP_NOT_EQUAL_CHECK_PP_NOT_EQUAL_8(c, y) 0
#define PP_NOT_EQUAL_CHECK_PP_NOT_EQUAL_9(c, y) 0
#define PP_NOT_EQUAL_CHECK_PP_NOT_EQUAL_10(c, y) 0


#    define PP_NOT_EQUAL_0(c, y) PP_IIF(c, PP_NIL, y(1, PP_NIL))
#    define PP_NOT_EQUAL_1(c, y) PP_IIF(c, PP_NIL, y(1, PP_NIL))
#    define PP_NOT_EQUAL_2(c, y) PP_IIF(c, PP_NIL, y(1, PP_NIL))
#    define PP_NOT_EQUAL_3(c, y) PP_IIF(c, PP_NIL, y(1, PP_NIL))
#    define PP_NOT_EQUAL_4(c, y) PP_IIF(c, PP_NIL, y(1, PP_NIL))
#    define PP_NOT_EQUAL_5(c, y) PP_IIF(c, PP_NIL, y(1, PP_NIL))
#    define PP_NOT_EQUAL_6(c, y) PP_IIF(c, PP_NIL, y(1, PP_NIL))
#    define PP_NOT_EQUAL_7(c, y) PP_IIF(c, PP_NIL, y(1, PP_NIL))
#    define PP_NOT_EQUAL_8(c, y) PP_IIF(c, PP_NIL, y(1, PP_NIL))
#    define PP_NOT_EQUAL_9(c, y) PP_IIF(c, PP_NIL, y(1, PP_NIL))
#    define PP_NOT_EQUAL_10(c, y) PP_IIF(c, PP_NIL, y(1, PP_NIL))

#pragma warning(disable : 4003)

#define PP_NOT_EQUAL_I(x, y) PP_CAT(PP_NOT_EQUAL_CHECK_, PP_NOT_EQUAL_ ## x(0, PP_NOT_EQUAL_ ## y))
#define PP_NOT_EQUAL(x, y) PP_NOT_EQUAL_I(x, y)

#define PP_COMPL_0 1
#define PP_COMPL_1 0
#define PP_COMPL_ID(id) id
#define PP_COMPL_I(x) PP_COMPL_ID(PP_COMPL_ ## x)
#define PP_COMPL(x) PP_COMPL_I(x)

#define PP_EQUAL(x, y) PP_COMPL(PP_NOT_EQUAL(x, y))

#define VA_NARGS_II(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, N, ...) N
#define VA_NARGS_I(paramsinparen) VA_NARGS_II paramsinparen
#define VA_NARGS(...) VA_NARGS_I((__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1))

#define VA_ARG_0(e0, ...) e0
#define VA_ARG_1(e0, e1, ...) e1
#define VA_ARG_2(e0, e1, e2, ...) e2
#define VA_ARG_3(e0, e1, e2, e3, ...) e3
#define VA_ARG_4(e0, e1, e2, e3, e4, ...) e4
#define VA_ARG_5(e0, e1, e2, e3, e4, e5, ...) e5
#define VA_ARG_6(e0, e1, e2, e3, e4, e5, e6, ...) e6
#define VA_ARG_7(e0, e1, e2, e3, e4, e5, e6, e7, ...) e7
#define VA_ARG_8(e0, e1, e2, e3, e4, e5, e6, e7, e8, ...) e8
#define VA_ARG_9(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, ...) e9
#define VA_ARG_10(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, ...) e10
#ifdef _MSC_VER
#define VA_ARG(_i, ...) PP_CAT(PP_CAT(VA_ARG_, _i),(__VA_ARGS__, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0))
#else
#define VA_ARG(_i, ...) PP_CAT(VA_ARG_, _i)(__VA_ARGS__, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
#endif



template<class Test, class Return>
Variant cpp_findmatch(int nr, Test test, Return returnFunc, bool reverse = false)
{
	int start, end;
	if (reverse) {
		start = nr;
		end = 0;
	} else {
		start = 1;
		end = nr + 1;
	}
	for (int i = start; i != end; reverse ? i-- : i++)
		if (test(i))
			return returnFunc(i);
	return 0;
}

template<class Test>
int cpp_findmatch(int nr, Test test)
{
	for (int i = 1; i <= nr; i++)
		if (test(i))
			return i;
	return 0;
}

template<class Test, class Return>
Variant cpp_findmatchintree(treenode top, Test test, Return returnFunc)
{
	if (test(top))
		return returnFunc(top);
	forobjecttreeunder (top) {
		if (test(a))
			return returnFunc(a);
	}
	return 0;
}

template<class Test>
treenode cpp_findmatchintree(treenode top, Test test)
{
	if (test(top))
		return top;
	forobjecttreeunder (top) {
		if (test(a))
			return a;
	}
	return 0;
}



template<class ValueFunc, class ReturnFunc, class ValidityFunc>
Variant cpp_findmaxmin(int nr, ValueFunc test, ReturnFunc returnFunc, 
							ValidityFunc validityFunc, bool reverse = false, bool isMax = true)
{
	int start, end, incr;
	if (reverse) {
		start = nr;
		end = 0;
		incr = -1;
	} else {
		start = 1;
		end = nr + 1;
		incr = 1;
	}
	int bestIndex = 0;
	double best = -FLT_MAX;
	for (int i = start; i != end; i+=incr) {
		if(validityFunc(i)) {
			double temp = test(i);
			if (isMax ? temp > best : temp < best) {
				bestIndex = i;
				best = temp;
			}
		}
	}
	if (bestIndex == 0)
		return 0;
	else {
		Variant returnVal = returnFunc(bestIndex);
		if((double)returnVal == -FLT_MAX)
			return best;
		else return returnVal;
	}
}

template<class Value, class ReturnFunc, class ValidityFunc>
Variant cpp_findmax(int nr, Value test, ReturnFunc returnFunc, ValidityFunc validityFunc, bool reverse = false)
{
	return cpp_findmaxmin(nr, test, returnFunc, validityFunc, reverse, true);
}

template<class ValueFunc, class ReturnFunc>
Variant cpp_findmax(int nr, ValueFunc test, ReturnFunc returnFunc)
{
	return cpp_findmaxmin(nr, test, returnFunc, [](int count) -> bool {return true;}, false, true);
}

template<class ValueFunc>
Variant cpp_findmax(int nr, ValueFunc test)
{
	double best = -FLT_MAX;
	for (int i = 1; i <= nr; i++) {
		double temp = test(i);
		if (temp > best)
			best = temp;
	}
	return best;
}


template<class ValueFunc, class ReturnFunc, class ValidityFunc>
Variant cpp_findmin(int nr, ValueFunc test, ReturnFunc returnFunc, ValidityFunc validityFunc, bool reverse = false)
{
	return cpp_findmaxmin(nr, test, returnFunc, validityFunc, reverse, false);
}

template<class ValueFunc, class ReturnFunc>
Variant cpp_findmin(int nr, ValueFunc test, ReturnFunc returnFunc)
{
	return cpp_findmaxmin(nr, test, returnFunc, [](int count) -> bool {return true;}, false, false);
}

template<class Test>
Variant cpp_findmin(int nr, Test test)
{
	double best = FLT_MAX;
	for (int i = 1; i <= nr; i++) {
		double temp = test(i);
		if (temp < best)
			best = temp;
	}
	return best;
}

template<class Do>
void cpp_repeat(int nr, Do doIt) 
{
	for(int i = 1; i <= nr; i++)
		doIt(i);
}


#define findmatchintree(...) \
	PP_IIF(PP_EQUAL(2, VA_NARGS(__VA_ARGS__)), \
		cpp_findmatchintree(VA_ARG(0, __VA_ARGS__), [&](treenode a) -> bool {return VA_ARG(1, __VA_ARGS__);}), \
			cpp_findmatchtree(VA_ARG(0, __VA_ARGS__), [&](treenode a) -> bool {return VA_ARG(1, __VA_ARGS__);}, \
						[&](treenode a) -> Variant {return VA_ARG(2, __VA_ARGS__);}))

#define findmatch(...) \
	PP_IIF(PP_EQUAL(2, VA_NARGS(__VA_ARGS__)), \
		cpp_findmatch(VA_ARG(0, __VA_ARGS__), [&](int count) -> bool {return VA_ARG(1, __VA_ARGS__);}), \
		PP_IIF(PP_EQUAL(3, VA_NARGS(__VA_ARGS__)), \
			cpp_findmatch(VA_ARG(0, __VA_ARGS__), [&](int count) -> bool {return VA_ARG(1, __VA_ARGS__);}, \
						[&](int count) -> Variant {return VA_ARG(2, __VA_ARGS__);}), \
			cpp_findmatch(VA_ARG(0, __VA_ARGS__), [&](int count) -> bool {return VA_ARG(1, __VA_ARGS__);}, \
						[&](int count) -> Variant {return VA_ARG(2, __VA_ARGS__);}, VA_ARG(3, __VA_ARGS__))))


#define findmax(...) \
	PP_IIF(PP_EQUAL(2, VA_NARGS(__VA_ARGS__)), \
		cpp_findmax(VA_ARG(0, __VA_ARGS__), [&](int count) -> double {return VA_ARG(1, __VA_ARGS__);}), \
		PP_IIF(PP_EQUAL(3, VA_NARGS(__VA_ARGS__)), \
			cpp_findmax(VA_ARG(0, __VA_ARGS__), [&](int count) -> double {return VA_ARG(1, __VA_ARGS__);}, \
			[&](int count) -> Variant {return VA_ARG(2, __VA_ARGS__); }), \
			PP_IIF(PP_EQUAL(4, VA_NARGS(__VA_ARGS__)), \
				cpp_findmax(VA_ARG(0, __VA_ARGS__), [&](int count) -> double {return VA_ARG(1, __VA_ARGS__);}, \
				[&](int count) -> Variant {return VA_ARG(2, __VA_ARGS__); }, \
				[&](int count) -> bool {return VA_ARG(3, __VA_ARGS__); }), \
				cpp_findmax(VA_ARG(0, __VA_ARGS__), [&](int count) -> double {return VA_ARG(1, __VA_ARGS__);}, \
				[&](int count) -> Variant {return VA_ARG(2, __VA_ARGS__); }, \
				[&](int count) -> bool {return VA_ARG(3, __VA_ARGS__); }, VA_ARG(4, __VA_ARGS)))))

#define findmin(...) \
	PP_IIF(PP_EQUAL(2, VA_NARGS(__VA_ARGS__)), \
		cpp_findmin(VA_ARG(0, __VA_ARGS__), [&](int count) -> double {return VA_ARG(1, __VA_ARGS__);}), \
		PP_IIF(PP_EQUAL(3, VA_NARGS(__VA_ARGS__)), \
			cpp_findmin(VA_ARG(0, __VA_ARGS__), [&](int count) -> double {return VA_ARG(1, __VA_ARGS__);}, \
			[&](int count) -> Variant {return VA_ARG(2, __VA_ARGS__); }), \
			PP_IIF(PP_EQUAL(4, VA_NARGS(__VA_ARGS__)), \
				cpp_findmin(VA_ARG(0, __VA_ARGS__), [&](int count) -> double {return VA_ARG(1, __VA_ARGS__);}, \
				[&](int count) -> Variant {return VA_ARG(2, __VA_ARGS__); }, \
				[&](int count) -> bool {return VA_ARG(3, __VA_ARGS__); }), \
				cpp_findmin(VA_ARG(0, __VA_ARGS__), [&](int count) -> double {return VA_ARG(1, __VA_ARGS__);}, \
				[&](int count) -> Variant {return VA_ARG(2, __VA_ARGS__); }, \
				[&](int count) -> bool {return VA_ARG(3, __VA_ARGS__); }, VA_ARG(4, __VA_ARGS)))))

#define repeat(nr, doIt) cpp_repeat(nr, [&](int count) -> {doIt;});


#ifndef FLEXSIM_ENGINE_COMPILE
#define query(...) \
	PP_IIF(PP_EQUAL(1, VA_NARGS(__VA_ARGS__)), \
		cpp_query(VA_ARG(0, __VA_ARGS__)), \
	PP_IIF(PP_EQUAL(2, VA_NARGS(__VA_ARGS__)), \
		cpp_query(VA_ARG(0, __VA_ARGS__), \
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(1, __VA_ARGS__));})),\
	PP_IIF(PP_EQUAL(3, VA_NARGS(__VA_ARGS__)), \
		cpp_query(VA_ARG(0, __VA_ARGS__),  \
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(1, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(2, __VA_ARGS__));})),\
	PP_IIF(PP_EQUAL(4, VA_NARGS(__VA_ARGS__)), \
		cpp_query(VA_ARG(0, __VA_ARGS__), \
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(1, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(2, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(3, __VA_ARGS__));})),\
	PP_IIF(PP_EQUAL(5, VA_NARGS(__VA_ARGS__)), \
		cpp_query(VA_ARG(0, __VA_ARGS__), \
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(1, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(2, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(3, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(4, __VA_ARGS__));})),\
	PP_IIF(PP_EQUAL(6, VA_NARGS(__VA_ARGS__)), \
		cpp_query(VA_ARG(0, __VA_ARGS__), \
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(1, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(2, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(3, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(4, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(5, __VA_ARGS__));})),\
	PP_IIF(PP_EQUAL(7, VA_NARGS(__VA_ARGS__)), \
		cpp_query(VA_ARG(0, __VA_ARGS__), \
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(1, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(2, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(3, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(4, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(5, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(6, __VA_ARGS__));})),\
	PP_IIF(PP_EQUAL(8, VA_NARGS(__VA_ARGS__)), \
		cpp_query(VA_ARG(0, __VA_ARGS__), \
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(1, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(2, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(3, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(4, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(5, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(6, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(7, __VA_ARGS__));})),\
	PP_IIF(PP_EQUAL(9, VA_NARGS(__VA_ARGS__)), \
		cpp_query(VA_ARG(0, __VA_ARGS__), \
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(1, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(2, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(3, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(4, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(5, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(6, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(7, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(8, __VA_ARGS__));})),\
		cpp_query(VA_ARG(0, __VA_ARGS__), \
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(1, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(2, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(3, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(4, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(5, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(6, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(7, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(8, __VA_ARGS__));}),\
		                    CppQueryLambda([&]() -> Variant {return Variant(VA_ARG(9, __VA_ARGS__));}))\
	)))))))))
#endif

}