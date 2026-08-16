#include <stdio.h>
#include <stdlib.h>
#include "GESTION.h"

int main()
{
    Produit produits[MAX_PRODUITS];
    Client clients[MAX_CLIENTS];
    Vente ventes[MAX_VENTES];
    Fournisseur fournisseurs[MAX_FOURNISSEURS];
    Promotion promotions[MAX_PROMOTIONS];

    int nbProduits = 0;
    int nbClients = 0;
    int nbVentes = 0;
    int nbFournisseurs = 0;
    int nbPromotions = 0;

    menuPrincipal(clients, &nbClients,
                  produits, &nbProduits,
                  fournisseurs, &nbFournisseurs,
                  ventes, &nbVentes,
                  promotions, &nbPromotions);

    return 0;
}
