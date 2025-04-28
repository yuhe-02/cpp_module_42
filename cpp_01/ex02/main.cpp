#include <iostream>
#include <string>

int main()
{

    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string &stringREF(brain);

    std::cout << "string type  address: " << &brain << std::endl;
    std::cout << "string *type address: " << stringPTR << std::endl;
    std::cout << "string &type address: " << &stringREF << std::endl;

    std::cout << "string type  value: " << brain << std::endl;
    std::cout << "string *type value: " << *stringPTR << std::endl;
    std::cout << "string &type value: " << stringREF << std::endl;
    return (0);
}