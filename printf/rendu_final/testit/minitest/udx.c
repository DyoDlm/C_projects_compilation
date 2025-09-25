#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main() {
    // Tests pour le format %u
    printf("\nTEST 1\n");
    ft_printf(" %u ", 0);
    printf("\n");
    printf("Original version : %u \n", 0);

    printf("\nTEST 2\n");
    ft_printf(" %u ", -1);
    printf("\n");
    printf("Original version : %u \n", -1); // -1 affiché en tant que unsigned

    printf("\nTEST 3\n");
    ft_printf(" %u ", 1);
    printf("\n");
    printf("Original version : %u \n", 1);

    printf("\nTEST 4\n");
    ft_printf(" %u ", 9);
    printf("\n");
    printf("Original version : %u \n", 9);

    printf("\nTEST 5\n");
    ft_printf(" %u ", 10);
    printf("\n");
    printf("Original version : %u \n", 10);

    printf("\nTEST 6\n");
    ft_printf(" %u ", 11);
    printf("\n");
    printf("Original version : %u \n", 11);

    printf("\nTEST 7\n");
    ft_printf(" %u ", 15);
    printf("\n");
    printf("Original version : %u \n", 15);

    printf("\nTEST 8\n");
    ft_printf(" %u ", 16);
    printf("\n");
    printf("Original version : %u \n", 16);

    printf("\nTEST 9\n");
    ft_printf(" %u ", 17);
    printf("\n");
    printf("Original version : %u \n", 17);

    printf("\nTEST 10\n");
    ft_printf(" %u ", 99);
    printf("\n");
    printf("Original version : %u \n", 99);

    printf("\nTEST 11\n");
    ft_printf(" %u ", 100);
    printf("\n");
    printf("Original version : %u \n", 100);

    printf("\nTEST 12\n");
    ft_printf(" %u ", 101);
    printf("\n");
    printf("Original version : %u \n", 101);

    printf("\nTEST 13\n");
    ft_printf(" %u ", -9);
    printf("\n");
    printf("Original version : %u \n", -9); // -9 affiché en tant que unsigned

    printf("\nTEST 14\n");
    ft_printf(" %u ", -10);
    printf("\n");
    printf("Original version : %u \n", -10); // -10 affiché en tant que unsigned

    printf("\nTEST 15\n");
    ft_printf(" %u ", -11);
    printf("\n");
    printf("Original version : %u \n", -11); // -11 affiché en tant que unsigned

    printf("\nTEST 16\n");
    ft_printf(" %u ", -14);
    printf("\n");
    printf("Original version : %u \n", -14); // -14 affiché en tant que unsigned

    printf("\nTEST 17\n");
    ft_printf(" %u ", -15);
    printf("\n");
    printf("Original version : %u \n", -15); // -15 affiché en tant que unsigned

    printf("\nTEST 18\n");
    ft_printf(" %u ", -16);
    printf("\n");
    printf("Original version : %u \n", -16); // -16 affiché en tant que unsigned

    printf("\nTEST 19\n");
    ft_printf(" %u ", -99);
    printf("\n");
    printf("Original version : %u \n", -99); // -99 affiché en tant que unsigned

    printf("\nTEST 20\n");
    ft_printf(" %u ", -100);
    printf("\n");
    printf("Original version : %u \n", -100); // -100 affiché en tant que unsigned

    printf("\nTEST 21\n");
    ft_printf(" %u ", -101);
    printf("\n");
    printf("Original version : %u \n", -101); // -101 affiché en tant que unsigned

    printf("\nTEST 22\n");
    ft_printf(" %u ", INT_MAX);
    printf("\n");
    printf("Original version : %u \n", INT_MAX);

    printf("\nTEST 23\n");
    ft_printf(" %u ", INT_MIN);
    printf("\n");
    printf("Original version : %u \n", INT_MIN); // INT_MIN affiché en tant que unsigned

    printf("\nTEST 24\n");
    ft_printf(" %u ", LONG_MAX);
    printf("\n");
    printf("Original version : %lu \n", LONG_MAX);

    printf("\nTEST 25\n");
    ft_printf(" %u ", LONG_MIN);
    printf("\n");
    printf("Original version : %lu \n", LONG_MIN); // LONG_MIN affiché en tant que unsigned

    printf("\nTEST 26\n");
    ft_printf(" %u ", UINT_MAX);
    printf("\n");
    printf("Original version : %u \n", UINT_MAX);

    printf("\nTEST 27\n");
    ft_printf(" %u ", ULONG_MAX);
    printf("\n");
    printf("Original version : %lu \n", ULONG_MAX);

    printf("\nTEST 28\n");
    ft_printf(" %u ", 9223372036854775807LL);
    printf("\n");
    printf("Original version : %llu \n", 9223372036854775807LL);

    printf("\nTEST 29\n");
    ft_printf(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("\n");
    printf("Original version : %u %u %lu %lu %lu %u %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42); // -42 affiché en tant qu'entier

    // Tests pour le format %x
    printf("\nTEST 30\n");
    ft_printf(" %x ", (unsigned int)INT_MAX);
    printf("\n");
    printf("Original version : %x \n", (unsigned int)INT_MAX);

    printf("\nTEST 31\n");
    ft_printf(" %x ", (unsigned int)INT_MIN);
    printf("\n");
    printf("Original version : %x \n", (unsigned int)INT_MIN); // INT_MIN affiché en tant que unsigned

    printf("\nTEST 32\n");
    ft_printf(" %x ", (unsigned long)LONG_MAX);
    printf("\n");
    printf("Original version : %lx \n", (unsigned long)LONG_MAX);

    printf("\nTEST 33\n");
    ft_printf(" %x ", (unsigned long)LONG_MIN);
    printf("\n");
    printf("Original version : %lx \n", (unsigned long)LONG_MIN); // LONG_MIN affiché en tant que unsigned

    printf("\nTEST 34\n");
    ft_printf(" %x ", UINT_MAX);
    printf("\n");
    printf("Original version : %x \n", UINT_MAX);

    printf("\nTEST 35\n");
    ft_printf(" %x ", (unsigned long)ULONG_MAX);
    printf("\n");
    printf("Original version : %lx \n", (unsigned long)ULONG_MAX);

    printf("\nTEST 36\n");
    ft_printf(" %x ", (unsigned long long)9223372036854775807LL);
    printf("\n");
    printf("Original version : %llx \n", (unsigned long long)9223372036854775807LL);

    printf("\nTEST 37\n");
    ft_printf(" %x %x %x %x %x %x %x", 
              (unsigned int)INT_MAX, 
              (unsigned int)INT_MIN, 
              (unsigned long)LONG_MAX, 
              (unsigned long)LONG_MIN, 
              (unsigned long)ULONG_MAX, 
              0U, 
              (unsigned int)-42);
    printf("\n");
    printf("Original version : %x %x %lx %lx %lx %x %d\n", 
              (unsigned int)INT_MAX, 
              (unsigned int)INT_MIN, 
              (unsigned long)LONG_MAX, 
              (unsigned long)LONG_MIN, 
              (unsigned long)ULONG_MAX, 
              0U, 
              -42); // -42 affiché en tant qu'entier

    printf("\nTEST 38\n");
    ft_printf(" %x ", 42);
    printf("\n");
    printf("Original version : %x \n", 42);

    printf("\nTEST 39\n");
    ft_printf(" %x ", (unsigned int)-42);
    printf("\n");
    printf("Original version : %x \n", (unsigned int)-42); // Affichage de -42 en tant que unsigned

    // Tests pour le format %d
    printf("\nTEST 40\n");
    ft_printf(" %d ", 0);
    printf("\n");
    printf("Original version : %d \n", 0);

    printf("\nTEST 41\n");
    ft_printf(" %d ", -1);
    printf("\n");
    printf("Original version : %d \n", -1);

    printf("\nTEST 42\n");
    ft_printf(" %d ", 1);
    printf("\n");
    printf("Original version : %d \n", 1);

    printf("\nTEST 43\n");
    ft_printf(" %d ", 9);
    printf("\n");
    printf("Original version : %d \n", 9);

    printf("\nTEST 44\n");
    ft_printf(" %d ", 10);
    printf("\n");
    printf("Original version : %d \n", 10);

    printf("\nTEST 45\n");
    ft_printf(" %d ", 11);
    printf("\n");
    printf("Original version : %d \n", 11);

    printf("\nTEST 46\n");
    ft_printf(" %d ", 15);
    printf("\n");
    printf("Original version : %d \n", 15);

    printf("\nTEST 47\n");
    ft_printf(" %d ", 16);
    printf("\n");
    printf("Original version : %d \n", 16);

    printf("\nTEST 48\n");
    ft_printf(" %d ", 17);
    printf("\n");
    printf("Original version : %d \n", 17);

    printf("\nTEST 49\n");
    ft_printf(" %d ", 99);
    printf("\n");
    printf("Original version : %d \n", 99);

    printf("\nTEST 50\n");
    ft_printf(" %d ", 100);
    printf("\n");
    printf("Original version : %d \n", 100);

    printf("\nTEST 51\n");
    ft_printf(" %d ", 101);
    printf("\n");
    printf("Original version : %d \n", 101);

    printf("\nTEST 52\n");
    ft_printf(" %d ", -9);
    printf("\n");
    printf("Original version : %d \n", -9);

    printf("\nTEST 53\n");
    ft_printf(" %d ", -10);
    printf("\n");
    printf("Original version : %d \n", -10);

    printf("\nTEST 54\n");
    ft_printf(" %d ", -11);
    printf("\n");
    printf("Original version : %d \n", -11);

    printf("\nTEST 55\n");
    ft_printf(" %d ", -14);
    printf("\n");
    printf("Original version : %d \n", -14);

    printf("\nTEST 56\n");
    ft_printf(" %d ", -15);
    printf("\n");
    printf("Original version : %d \n", -15);

    printf("\nTEST 57\n");
    ft_printf(" %d ", -16);
    printf("\n");
    printf("Original version : %d \n", -16);

    printf("\nTEST 58\n");
    ft_printf(" %d ", -99);
    printf("\n");
    printf("Original version : %d \n", -99);

    printf("\nTEST 59\n");
    ft_printf(" %d ", -100);
    printf("\n");
    printf("Original version : %d \n", -100);

    printf("\nTEST 60\n");
    ft_printf(" %d ", -101);
    printf("\n");
    printf("Original version : %d \n", -101);

    printf("\nTEST 61\n");
    ft_printf(" %d ", INT_MAX);
    printf("\n");
    printf("Original version : %d \n", INT_MAX);

    printf("\nTEST 62\n");
    ft_printf(" %d ", INT_MIN);
    printf("\n");
    printf("Original version : %d \n", INT_MIN);

    printf("\nTEST 63\n");
    ft_printf(" %d ", LONG_MAX);
    printf("\n");
    printf("Original version : %ld \n", LONG_MAX);

    printf("\nTEST 64\n");
    ft_printf(" %d ", LONG_MIN);
    printf("\n");
    printf("Original version : %ld \n", LONG_MIN);

    printf("\nTEST 65\n");
    ft_printf(" %d ", UINT_MAX);
    printf("\n");
    printf("Original version : %u \n", UINT_MAX);

    printf("\nTEST 66\n");
    ft_printf(" %d ", ULONG_MAX);
    printf("\n");
    printf("Original version : %lu \n", ULONG_MAX);

    printf("\nTEST 67\n");
    ft_printf(" %d ", 9223372036854775807LL);
    printf("\n");
    printf("Original version : %lld \n", 9223372036854775807LL);

    printf("\nTEST 68\n");
    ft_printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("\n");
    printf("Original version : %d %d %ld %ld %lu %d %d\n", 
           INT_MAX, 
           INT_MIN, 
           LONG_MAX, 
           LONG_MIN, 
           ULONG_MAX, 
           0, 
           -42); // -42 affiché en tant qu'entier

    return 0;
}

