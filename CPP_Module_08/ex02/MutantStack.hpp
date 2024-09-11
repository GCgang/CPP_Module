#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
    public:
        typedef typename Container::iterator Iterator;
        typedef typename Container::const_iterator ConstIterator;
        typedef typename Container::reverse_iterator ReverseIterator;
        typedef typename Container::const_reverse_iterator ConstReverseIterator;
    
        MutantStack();
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);
        ~MutantStack();

        Iterator Begin();
        Iterator End();
        ReverseIterator RBegin();
        ReverseIterator REnd();

        ConstIterator Begin() const;
        ConstIterator End() const;
        ConstReverseIterator RBegin() const;
        ConstReverseIterator REnd() const;
};

#include "MutantStack.tpp"

#endif