#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>

# include "type_traits.hpp"

namespace ft {

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
    typedef T*                              pointer;
    typedef T&                              reference;
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

}

#endif