#include "ft_printf.h"
#include <limits.h>  // Inclure pour les constantes UINT_MAX, INT_MAX, INT_MIN

int main() {
    // Tests pour le format %x (hexadécimal minuscule)
    ft_printf("Test 1:  %x \n", 0);         // Test 1 : Affichage de 0 en hexadécimal
    ft_printf("Test 2:  %x \n", -1);        // Test 2 : Affichage de -1 casté en unsigned en hexadécimal
    ft_printf("Test 3:  %x \n", 1);         // Test 3 : Affichage de 1 en hexadécimal
    ft_printf("Test 4:  %x \n", 9);         // Test 4 : Affichage de 9 en hexadécimal
    ft_printf("Test 5:  %x \n", 10);        // Test 5 : Affichage de 10 en hexadécimal (a)
    ft_printf("Test 6:  %x \n", 15);        // Test 6 : Affichage de 15 en hexadécimal (f)
    ft_printf("Test 7:  %x \n", 16);        // Test 7 : Affichage de 16 en hexadécimal (10)
    ft_printf("Test 8:  %x \n", 17);        // Test 8 : Affichage de 17 en hexadécimal (11)
    ft_printf("Test 9:  %x \n", 99);        // Test 9 : Affichage de 99 en hexadécimal
    ft_printf("Test 10: %x \n", 255);       // Test 10 : Affichage de 255 en hexadécimal (ff)

    // Tests pour le format %X (hexadécimal majuscule)
    ft_printf("Test 11: %X \n", 0);         // Test 11 : Affichage de 0 en hexadécimal
    ft_printf("Test 12: %X \n", -1);        // Test 12 : Affichage de -1 casté en unsigned en hexadécimal
    ft_printf("Test 13: %X \n", 1);         // Test 13 : Affichage de 1 en hexadécimal
    ft_printf("Test 14: %X \n", 9);         // Test 14 : Affichage de 9 en hexadécimal
    ft_printf("Test 15: %X \n", 10);        // Test 15 : Affichage de 10 en hexadécimal (A)
    ft_printf("Test 16: %X \n", 15);        // Test 16 : Affichage de 15 en hexadécimal (F)
    ft_printf("Test 17: %X \n", 16);        // Test 17 : Affichage de 16 en hexadécimal (10)
    ft_printf("Test 18: %X \n", 17);        // Test 18 : Affichage de 17 en hexadécimal (11)
    ft_printf("Test 19: %X \n", 99);        // Test 19 : Affichage de 99 en hexadécimal
    ft_printf("Test 20: %X \n", 255);       // Test 20 : Affichage de 255 en hexadécimal (FF)

    // Tests avec les limites des entiers pour %x et %X
    ft_printf("Test 21: %x \n", UINT_MAX);  // Test 21 : Affichage de UINT_MAX en hexadécimal minuscule
    ft_printf("Test 22: %X \n", UINT_MAX);  // Test 22 : Affichage de UINT_MAX en hexadécimal majuscule
    ft_printf("Test 23: %x \n", INT_MAX);   // Test 23 : Affichage de INT_MAX casté en unsigned en hexadécimal
    ft_printf("Test 24: %x \n", INT_MIN);   // Test 24 : Affichage de INT_MIN casté en unsigned en hexadécimal
    ft_printf("Test 25: %X \n", INT_MAX);   // Test 25 : Affichage de INT_MAX casté en unsigned en hexadécimal (majuscule)
    ft_printf("Test 26: %X \n", INT_MIN);   // Test 26 : Affichage de INT_MIN casté en unsigned en hexadécimal (majuscule)

    return 0;
}

