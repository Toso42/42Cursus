#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
protected:
	std::string	_name;
	int			_hitP;
	int			_energyP;
	int			_attackD;
public:
	//####	Orthodox Canon
	ClapTrap();
	ClapTrap(const ClapTrap& instance);
	ClapTrap& operator=(const ClapTrap& instance);
	~ClapTrap();
	//####	Other constructors
	ClapTrap(std::string name);
	//####	Methods
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	int		getAttackDamage(void);
	const std::string	getName(void);
};


#endif