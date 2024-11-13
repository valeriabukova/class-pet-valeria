//
//  main.cpp
//  class pet valeria
//
//  Created by Valeria  Bukova on 14.11.2024.
//
#include <iostream>


const int MAX_NAME_LENGTH = 20;


class Pet {
protected:
    char name[MAX_NAME_LENGTH];

public:
    Pet(const char* name) {
        
        int i = 0;
        while (name[i] != '\0' && i < MAX_NAME_LENGTH - 1) {
            this->name[i] = name[i];
            ++i;
        }
        this->name[i] = '\0';
    }

    virtual void Sound() const = 0;
    virtual void Show() const {
        std::cout << "Name: " << name << std::endl;
    }
    virtual void Type() const = 0;
    virtual ~Pet() = default;
};


class Dog : public Pet {
public:
    Dog(const char* name) : Pet(name) {}

    void Sound() const override {
        std::cout << name << " says: Woof!" << std::endl;
    }

    void Type() const override {
        std::cout << "Type: Dog" << std::endl;
    }
};


class Cat : public Pet {
public:
    Cat(const char* name) : Pet(name) {}

    void Sound() const override {
        std::cout << name << " says: Meow!" << std::endl;
    }

    void Type() const override {
        std::cout << "Type: Cat" << std::endl;
    }
};


class Parrot : public Pet {
public:
    Parrot(const char* name) : Pet(name) {}

    void Sound() const override {
        std::cout << name << " says: Squawk!" << std::endl;
    }

    void Type() const override {
        std::cout << "Type: Parrot" << std::endl;
    }
};


class Hamster : public Pet {
public:
    Hamster(const char* name) : Pet(name) {}

    void Sound() const override {
        std::cout << name << " says: Squeak!" << std::endl;
    }

    void Type() const override {
        std::cout << "Type: Hamster" << std::endl;
    }
};

int main() {
   
    Pet* pets[] = {
        new Dog("Buddy"),
        new Cat("Whiskers"),
        new Parrot("Polly"),
        new Hamster("Nibbles")
    };

  
    for (Pet* pet : pets) {
        pet->Show();
        pet->Type();
        pet->Sound();
        std::cout << "---------------------" << std::endl;
    }

   
    for (Pet* pet : pets) {
        delete pet;
    }

    return 0;
}
