#include "includes.hpp"
#include "classes.hpp"

int main (int argc, char **argv)
{
	int	topo;

    if (argc != 2)
    {
        std::cout << "wrong number of arguments, terminating" << std::endl;
        return(1);
    }
    ScalarConverter::convert(argv[1]);

	std::string	pippo = "ciao mamma";
    return (0);

	t_string	*ptr;
	t_string	str1;


	ptr = (t_string *)malloc(sizeof(t_string));

	ptr->array = NULL;
	ptr->size = 0;
}


main{
	input();
	init();
	if (loop())
		gestisci errore();
	libera tutto();

}