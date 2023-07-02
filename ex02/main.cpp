#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>

Base *generate( void ) {
	int i = rand() % 3;
	
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

void identify( Base *pointer ) {
	if (dynamic_cast<A *>(pointer))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(pointer))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(pointer))
		std::cout << "C" << std::endl;
}

static void identify(Base &Test)
{
	static int i;
	static std::string classes[3] = {"A", "B", "C"};
	
	while (i < 3)
	{
		void *foo = NULL; // only to initialize the unused var
		Base &unused = (Base &)foo; // only to prevent the -Werror from triggering for unused value of the casts
		try
		{
			if (i == 0)
				unused = dynamic_cast<A &>(Test);
			else if (i == 1)
				unused = dynamic_cast<B &>(Test);
			else if (i == 2)
				unused = dynamic_cast<C &>(Test);
			else
				std::cout << "unknow type" << std::endl;
			(void)unused;
		}
		catch (std::exception &e)
		{
			// std::cout << e.what() << std::endl; //enable to see what exception was cought
			i++;
			identify(Test);
			return;
		}
		std::cout << classes[i] << " is the identified type" << std::endl;
		i = 0;
		break;
	}
}

int main( void ) {
	srand(time(NULL));
	Base *test = generate();
	identify(test);
	identify(*test);
	delete test;
	return 0;
}