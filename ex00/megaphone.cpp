#include <iostream> //to have the std functions

void    ft_toupper(std::string &word)
{
    int size = word.length();
    for (int i = 0; i < size; i++)
        word[i] = std::toupper(word[i]);
}

int main(int ac, char **av)
{
    std::string word;

    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < ac; i++) 
    {
        word = (std::string)av[i];
        ft_toupper(word);
        std::cout << word;
    }
    std::cout << std::endl;
}