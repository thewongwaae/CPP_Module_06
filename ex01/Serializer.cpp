#include "Serializer.hpp"

/* Constructs */

Serializer::Serializer( void ) {
	std::cout << "Default constructor called" << std::endl;
}

Serializer::Serializer( const Serializer &copy ) {
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}

Serializer::~Serializer( void ) {
	std::cout << "Destructor called" << std::endl;
}

Serializer &Serializer::operator=( const Serializer &assign ) {
	if (this == &assign)
		return *this;
	
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}

/* Public Methods / Conversions */

uintptr_t Serializer::serialize( Data *ptr ) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::unserialize( uintptr_t raw ) {
	Data *data = new Data;
	*data = *reinterpret_cast<Data *>(raw);
	return data;
}