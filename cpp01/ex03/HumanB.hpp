#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

// Weapon;
// name;

//<name> attacks with their <weapon type> 문자열을 출력하는 attack()함수;
//HumanB() 생성자에서 Weapon을 지니지 않음
//HumanB는 항상 무장한 상태가 아닐 수도 있음

class HumanB
{
	private:
		std::string name;
		Weapon weapon;

	public:
		HumanB(std::string name);
		~HumanB();

		void setWeapon(Weapon weapon);
		void attack();
};

#endif