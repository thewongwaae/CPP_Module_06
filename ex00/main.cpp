#include "Conversion.hpp"

int main( int ac, char **av )
{
	if (ac != 2)
	{
		std::cerr << "One Argument required." << std::endl;
		return (1);
	}
	try
	{
		Conversion conversion(av[1]);
		// try
		// {
		// 	Conversion copy(conversion);
		// }
		// catch(const std::exception& e)
		// {
		// 	std::cerr << e.what() << std::endl;
		// }
	}
	catch(const Conversion::ErrorException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}