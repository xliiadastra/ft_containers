#include "../../ft_pair.hpp"
#include "../../ft_make_pair.hpp"
#include <iostream>

int main()
{
	ft::Pair<int, char> var;
	var.first = 1;
	var.second = 65;

	std::cout << var.first << std::endl;
	std::cout << var.second << std::endl;
}
