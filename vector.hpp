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

class	vector {


};


}

#endif
