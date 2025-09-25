#include "ft_printf.h"
#include <stdio.h>

int main()
{
    printf("\nTEST 1\n");
    ft_printf("%c", '0');
    printf("\n");
    printf("Original version : %c\n", '0');

    printf("\nTEST 2\n");
    ft_printf(" %c ", '0');
    printf("\n");
    printf("Original version :  %c \n", '0');

    printf("\nTEST 3\n");
    ft_printf(" %c", '0' - 256);
    printf("\n");
    printf("Original version :  %c\n", '0' - 256);

    printf("\nTEST 4\n");
    ft_printf("%c ", '0' + 256);
    printf("\n");
    printf("Original version : %c \n", '0' + 256);

    printf("\nTEST 5\n");
    ft_printf(" %c %c %c ", '0', 0, '1');
    printf("\n");
    printf("Original version :  %c %c %c \n", '0', 0, '1');

    printf("\nTEST 6\n");
    ft_printf(" %c %c %c ", ' ', ' ', ' ');
    printf("\n");
    printf("Original version :  %c %c %c \n", ' ', ' ', ' ');

    printf("\nTEST 7\n");
    ft_printf(" %c %c %c ", '1', '2', '3');
    printf("\n");
    printf("Original version :  %c %c %c \n", '1', '2', '3');

    printf("\nTEST 8\n");
    ft_printf(" %c %c %c ", '2', '1', 0);
    printf("\n");
    printf("Original version :  %c %c %c \n", '2', '1', 0);

    printf("\nTEST 9\n");
    ft_printf(" %c %c %c ", 0, '1', '2');
    printf("\n");
    printf("Original version :  %c %c %c \n", 0, '1', '2');

    return (0);
}

