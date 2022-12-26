#include "Warlock.hpp"


Warlock::Warlock(std::string const &name, std::string const &title): \
	_name(name), _title(title) {
		std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

void	Warlock::introduce() const {
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}

std::string	const &Warlock::getName() const {
	return this->_name;
}

std::string	const &Warlock::getTitle() const {
	return this->_title;
}

void	Warlock::setTitle(std::string const &title) {
	this->_title = title;
}

void	Warlock::learnSpell(ASpell *ptr) {
	if (ptr)
		this->_known.insert(std::pair<std::string, ASpell *>(ptr->getName(), ptr->clone()));
}
void	Warlock::forgetSpell(std::string spell) {
	std::map<std::string, ASpell *>::iterator it = this->_known.find(spell);
	if (it != this->_known.end())
		delete it->second;
	this->_known.erase(spell);
}

void	Warlock::launchSpell(std::string spell, ATarget const  &target) {
	ASpell *ptr = this->_known[spell];
	if (ptr)
		ptr->launch(target);
}