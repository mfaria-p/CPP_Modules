#ifndef EX00_WRONGCAT_HPP
# define EX00_WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    public:
        WrongCat(void);
        WrongCat(WrongCat const &cat);
        WrongCat &operator=(WrongCat const &cat);
        ~WrongCat(void);

        void makeSound(void);
};

#endif