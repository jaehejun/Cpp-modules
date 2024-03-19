#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	protected:
		ScavTrap();
	public:
		static const unsigned int scavEnergyPoints;
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& scavTrap);
		~ScavTrap();

		ScavTrap& operator=(const ScavTrap& scavTrap);

		virtual void attack(const std::string& target);
		void guardGate();
};

#endif