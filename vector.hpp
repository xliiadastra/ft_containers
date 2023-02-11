#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory> // allocator

namespace fd {

template <typename T, typename Alloc = std::allocator<T> >
class	Vector_base // 안전성을 위해서 만든다?
{
public:
	typedef Alloc allocator_type;

	Vector_base(const Alloc &) : start(0), finish(0), end_of_storage(0) {}
	Vector_base(size_t n, const Alloc &) : start(0), finish(0), end_of_storage(0) {
		start = allocate(n);
		finish = start;
		end_of_storage = start + n;
	}
};

template <typename T, typename Alloc = std::allocator<T> >
class	vector {
public:
	typedef T					value_type;
	typedef value_type&			reference;
	typedef const value_type&	const_reference;
	typedef value_type*			pointer;
	typedef const value_type*	const_pointer;
	typedef value_type*			iterator;
	typedef const value_type*	const_iterator;
	typedef size_t				size_type;
	typedef ptrdiff_t			difference_type;

};


}

#endif
