#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 150);
    std::cout << *bureaucrat << std::endl;
    delete bureaucrat;
}