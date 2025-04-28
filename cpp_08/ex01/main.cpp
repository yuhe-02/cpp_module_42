#include "./includes/Span.hpp"
#include <iostream>

int main()
{
    {
        Span *s = NULL;
        try
        {
            std::cout << "----normal test----" << std::endl;
            s = new Span();
            s->addNumber(2);
            s->addNumber(1);
            s->addNumber(0);
            s->addNumber(10);
            s->addNumber(90);
            std::cout << s->shortestSpan() << std::endl;
            std::cout << s->longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        if (s)
        {
            delete s;
        }
    }
    {
        Span *s = NULL;
        try
        {
            std::cout << "----no span----" << std::endl;
            s = new Span();
            s->addNumber(2);
            std::cout << s->shortestSpan() << std::endl;
            std::cout << s->longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        if (s)
        {
            delete s;
        }
    }
    {
        Span *s = NULL;
        try
        {
            std::cout << "----max storage----" << std::endl;
            s = new Span(0);
            s->addNumber(2);
            std::cout << s->shortestSpan() << std::endl;
            std::cout << s->longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        if (s)
        {
            delete s;
        }
    }
    {
        Span *s = NULL;
        try
        {
            std::cout << "----max----" << std::endl;
            s = new Span(10000);
            for (int i = 1; i < 10001; i++)
            {
                s->addNumber(i);
            }
            std::cout << s->shortestSpan() << std::endl;
            std::cout << s->longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        if (s)
        {
            delete s;
        }
    }
    {
        Span *s = NULL;
        try
        {
            std::cout << "----max----" << std::endl;
            s = new Span(10000);
            for (int i = 10000; i > 0; i--)
            {
                s->addNumber(i);
            }
            std::cout << s->shortestSpan() << std::endl;
            std::cout << s->longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        if (s)
        {
            delete s;
        }
    }
    {
        try
        {
            std::cout << "----bulk insert----" << std::endl;
            std::vector<int> input;
            for (int i = 0; i < 10000; ++i)
                input.push_back(i);
            Span sp(10000);
            sp.addRange(input.begin(), input.end());
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    return (0);
}