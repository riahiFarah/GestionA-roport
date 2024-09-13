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
                printf("Vous avez choisi : Mise a jour des Avions\n");
                int choix_maj;
                do {
                    afficher_menu_maj();
                    scanf("%d", &choix_maj);
                    switch (choix_maj) {
                        case 1:
                            { // Afficher le sous-menu pour ajouter un avion
                                int choix_ajout;
                                do {
                                    menu_ajouter();
                                    scanf("%d", &choix_ajout);
                                    switch (choix_ajout) {
                                        case 1:
                                            {// Ajout en tête
                                            Avion* nouvel_avion = (Avion*)malloc(sizeof(Avion));
                                            creation_liste_avion(&liste_avions);
                                            insere_tete_av(&liste_avions, nouvel_avion);
                                            printf("Avion ajouté en tête.\n");
                                            }
                                            break;
                                        case 2:
                                            {// Ajout en queue
                                            Avion* nouvel_avion = (Avion*)malloc(sizeof(Avion));
                                            creation_liste_avion(&liste_avions);
                                            insere_queue_av(&liste_avions, nouvel_avion);
                                            printf("Avion ajouté en queue.\n");
                                            }
                                            break;
                                        case 3:
                                            {// Ajout dans une position
                                            Avion* nouvel_avion = (Avion*)malloc(sizeof(Avion));
                                            creation_liste_avion(&liste_avions);
                                            int position;
                                            printf("Saisir la position d'insertion : ");
                                            scanf("%d", &position);
                                            if (insere_pos_av(&liste_avions, nouvel_avion, position)) {
                                                printf("Avion ajouté à la position %d.\n", position);
                                            } else {
                                                printf("Échec de l'insertion à la position %d.\n", position);
                                            }
                                            }
                                            break;
                                        case 4:
                                            printf("Retour au menu MAJ...\n");
                                            break;
                                        default:
                                            printf("Choix invalide, veuillez réessayer.\n");
                                            break;
                                    }
                                } while (choix_ajout != 4);
                            }
                            break;
                            case 2:
                                { // Afficher le sous-menu pour supprimer un avion
                                    int choix_suppression;
                                    do {
                                        menu_supprimer();
                                        scanf("%d", &choix_suppression);
                                        switch (choix_suppression) {
                                            case 1:
                                                { // Suppression en tête
                                                supprimer_tete_av(&liste_avions);
                                                printf("Avion supprimé en tête.\n");
                                                }
                                                break;
                                            case 2:
                                                { // Suppression en queue
                                                supprimer_queue_av(&liste_avions);
                                                printf("Avion supprimé en queue.\n");
                                                }
                                                break;
                                            case 3:
                                                { // Suppression à partir d'une position
                                                int position;
                                                printf("Saisir la position de suppression : ");
                                                scanf("%d", &position);
                                                suppression_pos_av(&liste_avions, position);
                                                }
                                                break;
                                            case 4:
                                                { // Suppression d'un avion donné
                                                char identifiant[7];
                                                printf("Saisir l'identifiant de l'avion à supprimer : ");
                                                scanf("%s", identifiant);
                                                suppression_av_donne(&liste_avions, identifiant);
                                                }
                                                break;
                                            case 5:
                                                { // Suppression des avions d'une compagnie donnée
                                                    char identifiant_prefixe[4];
                                                    printf("Saisir le préfixe d'identifiant de la compagnie : ");
                                                    scanf("%s", identifiant_prefixe);
                                                    suppression_avions_compagnie(&liste_avions, identifiant_prefixe);
                                                    printf("Les avions de la compagnie avec le préfixe %s ont été supprimés.\n", identifiant_prefixe);
                                                }
                                                break;
                                            case 6:
                                                printf("Retour au menu MAJ...\n");
                                                break;
                                            default:
                                                printf("Choix invalide, veuillez réessayer.\n");
                                                break;
                                        }
                                    } while (choix_suppression != 6);
                                }
                                break;
                        case 3:
                            // ici menu modification et son travail
                            break;
                        case 4:
                            printf("Retour au menu général...\n");
                            break;
                        default:
                            printf("Choix invalide, veuillez réessayer.\n");
                            break;
                    }
                } while (choix_maj != 4);
                break;
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
