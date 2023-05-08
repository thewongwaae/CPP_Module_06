#ifndef CONVERSION_H
# define CONVERSION_H

# include <iostream>
# include <string>
# include <ctype>
# include 

class Conversion {
	private:

	public:
		Conversion( void );
		Conversion( const Conversion &copy );
		Conversion &operator=( const Conversion &assign );
		~Conversion( void );
};

std::ostream &operator<<( std::ostream &o, Conversion *a );

#endif