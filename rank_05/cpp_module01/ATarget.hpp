#ifndef ATARGET_HPP
#define ATARGET_HPP
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {
	private:
		std::string	_type;
		ATarget(const ATarget &other);
		ATarget& operator=(const ATarget &other);
	
	public:
		std::string	const &getType() const;
		virtual ATarget *clone() const = 0;
		ATarget(std::string const &type);
		virtual ~ATarget();
		void	getHitBySpell(ASpell const &spell) const;

};


#endif