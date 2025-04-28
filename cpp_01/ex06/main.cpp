#include "includes/Harl.hpp"

int main() {
  Harl harl;

  harl.complainAboveLevel("DEBUG");
  harl.complainAboveLevel("INFO");
  harl.complainAboveLevel("WARNING");
  harl.complainAboveLevel("ERROR");
  harl.complainAboveLevel("NOTHING");
}