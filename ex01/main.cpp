#include <iostream>
#include "Serializer.hpp"

int main( void ) {
	Data data;
	Serializer serial;

	data.name = "Something";
	data.age = 1;

	std::cout << "\n\033[35mOriginal Data: Name[" << data.name
			<< "] Age[" << data.age << "]\033[0m"
			<< std::endl;

	uintptr_t serialized = serial.serialize(&data);

	Data *deserial = serial.unserialize(serialized);

	std::cout << "\033[36mDeserialized Data: Name[" << deserial->name
			<< "] Age[" << deserial->age << "]\033[0m\n"
			<< std::endl;

	std::cout << "\033[35mOriginal Address: " << &data << "\033[0m" << std::endl;
	std::cout << "\033[36mDeserialized Adress: " << deserial <<  "\033[0m" << std::endl;
	std::cout << std::endl;
}