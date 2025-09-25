#include "ft_printf.h"
#include <stdio.h>

int main()
{
    printf("\nTEST 1\n");
    ft_printf(" %u ", 0);
    printf("\n");
    printf("Original version :  %u \n", 0);

    printf("\nTEST 2\n");
    ft_printf(" %u ", -1);
    printf("\n");
    printf("Original version :  %u \n", -1);

    printf("\nTEST 3\n");
    ft_printf(" %u ", 1);
    printf("\n");
    printf("Original version :  %u \n", 1);

    printf("\nTEST 4\n");
    ft_printf(" %u ", 9);
    printf("\n");
    printf("Original version :  %u \n", 9);

    printf("\nTEST 5\n");
    ft_printf(" %u ", 10);
    printf("\n");
    printf("Original version :  %u \n", 10);

    printf("\nTEST 6\n");
    ft_printf(" %u ", 11);
    printf("\n");
    printf("Original version :  %u \n", 11);

    printf("\nTEST 7\n");
    ft_printf(" %u ", 15);
    printf("\n");
    printf("Original version :  %u \n", 15);

    printf("\nTEST 8\n");
    ft_printf(" %u ", 16);
    printf("\n");
    printf("Original version :  %u \n", 16);

    printf("\nTEST 9\n");
    ft_printf(" %u ", 17);
    printf("\n");
    printf("Original version :  %u \n", 17);

    printf("\nTEST 10\n");
    ft_printf(" %u ", 99);
    printf("\n");
    printf("Original version :  %u \n", 99);

    printf("\nTEST 11\n");
    ft_printf(" %u ", 100);
    printf("\n");
    printf("Original version :  %u \n", 100);

    printf("\nTEST 12\n");
    ft_printf(" %u ", 101);
    printf("\n");
    printf("Original version :  %u \n", 101);

    printf("\nTEST 13\n");
    ft_printf(" %u ", -9);
    printf("\n");
    printf("Original version :  %u \n", -9);

    printf("\nTEST 14\n");
    ft_printf(" %u ", -10);
    printf("\n");
    printf("Original version :  %u \n", -10);

    printf("\nTEST 15\n");
    ft_printf(" %u ", -11);
    printf("\n");
    printf("Original version :  %u \n", -11);

    printf("\nTEST 16\n");
    ft_printf(" %u ", -14);
    printf("\n");
    printf("Original version :  %u \n", -14);

    printf("\nTEST 17\n");
    ft_printf(" %u ", -15);
    printf("\n");
    printf("Original version :  %u \n", -15);

    printf("\nTEST 18\n");
    ft_printf(" %u ", -16);
    printf("\n");
    printf("Original version :  %u \n", -16);

    printf("\nTEST 19\n");
    ft_printf(" %u ", -99);
    printf("\n");
    printf("Original version :  %u \n", -99);

    printf("\nTEST 20\n");
    ft_printf(" %u ", -100);
    printf("\n");
    printf("Original version :  %u \n", -100);

    printf("\nTEST 21\n");
    ft_printf(" %u ", -101);
    printf("\n");
    printf("Original version :  %u \n", -101);

    return (0);
}

