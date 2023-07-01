#include "Conversion.hpp"

int main( int ac, char **av )
{
	if (ac != 2)
	{
		std::cerr << "Only one arguement required." << std::endl;
		return (1);
	}
	try
	{
		Conversion conversion(av[1]);
	}
	catch(const Conversion::Exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}