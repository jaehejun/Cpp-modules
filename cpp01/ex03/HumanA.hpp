#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

// Weapon;
// name;

//<name> attacks with their <weapon type> 문자열을 출력하는 attack()함수;
//HumanA(Weapon weapon) 생성자에서 Weapon을 지님
//HumanA는 항상 무장한 상태

class HumanA
{
	private:
		std::string name;
		Weapon& weapon;
		
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();

		void attack();
};

#endif