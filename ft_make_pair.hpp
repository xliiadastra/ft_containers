#ifndef FT_MAKE_PAIR_HPP
# define FT_MAKE_PAIR_HPP

# include "ft_pair.hpp"

template <typename T1, typename T2>
inline pair<T1, T2> make_pair(const T1&, x const T2& y)
{
	return (pair<T1, T2>(x, y));
}

#endif
