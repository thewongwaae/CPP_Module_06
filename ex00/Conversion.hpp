#ifndef CONVERSION_H
# define CONVERSION_H

# include <iostream>
# include <cstdlib>
# include <string>
# include <cstring>
# include <cctype>
# include <limits>
# include <climits>

enum types {
	NAN_INF,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	ERROR
};

class Conversion {
	private:
		const std::string	_input;
		int					_type;
		char				_char;
		int					_int;
		float				_float;
		double				_double;

		Conversion( void );

		int typeInput( void );
		void convertInput( void );
		void printOutput( void );

		void fromChar( void );
		void fromInt( void );
		void fromFloat( void );
		void fromDouble( void );

		std::string getInput( void ) const;
		int getType( void ) const;
		char getChar( void ) const;
		int getInt( void ) const;
		float getFloat( void ) const;
		double getDouble( void ) const;

	public:
		Conversion( const std::string input );
		Conversion( const Conversion &copy );
		Conversion &operator=( const Conversion &assign );
		~Conversion( void );

	class Exception : public std::exception {
		public:
			virtual const char *what( void ) const throw();
	};
};

#endif