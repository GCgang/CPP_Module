#include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack()
    : std::stack<T, Container>()
{
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other)
    : std::stack<T, Container>(other)
{
}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& other)
{
    if (this != &other)
    {
        std::stack<T, Container>::operator=(other);
    }
    return (*this);
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
}

template <typename T, typename Container>
typename MutantStack<T, Container>::Iterator MutantStack<T, Container>::Begin()
{
    return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::Iterator MutantStack<T, Container>::End()
{
    return (this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::ReverseIterator MutantStack<T, Container>::RBegin()
{
    return (this->c.rbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::ReverseIterator MutantStack<T, Container>::REnd()
{
    return (this->c.rend());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::ConstIterator MutantStack<T, Container>::Begin() const
{
    return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::ConstIterator MutantStack<T, Container>::End() const
{
    return (this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::ConstReverseIterator MutantStack<T, Container>::RBegin() const
{
    return (this->c.rbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::ConstReverseIterator MutantStack<T, Container>::REnd() const
{
    return (this->c.rend());
}