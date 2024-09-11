#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>


class Animal
{
    public:
        Animal();
        Animal(const Animal& animal);
        Animal& operator=(const Animal& animal);
        virtual ~Animal();
        virtual void MakeSound() const = 0;
        std::string GetType() const;
        void SetType(std::string type);
    protected:
        std::string mType;
};

#endif // ABSSTRACT_ANIMAL_HPP