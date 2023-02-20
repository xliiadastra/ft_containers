#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
// # include <iterator>

# include "type_traits.hpp"

namespace ft {

template <typename _Iterator>
class reverse_iterator
: public iterator<typename iterator_traits<_Iterator>::iterator_category,
                  typename iterator_traits<_Iterator>::value_type,
                  typename iterator_traits<_Iterator>::difference_type,
                  typename iterator_traits<_Iterator>::pointer,
                  typename iterator_traits<_Iterator>::reference>
{
protected:
    _Iterator _M_current;

public:
    typedef _Iterator                                               iterator_type;
    typedef typename iterator_traits<_Iterator>::difference_type    difference_type;
    typedef typename iterator_traits<_Iterator>::reference          reference;
    typedef typename iterator_traits<_Iterator>::pointer            pointer;

    reverse_iterator() {}

    explicit    reverse_iterator(iterator_type _x) : _M_current(_x) {}
    reverse_iterator(const reverse_iterator& _x) : _M_current(_x._M_current) {}

    template <typename _Iter>
    reverse_iterator(const reverse_iterator<_Iter>& _x) : _M_current(_x.base()) {}

    iterator_type   base() const { return _M_current; }

    reference   operator*() const {
        _Iterator _tmp = _M_current;
        return *--_tmp;
    }

    pointer operator->() const { return &(operator*()); }

    reverse_iterator&   operator++() {
        --_M_current;
        return *this;
    }

    reverse_iterator    operator++(int) {
        reverse_iterator _tmp = *this;
        --_M_current;
        return _tmp;
    }

    reverse_iterator&   operator--() {
        ++_M_current;
        return *this;
    }

    reverse_iterator    operator--(int) {
        reverse_iterator _tmp = *this;
        ++_M_current;
        return _tmp;
    }

    reverse_iterator    operator+(difference_type _n) const {
        return reverse_iterator(_M_current - _n);
    }

    reverse_iterator&   operator+=(difference_type _n) {
        _M_current -= _n;
        return *this;
    }

    reverse_iterator    operator-(difference_type _n) const {
        return reverse_iterator(_M_current + _n);
    }

    reverse_iterator&   operator-=(difference_type _n) {
        _M_current += _n;
        return *this;
    }

    reference   operator[](difference_type _n) const {
        return *(*this + _n);
    }
};


template <typename _Iter>
struct iterator_traits {
    typedef typename _Iter::difference_type     difference_type;
    typedef typename _Iter::value_type          value_type;
    typedef typename _Iter::pointer             pointer;
    typedef typename _Iter::reference           reference;
    typedef typename _Iter::iterator_category   iterator_category;
};

template <typename T>
struct iterator_traits<T*> {
    typedef ptrdiff_t                       difference_type;
    typedef T                               value_type;
    typedef T*                              pointer;
    typedef T&                              reference;
    typedef std::random_access_iterator_tag iterator_category;
};

template <typename T>
struct iterator_traits<const T*> {
    typedef ptrdiff_t                       difference_type;
    typedef T                               value_type;
    typedef const T*                        pointer;
    typedef const T&                        reference;
    typedef std::random_access_iterator_tag iterator_category;
};

template <typename _Category, typename _T, typename _Distance = ptrdiff_t,
          typename _Pointer = _T*, typename _Reference = _T&>
struct iterator {
    typedef _Category   iterator_category;
    typedef _T          value_type;
    typedef _Distance   difference_type;
    typedef _Pointer    pointer;
    typedef _Reference  reference;
};

template <typename _Iterator>
class _normal_iterator
: public iterator<typename iterator_traits<_Iterator>::iterator_category,
                  typename iterator_traits<_Iterator>::value_type,
                  typename iterator_traits<_Iterator>::difference_type,
                  typename iterator_traits<_Iterator>::pointer,
                  typename iterator_traits<_Iterator>::reference>
{
protected:
    _Iterator _M_current; // Member

public:
    typedef typename iterator_traits<_Iterator>::differenece_thhype difference_type;
    typedef typename iterator_traits<_Iterator>::reference          reference;
    typedef typename iterator_traits<_Iterator>::pointer            pointer;

    _normal_iterator() : _M_current(_Iterator()) {}

    explicit _normal_iterator(const _Iterator& _i) : _M_current(_i) {}

    // Allow iterator to const_iterator conversion
    template <typename _Iter>
    inline  _normal_iterator(const _normal_iterator<_Iter>& _i) : _M_current(_i.base()) {}

    // Forward iterator requirments
    reference   operator*() const { return (*_M_current); }

    pointer     operator->() const { return (_M_current); }

    _normal_iterator&   operator++() { ++_M_current; return (*this); }

    _normal_iterator    operator++(int) { return _normal_iterator(_M_current++); }

    // Bidrectional iterator requirements
    _normal_iterator&   operator--() { --_M_current; return (*this); }

    _normal_iterator    operator--(int) { return _normal_iterator(_M_current--); }

    // Random access iterator requirments
    reference   operator[](const difference_type& _n) const { return (_M_current[_n]); }

    _normal_iterator&   operator+=(const difference_type& _n) { _M_current += _n; return (*this); }

    _normal_iterator    operator+(const difference_type& _n) const { return _normal_iterator(_M_current + _n); }

    _normal_iterator&   operator-=(const difference_type& _n) { _M_current -= _n; return (*this); }

    _normal_iterator    operator-(const difference_type& _n) const { return _normal_iterator(_M_current - _n); }

    difference_type     operator-(const _normal_iterator& _i) const { return _M_current - _i.current; }

    const _Iterator&    base() const { return _M_current; }
};

// Forward iterator requirements
template <typename _IteratorL, typename _IteratorR>
inline bool operator==(const _normal_iterator<_IteratorL>& _lhs,
                       const _normal_iterator<_IteratorR>& _rhs)
{ return _lhs.base() == _rhs.base(); }

template <typename _IteratorL, typename _IteratorR>
inline bool operator!=(const _normal_iterator<_IteratorL>& _lhs,
                       const _normal_iterator<_IteratorR>& _rhs)
{ return !(_lhs == _rhs); }

// Random access iterator requirements
template <typename _IteratorL, typename _IteratorR>
inline bool operator<(const _normal_iterator<_IteratorL>& _lhs,
                      const _normal_iterator<_IteratorR>& _rhs)
{ return  _lhs.base() < _rhs.base(); }

template <typename _IteratorL, typename _IteratorR>
inline bool operator>(const _normal_iterator<_IteratorL>& _lhs,
                      const _normal_iterator<_IteratorR>& _rhs)
{ return _rhs < _lhs; }

template <typename _IteratorL, typename _IteratorR>
inline bool operator<=(const _normal_iterator<_IteratorL>& _lhs,
                       const _normal_iterator<_IteratorR>& _rhs)
{ return !(_rhs < _lhs); }

template <typename _IteratorL, typename _IteratorR>
inline bool operator>=(const _normal_iterator<_IteratorL>& _lhs,
                       const _normal_iterator<_IteratorR>& _rhs)
{ return !(_lhs < _rhs); }

template <typename _Iterator>
inline _normal_iterator<_Iterator>  operator+(typename _normal_iterator<_Iterator>::difference_type _n,
                                              const _normal_iterator<_Iterator>& _i)
{ return _normal_iterator<_Iterator>(_i.base() + _n); }

}

#endif