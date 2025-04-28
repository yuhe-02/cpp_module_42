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
            std::cout << ::easyfind(hoge, 3) << std::endl;
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
            std::cout << ::easyfind(q, 4) << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    return (0);
}