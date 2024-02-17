#ifndef PHARMACIE_H_INCLUDED
#define PHARMACIE_H_INCLUDED
struct Med {
  int code;
  char nom[50];
  int quantite;
 };
  typedef struct Med med ;
  struct test_med
  {
      int existe ;
      int position;
  };

  typedef struct test_med test;

 void intialisation_stock( med *stock ,int* nb_med  );
  test verif_medicament ( med *stock ,int* nb_med , char nom[50]);
void fichierstock (med *stock ,int* nb_med ) ;
  void ajout_medicament ( med* stock ,int* nb_med);
void Modifierfichiermed( med* stock ,int* nb_med);
void modquantite  ( med* stock ,int* nb_med);
void chercher_med ( med* stock ,int* nb_med);
void liste_appro ( med* stock ,int* nb_med);
void GestionPharmacie();

#endif // PHARMACIE_H_INCLUDED
