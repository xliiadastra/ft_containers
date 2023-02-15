#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

# include <cstddef>

namespace ft {
/*
 * enable_if
 */
template <bool B, class T = void>
struct enable_if {};
template <class T>
struct enable_if<true, T> {
    typedef T type;
};

/*
 * remove_const
 */
template <typename T>
struct remove_const { typedef T type; };

template <typename T>
struct remove_const<const T> { typedef T type; };

/*
 * remove_volatile
 */
template <typename T>
struct remove_volatile { typedef T type; };

template <typename T>
struct remove_volatile<volatile T> { typedef T type; };

/*
 * remove_cv
 */
template <typename T>
struct remove_cv { typedef typename remove_volatile<typename remove_const<T>::type>::type type; };

/*
 * true or false type
 */
struct false_type   { static const bool   value = false; };
struct true_type    { static const bool    value = true; };

/*
 * is_integral
 */
template <typename T>
struct ft_is_integral : public false_type {};
template <>
struct ft_is_integral<bool> : public true_type {};
template <>
struct ft_is_integral<char> : public true_type {};
template <>
struct ft_is_integral<signed char> : public true_type {};
template <>
struct ft_is_integral<unsigned char> : public true_type {};
template <>
struct ft_is_integral<wchar_t> : public true_type {};
template <>
struct ft_is_integral<char16_t> : public true_type {};
template <>
struct ft_is_integral<short> : public true_type {};
template <>
struct ft_is_integral<unsigned short> : public true_type {};
template <>
struct ft_is_integral<int> : public true_type {};
template <>
struct ft_is_integral<unsigned int> : public true_type {};
template <>
struct ft_is_integral<long> : public true_type {};
template <>
struct ft_is_integral<unsigned long> : public true_type {};
template <>
struct ft_is_integral<unsigned long int> : public true_type {};
template <>
struct ft_is_integral<long long> : public true_type {};
template <>
struct ft_is_integral<unsigned long long> : public true_type {};

template <typename T>
struct is_integral : public ft_is_integral<typename remove_cv<T>::type> {};
}
#endif