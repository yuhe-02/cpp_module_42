#include "../includes/DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "Creating DiamondTrap1 with default constructor" << std::endl;
    DiamondTrap diamond1; // デフォルトコンストラクタのテスト

    std::cout << std::endl << "Creating DiamondTrap2 with parameterized constructor" << std::endl;
    DiamondTrap diamond2("Diamond-X"); // 名前付きコンストラクタのテスト

    std::cout << std::endl << "\nCalling DiamondTrap1's whoAmI()" << std::endl;
    diamond1.whoAmI(); // `whoAmI` メソッドのテスト

    std::cout << std::endl << "\nCalling DiamondTrap2's whoAmI()" << std::endl;
    diamond2.whoAmI(); // `whoAmI` メソッドのテスト

    std::cout << std::endl << "\nAttacking with DiamondTrap2" << std::endl;
    diamond2.attack("Enemy"); // `attack` メソッドのテスト

    std::cout << std::endl << "\nCopying DiamondTrap1 to DiamondTrap3 using copy constructor" << std::endl;
    DiamondTrap diamond3(diamond1); // コピーコンストラクタのテスト

    std::cout << std::endl << "\nAssigning DiamondTrap2 to DiamondTrap4 using assignment operator" << std::endl;
    DiamondTrap diamond4;
    diamond4 = diamond2; // コピー代入演算子のテスト
    diamond4.whoAmI();

    std::cout << std::endl << "\nCalling Destructor" << std::endl;
    return 0;
}
