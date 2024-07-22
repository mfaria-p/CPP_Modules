#include <iostream>
//to have the std functions
void ft_upper(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
        std::cout << str[i];
        i++;
    }

}
int main(int ac, char **av)
{
    int i;

    i = 1;
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (i < ac)
        {
            ft_upper(av[i]);
            i++;
        }
        std::cout << std::endl; //to ensure the output is displayed
        return (0);
    }
}