#ifndef WARLOCK_HPP
#define WARLOCK_HPP
#include <iostream>

class Warlock {
	private:
		std::string	_name;
		std::string	_title;
		Warlock(const Warlock &warl);
		Warlock& operator=(const Warlock &warl);

	public:
		std::string	const &getName() const;
		std::string	const &getTitle() const;
		void	setTitle(std::string const &title);
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		void	introduce() const;

};


#endif