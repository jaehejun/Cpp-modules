#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon() : type("")
{
}

Weapon::Weapon(std::string type) : type(type)
{
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType()
{
	return type;
}

void Weapon::setType(std::string newType)
{
	this->type = newType;
}