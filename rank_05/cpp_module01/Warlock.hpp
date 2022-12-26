#ifndef WARLOCK_HPP
#define WARLOCK_HPP
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
	private:
		std::string	_name;
		std::string	_title;
		Warlock(const Warlock &warl);
		Warlock& operator=(const Warlock &warl);
		std::map<std::string, ASpell *>	_known;


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