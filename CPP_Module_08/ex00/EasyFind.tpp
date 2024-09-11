template <typename T>
typename T::iterator easyFind(T& container, int target)
{
    typename T::iterator it = std::find(container.begin(), container.end(), target);

    if (it == container.end())
    {
        throw NotFoundException();
    }
    return (it);
}

template <typename T>
typename T::const_iterator easyFind(const T& container, int target)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), target);

    if (it == container.end())
    {
        throw NotFoundException();
    }
    return (it);
}


template <typename Container>
void printContainer(const Container& container, const std::string& containerName)
{
    std::cout << containerName << ": [";
    typename Container::const_iterator it = container.begin();
    typename Container::const_iterator end = container.end();
    for (; it != end; it++)
    {
        if (it != container.begin())
        {
            std::cout << ", ";
        }
        std::cout << *it;
    }
    std::cout << "]" << std::endl;
}