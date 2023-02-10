#ifndef FT_MAKE_PAIR_HPP
# define FT_MAKE_PAIR_HPP

# include "ft_pair.hpp"

namespace ft
{
	template <typename T1, typename T2>
	inline ft::Pair<T1, T2> make_pair(const T1& x, const T2& y)
	{
		return (ft::Pair<T1, T2>(x, y));
	}
}
#endif
