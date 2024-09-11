#pragma once
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat& wrongCat);
        WrongCat& operator=(const WrongCat& wrongCat);
        ~WrongCat();
        void MakeSound() const;
};

#endif //WRONGCAT_HPP