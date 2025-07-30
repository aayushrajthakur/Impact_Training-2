#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() { // Virtual function
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    Animal* pet;
    Dog dog;
    Cat cat;

    pet = &dog;
    pet->makeSound(); // Calls Dog's makeSound()

    pet = &cat;
    pet->makeSound(); // Calls Cat's makeSound()

    return 0;
}
