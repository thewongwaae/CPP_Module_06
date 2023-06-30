#ifndef CONVERSION_H
# define CONVERSION_H

# include <iostream>
# include <string>
# include <cctype>
# include <limits>

class Conversion {
	private:
		const std::string	_input;
		char				_char;
		int					_int;
		float				_float;
		double				_double;

		Conversion( void );



		void fromChar( void );
		void fromInt( void );
		void fromFloat( void );
		void fromDouble( void );

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