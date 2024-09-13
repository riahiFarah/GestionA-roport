// menu.c

#include <stdio.h>

// Fonction pour afficher le menu général
void afficher_menu_general() {
    printf("MENU GENERAL\n");
    printf("1. Creation du repertoire Avion\n");
    printf("2. Mise a jour des Avions\n");
    printf("3. Recherche, affichage et tri\n");
    printf("4. Enregistrement et chargement dans un fichier\n");
    printf("5. Quitter\n");
    printf("Donner votre choix SVP : ");
}


// Fonction pour afficher le menu de mise à jour
void afficher_menu_maj() {
    printf("MENU MAJ\n");
    printf("1. Ajouter un nouvel avion\n");
    printf("2. Supprimer un avion\n");
    printf("3. Modifier les donnees d'un avion\n");
    printf("4. Retour Menu generale\n");
    printf("Donner votre choix SVP : ");
}

void menu_ajouter() {
        printf("Menu Ajouter\n");
        printf("1. Ajout en tête\n");
        printf("2. Ajout en queue\n");
        printf("3. Ajout dans une position\n");
        printf("4. Retour au menu MAJ\n");
        printf("Donner votre choix SVP : ");
}
void menu_supprimer() {
        printf("Menu Suppression\n");
        printf("1. Suppression en tête\n");
        printf("2. Suppression en queue\n");
        printf("3. Suppression a partir d ’une position\n");
        printf("4. Suppression d ’ un avion donné\n");
        printf("5. Suppression des avions d’une compagnie donnée\n");
        printf("6. Retour au menu MAJ\n");
        printf("Donner votre choix SVP : ");
}

void menu_modification() {
        printf("Menu Suppression\n");
        printf("1. Identifiant  \n");
        printf("2. Compagnie  \n");
        printf("3. Retour au menu MAJ\n");
        printf("Donner votre choix SVP : ");
}

