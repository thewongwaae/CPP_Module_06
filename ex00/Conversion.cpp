#include "Conversion.hpp"

/* Constructs */

Conversion::Conversion( void ) {
	std::cout << "Default constructor called" << std::endl;
}

Conversion::Conversion( const std::string input ) : _input(input) {
	std::cout << "Constructor called with input of " << input << std::endl;
	this->typeInput();
	this->convertInput();
	this->printOutput();
}

Conversion::Conversion( const Conversion &copy ) {
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}

Conversion &Conversion::operator=( const Conversion &assign ) {
	if (this == &assign)
		return *this;

	this->_type = assign.getType();
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

/* Input and output handlers */

void Conversion::typeInput( void ) {
	if (this->getInput().compare("nan") == 0)
		this->_type = ENUM_NAN;
	else if (this->getInput().compare("inf") == 0 || this->getInput().compare("+inf") == 0
		|| this->getInput().compare("-inf") == 0 || this->getInput().compare("+inff") == 0
		|| this->getInput().compare("-inff") == 0)
		this->_type = INF;
	else if (this->getInput().length() == 1 && !std::isdigit(this->getInput()[0]))
		this->_type = CHAR;
	else if (this->getInput().find('.') != std::string::npos)
		this->_type = FLOAT;
	else
		this->_type = INT;
}

void Conversion::convertInput( void ) {
	switch (this->_type)
	{
		case ENUM_NAN:
			break;
		case INF:
			break;
		case CHAR:
			this->fromChar();
			break;
		case INT:
			this->fromInt();
			break;
		case FLOAT:
			this->fromFloat();
			break;
		case DOUBLE:
			this->fromDouble();
			break;
		default:
			throw Conversion::Exception();
	}
}

void Conversion::printOutput( void ) {
	if (this->_type == ENUM_NAN)
		std::cout << "char: impossible" << std::endl
			<< "int: impossible" << std::endl
			<< "float: nanf" << std::endl
			<< "double: nan" << std::endl;
	else if (this->_type == INF)
		std::cout << "char: impossible" << std::endl
			<< "int: impossible" << std::endl
			<< "float: " << this->_float << "f" << std::endl
			<< "double: " << this->_double << std::endl;
	else
		std::cout << "char: '" << this->_char << "'" << std::endl
			<< "int: " << this->_int << std::endl
			<< "float: " << this->_float << "f" << std::endl
			<< "double: " << this->_double << std::endl;
}

/* Conversions */

void Conversion::fromChar( void ) {
	this->_char = this->_input[0];
	this->_int = static_cast<int>(this->_char);
	this->_float = static_cast<float>(this->_char);
	this->_double = static_cast<double>(this->_char);
}

void Conversion::fromInt( void ) {
	this->_int = std::stoi(this->_input);
	this->_float = static_cast<float>(this->_int);
	this->_double = static_cast<double>(this->_int);
	this->_char = static_cast<char>(this->_double);
}

void Conversion::fromFloat( void ) {
	this->_float = std::stof(this->_input);
	this->_int = static_cast<int>(this->_float);
	this->_double = static_cast<double>(this->_float);
	this->_char = static_cast<char>(this->_double);
}

void Conversion::fromDouble( void ) {
	this->_double = std::stod(this->_input);
	this->_int = static_cast<int>(this->_double);
	this->_float = static_cast<float>(this->_double);
	this->_char = static_cast<char>(this->_double);
}

/* Getters */

std::string Conversion::getInput( void ) const {
	return this->_input;
}

int Conversion::getType( void ) const {
	return this->_type;
}

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
	return "Error: Conversion error or unprintable character encountered";
}
