#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

//proper contors/detors chaining must be shown
//when ScavTrap created, program starts by building a ClapTrap.
//Detor is in reverse order. WHY?????

//ScavTrap will use the attributes of ClapTrap(update ClapTrap in Consequence) and must init to
// : name, hp(100):represent the ClapTrap HP, EP(50), AD(20)

// ScavTrap will have own special capacity : void guardGate();
// this will display message informing that ScavTrap is now in Gate keeper mode

#include "ClapTrap.hpp"

class ScavTrap: protected ClapTrap
{
	private:
		int a;
	
	public:
		void guardGate();
};

#endif