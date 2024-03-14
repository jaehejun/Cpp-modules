#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:
		ScavTrap();
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& scavTrap);
		virtual ~ScavTrap();

		ScavTrap& operator=(const ScavTrap& scavTrap);

		virtual void attack(const std::string& target);
		void guardGate();
};

#endif