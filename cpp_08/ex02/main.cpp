#include "./includes/MutantStack.hpp"
#include <iostream>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "mstack top: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "mstack size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    {
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << "iterator called" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::cout << "iterator end " << std::endl;
    
        std::stack<int> s(mstack);
    }
    {
        MutantStack<int>::reverse_iterator it = mstack.rbegin();
        MutantStack<int>::reverse_iterator ite = mstack.rend();
        ++it;
        --it;
        std::cout << "iterator called" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::cout << "iterator end " << std::endl;
    }
    {
        MutantStack<int>::const_iterator it = mstack.begin();
        MutantStack<int>::const_iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << "const iterator called" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::cout << "const iterator end " << std::endl;
    }
    {
        MutantStack<int>::const_reverse_iterator it = mstack.rbegin();
        MutantStack<int>::const_reverse_iterator ite = mstack.rend();
        ++it;
        --it;
        std::cout << "const iterator called" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::cout << "const iterator end " << std::endl;
    }

    return (0);
}
