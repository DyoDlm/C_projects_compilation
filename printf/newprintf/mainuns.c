#include "ft_printf.h"
#include <limits.h>  // Inclure pour les constantes UINT_MAX

int main() {
    // Tests pour le format %u avec des valeurs spécifiques
    ft_printf("Test 1:  %u \n", 0);      // Test 1 : Affichage de 0
    ft_printf("Test 2:  %u \n", -1);     // Test 2 : Affichage de -1 (casté en unsigned)
    ft_printf("Test 3:  %u \n", 1);      // Test 3 : Affichage de 1
    ft_printf("Test 4:  %u \n", 9);      // Test 4 : Affichage de 9
    ft_printf("Test 5:  %u \n", 10);     // Test 5 : Affichage de 10
    ft_printf("Test 6:  %u \n", 11);     // Test 6 : Affichage de 11
    ft_printf("Test 7:  %u \n", 15);     // Test 7 : Affichage de 15
    ft_printf("Test 8:  %u \n", 16);     // Test 8 : Affichage de 16
    ft_printf("Test 9:  %u \n", 17);     // Test 9 : Affichage de 17
    ft_printf("Test 10: %u \n", 99);     // Test 10 : Affichage de 99
    ft_printf("Test 11: %u \n", 100);    // Test 11 : Affichage de 100
    ft_printf("Test 12: %u \n", 101);    // Test 12 : Affichage de 101
    ft_printf("Test 13: %u \n", -9);     // Test 13 : Affichage de -9 (casté en unsigned)
    ft_printf("Test 14: %u \n", -10);    // Test 14 : Affichage de -10 (casté en unsigned)
    ft_printf("Test 15: %u \n", -11);    // Test 15 : Affichage de -11 (casté en unsigned)
    ft_printf("Test 16: %u \n", -14);    // Test 16 : Affichage de -14 (casté en unsigned)

    // Tests pour les limites des entiers non signés avec %u
    ft_printf("Test 17: %u \n", UINT_MAX);  // Test 17 : Affichage de UINT_MAX
    ft_printf("Test 18: %u \n", 0);        // Test 18 : Affichage de 0 pour comparer avec UINT_MAX
    ft_printf("Test 19: %u \n", (unsigned int)INT_MAX);  // Test 19 : INT_MAX casté en unsigned
    ft_printf("Test 20: %u \n", (unsigned int)INT_MIN);  // Test 20 : INT_MIN casté en unsigned (overflow)

    return 0;
}

