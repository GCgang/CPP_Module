#include <iostream>
#include "MutantStack.hpp"
#include <list>
#include <vector>

int main()
{
	std::cout <<  "==================================MutantStack==================================" << std::endl;
    MutantStack<int> mStack;
    const int numElements = 5;

    for (int i = 0; i < numElements; i++) {
        mStack.push(i);
        std::cout << "Pushed: " << i << std::endl;
    }

	std::cout << std::endl;
    std::cout << "Top element: " << mStack.top() << std::endl;
    std::cout << "Current size: " << mStack.size() << std::endl;
    std::cout << "Is stack empty?: " << (mStack.empty() ? "Yes" : "No") << std::endl;
	std::cout << std::endl;

    std::cout << "Using Begin and End:" << std::endl;
    for (MutantStack<int>::Iterator it = mStack.Begin(); it != mStack.End(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Using RBegin and REnd:" << std::endl;
    for (MutantStack<int>::ReverseIterator it = mStack.RBegin(); it != mStack.REnd(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    const MutantStack<int> constStack = mStack;
    std::cout << "Using ConstIterator with a const object:" << std::endl;
    for (MutantStack<int>::ConstIterator it = constStack.Begin(); it != constStack.End(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Using ConstReverseIterator with a const object:" << std::endl;
    for (MutantStack<int>::ConstReverseIterator it = constStack.RBegin(); it != constStack.REnd(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    MutantStack<int> copiedStack(mStack);
    std::cout << "Using copied stack:" << std::endl;
    while (!copiedStack.empty()) {
        std::cout << copiedStack.top() << " ";
        copiedStack.pop();
    }
    std::cout << std::endl;

    MutantStack<int> assignedStack;
    assignedStack = mStack;
    std::cout << "Using assigned stack:" << std::endl;
    while (!assignedStack.empty()) {
        std::cout << assignedStack.top() << " ";
        assignedStack.pop();
    }
    std::cout << std::endl;

    std::cout << std::endl;
 	std::cout <<  "============================MutantStack with vector============================" << std::endl;
    
    MutantStack<int, std::vector<int> > mStackWithVector;

    for (int i = 0; i < numElements; i++) {
        mStackWithVector.push(i);
        std::cout << "Pushed: " << i << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Top element: " << mStackWithVector.top() << std::endl;
    std::cout << "Current size: " << mStackWithVector.size() << std::endl;
    std::cout << "Is stack empty?: " << (mStackWithVector.empty() ? "Yes" : "No") << std::endl;
    std::cout << std::endl;

    std::cout << "Using Begin and End:" << std::endl;
    for (MutantStack<int, std::vector<int> >::Iterator it = mStackWithVector.Begin(); it != mStackWithVector.End(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Using RBegin and REnd:" << std::endl;
    for (MutantStack<int, std::vector<int> >::ReverseIterator it = mStackWithVector.RBegin(); it != mStackWithVector.REnd(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    const MutantStack<int, std::vector<int> > constStackWithVector = mStackWithVector;
    std::cout << "Using ConstIterator with a const object:" << std::endl;
    for (MutantStack<int, std::vector<int> >::ConstIterator it = constStackWithVector.Begin(); it != constStackWithVector.End(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Using ConstReverseIterator with a const object:" << std::endl;
    for (MutantStack<int, std::vector<int> >::ConstReverseIterator it = constStackWithVector.RBegin(); it != constStackWithVector.REnd(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    MutantStack<int, std::vector<int> > copiedStackWithVector(mStackWithVector);
    std::cout << "Using copied stack:" << std::endl;
    while (!copiedStackWithVector.empty()) {
        std::cout << copiedStackWithVector.top() << " ";
        copiedStackWithVector.pop();
    }
    std::cout << std::endl;

    MutantStack<int, std::vector<int> > assignedStackWithVector;
    assignedStackWithVector = mStackWithVector;
    std::cout << "Using assigned stack:" << std::endl;
    while (!assignedStackWithVector.empty()) {
        std::cout << assignedStackWithVector.top() << " ";
        assignedStackWithVector.pop();
    }
    std::cout << std::endl; 


    std::cout << std::endl;
	std::cout <<  "==================================list==================================" << std::endl;
    std::list<int> mList;
    const int listNumElements = 5;

    for (int i = 0; i < listNumElements; i++) {
        mList.push_back(i);
        std::cout << "Pushed: " << i << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Top element: " << mList.back() << std::endl;
    std::cout << "Current size: " << mList.size() << std::endl;
    std::cout << "Is list empty?: " << (mList.empty() ? "Yes" : "No") << std::endl;
    std::cout << std::endl;

    std::cout << "Using Begin and End:" << std::endl;
    for (std::list<int>::iterator it = mList.begin(); it != mList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Using RBegin and REnd:" << std::endl;
    for (std::list<int>::reverse_iterator it = mList.rbegin(); it != mList.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    const std::list<int> constList(mList);
    std::cout << "Using ConstIterator with a const object:" << std::endl;
    for (std::list<int>::const_iterator it = constList.begin(); it != constList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Using ConstReverseIterator with a const object:" << std::endl;
    for (std::list<int>::const_reverse_iterator it = constList.rbegin(); it != constList.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::list<int> copiedList(mList);
    std::cout << "Using copied list:" << std::endl;
    while (!copiedList.empty()) {
        std::cout << copiedList.back() << " ";
        copiedList.pop_back(); 
    }
    std::cout << std::endl;

    std::list<int> assignedList;
    assignedList = mList;
    std::cout << "Using assigned list:" << std::endl;
    while (!assignedList.empty()) {
        std::cout << assignedList.back() << " ";
        assignedList.pop_back();
    }
    std::cout << std::endl;

    return 0;
}
