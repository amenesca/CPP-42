#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>
# include <iostream>

class Fixed {

  private:
	int value;
    static const int frac_bits = 8;
  
  public:
    Fixed();
    Fixed(int const fpoint_int);
    Fixed(float const fpoint_float);
    ~Fixed();

    float toFloat(void) const;
    int toInt(void) const;

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, Fixed const &Fixed);

#endif
