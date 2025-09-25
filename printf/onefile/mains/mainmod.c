#include "ft_printf.h"

int main() {
    // Tests pour l'affichage du symbole % avec %%
    ft_printf("Test 1:  %% \n");                // Test 1 : Un seul %
    ft_printf("Test 2:  %%%% \n");               // Test 2 : Deux symboles %% affichant deux %
    ft_printf("Test 3:  %% %% %% \n");           // Test 3 : Trois symboles % séparés par des espaces
    ft_printf("Test 4:  %%  %%  %% \n");         // Test 4 : Trois symboles % séparés par deux espaces
    ft_printf("Test 5:  %%   %%   %% \n");       // Test 5 : Trois symboles % séparés par trois espaces
    ft_printf("Test 6:  %%\n");                  // Test 6 : Un seul % sans espace
    ft_printf("Test 7:  %% %%\n");               // Test 7 : Deux % séparés par un espace

    return 0;
}

