#include "Conversion.hpp"

/* Constructs */

Conversion::Conversion( void ) {
	std::cout << "Default constructor called" << std::endl;
}

Conversion::Conversion( const std::string input ) : _input(input) {
	std::cout << "Constructor called with input of " << input << std::endl;
}

Conversion::Conversion( const Conversion &copy ) {
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}

Conversion &Conversion::operator=( const Conversion &assign ) {
	if (this == &assign)
		return *this;

	this->_char = assign.getChar();
	this->_int = assign.getInt();
	this->_float = assign.getFloat();
	this->_double = assign.getDouble();

	std::cout << "Assignment operator called" << std::endl;
	return *this;
}

Conversion::~Conversion( void ) {
	std::cout << "Destructor called" << std::endl;
}

/* Input handlers */



/* Conversions */

void Conversion::fromChar( void ) {
	this->_char = this->_input[0];
	this->_int = static_cast<int>(this->_char);
	this->_float = static_cast<float>(this->_char);
	this->_double = static_cast<double>(this->_char);
}

void Conversion::fromInt( void ) {
	this->_char = static_cast<char>(this->_input[0]);
	this->_int = std::stoi(this->_input);
	this->_float = static_cast<float>(this->_int);
	this->_double = static_cast<double>(this->_int);
}

void Conversion::fromFloat( void ) {
	this->_char = static_cast<char>(this->_input[0]);
	this->_int = static_cast<int>(this->_float);
	this->_float = std::stof(this->_input);
	this->_double = static_cast<double>(this->_float);
}

void Conversion::fromDouble( void ) {
	this->_char = static_cast<char>(this->_input[0]);
	this->_int = static_cast<int>(this->_double);
	this->_float = static_cast<float>(this->_double);
	this->_double = std::stod(this->_input);
}

/* Getters */

char Conversion::getChar( void ) const {
	return this->_char;
}

int Conversion::getInt( void ) const {
	return this->_int;
}

float Conversion::getFloat( void ) const {
	return this->_float;
}

double Conversion::getDouble( void ) const {
	return this->_double;
}

/* Exception */

const char *Conversion::Exception::what( void ) const throw() {
	return "Error: Conversion error or unprintable character";
}
