#ifndef MYMUDUO_BASE_TYPES_H
#define MYMUDUO_BASE_TYPES_H

#include <stdint.h>
#include <string>

#ifndef NDEBUG
#include <assert.h>
#endif

namespace mymuduo
{
	using std::string;

	template<typename To, typename From>
	inline To implicit_case(From const &f) {
		return f;
	}

};

#endif
