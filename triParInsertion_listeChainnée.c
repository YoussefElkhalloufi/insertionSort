#include <stdio.h>
#include <stdlib.h>



typedef struct Element Element;
struct Element{
    int valeur;
    Element *suivant;
};


void append(Element **tete, int valeur){
    Element *element = malloc(sizeof(Element));
    element->valeur = valeur;
    element->suivant = NULL;

    if(*tete == NULL){
        *tete = element;
        return;
    }else{
        Element *tmp = *tete;
        while(tmp->suivant != NULL){
            tmp = tmp->suivant;
        }
        tmp->suivant = element;
    }
}


Element* triParInsertion(Element *tete){
    if(tete == NULL || tete->suivant == NULL) return tete; //Si la liste est vide ou a un seul element

    Element *trie = NULL ;//Liste triée
    Element *courante = tete ;// liste courante

    while(courante != NULL){
        Element *suivant = courante->suivant;

        if(trie == NULL || trie->valeur >= courante->valeur){
            courante->suivant = trie;
            trie = courante;
        } else {
            Element *tmp = trie;
            while(tmp->suivant != NULL && tmp->suivant->valeur < courante->valeur){
                tmp = tmp->suivant ;
            }
            courante->suivant = tmp->suivant;
            tmp->suivant = courante;
        }

        courante = suivant;
    }

    return trie;
}


Element *triParInsertion2(Element *tete) {
    if (tete == NULL) {
        return NULL; // Si la liste est vide, retourner NULL.
    }

    Element *listeTrie = NULL; // Pointeur vers la nouvelle liste triée.

    Element *tmp = tete;
    while (tmp != NULL) {
        // Créer un nouveau noeud pour la valeur actuelle.
        Element *nv = malloc(sizeof(Element));
        if (nv == NULL) {
            // Gérer une éventuelle erreur d'allocation mémoire.
            perror("Erreur d'allocation mémoire");
            exit(EXIT_FAILURE);
        }
        nv->valeur = tmp->valeur;
        nv->suivant = NULL;

        // Insérer le nouveau noeud dans la liste triée.
        if (listeTrie == NULL || listeTrie->valeur > nv->valeur) {
            // Insertion en tête de la liste triée.
            nv->suivant = listeTrie;
            listeTrie = nv;
        } else {
            // Rechercher la position d'insertion.
             Element *courant = listeTrie;
            while (courant->suivant != NULL && courant->suivant->valeur <= nv->valeur) {
                courant = courant->suivant;
            }
            // Insérer le nouveau noeud après le courant.
            nv->suivant = courant->suivant;
            courant->suivant = nv;
        }

        tmp = tmp->suivant;
    }

    return listeTrie;
}

void afficher(Element *tete){
    while(tete!=NULL){
        printf("%d -> ", tete->valeur);
        tete = tete->suivant;
    }
    printf("NULL\n");
}

int main(){

    /*Element *liste = NULL;
    append(&liste, 10);
    append(&liste, 20);
    append(&liste, 30);
    append(&liste, -5);
    append(&liste, 5);
    append(&liste, 15);
    append(&liste, 25);
    append(&liste, 40);

    printf("Affichage de la liste chainee avant le tri par insertion :\n\t_  ");
    afficher(liste);

    liste = triParInsertion(liste);


    printf("Affichage de la liste chainee apres le tri par insertion :\n\t_  ");
    afficher(liste);*/

    Element *liste2 = NULL;
    append(&liste2, 10);
    append(&liste2, 20);
    append(&liste2, 30);
    append(&liste2, -5);
    append(&liste2, 5);


    printf("Affichage de la liste chainee avant le tri par insertion V2:\n\t_  ");
    afficher(liste2);

    Element *listeTrie = triParInsertion2(liste2);


    printf("Affichage de la liste chainee apres le tri par insertion :\n\t_  ");
    afficher(listeTrie);

    printf("\n\nAffichage de la liste originale apres le tri:\n\t");
    afficher(liste2);

    return 0;
}
