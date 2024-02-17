 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ft_commun.h"
#include "Pharmacie.h"


 void intialisation_stock( med *stock ,int* nb_med  )
{
     char *temp[3];
     FILE* f = fopen("stock.txt", "r+");
    char line[100];
    while (fgets(line, sizeof(line), f) != NULL )
    {
         char *strToken = strtok(line, ",");
         int i = 0;
         while (strToken != NULL && i < 3 )
            {
                        temp[i] = strToken;
                        i++;
                        strToken = strtok(NULL, ",");
            }
                stock[*nb_med].code=atoi(temp[0]);
                strcpy(stock[*nb_med].nom,temp[1]);
                stock[*nb_med].quantite=atoi(temp[2]); //atoi sert à convertir une chaine en entier


                *nb_med = *nb_med + 1;
  }
}



  test verif_medicament ( med *stock ,int* nb_med , char nom[50])
  {   test medicament ;
      medicament.existe=0;
      stock[*nb_med].code= *nb_med +1;
      int i=0;
      while  (i<*nb_med && medicament.existe ==0 )
      {
          if (stricmp(nom,stock[i].nom)==0){
                                              medicament.existe=1;
                                              medicament.position=i;
                                              }
          else i++;
      }

       return medicament ;
  }
void fichierstock (med *stock ,int* nb_med ) {
    FILE* f = fopen("stock.txt","a");

        fprintf(f, "%d,%s,%d\n",
                stock[*nb_med].code,
                stock [*nb_med].nom,
                stock[*nb_med].quantite);

    fclose(f);
}
  void ajout_medicament ( med* stock ,int* nb_med)
  {     char nom[50];

        do{
        printf("Nom du mediacment : ");
        scanf("%s",nom);

        }while (verification_chaine(nom));

        test medi;
        medi=verif_medicament(stock,nb_med,nom);

        if (medi.existe == 0 ) {
                                 strcpy(stock[*nb_med].nom,nom);
                                do{ printf("la quantite: ");
                                    scanf("%d",&(stock[*nb_med].quantite));

                                  }while (stock[*nb_med].quantite<0);
                                  fichierstock (stock ,nb_med);
                                  (*nb_med)++;

                               }
      else printf("Le medicament existe deja");

  }

void Modifierfichiermed( med* stock ,int* nb_med)
{   int i;
    FILE* copie = fopen("stock.txt","w");
        for (i=0; i<*nb_med ;i++)
         fprintf(copie, "%d,%s,%d\n",
                stock[i].code,
                stock [i].nom,
                stock[i].quantite);
        fclose(copie);
        remove("stock.txt");
        rename("temp.txt", "stock.txt");

}

void modquantite  ( med* stock ,int* nb_med)
{     int nb ;
      char nom[50];
      do{
        printf("Nom du mediacment : ");
        scanf("%s",nom);
        }while (verification_chaine(nom));

        test medi;
        medi=verif_medicament(stock,nb_med,nom);
        char c ;
        if (medi.existe == 1) {
        do {printf("Pour ajouter taper + et pour retirez taper -");
            scanf("%c",&c);
        } while (c!='+' &&  c!='-');

        do{ printf("la quantite a ajouter ou à retirer  : ");
            scanf("%d",&nb);

                                  }while (nb<0);
         if (c=='+') stock[medi.position].quantite += nb;
         else stock[medi.position].quantite -= nb;

      Modifierfichiermed(stock ,nb_med);}
    else printf("Medicament Intouvable");

}
void chercher_med ( med* stock ,int* nb_med)
{

      char nom[50];
      do{
        printf("Nom du mediacment : ");
        scanf("%s",nom);
        }while (verification_chaine(nom));

        test medi;
        medi=verif_medicament(stock,nb_med,nom);

        if (medi.existe == 1) {
            printf( "Code medicament: %d \nNom commercial: %s \nQuantite en stock:  %d\n",
                stock[medi.position].code,
                stock[medi.position].nom,
                stock[medi.position].quantite);



      }
    else printf("Medicament Intouvable");
}

void liste_appro ( med* stock ,int* nb_med)
{   printf("\n             Liste des medicaments en rupture ou en carence \n \n");
    for (int i=0; i<*nb_med ;i++)

    {           if ( stock[i].quantite < 10 && stock[i].quantite >0 )
                printf( "Code medicament: %d | Nom commercial: %s  | Quantite en stock: %d  -> En carence \n",
                stock[i].code,
                stock[i].nom,
                stock[i].quantite);
                else if (stock[i].quantite==0)
                    printf( "Code medicament: %d | Nom commercial: %s | Quantite en stock: %d  -> En rupture \n",
                     stock[i].code,
                    stock[i].nom,
                stock[i].quantite);
    }
}
void GestionPharmacie()
{    int nb_med=0 ;
     med *stock= (med *)malloc(300 * sizeof(med));
     intialisation_stock(stock,&nb_med);
    int choix;
    do {
    printf("\n *********** GESTION PHARMACIE *********** \n ");
    printf("\n 1- Ajouter un medicament \n");
    printf("\n 2- Rechercher un medicament\n");
    printf("\n 3- Gerer le stock \n");
    printf("\n 4- Generer une liste des medicaments en rupture ou en carence \n");
    printf("\n 5- Quitter \n");


  do{
  printf(" \n Entrer un choix entre 1 et 5 : ");
  scanf("%d",&choix);
  }
  while (choix<0||choix>5);

  switch(choix)
  { case 1: system("cls");
            ajout_medicament(stock,&nb_med);

            break;
    case 2: system("cls");
            chercher_med(stock,&nb_med);
        break;
    case 3: system("cls");
            modquantite(stock,&nb_med);
            break;
    case 4: system("cls");
            liste_appro(stock,&nb_med);
            break;
    case 5: system("cls");
            break;
 }}
 while(choix != 5) ;

}




