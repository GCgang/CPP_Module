#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <cstdint>

class Data;

class Serializer
{
    public:
        static uintptr_t Serialize(Data* ptr);
        static Data* Deserialize(uintptr_t raw);
    private:
	    Serializer();
        Serializer(Serializer const& other);
        Serializer& operator=(Serializer const& other);
        ~Serializer();
};


#endif