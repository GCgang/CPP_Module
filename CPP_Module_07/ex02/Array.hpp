#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
    public:
        Array();
        Array(unsigned int arraySize);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        unsigned int Size() const;

    private:
        T* mArray;
        unsigned int mArraySize;
};

#include "Array.tpp"


// #include <stdexcept>

// template <typename T>
// class Array
// {
//     public:
//         Array();
//         Array(unsigned int arraySize);
//         Array(const Array& other);
//         Array& operator=(const Array& other);
//         ~Array();

//         T& operator[](unsigned int index);
//         const T& operator[](unsigned int index) const;
//         unsigned int Size() const;

//     private:
//         T* mArray;
//         unsigned int mArraySize;
// };

// // Definitions below

// template <typename T>
// Array<T>::Array()
//     : mArray(nullptr)
//     , mArraySize(0)
// {
// }

// template <typename T>
// Array<T>::Array(unsigned int arraySize)
//     : mArray(new T[arraySize]())
//     , mArraySize(arraySize)
// {
// }

// template <typename T>
// Array<T>::Array(const Array& other)
//     : mArray(nullptr)
//     , mArraySize(0)
// {
//     *this = other;
// }

// template <typename T>
// Array<T>& Array<T>::operator=(const Array& other)
// {
//     if (this != &other)
//     {
//         delete[] mArray;
//         mArraySize = other.Size();
//         mArray = new T[mArraySize];

//         for (unsigned int i = 0; i < mArraySize; i++)
//         {
//             mArray[i] = other.mArray[i];
//         }
//     }
    
//     return (*this);
// }

// template <typename T>
// Array<T>::~Array()
// {
//     delete[] mArray;
// }

// template <typename T>
// T& Array<T>::operator[](unsigned int index)
// {
//     if (index >= mArraySize)
//     {
//         throw std::out_of_range("Array index is out of bounds!");
//     }

//     return mArray[index];
// }

// template <typename T>
// const T& Array<T>::operator[](unsigned int index) const
// {
//     if (index >= mArraySize)
//     {
//         throw std::out_of_range("Array index is out of bounds!");
//     }

//     return mArray[index];
// }

// template <typename T>
// unsigned int Array<T>::Size() const
// {
//     return mArraySize;
// }

#endif
