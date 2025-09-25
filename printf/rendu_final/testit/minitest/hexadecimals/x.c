#include "ft_printf.h"
#include <stdio.h>

int main()
{
    printf("\nTEST 1\n");
    ft_printf(" %x ", 0);
    printf("\n");
    printf("Original version :  %x \n", 0);

    printf("\nTEST 2\n");
    ft_printf(" %x ", 1);
    printf("\n");
    printf("Original version :  %x \n", 1);

    printf("\nTEST 3\n");
    ft_printf(" %x ", 15);
    printf("\n");
    printf("Original version :  %x \n", 15);

    printf("\nTEST 4\n");
    ft_printf(" %x ", 16);
    printf("\n");
    printf("Original version :  %x \n", 16);

    printf("\nTEST 5\n");
    ft_printf(" %x ", 255);
    printf("\n");
    printf("Original version :  %x \n", 255);

    printf("\nTEST 6\n");
    ft_printf(" %x ", 256);
    printf("\n");
    printf("Original version :  %x \n", 256);

    printf("\nTEST 7\n");
    ft_printf(" %x ", -1);
    printf("\n");
    printf("Original version :  %x \n", -1);

    printf("\nTEST 8\n");
    ft_printf(" %x ", 4294967295); // Testing with a large unsigned int
    printf("\n");
    printf("Original version :  %x \n", 4294967295);

    return (0);
}

