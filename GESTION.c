#include <stdio.h>
#include <string.h>
#include "GESTION.h"


void menuPrincipal(Client clients[], int *nbClients,
                   Produit produits[], int *nbProduits,
                   Fournisseur fournisseurs[], int *nbFournisseurs,
                   Vente ventes[], int *nbVentes,
                   Promotion promotions[], int *nbPromotions)
{

    int choix;
    do
    {
        printf("\n============= SMARTMARKET =============\n\n\n");
        printf("==== PRODUITS ====\n\n");
        printf("1. Ajouter un produit\n");
        printf("2. Afficher les produits\n");
        printf("3. Produit avec stock max\n");
        printf("4. Prix moyen des produits\n");

        printf("\n==== CLIENTS ====\n\n");
        printf("5. Ajouter un client\n");
        printf("6. Afficher les clients\n");
        printf("7. Nombre total de clients\n");

        printf("\n==== FOURNISSEURS ====\n\n");
        printf("8. Ajouter un fournisseur\n");
        printf("9. Afficher les fournisseurs\n");
        printf("10. Nombre total de fournisseurs\n");

        printf("\n==== PROMOTION ====\n\n");
        printf("11. Ajouter une promotion\n");
        printf("12. Afficher les promotions\n");
        printf("13. Promotion avec réduction max\n");
        printf("14. Nombre total de promotions\n");

        printf("\n==== VENTES ====\n\n");
        printf("15. Enregistrer une vente\n");
        printf("16. Afficher les ventes\n");
        printf("17. Calculer le chiffre d'affaires\n");
        printf("18. Vente avec montant max\n");
        printf("19. Montant moyen des ventes\n");
        printf("20. Quantite totale vendue\n");

        printf("\n0. Quitter\n");
        printf("\n\nVotre choix : ");
        scanf("%d", &choix);
        getchar();

        switch (choix)
        {
        case 1:
            ajouterProduit(produits, nbProduits);
            break;
        case 2:
            afficherProduits(produits, nbProduits);
            break;
        case 3:
            produitAvecStockMax(produits, nbProduits);
            break;
        case 4:
            moyennePrixProduits(produits, nbProduits);
            break;

        case 5:
            ajouterClient(clients, nbClients);
            break;
        case 6:
            afficherClients(clients, nbClients);
            break;
        case 7:
            nombreTotalClients(nbClients);
            break;

        case 8:
            ajouterFournisseur(fournisseurs, nbFournisseurs);
            break;
        case 9:
            afficherFournisseurs(fournisseurs, nbFournisseurs);
            break;
        case 10:
            nombreTotalFournisseurs(nbFournisseurs);
            break;

        case 11:
            ajouterPromotion(promotions, nbPromotions);
            break;
        case 12:
            afficherPromotions(promotions, nbPromotions);
            break;
        case 13:
            promotionMaxReduction(promotions, nbPromotions);
            break;
        case 14:
            nombreTotalPromotions(nbPromotions);
            break;

        case 15:
            enregistrerVente(ventes, nbVentes,produits, *nbProduits,clients, *nbClients);
            break;
        case 16:
            afficherVentes(ventes, nbVentes);
            break;
        case 17:
            calculerChiffreAffaires(ventes, nbVentes);
            break;
        case 18:
            venteMaxMontant(ventes, nbVentes);
            break;
        case 19:
            moyenneMontantVentes(ventes, nbVentes);
            break;
        case 20:
            totalQuantiteVendue(ventes, nbVentes);
            break;

        case 0:
            printf("\nFermeture du programme SmartMarket...\n");
            break;
        default:
            printf("\nChoix invalide, veuillez réessayer.\n");
        }
    }
    while (choix != 0);
}


int rechercherProduit(Produit produits[], int nbProduits, int idProduit)
{
    for(int i=0; i<nbProduits; i++)
    {
        if(produits[i].idProduit==idProduit)
            return i;
    }

    return -1;
}

int rechercherClient(Client clients[], int nbClients, int idClient)
{
    for(int i=0; i<nbClients; i++)
    {
        if(clients[i].idClient==idClient)
            return i;
    }

    return -1;
}


//PRODUITS
void ajouterProduit(Produit produits[], int *nbProduits)
{
    Produit p;
    if(*nbProduits>=MAX_PRODUITS)
    {
        printf("Tableau des produits plein.\n");
        return;
    }
    printf("\n--- Ajouter un produit ---\n");
    printf("ID : ");
    scanf("%d", &p.idProduit);
    getchar();
    for(int i=0; i<*nbProduits; i++)
    {
        if(produits[i].idProduit==p.idProduit)
        {
            printf("ID déjà existant.\n");
            return;
        }
    }
    printf("Nom : ");
    fgets(p.nom, 50, stdin);
    p.nom[strcspn(p.nom, "\n")] = '\0';
    printf("Prix : ");
    scanf("%f", &p.prix);
    printf("Stock : ");
    scanf("%d", &p.stock);

    produits[(*nbProduits)++] = p;
    printf("Produit ajouté avec succès !\n");
}

void afficherProduits(Produit produits[], int *nbProduits)
{
    printf("\n--- Liste des produits ---\n");
    printf("%-5s %-30s %-20s %-8s\n",
           "ID",
           "NOM",
           "PRIX",
           "STOCK");
           printf("=======================================================================\n\n");
    for (int i = 0; i < *nbProduits; i++)
    {
        printf("%-5d %-30s %-20d %-8d\n",
               produits[i].idProduit, produits[i].nom,
               produits[i].prix, produits[i].stock);
    }
}

void produitAvecStockMax(Produit produits[], int *nbProduits)
{
    if (*nbProduits == 0)
    {
        printf("Aucun produit.\n");
        return;
    }
    Produit max = produits[0];
    for (int i = 1; i < *nbProduits; i++)
    {
        if (produits[i].stock > max.stock) max = produits[i];
    }
    printf("Stock max: %s (%d)\n", max.nom, max.stock);
}

void moyennePrixProduits(Produit produits[], int *nbProduits)
{
    if (*nbProduits == 0)
    {
        printf("Aucun produit.\n");
        return;
    }
    float somme = 0;
    for (int i = 0; i < *nbProduits; i++) somme += produits[i].prix;
    printf("Prix moyen: %.2f\n", somme / *nbProduits);
}

//CLIENTS
void ajouterClient(Client clients[], int *nbClients)
{
    Client c;
    if(*nbClients>=MAX_CLIENTS)
    {
        printf("Tableau des clients plein.\n");
        return;
    }
    printf("\n--- Ajouter un client ---\n");
    printf("ID : ");
    scanf("%d", &c.idClient);
    getchar();
    for(int i=0; i<*nbClients; i++)
    {
        if(clients[i].idClient==c.idClient)
        {
            printf("ID déjà existant.\n");
            return;
        }
    }
    printf("Nom : ");
    fgets(c.nom, 50, stdin);
    c.nom[strcspn(c.nom, "\n")] = '\0';
    printf("Adresse : ");
    fgets(c.adresse, 100, stdin);
    c.adresse[strcspn(c.adresse, "\n")] = '\0';
    printf("Téléphone : ");
    fgets(c.telephone, 20, stdin);
    c.telephone[strcspn(c.telephone, "\n")] = '\0';

    clients[(*nbClients)++] = c;
    printf("Client ajouté avec succès !\n");

}

void afficherClients(Client clients[], int *nbClients)
{
    printf("\n--- Liste des clients ---\n");
    printf("%-5s %-30s %-20s %-8s\n",
           "ID",
           "NOM",
           "ADRESSE",
           "TELEPHONE");
           printf("=======================================================================\n\n");
    for (int i = 0; i < *nbClients; i++)
    {
        printf("%-5d %-30s %-20s %-8s\n",
               clients[i].idClient, clients[i].nom,
               clients[i].adresse, clients[i].telephone);
    }
}

void nombreTotalClients(int *nbClients)
{
    printf("Nombre total de clients: %d\n", *nbClients);
}

//FOURNISSEURS
void ajouterFournisseur(Fournisseur fournisseurs[], int *nbFournisseurs)
{
    Fournisseur f;
    if(*nbFournisseurs>=MAX_FOURNISSEURS)
    {
        printf("Tableau plein.\n");
        return;
    }
    printf("\n--- Ajouter un fournisseur ---\n");
    printf("ID : ");
    scanf("%d", &f.idFournisseur);
    getchar();
    printf("Nom : ");
    fgets(f.nom, 50, stdin);
    f.nom[strcspn(f.nom, "\n")] = '\0';
    printf("Contact : ");
    fgets(f.contact, 50, stdin);
    f.contact[strcspn(f.contact, "\n")] = '\0';

    fournisseurs[(*nbFournisseurs)++] = f;
    printf("Fournisseur ajouté avec succès !\n");
}

void afficherFournisseurs(Fournisseur fournisseurs[], int *nbFournisseurs)
{
    printf("\n--- Liste des fournisseurs ---\n");
    printf("%-5s %-30s %-20s\n",
           "ID",
           "NOM",
           "CONTACT");
           printf("=============================================================\n\n");
    for (int i = 0; i < *nbFournisseurs; i++)
    {
        printf("%-5d %-30s %-20s\n",
               fournisseurs[i].idFournisseur, fournisseurs[i].nom,
               fournisseurs[i].contact);
    }
}

void nombreTotalFournisseurs(int *nbFournisseurs)
{
    printf("Nombre total de fournisseurs: %d\n", *nbFournisseurs);
}

//VENTES
void enregistrerVente(Vente ventes[], int *nbVentes,
                      Produit produits[], int nbProduits,
                      Client clients[], int nbClients)
{
    Vente v;

    int indiceProduit;
    int indiceClient;

    printf("ID Vente : ");
    scanf("%d",&v.idVente);

    printf("ID Produit : ");
    scanf("%d",&v.idProduit);

    indiceProduit=rechercherProduit(produits,nbProduits,v.idProduit);

    if(indiceProduit==-1)
    {
        printf("Produit introuvable.\n");
        return;
    }

    printf("ID Client : ");
    scanf("%d",&v.idClient);

    indiceClient=rechercherClient(clients,nbClients,v.idClient);

    if(indiceClient==-1)
    {
        printf("Client introuvable.\n");
        return;
    }

    printf("Quantité : ");
    scanf("%d",&v.quantite);

    if(v.quantite>produits[indiceProduit].stock)
    {
        printf("Stock insuffisant.\n");
        return;
    }

    produits[indiceProduit].stock-=v.quantite;

    v.montant=v.quantite*produits[indiceProduit].prix;

    ventes[(*nbVentes)++]=v;

    printf("Vente enregistrée.\n");
}

void afficherVentes(Vente ventes[], int *nbVentes)
{
    printf("\n--- Liste des ventes ---\n");
    printf("%-5s %-30s %-20s %-8s\n",
           "ID VENTE",
           "ID PRODUIT",
           "ID CLIENT",
           "QUANTITE",
           "MONTANT");
           printf("=============================================================\n\n");
    for (int i = 0; i < *nbVentes; i++)
    {
        printf("%-5d %-30s %-20d %-8d %-15d\n",
               ventes[i].idVente, ventes[i].idProduit,
               ventes[i].idClient, ventes[i].quantite, ventes[i].montant);
    }
}

void calculerChiffreAffaires(Vente ventes[], int *nbVentes)
{
    float total = 0;
    for (int i = 0; i < *nbVentes; i++)
    {
        total += ventes[i].montant;
    }
    printf("\nChiffre d'affaires total : %.2f\n", total);
}

void venteMaxMontant(Vente ventes[], int *nbVentes)
{
    if (*nbVentes == 0)
    {
        printf("Aucune vente.\n");
        return;
    }
    Vente max = ventes[0];
    for (int i = 1; i < *nbVentes; i++)
    {
        if (ventes[i].montant > max.montant) max = ventes[i];
    }
    printf("Vente max: ID %d | Montant: %.2f\n", max.idVente, max.montant);
}

void moyenneMontantVentes(Vente ventes[], int *nbVentes)
{
    if (*nbVentes == 0)
    {
        printf("Aucune vente.\n");
        return;
    }
    float somme = 0;
    for (int i = 0; i < *nbVentes; i++) somme += ventes[i].montant;
    printf("Montant moyen des ventes: %.2f\n", somme / *nbVentes);
}

void totalQuantiteVendue(Vente ventes[], int *nbVentes)
{
    if (*nbVentes == 0)
    {
        printf("Aucune vente.\n");
        return;
    }
    int total = 0;
    for (int i = 0; i < *nbVentes; i++) total += ventes[i].quantite;
    printf("Quantité totale vendue: %d\n", total);
}

//PROMOTIONS

int verifierDate(char date[])
{
    int jour, mois, annee;

    if(sscanf(date, "%d/%d/%d", &jour, &mois, &annee) != 3)
        return 0;

    if(annee < 2000 || annee > 2100)
        return 0;

    if(mois < 1 || mois > 12)
        return 0;

    if(jour < 1)
        return 0;

    switch(mois)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        if(jour > 30)
            return 0;
        break;

    case 2:
        if((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0))
        {
            if(jour > 29)
                return 0;
        }
        else
        {
            if(jour > 28)
                return 0;
        }
        break;

    default:
        if(jour > 31)
            return 0;
    }

    return 1;
}

void ajouterPromotion(Promotion promotions[], int *nbPromotions)
{
    Promotion p;
    if(*nbPromotions>=MAX_PROMOTIONS)
    {
        printf("Tableau plein.\n");
        return;
    }
    printf("\n--- Ajouter une promotion ---\n");
    printf("ID : ");
    scanf("%d", &p.idPromo);
    getchar();
    printf("Type : ");
    fgets(p.type, 30, stdin);
    p.type[strcspn(p.type, "\n")] = '\0';
    printf("Réduction (%%) : ");
    scanf("%f", &p.reduction);
    getchar();
    do
    {
        printf("Date début (JJ/MM/AAAA) : ");
        fgets(p.dateDebut,20,stdin);
        p.dateDebut[strcspn(p.dateDebut,"\n")] = '\0';

        if(!verifierDate(p.dateDebut))
            printf("Date invalide !\n");

    }
    while(!verifierDate(p.dateDebut));
    do
    {
        printf("Date fin (JJ/MM/AAAA) : ");
        fgets(p.dateFin,20,stdin);
        p.dateFin[strcspn(p.dateFin,"\n")] = '\0';

        if(!verifierDate(p.dateFin))
            printf("Date invalide !\n");

    }
    while(!verifierDate(p.dateFin));

    promotions[(*nbPromotions)++] = p;
    printf("Promotion ajoutée avec succès !\n");
}

void afficherPromotions(Promotion promotions[], int *nbPromotions)
{
    printf("\n--- Liste des promotions ---\n");
    printf("%-5s %-30s %-20s %-8s %-15s\n",
           "ID",
           "TYPE",
           "REDUCTION",
           "DATE DEBUT",
           "DATE FIN");
           printf("=============================================================\n\n");
    for (int i = 0; i < *nbPromotions; i++)
    {
        printf("%-5d %-30s %-20d %-8s %-15s\n",
               promotions[i].idPromo, promotions[i].type,
               promotions[i].reduction, promotions[i].dateDebut,
               promotions[i].dateFin);
    }
}

void promotionMaxReduction(Promotion promotions[], int *nbPromotions)
{
    if (*nbPromotions == 0)
    {
        printf("Aucune promotion.\n");
        return;
    }
    Promotion max = promotions[0];
    for (int i = 1; i < *nbPromotions; i++)
    {
        if (promotions[i].reduction > max.reduction) max = promotions[i];
    }
    printf("Promo max: %s (%.2f%%)\n", max.type, max.reduction);
}

void nombreTotalPromotions(int *nbPromotions)
{
    printf("Nombre total de promotions: %d\n", *nbPromotions);
}
