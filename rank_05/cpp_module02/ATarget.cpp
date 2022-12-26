#include "ATarget.hpp"

ATarget::ATarget(std::string const &type): \
	_type(type) {}

ATarget::~ATarget() {}

std::string	const &ATarget::getType() const {
	return this->_type;
}

void	ATarget::getHitBySpell(ASpell const &spell) const {
	std::cout << this->_type << " has been " << spell.getEffects() << "!" << std::endl;
}