#include "Conversion.hpp"

/* Constructs */

Conversion::Conversion( void ) {
	std::cout << "Default constructor called" << std::endl;
}

Conversion::Conversion( const std::string input ) : _input(input) {
	std::cout << "Constructor called with input of " << input << std::endl;
	this->_double = atof(this->getInput().c_str());
	this->_type = this->typeInput();
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

int Conversion::typeInput( void ) {
	const std::string& input = this->getInput();

	if (input.compare("nan") == 0 || input.compare("+inf") == 0 || input.compare("-inf") == 0 ||
		input.compare("+inff") == 0 || input.compare("-inff") == 0)
		return NAN_INF;

	if (input.length() == 1 && (input[0] == '+' || input[0] == '-' || input[0] == 'f' || input[0] == '.'))
		return CHAR;

	if (input.find_first_of("+-") != input.find_last_of("+-"))
		return ERROR;

	if (input.find_first_not_of("0123456789") == std::string::npos)
		return INT;
	else if (input.find_first_of(".") != std::string::npos)
	{
		if (input.find_last_of(".") == input.find_first_of(".") &&
			isdigit(input[input.find_first_of(".") + 1]))
			return DOUBLE;
		else
			return ERROR;
	}
	else if (input.find_first_of("f") != std::string::npos)
	{
		if (input.find_last_of("f") == input.find_first_of("f") &&
			input.find_first_of(".") != input.find_last_of(".") &&
			input.find_first_of("f") - input.find_first_of(".") == 1 &&
			input[input.find_first_of(".") + 1] == '\0')
			return FLOAT;
		else
			return ERROR;
	}
	else if (input.length() == 1 && std::isprint(input[0]))
		return CHAR;
	else
		return ERROR;
}

void Conversion::convertInput( void ) {
	switch (this->_type)
	{
		case NAN_INF:
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
	if (this->getType() != NAN_INF && this->getDouble() <= UCHAR_MAX && this->getDouble() >= 0)
		std::cout << "char: " << (isprint(this->getChar()) ? "'" + std::string(1, this->getChar()) + "'" : "Non displayable") << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	if (this->getType() != NAN_INF && this->getDouble() >= std::numeric_limits<int>::min() && this->getDouble() <= std::numeric_limits<int>::max())
		std::cout << "int: " << this->getInt() << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	if (this->getType() != NAN_INF)
		std::cout << "float: " << this->getFloat() << (this->getFloat() - this->getInt() == 0 ? ".0f" : "f") << std::endl;
	else if (this->getInput() == "nan" || this->getInput() == "nanf")
		std::cout << "float: nanf" << std::endl;
	else
		std::cout << "float: " << (this->getInput()[0] == '+' ? "+inff" : "-inff") << std::endl;

	if (this->getType() != NAN_INF)
		std::cout << "double: " << this->getDouble() << (this->getDouble() < std::numeric_limits<int>::min() || this->getDouble() > std::numeric_limits<int>::max() || this->getDouble() - this->getInt() == 0 ? ".0" : "") << std::endl;
	else if (this->getInput() == "nan" || this->getInput() == "nanf")
		std::cout << "double: nan" << std::endl;
	else
		std::cout << "double: " << (this->getInput()[0] == '+' ? "+inf" : "-inf") << std::endl;
}

/* Conversions */

void Conversion::fromChar( void ) {
	this->_char = static_cast<unsigned char>(this->getInput()[0]);
	this->_int = static_cast<int>(this->getChar());
	this->_float = static_cast<float>(this->getChar());
	this->_double = static_cast<double>(this->getChar());
}

void Conversion::fromInt( void ) {
	this->_int = static_cast<int>(this->getDouble());
	this->_char = static_cast<unsigned char>(this->getInt());
	this->_float = static_cast<float>(this->getDouble());
}

void Conversion::fromFloat( void ) {
	this->_float = static_cast<float>(this->getDouble());
	this->_char = static_cast<char>(this->getFloat());
	this->_int = static_cast<int>(this->getFloat());
}

void Conversion::fromDouble( void ) {
	this->_char = static_cast<char>(this->getDouble());
	this->_int = static_cast<int>(this->getDouble());
	this->_float = static_cast<float>(this->getDouble());
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
