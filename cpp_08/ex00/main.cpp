#include "./includes/easyfind.hpp"
#include <deque>
#include <iostream>
#include <vector>

int main()
{
    {
        try
        {
            std::cout << "----normal test----" << std::endl;
            std::vector<int> hoge;
            hoge.push_back(3);
            hoge.push_back(1);
            hoge.push_back(4);
            std::vector<int>::iterator it = ::easyfind(hoge, 3);
            std::cout << "find: " << *it << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try
        {
            std::cout << "----normal test----" << std::endl;
            std::deque<int> q;
            q.push_back(2);
            q.push_back(3);
            std::deque<int>::iterator it = ::easyfind(q, 90);
            std::cout << "find: " << *it << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try
        {
            std::cout << "----normal test----" << std::endl;
            std::vector<int> hoge;
            hoge.push_back(3);
            hoge.push_back(1);
            hoge.push_back(4);
            std::vector<int>::iterator it = ::easyfind(hoge, 3);
            std::cout << "find: " << *it << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try
        {
            std::cout << "----normal test----" << std::endl;
            std::vector<int> hoge;
            hoge.push_back(3);
            hoge.push_back(1);
            hoge.push_back(4);
        
            const std::vector<int> vec = hoge;
            std::vector<int>::const_iterator it = ::easyfind(vec, 3);
            std::cout << "find: " << *it << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    return (0);
}