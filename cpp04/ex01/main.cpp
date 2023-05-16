#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	{
		const Animal* j = new Dog();
		std::cout << std::endl;
		const Animal* i = new Cat();
		std::cout << std::endl;
		
		delete j;//should not create a leak delete i;
		std::cout << std::endl;
		delete i;
		std::cout << std::endl;
	}

	Animal *animal[10];

	for (int i = 0; i < 5; i++)
	{
		animal[i] = new Dog();
		std::cout << std::endl;
	}
	for (int i = 5; i < 10; i++)
	{
		animal[i] = new Cat();
		std::cout << std::endl;
	}

//	Animal* Dog;
//	Cat *cat;

	for (int i = 0; i < 10; i++)
	{
		delete animal[i];
		std::cout << std::endl;
	}
}