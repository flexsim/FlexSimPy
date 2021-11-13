#pragma once 

namespace FlexSim
{

template< typename Lambda >
class ScopeGuard
{
	mutable bool committed;
	Lambda rollbackLambda;
public:

	explicit ScopeGuard(Lambda&& _l)
	// explicit, unless you want implicit conversions from *everything*
	: committed(false)
	, rollbackLambda(std::forward<Lambda>(_l)) // avoid copying unless necessary
	{}

	template< typename AdquireLambda >
	ScopeGuard(const AdquireLambda&& _al, const Lambda&& _l) : committed(false), rollbackLambda(std::forward(_l))
	{
		_al();
	}

	// no copy constructor
	ScopeGuard(const ScopeGuard& that) = delete;

	// move constructor
	ScopeGuard(ScopeGuard&& that)
		: committed(that.committed)
		, rollbackLambda(std::move(that.rollbackLambda))
	{
		that.committed = true;
	}

	~ScopeGuard()
	{
		if (!committed)
			rollbackLambda();
	}
	inline void commit() const { committed = true; }
};

template< typename aLambda, typename rLambda>
ScopeGuard< rLambda > // return by value is the preferred C++11 way.
makeScopeGuard(aLambda&& _a, rLambda&& _r) // again perfect forwarding
{
	return ScopeGuard< rLambda >(std::forward<aLambda>(_a), std::forward<rLambda>(_r)); // *** no longer UB, because we're returning by value
}

template<typename rLambda>
ScopeGuard< rLambda > makeScopeGuard(rLambda&& _r)
{
	return ScopeGuard< rLambda >(std::forward<rLambda>(_r));
}

}