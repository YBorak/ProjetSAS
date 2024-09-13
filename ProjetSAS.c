#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int choix, choix2, nAfficher, temp, nbr;
int countPhysique=0, countMathinfo=0, countChimique=0, countBiologie=0;

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
etudiants tmp[50];


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

    do{
        printf("Departement d etudiant(physique, chimique, mathinfo, biologie): ");
        scanf("%s", etudiant[count].departement);
        if (strcasecmp(etudiant[count].departement, "physique") != 0 && strcasecmp(etudiant[count].departement, "chimique") && 0 || strcasecmp(etudiant[count].departement, "mathinfo") != 0 && strcasecmp(etudiant[count].departement, "biologie") != 0) {
        }

    } while (strcasecmp(etudiant[count].departement, "physique") != 0 && strcasecmp(etudiant[count].departement, "chimique") != 0 && strcasecmp(etudiant[count].departement, "mathinfo") != 0 && strcasecmp(etudiant[count].departement, "biologie") != 0); 
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
        printf("press ENTER key to continue...\n");
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
        printf("[0]--->Retour\n");
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
            scanf("%d/%d/%d", &etudiant[i].dateDeNaissance.jour, &etudiant[i].dateDeNaissance.mois, &etudiant[i].dateDeNaissance.annee);
            if (etudiant[i].dateDeNaissance.jour < 1 || etudiant[i].dateDeNaissance.jour > 31 || etudiant[i].dateDeNaissance.mois < 1 || etudiant[i].dateDeNaissance.mois > 12 || etudiant[i].dateDeNaissance.annee < 1924 || etudiant[i].dateDeNaissance.annee > 2006) {
                printf("incorrecte date de naissance, ressayer: \n");
            }
            } while (etudiant[i].dateDeNaissance.jour < 1 || etudiant[i].dateDeNaissance.jour > 31 || etudiant[i].dateDeNaissance.mois < 1 || etudiant[i].dateDeNaissance.mois > 12 || etudiant[i].dateDeNaissance.annee < 1924 || etudiant[i].dateDeNaissance.annee > 2006);
            
            do{
                
            printf("Departement d etudiant(physique, chimique, mathinfo, biologie): ");
            scanf("%s", etudiant[i].departement);
            if (strcasecmp(etudiant[i].departement, "physique") != 0 && strcasecmp(etudiant[i].departement, "chimique") && 0 || strcasecmp(etudiant[i].departement, "mathinfo") != 0 && strcasecmp(etudiant[i].departement, "biologie") != 0) {
            }

            } while (strcasecmp(etudiant[i].departement, "physique") != 0 && strcasecmp(etudiant[i].departement, "chimique") != 0 && strcasecmp(etudiant[i].departement, "mathinfo") != 0 && strcasecmp(etudiant[i].departement, "biologie") != 0); 
                printf("\n");

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
    printf("ID: %d | Nom: %s | Prenom: %s | Date de naissance: %d/%d/%d | Departement: %s | Note general: %.2f\n", 
    etudiant[i].id, 
    etudiant[i].nom, 
    etudiant[i].prenom, 
    etudiant[i].dateDeNaissance.jour, 
    etudiant[i].dateDeNaissance.mois, 
    etudiant[i].dateDeNaissance.annee, 
    etudiant[i].departement, 
    etudiant[i].noteGenerale); 
    }
}

void calculerMoyenneEtudiant(){


    printf("le departement notes que vous shouitez calculer: ");
    scanf("%s", filiere);

    float sumfiliere=0; int countfiliere=0;
    for(int i=0; i<count;i++){
        if(strcasecmp(etudiant[i].departement, filiere)==0){
            sumfiliere += etudiant[i].noteGenerale;
            countfiliere++;
        }
    }
        system("cls");
    printf("\nLa moyenne de departement %s entiere est %.2f\n",filiere, sumfiliere/countfiliere);
        printf("press ENTER key to continue...\n");
        getchar();
        getchar();

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

        printf("\nAffichage le nombre d etudiants dans chaque departement\n");      

        for(int i=0; i<count;i++){
        if(strcasecmp(etudiant[i].departement, "physique")==0){
            countPhysique++;
        } else if (strcasecmp(etudiant[i].departement, "mathinfo")==0){
            countMathinfo++;
        } else if (strcasecmp(etudiant[i].departement, "chimique")==0){
            countChimique++;
        } else if (strcasecmp(etudiant[i].departement, "biologie")==0){
            countBiologie++;
        }
    }
        printf("\nLe nombre d etudiant dans le departement physique sont %d\n" , countPhysique);
        printf("Le nombre d etudiant dans le departement mathinfo sont %d\n" , countMathinfo);
        printf("Le nombre d etudiant dans le departement chimique sont %d\n" , countChimique);
        printf("Le nombre d etudiant dans le departement biologie sont %d\n" , countBiologie);

    } else if(choix2==3){

        printf("\nAffichage les etudiants ayant une moyenne generale superieure a 16\n");      
        for(int i=0;i<count;i++){
            if(etudiant[i].noteGenerale >= 16){
                printf("\nl etudient %s %s a eu une moyenne generale de %.2f sur 20.\n", etudiant[i].nom, etudiant[i].prenom, etudiant[i].noteGenerale);
            }
        }

    } else if(choix2==4){

        printf("\nAffichage 3 etudiants ayant les meilleures notes.\n");      
        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
            if (etudiant[i].noteGenerale < etudiant[j].noteGenerale) {

            etudiants temp = etudiant[i];
            etudiant[i] = etudiant[j];
            etudiant[j] = temp;
            }
        }
        //for(int i=0;i<count && i<3;i++){
        printf("\nL'etudiant %s %s a eu une note de %.2f sur 20.\n", etudiant[i].nom, etudiant[i].prenom, etudiant[i].noteGenerale);
        //}
    }

    } else if(choix2==5){

        printf("\nAffichage le nombre d etudiants ayant reussi dans chaque departement note >= 10\n");      
        for(int i=0;i<count;i++){
            if(etudiant[i].noteGenerale >= 10){
                printf("\nl etudient %s %s de departement %s a eu une moyenne generale de %.2f sur 20.\n", etudiant[i].nom, etudiant[i].prenom,etudiant[i].departement, etudiant[i].noteGenerale);
            }
        }
    } else if(choix2==0){   
    } else {
        printf("choix invalide!\n");
    }

}


void rechercheEtudiant(){

    char rechEtu[100];

    do{
        printf("\n-------------------------------------------------\n");
        printf("[1]--->Rechercher un etudiant par son nom\n");
        printf("[2]--->Afficher la liste des etudiants inscrits dans un departement specifique\n");
        printf("[0]--->Retour\n");
        printf("\n-------------------------------------------------\n");
        printf("Entrer votre choix: ");
        scanf("%d", &choix2);
        printf("Choix [%d]\n",choix2);
    } while (choix2 < 0 || choix2 > 3);

    if(choix2==1){

    printf("\nEntrer le nom de de letudiant que vous shouitez trouver\n: ");
    scanf("%s", rechEtu);

    for(int i=0; i<count;i++){
        if(strcasecmp(etudiant[i].nom, rechEtu)==0){
            printf("\nL etudiant trouve par son nom:  \n");
            printf("ID: %d | Nom: %s | Prenom: %s | Date de naissance: %d/%d/%d | Departement: %s | Note general: %.2f\n", 
            etudiant[i].id, 
            etudiant[i].nom, 
            etudiant[i].prenom, 
            etudiant[i].dateDeNaissance.jour, 
            etudiant[i].dateDeNaissance.mois, 
            etudiant[i].dateDeNaissance.annee, 
            etudiant[i].departement, 
            etudiant[i].noteGenerale); 
        }
    }

    } else if(choix2==2){

    printf("\nEntrer le departement que vous shouitez trouver: ");
    scanf("%s", filiere);

    printf("\nLe departement que vous shouitez trouve:\n");
    for(int i=0; i<count;i++){
        if(strcasecmp(etudiant[i].departement, filiere)==0){
            printf("ID: %d | Nom: %s | Prenom: %s | Date de naissance: %d/%d/%d | Departement: %s | Note general: %.2f\n", 
            etudiant[i].id, 
            etudiant[i].nom, 
            etudiant[i].prenom, 
            etudiant[i].dateDeNaissance.jour, 
            etudiant[i].dateDeNaissance.mois, 
            etudiant[i].dateDeNaissance.annee, 
            etudiant[i].departement, 
            etudiant[i].noteGenerale); 
        }
    }
    } else if (choix2==3){
    } else{
        printf("choix invalide!\n");
    }
    
}

void TrierEtudiant(){

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

        printf("Tri par order alphabitique (A-Z)\n");
        for(int i=0; i<count;i++){
            for(int j=i+1;j<count;j++){
            if(strcasecmp(etudiant[i].nom, etudiant[j].nom)>0){
                etudiants temp = etudiant[i];
                etudiant[i] = etudiant[j];
                etudiant[j] = temp;
            }
        }
        printf("Etudiant: %s %s\n",etudiant[i].nom, etudiant[i].prenom);
        }
        main();

        } else if (choix2==2) {

        printf("Tri par order alphabitique (Z-A)\n");
        for(int i=0; i<count;i++){
            for(int j=i+1;j<count;j++){
            if(strcasecmp(etudiant[i].nom, etudiant[j].nom)<0){
                etudiants temp = etudiant[j];
                etudiant[j] = etudiant[i];
                etudiant[i] = temp;
            }
        }
        printf("Etudiant: %s %s\n",etudiant[i].nom, etudiant[i].prenom);
        }
        main();


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
                etudiants temp = etudiant[i];
                etudiant[i] = etudiant[j];
                etudiant[j] = temp;
            }
        }
        printf("la moyenne generale de %s %s est %.2f\t\n", etudiant[i].nom, etudiant[i].prenom, etudiant[i].noteGenerale);
        }

        } else if (choix2==2) {

        printf("\nTri des etudiants par moyenne generale de faible jusqu au elve\n");
        for(int i=0; i<count;i++){
            for(int j=i+1;j<count;j++){
            if(etudiant[i].noteGenerale > etudiant[j].noteGenerale){
                etudiants temp = etudiant[i];
                etudiant[i] = etudiant[j];
                etudiant[j] = temp;
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
                printf("\netudiant %s, %s a reussi avec: %.2f\t\n", etudiant[i].nom, etudiant[i].prenom, etudiant[i].noteGenerale);
        }
        
    } else if(choix2==0){   
    } else {
        printf("choix invalide!\n");
    }
}