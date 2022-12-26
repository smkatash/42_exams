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
	this->_book.learnSpell(ptr);
}
void	Warlock::forgetSpell(std::string spell) {
	this->_book.forgetSpell(spell);
}

void	Warlock::launchSpell(std::string spell, ATarget const  &target) {
    ATarget const *test = nullptr;
    if (test == &target)
        return;
    ASpell *temp = this->_book.createSpell(spell);
    if (temp)
        temp->launch(target);
}