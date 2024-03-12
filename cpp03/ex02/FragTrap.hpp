#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: protected ClapTrap
{
	private:
		FragTrap();
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap& fragTrap);
		~FragTrap();

		FragTrap& operator=(const FragTrap& fragTrap);

		void highFivesGuys();
};

#endif