#ifndef ASPELL_HPP
#define ASPELL_HPP
#include <iostream>
#include "ATarget.hpp"
class ATarget;

class ASpell {
	private:
		std::string	_name;
		std::string	_effects;
		ASpell(const ASpell &other);
		ASpell& operator=(const ASpell &other);
	
	public:
		std::string	const &getName() const;
		std::string	const &getEffects() const;
		virtual ASpell *clone() const = 0;
		ASpell(std::string const &name, std::string const &effects);
		virtual ~ASpell();
		void	launch(ATarget const &target) const;

};


#endif