#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft {
    template<typename _Iterator>
    class reverse_iterator : public iterator<typename iterator_traits<_Iterator>::iterator_catgory,
                                             typename iterator_traits<_Iterator>::value_type,
                                             typename iterator_traits<_Iterator>::difference_type,
                                             typename iterator_traits<_Iterator>::pointer,
                                             typename iterator_traits<_Iterator>::reference>
}

#endif