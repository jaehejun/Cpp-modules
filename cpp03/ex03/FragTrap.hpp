#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	protected:
		FragTrap();
	public:
		static const unsigned int fragHitPoints;
		static const unsigned int fragAttackDamage;
		FragTrap(std::string name);
		FragTrap(const FragTrap& fragTrap);
		~FragTrap();

		FragTrap& operator=(const FragTrap& fragTrap);

		void highFivesGuys();
};

#endif