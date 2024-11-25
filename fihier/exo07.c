#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
} Lecteur;

void supprimerLecteur(Lecteur lecteurs[], int *n, int id) {
    int i, found = 0;

    for (i = 0; i < *n; i++) {
        if (lecteurs[i].id == id) {
            found = 1;

            for (int j = i; j < *n - 1; j++) {
                lecteurs[j] = lecteurs[j + 1];
            }

            (*n)--;
            printf("Le lecteur avec l'ID %d a été supprimé avec succès.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Le lecteur avec l'ID %d n'existe pas.\n", id);
    }
}

int main() {
    int n, idToDelete;

    printf("Entrez le nombre de lecteurs: ");
    scanf("%d", &n);

    Lecteur lecteurs[n];

    for (int i = 0; i < n; i++) {
        printf("Entrez les informations du lecteur %d:\n", i + 1);
        printf("ID du lecteur: ");
        scanf("%d", &lecteurs[i].id);
        printf("Nom du lecteur: ");
        scanf(" %[^\n]", lecteurs[i].name);
    }

    printf("\nLes lecteurs enregistrés:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Nom: %s\n", lecteurs[i].id, lecteurs[i].name);
    }

    printf("\nEntrez l'ID du lecteur à supprimer: ");
    scanf("%d", &idToDelete);

    supprimerLecteur(lecteurs, &n, idToDelete);

    printf("\nLes lecteurs après la suppression:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Nom: %s\n", lecteurs[i].id, lecteurs[i].name);
    }

    return 0;
}
