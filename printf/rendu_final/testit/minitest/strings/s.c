#include "ft_printf.h"
#include <stdio.h>

int main()
{
    printf("\nTEST 1\n");
    ft_printf(" %s", "");
    printf("\n");
    printf("Original version :  %s\n", "");

    printf("\nTEST 2\n");
    ft_printf("%s ", "");
    printf("\n");
    printf("Original version : %s \n", "");

    printf("\nTEST 3\n");
    ft_printf(" %s ", "");
    printf("\n");
    printf("Original version :  %s \n", "");

    printf("\nTEST 4\n");
    ft_printf(" %s ", "-");
    printf("\n");
    printf("Original version :  %s \n", "-");

    printf("\nTEST 5\n");
    ft_printf(" %s %s ", "", "-");
    printf("\n");
    printf("Original version :  %s %s \n", "", "-");

    printf("\nTEST 6\n");
    ft_printf(" %s %s ", " - ", "");
    printf("\n");
    printf("Original version :  %s %s \n", " - ", "");

    printf("\nTEST 7\n");
    ft_printf(" %s %s %s %s %s", " - ", "", "4", "", "2");
    printf("\n");
    printf("Original version :  %s %s %s %s %s \n", " - ", "", "4", "", "2");

    printf("\nTEST 8\n");
    ft_printf(" NULL %s NULL ", NULL);
    printf("\n");
    printf("Original version :  NULL %s NULL \n", NULL);

    return (0);
}

