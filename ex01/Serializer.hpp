#include <string>
#include <iostream>
#include <stdint.h>

typedef struct Data
{
	std::string	name;
	size_t		age;
	Data		*next;
}	Data;

class Serializer {
	private:

	public:
		Serializer( void );
		Serializer( const Serializer &copy );
		~Serializer( void );
		Serializer &operator=( const Serializer &assign );

		uintptr_t	serialize( Data *ptr );
		Data		*unserialize( uintptr_t raw );
};
