#include "Patient.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int isNum(char s[])
{ int i=0 , num = 1  ;
    while( s[i]!= '\0' && num ==1 )
    {
        if (!(s[i]>='0'&&s[i]<='9'))
        {
            num=0 ;
        }
        i++ ;
    }
    return num ;
}



int isChar(char s[])
{ int i=0 , num = 1  ;
    while( s[i]!= '\0' && num ==1 )
    {
        if (!(toupper(s[i])>='A'&&toupper(s[i])<='Z'))
        {
            num=0 ;
        }
        i++ ;
    }
    return num ;
}





//lire un patient a partir du clavier

Patient* PatientRead()
{   Patient *p ;
        p= (Patient*)malloc(sizeof(Patient));
        do {
        printf("entrer le nom du patient \n") ;
        scanf("%s",p->Lname) ;
        }while(!isChar(p->Lname) || strlen(p->Lname)<=3) ;

        do {
        printf("entrer le prenom du patient \n") ;
        scanf("%s",p->Fname) ;
        }while(!isChar(p->Fname) || strlen(p->Fname)<3) ;
        do {
            printf("entrer le N°CIN du patient \n") ;
            scanf("%s",p->CIN) ;
            if(strlen(p->CIN)<8 || strlen(p->CIN)>8)
                {
                    printf("Merci d'entrer un N°CIN Valide ") ;

                }
        }while(!isNum(p->CIN) || (strlen(p->CIN)!=8) ) ;
        do {
        printf("entrer le N°TEL du patient \n") ;
        scanf("%s",p->Tel) ;
             if(strlen(p->Tel)<8)
                {
                    printf("Merci d'entrer un N°TEL Valide ") ;

                }
        }while(!isNum(p->Tel) || strlen(p->Tel)<8 ) ;
    return p  ;

}



// procedure qui permet d'afficher un patient

void PatientPrint(Patient p)
{
    printf("\n\n nom du patient : %s  %s \n CIN :  %s \n  TEL  :  %s \n",p.Fname , p.Lname , p.CIN , p.Tel) ;
}


// fonction d'enregistrement d'un patient dans un fichier Texte
int enregistrerPatients(Patient *p)
{   FILE *fichier;

    fichier = fopen("C:\\Users\\rayen\\Desktop\\C project Managment\\patients.txt","a");
    fprintf(fichier, "%s , %s , %s , %s \n",p->Fname , p->Lname , p->CIN , p->Tel);
    fclose(fichier);
    return 1 ;
}



int patientComparer(Patient *p1 , Patient *p2)
{
    if(p1==p2)
    {
        return 1 ;
    }
    else {
            printf(" \n %s , %s \n ", p1->CIN,p2->CIN ) ;
        if ( strcmp(p1->CIN,p2->CIN)==0 )
            {
                return 1 ;
            }
            else return 0 ;
    }

}






// destruction d'une structure patient


void PatientDestruction(Patient *p )
{
    free(p) ;
}




/* -------------------------------------Fin des fonctions du patient ------------------------------------------  */





/* fonctions des noeuds  */


// Creation d'une Noeud
NOEUD noeudCreer(Patient *p){
    NOEUD n;
    n =(NOEUD)malloc(sizeof(structNoeud));
    if(!n)
        printf ("\n Plus d'espace : Creation impossible");
    else
    {
    n->patient = p ;
    n->suivant = NULL;
     n->precedent = NULL;
    }
    return n;
}

// declation du code pour la destruction d'une noeud et du liste

void  DestructionNoeud(NOEUD n )
{
    PatientDestruction(n->patient) ;
    free(n) ;
}








/*fin des fonctions des noeuds   */







 /*------------------------------------- les fonctions de base de la structure liste :   ------------------- */


// creer une liste

List ListCreate()
{
    List L;
    L = (List)malloc(sizeof(structListe)); // Change this line
    if (!L)
        printf("\nProblème de mémoire");
    else {
        L->length = 0;
        L->head = NULL;
        L->tail = NULL;
    }
    return (L);
}

// fonction qui verifie si une liste est vide

int EstVide(List l)
{
    if(l->length==0)
    {   return 1 ;
        }
        return 0 ;
}


// procedure qui affiche le contenue d'une liste complete :

void ListeAfficher(List l)
{ NOEUD n ;
    n = l->head ;
    if (EstVide(l))
    {
        printf("Liste Vide ") ;
    }
    else {
            if(l->length==1)
            {
                    PatientPrint(*n->patient) ;
            }
            else {
                     while(n)
                        {
                            PatientPrint(*n->patient) ;
                            n=n->suivant ;

                        }
                }
        }



}





void listeDestruction(List l)
{
    int i;
    NOEUD p, q;
    q= l->head;
    for(i = 1;i <= l->length; i++)
        {
            p=q;
            q=q->suivant;
            DestructionNoeud(p);
        }
    free(l) ;
}



// fonction qui verifie la presence d'un patient dans la liste :

int ExistePat(Patient *p, List l )
{    NOEUD n ;
    if (EstVide(l))
    {
        printf("la liste est vide merci d'ajouter des patients a votre base de données ! ") ;
        return 0 ;
    }
    else {
        n=l->head ;
        while (n!= NULL )
        {
            if(patientComparer(n->patient,p)==1)
            {
                printf("\n patient Existe \n ") ;
                return 1 ;
            }
            else {
                n=n->suivant ;
            }

        }
        return 0 ;


    }

}

// fonction qui verifie la presence d'un patient dans la liste Avec  la CIN  :

NOEUD CherchCinPat(char Cin[9], List l )
{    NOEUD n ;
    if (EstVide(l))
    {
        printf(" \n la liste est vide merci d'ajouter des patients a votre base de données ! \n ") ;
        return NULL ;
    }
    else {
        n=l->head ;
        while (n!= NULL )
        {
            if(strcmp(n->patient->CIN,Cin)==0)
            {
                return n ;
            }
            else {
                n=n->suivant ;
            }

        }
        return NULL ;


    }

}
void CherchTelPat(char Tel[9], List l )
{    NOEUD n ;
    if (EstVide(l))
    {
        printf(" \n la liste est vide merci d'ajouter des patients a votre base de données ! \n ") ;
    }
    else {
        n=l->head ;
        while (n!= NULL )
        {
            if(strcmp(n->patient->Tel,Tel)==0)
            {
                PatientPrint(*n->patient) ;
            }
           n=n->suivant ;

        }


    }

}
void CherchNomPat(char Nom[30], List l )
{    NOEUD n ;
    if (EstVide(l))
    {
        printf(" \n la liste est vide merci d'ajouter des patients a votre base de données ! \n ") ;
    }
    else {
        n=l->head ;
        while (n!= NULL )
        {
            if(strcmp(n->patient->Lname,Nom)==0)
            {
                PatientPrint(*n->patient) ;
            }
            n=n->suivant ;

        }


    }

}
void CherchPrenomPat(char Prenom[30], List l )
{    NOEUD n ;
    if (EstVide(l))
    {
        printf(" \n la liste est vide merci d'ajouter des patients a votre base de données ! \n ") ;
    }
    else {
        n=l->head ;
        while (n!= NULL )
        {
            if(strcmp(n->patient->Fname,Prenom)==0)
            {
                PatientPrint(*n->patient) ;
            }
                n=n->suivant ;

        }


    }

}

NOEUD CherchPatient (Patient *p,List l)
{
    NOEUD n ;

    if(!ExistePat(p,l))
    {

        n= NULL ;
    }
    else {
        n=l->head ;
              while (n!= NULL )
        {
            if(patientComparer(n->patient,p)==1)
            {
                return n ;
            }
            else {
                n=n->suivant ;
            }

        }


    }
return n ;

}

void AffichePatientAvecCin(char cin[9] , List l )
{
    NOEUD n ;
    n = CherchCinPat(cin,l) ;
    if(!n)
    {
        printf("\n Cin introuvable ! \n ") ;
    }
    else
    {
        PatientPrint(*n->patient) ;

    }

}

int EnregistrerListeEnFichier(List l )
{   NOEUD n ;
    if(EstVide(l))
    {
    printf(" \n  La Liste est vide ! \n ") ;
        return 0 ;
    }
    n = l->head ;
    remove("patients.txt") ;
    FILE *fichier ;
    fichier= fopen("C:\\Users\\rayen\\Desktop\\C project Managment\\patients.txt","a");
    while(n!=NULL)
    {
    fprintf(fichier, "%s , %s , %s , %s \n",n->patient->Fname , n->patient->Lname , n->patient->CIN , n->patient->Tel);
    n=n->suivant ;

    }

    fclose(fichier);
    return 1 ;
}

int ModifCinPatient(char OldCin [9],char NewCin[9],List l )
{   NOEUD n ;
    n = CherchCinPat(OldCin,l);
    if (EstVide(l))
    {
        printf("\n La liste est vide : modification impossible \n ") ;
        return 0 ;
    }
    if(!n)
    {

    printf(" \n Cin introuvable !! \n ") ;
    return 0 ;
    }
    else
    {
       strcpy(n->patient->CIN,NewCin);
       EnregistrerListeEnFichier(l) ;
       return 1 ;

    }



}

void modifNomPatient(List l , char cin [9],char newNom[30])
{
    NOEUD n ;
    n= CherchCinPat(cin,l) ;
    if (!n)
    {

        printf("Patient Introuvable") ;
    }
    else {
        strcpy(n->patient->Lname,newNom) ;
        EnregistrerListeEnFichier(l) ;

    }

}
void modifPrenomPatient(List l , char cin [9],char newPrenom[30])
{
    NOEUD n ;
    n= CherchCinPat(cin,l) ;
    if (!n)
    {

        printf("Patient Introuvable") ;
    }
    else {
        strcpy(n->patient->Fname,newPrenom) ;
        EnregistrerListeEnFichier(l) ;

    }

}
void modifTelPatient(List l , char cin [9],char NewTel[30])
{
    NOEUD n ;
    n= CherchCinPat(cin,l) ;
    if (!n)
    {

        printf("Patient Introuvable") ;
    }
    else {
        strcpy(n->patient->Tel,NewTel) ;
        EnregistrerListeEnFichier(l) ;

    }

}

/*-------------------------------  fin des fonction de la liste ----------------------- */



// Ajout d'un patient dans une liste doublement chainé
int AddPatient(Patient *p, List l)
{
    NOEUD n;
    n = noeudCreer(p);
    if (!n)
    {
        printf("\n Ajout impossible: memoire insuffisante ! \n");
        return 0;
    }
    else
    {
        if(l->length==0)
        {
            l->head = n ;
            l->tail = n;
            l->length++  ;

            return 1 ;
        }
        else // AJOUT A VERIFIER A CETTE  PARTIE DU CODE !!!!!!!!!!!!!! WARNING
            {   n->precedent = l->tail;
                l->tail->suivant = n;
                l->tail=n ;
                l->length++ ;
                return 1 ;

            }

        return 0 ;
    }
}


List LireFichier()
{
    List l ;
    FILE *fichier ;
    Patient *p ;
    p= (Patient*)malloc(sizeof(Patient));
    l = ListCreate() ;
    fichier= fopen("C:\\Users\\rayen\\Desktop\\C project Managment\\patients.txt","r");
    while(fscanf(fichier, "%s , %s , %s , %s ", p->Fname, p->Lname, p->CIN , p->Tel) == 4)
    {
        AddPatient(p,l) ;
        p= (Patient*)malloc(sizeof(Patient));


    }
    fclose(fichier) ;
    return l ;

}


// fonction qui supprime un patient de la liste :

int SupprListe(List l ,char Cin[] )
{
    NOEUD n ;
    n = l->head ;
    if (strcmp(n->patient->CIN, Cin) == 0)
    {
        l->head = n->suivant;
        DestructionNoeud(n) ;
        l->length--;
        EnregistrerListeEnFichier(l) ;
        return 1 ;
    }
    else {
        while(n)
        {    n= n->suivant;
            if (strcmp(n->patient->CIN, Cin) == 0)
            {
                n->precedent->suivant = n->suivant ;
                DestructionNoeud(n) ;
                l->length-- ;
                EnregistrerListeEnFichier(l) ;
                return 1 ;
            }

        }
    }

    return 0 ;
}


void menuModificationPatient(List l)
{   int choix ;
    char nom [30] ;
    char prenom [30] ;
    char oldcin [9] ;
    char newcin [9] ;
    char tel[9] ;
    system("cls") ;
    printf("1-modifier Nom : \n") ;
    printf("2-modifier prenom  \n") ;
    printf("3-modifier Cin \n") ;
    printf("4-modifier TEL \n") ;
    scanf("%i",&choix) ;

    switch(choix)
    {
    case 1 :
        printf("entrer Cin du patient a modifier") ;
        scanf("%s",oldcin) ;
        printf("entrer le nouveau nom du patient") ;
        scanf("%s",nom) ;
        modifNomPatient(l,oldcin,nom) ;
        break ;
    case 2 :
        printf("entrer Cin du patient a modifier") ;
        scanf("%s",oldcin) ;
        printf("entrer le nouveau prenom du patient") ;
        scanf("%s",prenom) ;
        modifPrenomPatient(l,oldcin,prenom) ;
        break ;
    case 3 :
        printf("entrer Cin du patient a modifier") ;
        scanf("%s",oldcin) ;
        printf("entrer le nouveau N-CIN du patient") ;
        scanf("%s",newcin) ;
        ModifCinPatient(oldcin,newcin,l) ;
        break ;
        case 4 :
        printf("entrer Cin du patient a modifier") ;
        scanf("%s",oldcin) ;
        printf("entrer le nouveau N-TEL du patient") ;
        scanf("%s",tel) ;
        modifTelPatient(l,oldcin,tel) ;
        break ;

    }

}
void menuRecherchePatient(List l)
{   int choix ;
    char nom [30] ;
    char prenom [30] ;
    char cin [9] ;
    char tel[9] ;
    system("cls") ;
    printf("1-recherche Avec Nom : \n") ;
    printf("2-recherche avec prenom  \n") ;
    printf("3-recherche avec Cin \n") ;
    printf("3-recherche avec Tel \n") ;


    scanf("%i",&choix) ;

    switch(choix)
    {
    case 1 :
        printf("entrer le nom du patient : ") ;
        scanf("%s",nom) ;
        CherchNomPat(nom,l) ;
        break ;
    case 2 :
        printf("entrer le  prenom du patient : ") ;
        scanf("%s",prenom) ;
        CherchPrenomPat(prenom,l) ;
        break ;
    case 3 :
        printf("entrer le  N-CIN du patient : ") ;
        scanf("%s",cin) ;
        CherchCinPat(cin,l) ;
        break ;
        case 4 :
        printf("entrer le  N-TEL du patient : ") ;
        scanf("%s",tel) ;
        CherchTelPat(tel,l) ;
        break ;

    }

}
void GestionPatient()
{
    int choix;
        Patient *p ;
    List l ;
    l = ListCreate() ;
    l = LireFichier() ;
    char cin [9] ;
    system("cls");
    do {




    printf(" \n **********************\n");
    printf("* Gestion des Patients *\n");
    printf(" **********************\n\n");

    printf("1. Ajouter un Patient\n \n");
    printf("2. Afficher Tous les Patients\n\n");
    printf("3. Supprimer un Patient\n\n");
    printf("4. Modifier un Patient\n\n");
    printf("5. Chercher un Patient\n\n");
    printf("6. Quitter\n\n");

    printf("Entrez votre choix : \n");
    scanf("%i", &choix);


    switch(choix)
        {
        case 1 :
            p =(Patient*)malloc(sizeof(Patient));
            p = PatientRead() ;
            AddPatient(p,l) ;
            EnregistrerListeEnFichier(l) ;
            break  ;
        case 2 :
            ListeAfficher(l)  ;
            break ;
        case 3 :
            printf("entrer CIN du Patient A supprimer ") ;
            scanf("%s",cin) ;
            ListeAfficher(l) ;
            SupprListe(l,cin);
            break ;
        case 4 :menuModificationPatient(l) ;
            break ;

        case 5 :
            menuRecherchePatient(l) ;
            break ;
        }
        }while(choix!=6) ;
}
