#include <iostream>

// Encapsulation: Create a class with private members and public methods.
class EncapsulationExample {
private:
    int data;

public:
    void setData(int value) {
        data = value;
    }

    int getData() {
        return data;
    }
};

// Inheritance: Create a base class and a derived class.
class Animal {
public:
    void makeSound() {
        std::cout << "Animal makes a sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() {
        std::cout << "Dog barks" << std::endl;
    }
};

// Polymorphism: Demonstrate method overriding.
class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing a shape" << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }
};

// Abstraction: Use an abstract class with pure virtual functions.
class AbstractClass {
public:
    virtual void abstractMethod() = 0; // Pure virtual function

    void concreteMethod() {
        std::cout << "Concrete method in abstract class" << std::endl;
    }
};

class ConcreteClass : public AbstractClass {
public:
    void abstractMethod() override {
        std::cout << "Implementation of abstract method" << std::endl;
    }
};

int main() {
    // Encapsulation example
    EncapsulationExample encapsulationObj;
    encapsulationObj.setData(42);
    std::cout << "Encapsulation Example: " << encapsulationObj.getData() << std::endl;

    // Inheritance example
    Animal* animal = new Dog();
    animal->makeSound();

    // Polymorphism example
    Shape* shape = new Circle();
    shape->draw();

    // Abstraction example
    ConcreteClass concreteObj;
    concreteObj.abstractMethod();
    concreteObj.concreteMethod();

    return 0;
}
