#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

  private:
    
    static const int frac_bits = 8;
  
  public:
    Fixed();
    Fixed(int const fpoint_int);
    Fixed(float const fpoint_float);
    Fixed(Fixed const& fixed);
    ~Fixed();

    float toFloat(void) const;
    int toInt(void) const;

    Fixed& operator=(Fixed const& fixed);

    int getRawBits(void) const;
    void setRawBits(int const raw);
};


#endif
