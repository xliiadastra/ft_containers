#ifndef FT_STACK_HPP
# define FT_STACK_HPP

# include <memory>
# include <vector>
# include <stack>

namespace ft
{
	template <typename T, class _Container = std::vector<T> >
	class	Stack
	{
	private:
		friend bool operator==(const Stack&, const Stack&);
		friend bool operator<(const Stack&, const Stack&);
	public:
		typedef typename _Container::value_type	value_type;
		typedef typename _Container::size_type	size_type;
		typedef typename _Container				container_type;

		typedef typename _Container::reference			reference;
		typedef typename _Container::const_reference	const_reference;
	protected:
		_Container	_M_c; // why _M_c?
	public:
		Stack() : _M_c() {}
		explicit	Stack(const _Container& __s) : _M_c(__s) {}

		bool			empty() const { return _M_c.empty(); }
		size_type		size() const { return _M_c.size(); }
		reference		top() { return _M.c.back(); }
		const_reference	top() const { return _M_c.back(); }
		void			push(const value_type& __x) { _M_c.push_back(__x); }
		void			pop() { _M_c.pop_back(); }
	};

	template <typename T, class _Con>
	bool operator==(const Stack<T, _Con>& __x, const Stack<T, _Con>& __y) {
		return (__x._M_c == __y._M_c);
	}

	template <typename T, class _Con>
	bool operator<(const Stack<T, _Con>& __x, const Stack<T, _Con>& __y) {
		return (__x._M_c < __y._M_c);
	}

	template <typename T, class _Con>
	bool operator!=(const Stack<T, _Con>& __x, const Stack<T, _Con>& __y) {
		return (__x._M_c != __y._M_c);
	}
	
	template <typename T, class _Con>
	bool operator>(const Stack<T, _Con>& __x, const Stack<T, _Con>& __y) {
		return (__x._M_c > __y._M_c);
	}
	
	template <typename T, class _Con>
	bool operator<=(const Stack<T, _Con>& __x, const Stack<T, _Con>& __y) {
		return (__x._M_c <= __y._M_c);
	}

	template <typename T, class _Con>
	bool operator>=(const Stack<T, _Con>& __x, const Stack<T, _Con>& __y) {
		return (__x._M_c >= __y._M_c);
	}
}
#endif
