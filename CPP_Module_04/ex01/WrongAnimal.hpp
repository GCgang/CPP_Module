#pragma once
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& wrongAnimal);
        WrongAnimal& operator=(const WrongAnimal& wrongAnimal);
        ~WrongAnimal();
        void MakeSound() const;
        std::string GetType() const;
        void SetType(std::string type);
    protected:
        std::string mType;
};

#endif //WRONGANIMAL_HPP