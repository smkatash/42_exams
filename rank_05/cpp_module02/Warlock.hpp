#ifndef WARLOCK_HPP
#define WARLOCK_HPP
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock {
	private:
		std::string	_name;
		std::string	_title;
		Warlock(const Warlock &warl);
		Warlock& operator=(const Warlock &warl);
		SpellBook _book;


	public:
		std::string	const &getName() const;
		std::string	const &getTitle() const;
		void	setTitle(std::string const &title);
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		void	introduce() const;

		void	learnSpell(ASpell *ptr);
		void	forgetSpell(std::string spell);
		void	launchSpell(std::string spell, ATarget const &target);

};


#endif