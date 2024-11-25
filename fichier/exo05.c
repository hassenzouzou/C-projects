#include <stdio.h>
#include <string.h>

struct Lecteur {
    char nom[50];
    char prenom[50];
    int age;
};

int main() {
    struct Lecteur lecteurs[2];
    int i;

    printf("=== Saisie des données des lecteurs ===\n");
    for (i = 0; i < 2; i++) {
        printf("\nLecteur n° %d:\n", i + 1);

        printf("Entrez le nom: ");
        scanf("%s", lecteurs[i].nom);

        printf("Entrez le prénom: ");
        scanf("%s", lecteurs[i].prenom);

        printf("Entrez l'âge: ");
        scanf("%d", &lecteurs[i].age);
    }

    printf("\n=== Affichage des données des lecteurs ===\n");
    for (i = 0; i < 2; i++) {
        printf("\nLecteur n° %d:\n", i + 1);
        printf("Nom: %s\n", lecteurs[i].nom);
        printf("Prénom: %s\n", lecteurs[i].prenom);
        printf("Âge: %d\n", lecteurs[i].age);
    }

    return 0;
}
