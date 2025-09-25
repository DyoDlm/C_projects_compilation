#include <stdio.h>
#include <stdlib.h>
// Prototype de la fonction convertor
char *convertor(void *value, char type);

int main(void)
{
    // 1. Tester un entier (int)
    long long int_value = -1234567890;
    char *int_str = convertor(&int_value, 'd');
    if (int_str)
    {
        printf("Conversion de l'entier (d) : %s\n", int_str);
        free(int_str);  // Libérer la mémoire
    }

    // 2. Tester un entier non signé (unsigned long long)
    unsigned long long unsigned_value = 9876543210987654321ULL;
    char *unsigned_str = convertor(&unsigned_value, 'u');
    if (unsigned_str)
    {
        printf("Conversion de l'entier non signé (u) : %s\n", unsigned_str);
        free(unsigned_str);  // Libérer la mémoire
    }

    // 3. Tester une valeur hexadécimale en minuscule (x)
    unsigned long long hex_value = 0x1ABCDEF123456789ULL;
    char *hex_str = convertor(&hex_value, 'x');
    if (hex_str)
    {
        printf("Conversion en hexadécimal (x) : %s\n", hex_str);
        free(hex_str);  // Libérer la mémoire
    }

    // 4. Tester une valeur hexadécimale en majuscule (X)
    char *hex_str_upper = convertor(&hex_value, 'X');
    if (hex_str_upper)
    {
        printf("Conversion en hexadécimal (X) : %s\n", hex_str_upper);
        free(hex_str_upper);  // Libérer la mémoire
    }

    // 5. Tester un caractère (char)
    char char_value = 'A';
    char *char_str = convertor(&char_value, 'c');
    if (char_str)
    {
        printf("Conversion du caractère (c) : %s\n", char_str);
        free(char_str);  // Libérer la mémoire
    }

    // 6. Tester une chaîne de caractères (string)
    char *str_value = "Hello, World!";
    char *str_result = convertor(str_value, 's');
    if (str_result)
    {
        printf("Conversion de la chaîne (s) : %s\n", str_result);
    }

    // 7. Tester un pointeur (p)
    void *ptr_value = (void *)0x7ffee1234567;
    char *ptr_str = convertor(&ptr_value, 'p');
    if (ptr_str)
    {
        printf("Conversion du pointeur (p) : %s\n", ptr_str);
        free(ptr_str);  // Libérer la mémoire
    }

    return 0;
}
