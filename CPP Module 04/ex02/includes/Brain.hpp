#ifndef EX01_BRAIN_HPP
# define EX01_BRAIN_HPP

#include <iostream>

class Brain
{
private:
    std::string _ideas[100];

public:
    Brain();
    Brain( const Brain& other );
    Brain& operator=( const Brain& other );
    ~Brain();

    // Getter for an idea
    std::string getIdea(int index) const;
    
    // Setter for an idea
    void setIdea(int index, const std::string& idea);
};

#endif