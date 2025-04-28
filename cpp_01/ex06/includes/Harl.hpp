#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <string>

class Harl
{
  private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    void (Harl::*m_fpFunc[4])(void);
    int _getComplainLevel(const std::string &level);

  public:
    Harl();
    ~Harl();
    void complain(std::string level);
    void complainAboveLevel(std::string level);
};
#endif