#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	{
		const AAnimal* j = new Dog();
		std::cout << std::endl;
		const AAnimal* i = new Cat();
		std::cout << std::endl;
		
		delete j;//should not create a leak delete i;
		std::cout << std::endl;
		delete i;
		std::cout << std::endl;
	}

	AAnimal *animal[10];

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

	for (int i = 0; i < 10; i++)
	{
		std::cout << animal[i]->getType() << std::endl;
		std::cout << std::endl;
	}

	Cat cat = *(Cat *)animal[5];
	cat.think();
	std::cout << std::endl;

	Dog dog(*(Dog *)animal[0]);
	dog.think();
	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
	{
			delete animal[i];
			std::cout << std::endl;
	}
}