// avion.h : contient les déclarations des structures et prototypes de fonctions.

#ifndef AVION_H
#define AVION_H

typedef struct compagnie {
    char* nom;
    char acronyme[4]; // 3 lettres + 1 pour '\0'
} Compagnie;

typedef struct avion {
    char identifiant[7];
    int carburant;
    int consommation;
    char heure_decollage[5];
    Compagnie* compagnie;
    struct avion* suivant;
} Avion;

// Prototypes des fonctions
int taille_liste_av(Avion* tete);
Avion* recherche_av(Avion* tete, const char* identifiant);
void insere_tete_av(Avion** tete, Avion* nouvel_avion);
void insere_queue_av(Avion** tete, Avion* nouvel_avion);
int insere_pos_av(Avion** tete, Avion* nouvel_avion, int pos);
void supprimer_tete_av(Avion** tete);
void supprimer_queue_av(Avion** tete);
void suppression_pos_av(Avion** tete, int pos);
void suppression_av_donne(Avion** tete, const char* identifiant);
void afficher_avion(Avion* avion);
void afficher_liste(Avion* tete);

int identifiant_unique(Avion* tete, const char* identifiant);
void creation_liste_avion(Avion** tete);

int identifiant_valide(const char* identifiant);
int carburant_valide(const char* carburant_str);
int consommation_valide(const char* consommation_str);
int heure_valide(const char* heure);


void ajouter_avion(Avion** tete, Avion* nouvel_avion);
void suppression_avions_compagnie(Avion** tete, const char* prefixe);

#endif // AVION_H
