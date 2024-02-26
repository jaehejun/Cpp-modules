#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

// std::string type;
// type의 const reference를 반환하는 getType()함수;
// 매개변수로 전달된 새로운 type을 사용하여 type을 설정하는 setType()함수;

class Weapon
{
	private:
		std::string type;
	
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();

		const std::string& getType();
		void setType(std::string newType);
};

#endif