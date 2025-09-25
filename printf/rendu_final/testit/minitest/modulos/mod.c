#include "ft_printf.h"
#include <stdio.h>

int main()
{
    printf("\nTEST 1\n");
    ft_printf(" %%");
    printf("\n");
    printf("Original version :  %% \n");

    printf("\nTEST 2\n");
    ft_printf(" %%%% ");
    printf("\n");
    printf("Original version :  %%%% \n");

    printf("\nTEST 3\n");
    ft_printf(" %% %% %% ");
    printf("\n");
    printf("Original version :  %% %% %% \n");

    printf("\nTEST 4\n");
    ft_printf(" %%  %%  %% ");
    printf("\n");
    printf("Original version :  %%  %%  %% \n");

    printf("\nTEST 5\n");
    ft_printf(" %%   %%   %% ");
    printf("\n");
    printf("Original version :  %%   %%   %% \n");

    printf("\nTEST 6\n");
    ft_printf("%%");
    printf("\n");
    printf("Original version : %%\n");

    printf("\nTEST 7\n");
    ft_printf("%% %%");
    printf("\n");
    printf("Original version : %% %%\n");

    return (0);
}

