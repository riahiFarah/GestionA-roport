#include <stdio.h>  //  Biblioth�que standard de C contient des fonctions utiles pour la gestion de la m�moire dynamique
#include <string.h> //  Biblioth�que contient des fonctions pour manipuler des cha�nes de caract�res.
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
                printf("Vous avez choisi : Mise � jour des Avions\n");
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
                printf("Choix invalide, veuillez r�essayer.\n");
                break;
        }

    } while (choix != 5);

    return 0;
}
