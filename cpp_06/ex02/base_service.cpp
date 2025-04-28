#include "base_service.hpp"
#include <cstdlib>
#include <ctime>

Base *generate(void) {
  static bool init_flag = false;
  if (!init_flag) {
    srand(time(0));
    init_flag = true;
  }

  int random = rand() % 3;
  if (random == 0)
    return new A();
  else if (random == 1)
    return new B();
  else
    return new C();
}

void identify(Base *p) {
  std::cout << "Identifying type of pointer: ";
  if (dynamic_cast<A *>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "C" << std::endl;
  else
    std::cout << "Unknown type" << std::endl;
}
void identify(Base &p) {
  std::cout << "Identifying type of reference: ";
  if (dynamic_cast<A *>(&p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(&p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(&p))
    std::cout << "C" << std::endl;
  else
    std::cout << "Unknown type" << std::endl;
}