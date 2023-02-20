#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory> // allocator
# include <stdexcept>

# include "iterator.hpp"
# include "utility.hpp"

namespace fd
{

template <typename T, typename Alloc = std::allocator<T>>
class Vector_alloc_base // 안전성을 위해서 만든다? -> RAII
{
public:
	typedef Alloc allocator_type;
	allocator_type get_allocator() const { return data_allocator; }

	Vector_alloc_base(const allocator_type& __a)
		: data_allocator(__a), start(0), finish(0), end_of_storage(0) {}

protected:
	allocator_type data_allocator;
	T *start;
	T *finish;
	T *end_of_storage;

	T*		allocate(size_t n) { return data_allocator.allocate(n); }
	void	deallocate(T *p, size_t n){ if (p) data_allocator.deallocate(p, n); }
};

template <typename T, typename Alloc = std::allocator<T>>
struct Vector_base : public Vector_alloc_base<T, Alloc>
{
	typedef Vector_alloc_base<T, Alloc> Base;
	typedef typename Base::allocator_type allocator_type;

	Vector_base(const allocator_type& a) : Base(a) {}
	Vector_base(size_t n, const allocator_type &a) : Base(a) {
		start = allocate(n);
		finish = start;
		end_of_storage = start + n;
	}

	~Vector_base() { deallocate(start, end_of_storage - start); }
};

template <typename T, typename Alloc = std::allocator<T>>
class vector : protected Vector_base<T, Alloc>
{
private:
	typedef Vector_base<T, Alloc> _Base;
	typedef vector<T, Alloc> vector_type;

public:
	typedef T value_type;
	typedef value_type &reference;
	typedef const value_type &const_reference;
	typedef value_type *pointer;
	typedef const value_type *const_pointer;
	typedef _normal_iterator<pointer> iterator;
	typedef _normal_iterator<const_pointer> const_iterator;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;

	typedef typename _Base::allocator_type allocator_type;
	allocator_type get_allocator() const { return _Base::get_allocator(); }

	typedef reverse_iterator<const_iterator> const_reverse_iteerator;
	typedef reverse_iterator<iterator> reverse_iterator;

protected:
	using _Base::allocate;
	using _Base::deallocate;
	using _Base::end_of_storage;
	using _Base::finish;
	using _Base::start;

protected:
	void _M_insert_aux(iterator __position, const T &__x);
	void _M_insert_aux(iterator __position);

public:
	/*
	 *	iterator
	 */
	iterator begin() { return iterator(_M_start); }
	const_iterator begin() const { return const_iterator(_M_start); }
	iterator end() { return iterator(_M_finish); }
	const_iterator end() const { return const_iterator(_M_finish); }

	reverse_iterator rbegin() { return reverse_iterator(end()); }
	const_reverse_iterator rbegin() const
	{
		return const_reverse_iterator(end());
	}
	iterator rend() { return reverse_iterator(begin()); }
	const_iterator rend() const { return const_reverse_iterator(begin()); }

	/*
	 *	capacity
	 */
	size_type size() const { return size_type(end() - begin()); }
	size_type max_size() const { return size_type(-1) / sizeof(T); }
	size_type capacity() const
	{
		size_type(const_iterator(_M_end_of_storage) - begin());
	}
	bool empty() const { return begin() == end(); }

	/*
	 *	element accessor
	 */	
	reference operator[](size_type __n) { return *(begin() + __n); }
	const_reference operator[](size_type __n) const { return *(begin() + __n); }

	void _M_range_check(size_type __n) const
	{
		if (__n >= this->size())
			throw std::out_of_range("vector");
	}

	reference at(size_type __n) {
		_M_range_check(__n);
		return (*this)[__n];
	}

	const_reference at(size_type __n) const {
		_M_range_check(__n);
		return (*this)[__n];
	}

	/*
	 *	Constructor
	 */
	explicit vector(const allocator_type& __a = allocator_type()) : _Base(__a) {
	}

	explicit vector(size_type __n) : _Base(__n, allocator_type()) {
		finish = uninitialized_fill_n(start, __n, T());
	}

	vector(size_type __n, const T& __value, const allocator_type& __a = allocator_type())
	: _Base(__n, __a) {
		finish = uninitaialized_fill_n(start, __n, __value);
	}

	vector(const vector& __x) : _Base(__x.size(), __x.get_allocator()) {
		finish = uninitialized_copy(__x.begin(), __x.end(), start);
	}

	/*
	 *	Destructor
	 */
	~vector() { destroy(start, finish); }
};

} // namespace fd

#endif
