#include <stdio.h>
#include <stdlib.h>


void triParInsertion(int arr[], int taille){
    for (int i = 1; i < taille; i++) { // On commence avec le deuxième element

        int cle = arr[i]; // Initialiser lelement courant dans la variable cle

        int j = i - 1; // Initialiser j à l'indice précédent (i - 1)


        // Cette boucle déplace les éléments plus grands que la clé d'une position vers la droite

        while (j >= 0 && arr[j] > cle) { // Tant que j >= 0 et que lelement arr[j] est superieur a la cle
            arr[j + 1] = arr[j]; // Decale l'element arr[j] d'une position vers la droite
            j--; // Passe a lelement precedent
        }
        arr[j + 1] = cle; // insere la cle a sa position correcte
    }
}



void afficher(int arr[], int taille){

    for(int i = 0; i<taille; i++){
        printf("\t%d:\t%d\n", i, arr[i]);
    }
}

int main(){


    int arr[] = {11,12,13,5,6,-2};
    int taille = sizeof(arr) / sizeof(arr[0]);

    printf("Affichage du tableau avant le tri :\n");
    afficher(arr,taille);

    triParInsertion(arr, taille);
    printf("\n\nAffichage du tableau apres le tri :\n");
    afficher(arr, taille);
    return 0;
}
