#include <stdio.h>  //  Bibliothèque standard de C contient des fonctions utiles pour la gestion de la mémoire dynamique
#include <string.h> //  Bibliothèque contient des fonctions pour manipuler des chaînes de caractères.
#include "avion.h"
#include "menu.h"

// Ne pas inclure les fichiers .c dans ce fichier


int main() {
    printf("Bienvenue dans le gestionnaire de trafic aerien !\n");
    Avion* liste_avions = NULL;

    int choix;

    do {
        afficher_menu_general();
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                printf("Vous avez choisi : Creation du repertoire Avion\n");
                creation_liste_avion(&liste_avions);
                break;
            case 2:
                printf("Vous avez choisi : Mise à jour des Avions\n");
                // Appeler la fonction correspondante
                break;
            case 3:
                printf("Vous avez choisi : Recherche, affichage et tri\n");
                // Appeler la fonction correspondante
                break;
            case 4:
                printf("Vous avez choisi : Enregistrement et chargement dans un fichier\n");
                // Appeler la fonction correspondante
                break;
            case 5:
                printf("Quitter...\n");
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
                break;
        }

    } while (choix != 5);

    return 0;
}
