#ifndef FT_PAIR_HPP
# define FT_PAIR_HPP

namespace ft
{
	template <typename T1, typename T2>
	class	Pair
	{
	private:
		typedef T1 first_type;
		typedef T2 second_type;

		T1	first;
		T2	second;

		Pair() : first(T1()), second(T2()) {} // T1 = int, T2 = char
		Pair(const T1& f, const T2& s) : first(f), second(s) {}

		template <typename U1, typename U2>
		Pair(const Pair<U1, U2>& p) : first(p.first), second(p.second) {} // copy constructor
	};

	template <typename T1, typename T2>
	inline bool	operator==(const Pair<T1, T2>& x, const Pair<T1, T2>& y) {// what is inline?
		return ((x.first == y.first) && (x.second == y.second));
	}

	template <typename T1, typename T2>
	inline bool operator<(const Pair<T1, T2>& x, const Pair<T1, T2>& y) {
		return ((x.first < y.first) || (!(y.first < x.first) && (x.second < y.second)));
	}
}
#endif
