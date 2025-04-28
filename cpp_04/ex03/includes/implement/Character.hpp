#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>
#define MAX_EQUIP 4
class Character : public ICharacter
{
  private:
    std::string name_;
    AMateria *equipments_[MAX_EQUIP];
    bool free_responsible_[MAX_EQUIP];

  public:
    Character();
    ~Character();
    Character(std::string const &name);
    Character(const Character &other);
    Character &operator=(const Character &other);
    std::string const &getName() const;
    AMateria *getEquipment(int idx);
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};
#endif