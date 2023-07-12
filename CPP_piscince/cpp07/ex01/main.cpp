#include "includes.hpp"
#include "types.hpp"
#include "templates.tpp"

int main()
{
	int	int_array[ARR_SIZE] = {0, 1, 2};
	char char_array[ARR_SIZE] = {'a', 'b', 'c'};

    std::cout << "before change: " << std::endl;
    print(int_array, ARR_SIZE);
    print(char_array, ARR_SIZE);
    std::cout << "after iter: " << std::endl;
	iter(int_array, ARR_SIZE, addone<int>);
    print(int_array, ARR_SIZE);
	iter(char_array, ARR_SIZE, addone<char>);
    print(char_array, ARR_SIZE);

}
