// avion.c contient les définitions (implementations) des fonctions déclarées dans avion.h.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avion.h"


int taille_liste_av(Avion* tete) {
    int taille = 0;
    Avion* courant = tete;
    while (courant != NULL) {
        taille++;
        courant = courant->suivant;
    }
    return taille;
}

Avion* recherche_av(Avion* tete, const char* identifiant) {
    Avion* courant = tete;
    while (courant != NULL) {
        if (strcmp(courant->identifiant, identifiant) == 0) {
            return courant;
        }
        courant = courant->suivant;
    }
    return NULL;
}

void insere_tete_av(Avion** tete, Avion* nouvel_avion) {
    nouvel_avion->suivant = *tete;
    *tete = nouvel_avion;
    printf("Taille actuelle de la liste des avions : %d\n", taille_liste_av(*tete));
}

void insere_queue_av(Avion** tete, Avion* nouvel_avion) {
    if (*tete == NULL) {
        *tete = nouvel_avion;
        nouvel_avion->suivant = NULL;
    } else {
        Avion* courant = *tete;
        while (courant->suivant != NULL) {
            courant = courant->suivant;
        }
        courant->suivant = nouvel_avion;
        nouvel_avion->suivant = NULL;
    }
   printf("Taille actuelle de la liste des avions : %d\n", taille_liste_av(*tete));

}

int insere_pos_av(Avion** tete, Avion* nouvel_avion, int pos) {
    if (pos <= 0 || pos > taille_liste_av(*tete) + 1) {
        printf("Position invalide.\n");
        return 0 ;
    }
    if (pos == 1) {
        insere_tete_av(tete, nouvel_avion);
        return 1;
    } else {
        Avion* courant = *tete;
        for (int i = 1; i < pos - 1; i++) {
            courant = courant->suivant;
        }
        nouvel_avion->suivant = courant->suivant;
        courant->suivant = nouvel_avion;
        return 1;
    }
    printf("Taille actuelle de la liste des avions : %d\n", taille_liste_av(*tete));
}

void supprimer_tete_av(Avion** tete) {
    if (*tete != NULL) {
        Avion* temp = *tete;
        *tete = (*tete)->suivant;
        free(temp);
    }
    printf("Taille actuelle de la liste des avions : %d\n", taille_liste_av(*tete));
}

void supprimer_queue_av(Avion** tete) {
    if (*tete == NULL) {
        return; // Liste vide
    }
    if ((*tete)->suivant == NULL) {
        free(*tete);
        *tete = NULL;
    } else {
        Avion* courant = *tete;
        while (courant->suivant->suivant != NULL) {
            courant = courant->suivant;
        }
        free(courant->suivant);
        courant->suivant = NULL;
    }
    printf("Taille actuelle de la liste des avions : %d\n", taille_liste_av(*tete));
}

void suppression_pos_av(Avion** tete, int pos) {
    if (pos <= 0 || pos > taille_liste_av(*tete)) {
        printf("Position invalide.\n");
        return;
    }
    if (pos == 1) {
        supprimer_tete_av(tete);
    } else {
        Avion* courant = *tete;
        for (int i = 1; i < pos - 1; i++) {
            courant = courant->suivant;
        }
        Avion* temp = courant->suivant;
        courant->suivant = temp->suivant;
        free(temp);
    }
    printf("Taille actuelle de la liste des avions : %d\n", taille_liste_av(*tete));
}

void suppression_av_donne(Avion** tete, const char* identifiant) {
    Avion* courant = *tete;
    Avion* precedent = NULL;

    while (courant != NULL && strcmp(courant->identifiant, identifiant) != 0) {
        precedent = courant;
        courant = courant->suivant;
    }

    if (courant != NULL) {
        if (precedent == NULL) {
            *tete = courant->suivant; // Suppression de la tête
        } else {
            precedent->suivant = courant->suivant;
        }
        free(courant);
    }
    printf("Taille actuelle de la liste des avions : %d\n", taille_liste_av(*tete));
}

void afficher_avion(Avion* avion) {
    if (avion != NULL) {
        printf("Identifiant : %s\n", avion->identifiant);
        printf("Carburant : %d\n", avion->carburant);
        printf("Consommation : %d\n", avion->consommation);
        printf("Heure de décollage : %s\n", avion->heure_decollage);
    }
}

void afficher_liste(Avion* tete) {
    Avion* courant = tete;
    while (courant != NULL) {
        afficher_avion(courant);
        courant = courant->suivant;
        printf("\n");
    }
}


//////////////////////////////////////////////////////

int identifiant_unique(Avion* tete, const char* identifiant) {
    Avion* courant = tete;
    while (courant != NULL) {
        if (strcmp(courant->identifiant, identifiant) == 0) {
            return 0; // Identifiant déjà utilisé
        }
        courant = courant->suivant;
    }
    return 1; // Identifiant unique
}


void creation_liste_avion(Avion** tete) {
    int continuer = 1;
    while (continuer) {
        Avion* nouvel_avion = (Avion*)malloc(sizeof(Avion));
        printf("Vous allez ajouter une nouvelle avion.\n");

        do {
            printf("Saisir l'identifiant de l'avion (3 lettres majuscules + 3 chiffres, ex: ABC123) : ");
            scanf("%s", nouvel_avion->identifiant);
        } while (!identifiant_valide(nouvel_avion->identifiant));

        if (!identifiant_unique(*tete, nouvel_avion->identifiant)) {
            printf("Erreur : L'identifiant existe déjà !\n");
            free(nouvel_avion);
            continue;
        }

        // Saisie et vérification du carburant
        char carburant_str[10];  // Assume the input won't exceed 10 characters

        do {
            printf("Saisir le carburant de l'avion (nombre entier positif) : ");
            scanf("%s", carburant_str);
        } while (!carburant_valide(carburant_str));

        int carburant = atoi(carburant_str);  // Convert valid string to integer

        // Saisie et vérification de la consommation
        char consommation_str[10];  // Assume the input won't exceed 10 characters

        do {
            printf("Saisir la consommation de l'avion (nombre entier positif) : ");
            scanf("%s", consommation_str);
        } while (!consommation_valide(consommation_str));

        int consommation = atoi(consommation_str);  // Convert valid string to integer

        // Saisie et vérification de l'heure de décollage
        do {
            printf("Saisir l'heure de décollage (HHMM) : ");
            scanf("%s", nouvel_avion->heure_decollage);
        } while (!heure_valide(nouvel_avion->heure_decollage));

        nouvel_avion->suivant = NULL;

        int position;

        int tentative = 0;
        int insertion_reussie = 0; // 0 si l'insertion échoue, 1 si elle réussit

        while (tentative < 3 && !insertion_reussie) {
            printf("Choisir la position d'insertion (1 pour tete, 0 pour queue, ou autre pour position donnee) : ");
            scanf("%d", &position);

            int returnValue = insere_pos_av(tete, nouvel_avion, position);
            if ( returnValue == 0) {
                tentative++;
                printf("Position invalide. Il vous reste %d tentatives.\n", 3 - tentative);
            } else {
                insertion_reussie = 1; // Insertion réussie
            }
        }

        // Si l'insertion échoue après 3 tentatives, on sort de la boucle
        if (!insertion_reussie) {
            printf("Vous avez épuisé toutes vos tentatives. Avion non ajouté.\n");
            free(nouvel_avion); // Libérer la mémoire allouée pour l'avion
            continue;
        }

        printf("Voulez-vous ajouter un autre avion ? (1 pour Oui, n'importe quel autre click pour Non) : ");
        scanf("%d", &continuer);
    }
}


// Fonction pour valider l'identifiant de l'avion
int identifiant_valide(const char* identifiant) {
    if (strlen(identifiant) != 6) {
        printf("Erreur : L'identifiant doit comporter exactement 6 caractères (3 lettres suivies de 3 chiffres).\n");
        return 0;
    }

    for (int i = 0; i < 3; i++) {
        if (!isupper(identifiant[i])) {
            printf("Erreur : Les trois premiers caractères doivent être des lettres majuscules (acronyme de la compagnie).\n");
            return 0;
        }
    }

    for (int i = 3; i < 6; i++) {
        if (!isdigit(identifiant[i])) {
            printf("Erreur : Les trois derniers caractères doivent être des chiffres (numéro de vol).\n");
            return 0;
        }
    }

    return 1;
}

int carburant_valide(const char* carburant_str) {
    // Vérifier que tous les caractères de la chaîne sont des chiffres
    for (int i = 0; i < strlen(carburant_str); i++) {
        if (!isdigit(carburant_str[i])) {
            printf("Erreur : Le carburant doit etre un nombre entier positif.\n");
            return 0;  // Carburant invalide
        }
    }

    // Convertir la chaîne en entier
    int carburant = atoi(carburant_str);

    // Vérifier que le carburant est positif
    if (carburant > 0) {
        return 1;  // Carburant valide
    } else {
        printf("Erreur : Le carburant doit etre un nombre entier positif.\n");
        return 0;  // Carburant invalide
    }
}
int consommation_valide(const char* consommation_str) {
    // Vérifier que tous les caractères de la chaîne sont des chiffres
    for (int i = 0; i < strlen(consommation_str); i++) {
        if (!isdigit(consommation_str[i])) {
            printf("Erreur : La consommation doit etre un nombre entier positif.\n");
            return 0;  // Consommation invalide
        }
    }

    // Convertir la chaîne en entier
    int consommation = atoi(consommation_str);

    // Vérifier que la consommation est positive
    if (consommation > 0) {
        return 1;  // Consommation valide
    } else {
        printf("Erreur : La consommation doit etre un nombre entier positif.\n");
        return 0;  // Consommation invalide
    }
}

int heure_valide(const char* heure) {
    // L'heure contient exactement 4 caractères
    if (strlen(heure) != 4) {
        printf("Erreur : L'heure doit contenir exactement 4 caracteres (HHMM).\n");
        return 0;
    }

    // Vérifier que les deux premiers caractères (HH) sont des chiffres
    if (!isdigit(heure[0]) || !isdigit(heure[1])) {
        printf("Erreur : Les heures doivent etre des chiffres.\n");
        return 0;
    }

    // Vérifier que les deux derniers caractères (MM) sont des chiffres
    if (!isdigit(heure[2]) || !isdigit(heure[3])) {
        printf("Erreur : Les minutes doivent etre des chiffres.\n");
        return 0;
    }

    // Extraire les heures et les minutes sous forme d'entiers
    int heures = (heure[0] - '0') * 10 + (heure[1] - '0');
    int minutes = (heure[2] - '0') * 10 + (heure[3] - '0');

    // Vérifier que les heures sont entre 00 et 24
    if (heures < 0 || heures > 23) {
        printf("Erreur : Les heures doivent etre comprises entre 00 et 23.\n");
        return 0;
    }

    // Vérifier que les minutes sont entre 00 et 59
    if (minutes < 0 || minutes > 59) {
        printf("Erreur : Les minutes doivent etre comprises entre 00 et 59.\n");
        return 0;
    }

    // Si toutes les vérifications sont correctes
    return 1;
}

