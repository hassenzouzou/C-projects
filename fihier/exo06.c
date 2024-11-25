#include <stdio.h>

struct Livre {
    char titre[100];
    char auteur[50];
    int annee;
    float prix;
};

int main() {
    struct Livre livre;

    printf("Entrez les informations du livre :\n");
    printf("Titre : ");
    fgets(livre.titre, 100, stdin);

    printf("Auteur : ");
    fgets(livre.auteur, 50, stdin);

    printf("Annee de publication : ");
    scanf("%d", &livre.annee);

    printf("Prix : ");
    scanf("%f", &livre.prix);

    printf("\n--- Informations du livre ---\n");
    printf("Titre : %s", livre.titre);
    printf("Auteur : %s", livre.auteur);
    printf("Annee : %d\n", livre.annee);
    printf("Prix : %.2f DA\n", livre.prix);

    return 0;
}
