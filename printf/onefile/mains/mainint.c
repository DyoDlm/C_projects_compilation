#include "ft_printf.h"
#include <limits.h>  // Inclure pour les constantes INT_MAX, INT_MIN, etc.

int main() {
    // Tests pour le format %d avec des valeurs spécifiques
    ft_printf("Test 1:  %d \n", 0);        // Test 1 : Affichage de 0
    ft_printf("Test 2:  %d \n", -1);       // Test 2 : Affichage de -1
    ft_printf("Test 3:  %d \n", 1);        // Test 3 : Affichage de 1
    ft_printf("Test 4:  %d \n", 9);        // Test 4 : Affichage de 9
    ft_printf("Test 5:  %d \n", 10);       // Test 5 : Affichage de 10
    ft_printf("Test 6:  %d \n", 11);       // Test 6 : Affichage de 11
    ft_printf("Test 7:  %d \n", 15);       // Test 7 : Affichage de 15
    ft_printf("Test 8:  %d \n", 16);       // Test 8 : Affichage de 16
    ft_printf("Test 9:  %d \n", 17);       // Test 9 : Affichage de 17
    ft_printf("Test 10: %d \n", 99);       // Test 10 : Affichage de 99
    ft_printf("Test 11: %d \n", 100);      // Test 11 : Affichage de 100
    ft_printf("Test 12: %d \n", 101);      // Test 12 : Affichage de 101
    ft_printf("Test 13: %d \n", -9);       // Test 13 : Affichage de -9
    ft_printf("Test 14: %d \n", -10);      // Test 14 : Affichage de -10
    ft_printf("Test 15: %d \n", -11);      // Test 15 : Affichage de -11
    ft_printf("Test 16: %d \n", -14);      // Test 16 : Affichage de -14

    // Tests avec les limites des types int définies dans limits.h
    ft_printf("Test 17: %d \n", INT_MAX);  // Test 17 : Valeur maximale pour un int
    ft_printf("Test 18: %d \n", INT_MIN);  // Test 18 : Valeur minimale pour un int
    ft_printf("Test 19: %d \n", LONG_MAX); // Test 19 : Valeur maximale pour un long
    ft_printf("Test 20: %d \n", LONG_MIN); // Test 20 : Valeur minimale pour un long
    ft_printf("Test 21: %d \n", UINT_MAX); // Test 21 : Valeur maximale pour un unsigned int (cast en signé)
    
    return 0;
}

