template <typename T>
Array<T>::Array()
    : mArray(NULL)
    , mArraySize(0)
{
}

template <typename T>
Array<T>::Array(unsigned int arraySize)
    : mArraySize(arraySize)
{
    mArray = new T[arraySize];
}

template <typename T>
Array<T>::Array(const Array& other)
    : mArray(NULL)
    , mArraySize(0)
{
    *this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] mArray;
        mArraySize = other.Size();
        mArray = new T[mArraySize];

        for (unsigned int index = 0; index < mArraySize; index++)
        {
            mArray[index] = other.mArray[index];
        }
    }
    
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    delete[] mArray;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (mArraySize <= index)
    {
        throw std::out_of_range("Array index is out of bounds!");
    }

    return (mArray[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{

    if (mArraySize <= index)
    {
        throw std::out_of_range("Array index is out of bounds!");
    }

    return (mArray[index]);
}

template <typename T>
unsigned int Array<T>::Size() const
{
    return (mArraySize);
}