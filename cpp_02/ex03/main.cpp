#include "includes/Point.hpp"
#include <iostream>

int main() {
  // // default constructor
  Point a;
  // with parameter
  Point b(1.0f, 0);
  // copy constructor
  Point c(0, 1.0f);
  Point p(0.499f, 0.5f);
  std::cout << "p:" << p.getX() << std::endl;
  // Point a(0.0f, 0.0f);  // 三角形の頂点A
  // Point b(1000000000.0f, 0.0f);  // 三角形の頂点B
  // Point c(0.0f, 1000000000.0f);  // 三角形の頂点C
  // Point p(499999999.9f, 500000000.0f);  // 判定する点
  bool res = bsp(a, b, c, p);
  std::string res_str = res == true ? "true" : "false";

  std::cout << res_str << std::endl;
  return (0);
}

// int main(int argc, char **argv) {
// 	if (argc != 9) {
// 		return (1);
// 	}
// 	Point a(atof(argv[1]), atof(argv[2]));
// 	Point b(atof(argv[3]), atof(argv[4]));
// 	Point c(atof(argv[5]), atof(argv[6]));
// 	Point p(atof(argv[7]), atof(argv[8]));
// 	bool res = bsp(a, b, c, p);
// 	std::string res_str = res == true ? "true" : "false";

// 	std::cout << res_str << std::endl;
// 	return (0);
// }