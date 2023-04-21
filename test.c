
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool number(char **av) 
{
    char *string = av[1];
    int tamanho = strlen(string);
    int i = 0;
    
    while (i < tamanho) 
    {
        char c = string[i];
        if ((c < '0' || c > '9') && c != '.' && c != '-') {
            return false;
        }
        i++;
    }
    return true;
}

bool valid_size(char **av)
{
    double arg = atof(av[1]);
    if (arg >= -2.0 && arg <= 1.0) 
        return true;
    else
        return false;
}

int main(int ac, char **av)
{
    int i = 1;

    if (ac == 3)
    {
        while (i < ac)
        {
            if (av[1] == NULL) {
                puts("Invalid");
                return 0;
            }
            if (number(&av[i]) == true && valid_size(&av[i]) == true)
                puts("Valid");
            else 
                puts("Invalid");
            i++;
        }
    }
    else 
        return 0;
}
