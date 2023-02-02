#ifndef FT_STACK_HPP
# define FT_STACK_HPP

# include <memory>
# include <vector>
# include <stack>

namespace ft
{
	template <typename T, class Container = std::vector<T>>
	class	stack
	{
	private:
		T	*data;
		int	size;
		int	capacity;

	public:
		Stack() : size(0), capacity(10) {
		data = 
	}
	};
}

#endif
