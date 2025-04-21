#ifndef EX00_WRONGANIMAL_HPP
# define EX00_WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string _wrong_type;
    public:
        WrongAnimal(void);
        WrongAnimal( std::string type );
        WrongAnimal(WrongAnimal const &type);
        WrongAnimal &operator=(WrongAnimal const &WrongAnimal);
        virtual ~WrongAnimal(void);

        void makeSound(void);
        std::string getType() const;
};

#endif