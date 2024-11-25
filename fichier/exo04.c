#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    char email[50];
} Lecteur;

typedef struct {
    int id;
    char title[50];
    char author[50];
} Ouvrage;

int main() {
    Lecteur lecteurs[4];
    Ouvrage ouvrages[4];

    for (int i = 0; i < 4; i++) {
        printf("Entrez les informations pour le lecteur %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &lecteurs[i].id);
        printf("Nom: ");
        scanf(" %[^\n]%*c", lecteurs[i].name);
        printf("Email: ");
        scanf(" %[^\n]%*c", lecteurs[i].email);
    }

    for (int i = 0; i < 4; i++) {
        printf("Entrez les informations pour l'ouvrage %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &ouvrages[i].id);
        printf("Titre: ");
        scanf(" %[^\n]%*c", ouvrages[i].title); 
        printf("Auteur: ");
        scanf(" %[^\n]%*c", ouvrages[i].author); 
    }

    FILE *fileLecteurs = fopen("lecteurs.txt", "w");
    if (fileLecteurs == NULL) {
        printf("Erreur lors de la création du fichier des lecteurs!\n");
        return 1;
    }

    fprintf(fileLecteurs, "ID\tNom\t\tEmail\n");
    for (int i = 0; i < 4; i++) {
        fprintf(fileLecteurs, "%d\t%s\t%s\n", lecteurs[i].id, lecteurs[i].name, lecteurs[i].email);
    }
    fclose(fileLecteurs);

    FILE *fileOuvrages = fopen("ouvrages.txt", "w");
    if (fileOuvrages == NULL) {
        printf("Erreur lors de la création du fichier des ouvrages!\n");
        return 1;
    }

    fprintf(fileOuvrages, "ID\tTitre\t\t\tAuteur\n");
    for (int i = 0; i < 4; i++) {
        fprintf(fileOuvrages, "%d\t%s\t%s\n", ouvrages[i].id, ouvrages[i].title, ouvrages[i].author);
    }
    fclose(fileOuvrages);

    printf("Les fichiers ont été créés avec succès!\n");
    return 0;
}
