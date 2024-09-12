#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int jour;
    int mois;
    int annee;
} date;

typedef struct {
    int id;
    char nom[100];
    char prenom[100];
    date dateDeNaissance;
    char departement[100];
    float noteGenerale;
} etudiants;

etudiants etudiant[100]; //Tableau General Etudiants.
int count=0;
int nEtudiant=0;
int idc=1;


void ajouterEtudiant();
//void modifierSuppEtudiant();
void afficherDetailsEtudiant();
void calculerMoyenneEtudiant();
//void Statistiques();
//void rechercheEtudiant();
//void TrierEtudiant();

int main(){

    int choix;

    do {
        printf("\n----Gestion des etudiants dans une universite----\n");
        printf("[1]---> Ajouter un etudiant\n");
        printf("[2]---> Modifier ou supprimer un etudiant\n");
        printf("[3]---> Afficher les details d un etudiant\n");
        printf("[4]---> Calculer la moyenne generale\n");
        printf("[5]---> Statistiques\n");
        printf("[6]---> Rechercher un etudiant\n");
        printf("[7]---> Trier un etudiant\n");
        printf("[8]---> Quiter\n");
        printf("-------------------------------------------------\n");

        printf("Entrer votre choix: ");
        scanf("%d", &choix);

        switch(choix){

        case 1: ajouterEtudiant(); break;
        //case 2: modifierSuppEtudiant(); break;
        case 3: afficherDetailsEtudiant(); break;
        case 4: calculerMoyenneEtudiant(); break;
        //case 5: Statistiques(); break;
        //case 6: rechercheEtudiant(); break;
        //case 7: TrierEtudiant(); break;
        case 8: exit(1);
        default:
            printf("Erreur resayer a nouveau."); 
    }

    } while (choix >0 && choix <9);

    return 0;
}

void ajouterEtudiant() {

    int nbr;

    printf("\n");
    printf("\nEntrer le nombre d etudiant vous voulez ajouter: ");
    scanf("%d", &nbr);

    for (int i=0;i<nbr;i++){
        etudiant[count].id = idc;

        printf("Etudiant id: %d\n", etudiant[count].id);

        printf("Nom d etudiant: ");
        scanf("%s", etudiant[count].nom);

        printf("Prenom d etudiant: ");
        scanf("%s", etudiant[count].prenom);
        printf("\n");

        printf("Date de naissance d etudiant\n");

        do {

            printf("Entrer le jour de naissance: ");
            scanf("%d", &etudiant[count].dateDeNaissance.jour);
            if (etudiant[count].dateDeNaissance.jour < 1 || etudiant[count].dateDeNaissance.jour > 31) {
                printf("incorrecte!\n");
            }

        } while (etudiant[count].dateDeNaissance.jour < 1 || etudiant[count].dateDeNaissance.jour > 31);

        do {

            printf("Entrer le mois de naissance: ");
            scanf("%d", &etudiant[count].dateDeNaissance.mois);
            if (etudiant[count].dateDeNaissance.mois < 1 || etudiant[count].dateDeNaissance.mois > 12) {
                printf("incorrecte!\n");
            }

        } while (etudiant[count].dateDeNaissance.mois < 1 || etudiant[count].dateDeNaissance.mois > 12);

        do {

            printf("Entrer le mois de naissance: ");
            scanf("%d", &etudiant[count].dateDeNaissance.annee);
            if (etudiant[count].dateDeNaissance.annee < 1950 || etudiant[count].dateDeNaissance.annee > 2050) {
                printf("incorrecte!\n");
            }

        } while (etudiant[count].dateDeNaissance.annee < 1950 || etudiant[count].dateDeNaissance.annee > 2050);

        printf("Departement d etudiant: ");
        scanf("%s", etudiant[count].departement);

        printf("Note general d etudiant: ");
        scanf("%f", &etudiant[count].noteGenerale);
        printf("\n");
        
        count++;
        nEtudiant++;
        idc++;

        system("cls");
        printf("L ajout d etudiant a ete faite avec sucsess\n");
        printf("press any key to continue...");
        getchar();
        getchar();

    }

}

/*
void modifierSuppEtudiant(){


}
*/

void afficherDetailsEtudiant(){

    for(int i=0;i<count;i++) {
        printf("ID: %d | Nom: %s | Prenom: %s | Date de naissance: %d/%d/%d | Departement: %s | Note general: %.2f\n", etudiant[i].id, etudiant[i].nom, etudiant[i].prenom, etudiant[i].dateDeNaissance.jour, etudiant[i].dateDeNaissance.mois, etudiant[i].dateDeNaissance.annee, etudiant[i].departement, etudiant[i].noteGenerale); 
    }
}

void calculerMoyenneEtudiant(){

    char filiere[100];
    printf("le departements que vous shouitez calculer: ");
    scanf("%s", filiere);

    int countfiliere=0;
    float sumfiliere=0;
    for(int i=0; i<count;i++){
        if(strcmp(etudiant[i].departement, filiere)==0){
            sumfiliere += etudiant[i].noteGenerale;
            countfiliere++;
        }
    }
    printf("\nLa moyenne de departement %s entiere est %.2f\n",filiere, sumfiliere/countfiliere);

    float sum=0, Moyenne=0;
    for(int i=0; i<nEtudiant;i++){
        sum+=etudiant[i].noteGenerale;
    }
    Moyenne=sum/nEtudiant;
    printf("\nLa moyenne de de l universite entiere est %.2f\n", Moyenne);
}

/*
void Statistiques(){

}
void rechercheEtudiant(){

}
void TrierEtudiant(){

}

*/