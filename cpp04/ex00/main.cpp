#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		std::cout << dog->getType() << " " << std::endl;
		dog->makeSound();
		std::cout << cat->getType()  << " " << std::endl;
		cat->makeSound();
		std::cout << meta->getType()  << " " << std::endl;
		meta->makeSound();

		delete meta;
		delete dog;
		delete cat;
	}
	std::cout << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal(); 
		const WrongAnimal* cat = new WrongCat();

		std::cout << cat->getType()  << " " << std::endl;
		cat->makeSound();
		std::cout << meta->getType()  << " " << std::endl;
		meta->makeSound();

		delete meta;
		delete cat;
	}
	std::cout << std::endl;
	return 0;
}