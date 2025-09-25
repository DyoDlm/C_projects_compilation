#include <stdio.h>
#include <stdlib.h>

char	**ss(const char *segment);

int main(void)
{
    // Chaîne de test avec des segments contenant des symboles '%'
    const char *test_string = "%c";

    // Appel de la fonction ss pour obtenir les segments
    char **segments = ss(test_string);

    // Vérification que les segments ont été correctement générés
    if (!segments)
    {
        printf("Erreur lors de la génération des segments.\n");
        return 1;
    }

    // Affichage des segments
    printf("Segments extraits :\n");
    for (int i = 0; segments[i] != NULL; i++)
    {
        printf("Segment %d: %s\n", i + 1, segments[i]);
       	free(segments[i]);  // Libérer chaque segment après l'utilisation
    }

    // Libération du tableau de segments
    free(segments);

    return 0;
}
