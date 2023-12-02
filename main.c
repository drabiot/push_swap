#include "push_swap.h"
#include "libft.h"

int main(int argc, char **argv)
{
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
        ft_split(argv[1], ' ');
}