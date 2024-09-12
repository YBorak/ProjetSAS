#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int choix, choix2, nAfficher;

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
char filiere[100];


void ajouterEtudiant();
void modifierSuppEtudiant();
void afficherDetailsEtudiant();
void calculerMoyenneEtudiant();
void Statistiques();
void rechercheEtudiant();
void TrierEtudiant();

int main(){

    do {
        printf("\n-------------------------------------------------\n");
        printf("\n----Gestion des etudiants dans une universite----\n");
        printf("[1]---> Ajouter un etudiant\n");
        printf("[2]---> Modifier ou supprimer un etudiant\n");
        printf("[3]---> Afficher les details d un etudiant\n");
        printf("[4]---> Calculer la moyenne generale\n");
        printf("[5]---> Statistiques\n");
        printf("[6]---> Rechercher un etudiant\n");
        printf("[7]---> Trier un etudiant\n");
        printf("[0]---> Quiter\n");
        printf("\n-------------------------------------------------\n");

        printf("Entrer votre choix: ");
        scanf("%d", &choix);
        printf("-------------------------------------------------\n");
        printf("Choix [%d]\n",choix);

        switch(choix){

        case 1: ajouterEtudiant(); break;
        case 2: modifierSuppEtudiant(); break;
        case 3: afficherDetailsEtudiant(); break;
        case 4: calculerMoyenneEtudiant(); break;
        case 5: Statistiques(); break;
        case 6: rechercheEtudiant(); break;
        case 7: TrierEtudiant(); break;
        case 0: exit(1);
        default:
            printf("\nchoix invalide!\n");
        main(); 
    }

    } while (choix >0 && choix <9);

    return 0;
}

void ajouterEtudiant() {

    int nbr;

do{
    printf("\nEntrer le nombre d etudiant vous voulez ajouter: ");
    scanf("%d", &nbr);
    if (nbr <0 || nbr > 100) {
        printf("Max c est 100\n");
    }
} while (nbr <0 || nbr >100 );

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
            printf("Entrer la date de naissance jj/mm/aa: ");
            scanf("%d/%d/%d", &etudiant[count].dateDeNaissance.jour, &etudiant[count].dateDeNaissance.mois, &etudiant[count].dateDeNaissance.annee);
            if (etudiant[count].dateDeNaissance.jour < 1 || etudiant[count].dateDeNaissance.jour > 31 || etudiant[count].dateDeNaissance.mois < 1 || etudiant[count].dateDeNaissance.mois > 12 || etudiant[count].dateDeNaissance.annee < 1924 || etudiant[count].dateDeNaissance.annee > 2006) {
                printf("incorrecte date de naissance, ressayer: \n");
            }

        } while (etudiant[count].dateDeNaissance.jour < 1 || etudiant[count].dateDeNaissance.jour > 31 || etudiant[count].dateDeNaissance.mois < 1 || etudiant[count].dateDeNaissance.mois > 12 || etudiant[count].dateDeNaissance.annee < 1924 || etudiant[count].dateDeNaissance.annee > 2006);

        printf("\n");

        printf("Departement d etudiant: ");
        scanf("%s", etudiant[count].departement);

        printf("\n");

    do{
        printf("Note general d etudiant: ");
        scanf("%f", &etudiant[count].noteGenerale);
        if (etudiant[count].noteGenerale < 0 || etudiant[count].noteGenerale > 20) {
            printf("incorrecte!\n");
        }
    } while (etudiant[count].noteGenerale < 0 || etudiant[count].noteGenerale > 20);
        printf("\n");
    
        count++;
        nEtudiant++;
        idc++;

        system("cls");
        printf("\nLajout d etudiant a ete fait avec succses\n");
        printf("press any key to continue...\n");
        getchar();
        getchar();

    }

}


void modifierSuppEtudiant(){

    int trouveId=0, choixId=0;

    do{
        printf("\n-------------------------------------------------\n");
        printf("\n[1]--->Modifier les informations dun etudiant en fonction de son numero unique\n");
        printf("[2]--->Supprimer les informations dun etudiant en fonction de son numero unique\n");
        printf("[0]--->Quitter\n");
        printf("\n-------------------------------------------------\n");
        printf("Entrer votre choix: ");
        scanf("%d", &choix2);
        printf("Choix [%d]\n",choix2);
    } while (choix2 < 0 || choix2 > 2);

    if (choix2 == 1){

    printf("\nEntrer ID de letudiant que vous voulez modifier: \n");
    scanf("%d", &choixId);
    
    for(int i=0;i<count+1;i++) {
        trouveId=1;
        if(etudiant[i].id == choixId) {
            printf("Modifier le nom:");
            scanf("%s", etudiant[i].nom);
            printf("Modifier le prenom:");
            scanf("%s", etudiant[i].prenom);

            do {
            printf("Entrer la date de naissance jj/mm/aa: ");
            scanf("%d/%d/%d", &etudiant[count].dateDeNaissance.jour, &etudiant[count].dateDeNaissance.mois, &etudiant[count].dateDeNaissance.annee);
            if (etudiant[count].dateDeNaissance.jour < 1 || etudiant[count].dateDeNaissance.jour > 31 || etudiant[count].dateDeNaissance.mois < 1 || etudiant[count].dateDeNaissance.mois > 12 || etudiant[count].dateDeNaissance.annee < 1924 || etudiant[count].dateDeNaissance.annee > 2006) {
                printf("incorrecte date de naissance, ressayer: \n");
            }
            } while (etudiant[count].dateDeNaissance.jour < 1 || etudiant[count].dateDeNaissance.jour > 31 || etudiant[count].dateDeNaissance.mois < 1 || etudiant[count].dateDeNaissance.mois > 12 || etudiant[count].dateDeNaissance.annee < 1924 || etudiant[count].dateDeNaissance.annee > 2006);

            printf("Modifier la note general:");
            scanf("%f", &etudiant[i].noteGenerale);
        }
    }
    printf("\nLa modification a ete fait avec succes\n");
    }

    if (choix2 == 2){
    printf("Entrer ID de letudiant que vous voulez suprimer: ");
    scanf("%d", &choixId);

    for(int i=0;i<count;i++){
        for(int j=i;j<count;j++){
            if(etudiant[i].id==choixId){
                etudiant[j]=etudiant[j+1];
            }
            count--;
        }
        printf("\nLa modification a ete fait avec succes\n");
    }
    
    }
    else if (choix2 == 0){
    } else {
        printf("choix invalide!\n");
    }
}


void afficherDetailsEtudiant(){

    printf("\n");
    for(int i=0;i<count;i++){
    printf("ID: %d | Nom: %s | Prenom: %s | Date de naissance: %d/%d/%d | Departement: %s | Note general: %.2f\n", etudiant[i].id, etudiant[i].nom, etudiant[i].prenom, etudiant[i].dateDeNaissance.jour, etudiant[i].dateDeNaissance.mois, etudiant[i].dateDeNaissance.annee, etudiant[i].departement, etudiant[i].noteGenerale); 
    }
}

//float MG;
void calculerMoyenneEtudiant(){

    printf("le departement notes que vous shouitez calculer: ");
    scanf("%s", filiere);

    float sumfiliere=0; int countfiliere=0;
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
   // MG = Moyenne;
}


void Statistiques(){

        do{
        printf("\n-------------------------------------------------\n");
        printf("\n[1]--->Afficher le nombre total d etudiants inscrits\n");
        printf("[2]--->Afficher le nombre d etudiants dans chaque departement\n");
        printf("[3]--->Afficher les etudiants ayant une moyenne generale superieure a un certain seuil\n");
        printf("[4]--->Afficher les 3 etudiants ayant les meilleures notes.\n");
        printf("[5]--->Afficher le nombre d etudiants ayant reussi dans chaque departement\n");
        printf("[0]--->Quitter\n");
        printf("\n-------------------------------------------------\n");
        printf("Entrer votre choix: ");
        scanf("%d", &choix2);
        printf("Choix [%d]\n",choix2);
    } while (choix2 < 0 || choix2 > 5);

    if(choix2==1){

        printf("\nAffichage de nombre total d'etudiants inscrits\n");
        for(int i= 0; i<count;i++){
        }
        printf("\nle nombre d etudiants inscrit est %d\n", count);

    } else if (choix2==2){



    } else if(choix2==3){

    } else if(choix2==4){

    } else if(choix2==5){
        
    } else if(choix2==0){   
    } else {
        printf("choix invalide!\n");
    }

}


void rechercheEtudiant(){

    char rechEtu[100];

    printf("\nEntrer le nom de de letudiant que vous shouitez trouver\n: ");
    scanf("%s", rechEtu);

    for(int i=0; i<count;i++){
        if(strcmp(etudiant[i].nom, rechEtu)==0){
            printf("Letudiant trouve par son nom:  \n");
            printf("ID: %d | Nom: %s | Prenom: %s | Date de naissance: %d/%d/%d | Departement: %s | Note general: %.2f\n", etudiant[i].id, etudiant[i].nom, etudiant[i].prenom, etudiant[i].dateDeNaissance.jour, etudiant[i].dateDeNaissance.mois, etudiant[i].dateDeNaissance.annee, etudiant[i].departement, etudiant[i].noteGenerale); 
        }
    }

    printf("Entrer le departement que vous shouitez trouver: ");
    scanf("%s", filiere);

    for(int i=0; i<count;i++){
        if(strcmp(etudiant[i].departement, filiere)==0){
            printf("Les etudiants trouve par departement :  \n");
            printf("ID: %d | Nom: %s | Prenom: %s | Date de naissance: %d/%d/%d | Departement: %s | Note general: %.2f\n", etudiant[i].id, etudiant[i].nom, etudiant[i].prenom, etudiant[i].dateDeNaissance.jour, etudiant[i].dateDeNaissance.mois, etudiant[i].dateDeNaissance.annee, etudiant[i].departement, etudiant[i].noteGenerale); 
        }
    }
}

void TrierEtudiant(){

    etudiants tmp[100];

    do{
        printf("\n-------------------------------------------------\n");
        printf("\n[1]--->Tri par order alphabitique\n");
        printf("[2]--->Tri des etudiants par moyenne generale, du plus eleve au plus faible ou inversement\n");
        printf("[3]--->Tri des etudiants selon leur statut de reussite\n");
        printf("[0]--->Retour\n");
        printf("\n-------------------------------------------------\n");
        printf("Entrer votre choix: ");
        scanf("%d", &choix2);
        printf("Choix [%d]\n",choix2);
    } while (choix2 < 0 || choix2 > 3);

    if (choix2==1){

        do{
        printf("\n-------------------------------------------------\n");
        printf("\n[1]--->Tri par order alphabitique (A-Z)\n");
        printf("[2]--->Tri par order alphabitique (Z-A)\n");
        printf("[0]--->Retour\n");
        printf("\n-------------------------------------------------\n");
        printf("Entrer votre choix: ");
        scanf("%d", &choix2);
        printf("Choix [%d]\n",choix2);
    } while (choix2 < 0 || choix2 > 2);

        if(choix2==1){

        printf("Tri par order alphabitique (A-Z)");
        for(int i=0; i<count;i++){
            for(int j=i+1;j<count;j++){
            if(strcasecmp(etudiant[i].nom, etudiant[j].nom)>0){
                tmp[0] = etudiant[i];
                etudiant[i] = etudiant[j];
                etudiant[j] = tmp[0];
            }
        }
        printf("Tri croissant:\n %s\t\n",etudiant[i].nom);
        }

        } else if (choix2==2) {

        printf("Tri par order alphabitique (Z-A)\n");
        for(int i=0; i<count;i++){
            for(int j=i+1;j<count;j++){
            if(strcasecmp(etudiant[i].nom, etudiant[j].nom)<0){
                tmp[0] = etudiant[j];
                etudiant[j] = etudiant[i];
                etudiant[i] = tmp[0];
            }
        }
        printf("Tri decroissant:\n %s\t\n", etudiant[i].nom);
        }

        } else if (choix2==0) {
        } else{
            printf("choix invalide!\n");
        }


    } else if(choix2==2){

        do{
        printf("\n-------------------------------------------------\n");
        printf("[1]--->Tri des etudiants par moyenne generale, du elve au plus bas\n");
        printf("[2]--->Tri des etudiants par moyenne generale, du plus bas au elve\n");
        printf("[0]--->Retour\n");
        printf("\n-------------------------------------------------\n");
        printf("Entrer votre choix: ");
        scanf("%d", &choix2);
        printf("Choix [%d]\n",choix2);
    } while (choix2 < 0 || choix2 > 2);

        if(choix2==1){
            
        printf("\nTri des etudiants par moyenne generale elve au faible\n");
        for(int i=0; i<count;i++){
            for(int j=i+1;j<count;j++){
            if(etudiant[i].noteGenerale < etudiant[j].noteGenerale){
                tmp[0] = etudiant[i];
                etudiant[i] = etudiant[j];
                etudiant[j] = tmp[0];
            }
        }
        printf("moyenne generale de basse jusqu a elve: %.2f\t\n", etudiant[i].noteGenerale);
        }

        } else if (choix2==2) {

        printf("\nTri des etudiants par moyenne generale de faible jusqu au elve\n");
        for(int i=0; i<count;i++){
            for(int j=i+1;j<count;j++){
            if(etudiant[i].noteGenerale > etudiant[j].noteGenerale){
                tmp[0] = etudiant[i];
                etudiant[i] = etudiant[j];
                etudiant[j] = tmp[0];
            }
        }
        printf("moyenne generale de faible jusqu au elve: %.2f\t\n", etudiant[i].noteGenerale);
        }

        } else if (choix2==0) {
        } else{
            printf("choix invalide!\n");
        }

    } else if(choix2==3){
        
        printf("\nTri des etudiants selon leur statut de reussite\n");
        int reuissite=0;
        for(int i=0; i<count;i++){
            if(etudiant[i].noteGenerale >= 10 && etudiant[i].noteGenerale <=20)
                printf("\netudiant %s, %s a reussi avec: %.2f\t\n",etudiant[i].nom, etudiant[i].prenom, etudiant[i].noteGenerale);
        }
        
    } else if(choix2==0){   
    } else {
        printf("choix invalide!\n");
    }

}

/*
void TrierEtudiant(){
    
    etudiants tmp[100];

    do{
        printf("\n-------------------------------------------------\n");
        printf("\n[1]--->Tri par order alphabitique (A-Z)\n");
        printf("[2]--->Tri par order alphabitique (Z-A)\n");
        printf("[3]--->Tri des etudiants par moyenne generale\n");
        printf("[4]--->Tri des etudiants selon leur statut de reussite\n");
        printf("[0]--->Quitter\n");
        printf("\n-------------------------------------------------\n");
        printf("Entrer votre choix: ");
        scanf("%d", &choix2);
        printf("Choix [%d]\n",choix2);
    } while (choix2 < 0 || choix2 > 4);

    if (choix2 == 1){

    printf("Tri par order alphabitique (A-Z): ");
    for(int i=0; i<count;i++){
        for(int j=i+1;j<count;j++){
            if(strcasecmp(etudiant[i].nom, etudiant[j].nom)>0){
                tmp[0] = etudiant[i];
                etudiant[i] = etudiant[j];
                etudiant[j] = tmp[0];
            }
        }
        printf("Tri croissant:\n %s\t\n",etudiant[i].nom);
        }

    } else if (choix2 == 2){

    printf("Tri par order alphabitique (Z-A): \n");
    for(int i=0; i<count;i++){
        for(int j=i+1;j<count;j++){
            if(strcasecmp(etudiant[i].nom, etudiant[j].nom)<0){
                tmp[0] = etudiant[j];
                etudiant[j] = etudiant[i];
                etudiant[i] = tmp[0];
            }
        }
        printf("Tri decroissant:\n %s\t\n",etudiant[i].nom);
        }
    } else if (choix2 == 3){

    printf("\nTri des etudiants par moyenne generale elve et basse:\n");
    for(int i=0; i<count;i++){
        for(int j=i+1;j<count;j++){
            if(etudiant[i].noteGenerale < etudiant[j].noteGenerale){
                tmp[0] = etudiant[i];
                etudiant[i] = etudiant[j];
                etudiant[j] = tmp[0];
            }
        }
        printf("moyenne generale de basse jusqu a elve: %.2f\t\n", etudiant[i].noteGenerale);
        }


    printf("\nTri des etudiants par moyenne generale elve et basse:\n");
    for(int i=0; i<count;i++){
        for(int j=i+1;j<count;j++){
            if(etudiant[i].noteGenerale > etudiant[j].noteGenerale){
                tmp[0] = etudiant[i];
                etudiant[i] = etudiant[j];
                etudiant[j] = tmp[0];
            }
        }
        printf("moyenne generale de basse jusqu a elve: %.2f\t\n", etudiant[i].noteGenerale);
        }

    } else if (choix2 == 4){
        printf("\nTri des etudiants selon leur statut de reussite\n");
        int reuissite=0;
    for(int i=0; i<count;i++){
            if(etudiant[i].noteGenerale >= 10 && etudiant[i].noteGenerale <=20)
                printf("\netudiant %s, %s a reussi avec: %.2f\t\n",etudiant[i].nom, etudiant[i].prenom, etudiant[i].noteGenerale);
        }
    
    } else if (choix2 == 0){
    } else {
        printf("choix invalide!\n");
    }

}
*/