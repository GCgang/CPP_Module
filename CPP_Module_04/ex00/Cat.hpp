#pragma once
#ifndef CAT_HPP
# define CAT_HPP

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat& cat);
        Cat& operator=(const Cat& cat);
        virtual ~Cat();
        virtual void MakeSound() const;
};

#endif //CAT_HPP