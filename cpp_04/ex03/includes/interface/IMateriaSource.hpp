#ifndef __IMATERIASOURCE_HPP__
#define __IMATERIASOURCE_HPP__

#include "AMateria.hpp"
#include <string>
class IMateriaSource
{
  protected:
    //
  public:
    IMateriaSource();
    virtual ~IMateriaSource();
    IMateriaSource(const IMateriaSource &other);
    IMateriaSource &operator=(const IMateriaSource &other);
    virtual void learnMateria(AMateria *) = 0;
    virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif