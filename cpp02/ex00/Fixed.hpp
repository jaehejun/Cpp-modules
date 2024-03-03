#ifndef FIXED_HPP
# define FIEXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	private:
		int fixedPointNumberValue;
		static const int fractionalBits;

	public:
	/* default constructor that initialize fixed_point number value to 0
	Copy constructor
	copy assignment operator overload
	destructor
	int getRawBits(void) const; that returns the raw value of the fixed-point value
	void setRawBits(int const raw); that sets the raw value of the fixed-point number*/
		Fixed();
		//copy-constructor;
		Fixed(Fixed &fixed);
		//copy assignment operator overload(=)
		
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif