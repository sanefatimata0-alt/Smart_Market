#ifndef GESTION_H_INCLUDED
#define GESTION_H_INCLUDED

#define MAX_PRODUITS 100
#define MAX_CLIENTS 100
#define MAX_VENTES 100
#define MAX_FOURNISSEURS 100
#define MAX_PROMOTIONS 100

// Produits
typedef struct
{
    int idProduit;
    char nom[50];
    float prix;
    int stock;
} Produit;

// Clients
typedef struct
{
    int idClient;
    char nom[50];
    char adresse[100];
    char telephone[20];
} Client;

// Fournisseurs
typedef struct
{
    int idFournisseur;
    char nom[50];
    char contact[9];
} Fournisseur;

// Ventes
typedef struct
{
    int idVente;
    int idProduit;
    int idClient;
    int quantite;
    float montant;
} Vente;

// Promotions
typedef struct
{
    int idPromo;
    char type[30];
    float reduction;
    char dateDebut[20];
    char dateFin[20];
} Promotion;


//MENU

void menuPrincipal(Client clients[], int *nbClients,
                   Produit produits[], int *nbProduits,
                   Fournisseur fournisseurs[], int *nbFournisseurs,
                   Vente ventes[], int *nbVentes,
                   Promotion promotions[], int *nbPromotions);


//PRODUITS

void ajouterProduit(Produit produits[], int *nbProduits);
void afficherProduits(Produit produits[], int *nbProduits);
void produitAvecStockMax(Produit produits[], int *nbProduits);
void moyennePrixProduits(Produit produits[], int *nbProduits);

int rechercherProduit(Produit produits[], int nbProduits, int idProduit);
int idProduitExiste(Produit produits[], int nbProduits, int idProduit);

//CLIENTS

void ajouterClient(Client clients[], int *nbClients);
void afficherClients(Client clients[], int *nbClients);
void nombreTotalClients(int *nbClients);

int rechercherClient(Client clients[], int nbClients, int idClient);
int idClientExiste(Client clients[], int nbClients, int idClient);


//FOURNISSEURS

void ajouterFournisseur(Fournisseur fournisseurs[], int *nbFournisseurs);
void afficherFournisseurs(Fournisseur fournisseurs[], int *nbFournisseurs);
void nombreTotalFournisseurs(int *nbFournisseurs);


//VENTES

void enregistrerVente(Vente ventes[], int *nbVentes,
                      Produit produits[], int nbProduits,
                      Client clients[], int nbClients);

void afficherVentes(Vente ventes[], int *nbVentes);
void calculerChiffreAffaires(Vente ventes[], int *nbVentes);
void venteMaxMontant(Vente ventes[], int *nbVentes);
void moyenneMontantVentes(Vente ventes[], int *nbVentes);
void totalQuantiteVendue(Vente ventes[], int *nbVentes);


//PROMOTIONS

void ajouterPromotion(Promotion promotions[], int *nbPromotions);
void afficherPromotions(Promotion promotions[], int *nbPromotions);
void promotionMaxReduction(Promotion promotions[], int *nbPromotions);
void nombreTotalPromotions(int *nbPromotions);

int rechercherProduit(Produit produits[], int nbProduits, int idProduit);
int rechercherClient(Client clients[], int nbClients, int idClient);
int verifierDate(char date[]);

#endif
