🛒 SmartMarket

Application de gestion d'un supermarché en langage C

«🎓 Projet universitaire — Licence 1 Génie Logiciel
🏫 ISI Keur Massar — Dakar, Sénégal»

---

📌 Présentation

SmartMarket est une application console développée en langage C dans le cadre d'un projet universitaire.

L'objectif du projet est de faciliter la gestion des principales activités d'un supermarché : produits, clients, fournisseurs, promotions et ventes.

L'application permet également d'effectuer plusieurs calculs et statistiques afin de faciliter le suivi de l'activité du supermarché.

---

🎯 Objectifs du projet

SmartMarket a été conçu pour permettre de :

- 📦 Gérer les produits et leur stock
- 👤 Gérer les clients
- 🚚 Gérer les fournisseurs
- 🏷️ Gérer les promotions
- 💰 Enregistrer les ventes
- 📊 Calculer le chiffre d'affaires
- 📈 Calculer différentes statistiques

---

⚙️ Fonctionnalités

📦 Gestion des produits

- Ajouter un produit
- Afficher la liste des produits
- Rechercher un produit
- Trouver le produit ayant le stock maximum
- Calculer le prix moyen des produits
- Contrôler le nombre maximal de produits

👤 Gestion des clients

- Ajouter un client
- Afficher les clients
- Rechercher un client
- Afficher le nombre total de clients

🚚 Gestion des fournisseurs

- Ajouter un fournisseur
- Afficher les fournisseurs
- Afficher le nombre total de fournisseurs

🏷️ Gestion des promotions

- Ajouter une promotion
- Afficher les promotions
- Vérifier la validité des dates
- Trouver la promotion avec la réduction maximale
- Afficher le nombre total de promotions

💰 Gestion des ventes

- Enregistrer une vente
- Afficher les ventes
- Calculer le chiffre d'affaires
- Trouver la vente avec le montant maximal
- Calculer le montant moyen des ventes
- Calculer la quantité totale vendue
- Contrôler le stock lors d'une vente

---

🧩 Entités principales

Le projet repose sur cinq entités principales :

Entité| Rôle
📦 Produit| Gestion des articles et du stock
👤 Client| Gestion des clients
💰 Vente| Enregistrement des ventes
🚚 Fournisseur| Gestion des fournisseurs
🏷️ Promotion| Gestion des réductions et périodes promotionnelles

---

🗂️ Structure du projet

SmartMarket/
│
├── main.c
├── GESTION.c
├── GESTION.h
└── README.md

"main.c"

Contient le point d'entrée du programme et initialise les tableaux ainsi que les compteurs.

"GESTION.h"

Contient :

- les structures ;
- les constantes ;
- les prototypes des fonctions.

"GESTION.c"

Contient l'implémentation des différentes fonctions de gestion du supermarché.

---

💻 Technologies utilisées

- Langage : C
- IDE : Code::Blocks
- Compilateur : GNU GCC
- Programmation modulaire
- Structures ("struct")
- Tableaux de structures
- Pointeurs
- Fonctions
- Boucles et conditions
- Gestion des chaînes de caractères

---

🧠 Notions de programmation mises en pratique

Ce projet permet de mettre en pratique plusieurs notions fondamentales du langage C :

Structures

Les données sont organisées grâce à différentes structures :

Produit
Client
Fournisseur
Vente
Promotion

Tableaux de structures

Les différents éléments sont stockés dans des tableaux :

Produit produits[MAX_PRODUITS];
Client clients[MAX_CLIENTS];
Vente ventes[MAX_VENTES];

Pointeurs

Les compteurs sont transmis par adresse afin de pouvoir être modifiés directement dans les fonctions :

int *nbProduits

Programmation modulaire

Le programme est séparé en plusieurs fichiers afin d'améliorer son organisation :

main.c
GESTION.h
GESTION.c

---

📊 Quelques statistiques disponibles

SmartMarket permet notamment de calculer :

- 📈 Le chiffre d'affaires total
- 📊 Le prix moyen des produits
- 📊 Le montant moyen des ventes
- 📦 Le produit ayant le stock maximum
- 💰 La vente ayant le montant maximum
- 🛒 La quantité totale vendue
- 👥 Le nombre total de clients
- 🚚 Le nombre total de fournisseurs
- 🏷️ Le nombre total de promotions

---

▶️ Compilation et exécution

Avec GCC, le projet peut être compilé avec :

gcc main.c GESTION.c -o SmartMarket

Puis exécuté avec :

./SmartMarket

Avec Code::Blocks

1. Ouvrir le projet dans Code::Blocks.
2. Vérifier que "main.c", "GESTION.c" et "GESTION.h" sont présents.
3. Compiler le projet.
4. Exécuter le programme.
5. Utiliser le menu principal pour tester les différentes fonctionnalités.

---

🖥️ Fonctionnement

Au lancement, SmartMarket affiche un menu principal permettant d'accéder aux différentes fonctionnalités.

##### SMARTMARKET #####

### Produits ###
1. Ajouter un produit
2. Afficher les produits
3. Produit avec stock max
4. Prix moyen des produits

### Clients ###
5. Ajouter un client
6. Afficher les clients
7. Nombre total de clients

### Fournisseurs ###
8. Ajouter un fournisseur
9. Afficher les fournisseurs
10. Nombre total de fournisseurs

### Promotions ###
11. Ajouter une promotion
12. Afficher les promotions
13. Promotion avec réduction max
14. Nombre total de promotions

### Ventes ###
15. Enregistrer une vente
16. Afficher les ventes
17. Calculer le chiffre d'affaires
18. Vente avec montant max
19. Montant moyen des ventes
20. Quantité totale vendue

0. Quitter

---

🗃️ Modèle conceptuel

Le projet est basé sur cinq entités principales :

Fournisseur
     │
     │ fournit
     ▼
  Produit
   │   │
   │   └──────── Promotion
   │
   ▼
  Vente
   ▲
   │
 Client

Le MCD permet de représenter les principales relations entre les données utilisées par l'application.

---

🚀 Améliorations possibles

Plusieurs évolutions pourraient être ajoutées dans une future version :

- 💾 Sauvegarde des données dans des fichiers
- 🗄️ Utilisation d'une base de données
- 🖥️ Création d'une interface graphique
- 🔐 Gestion des utilisateurs et des accès
- 📊 Tableau de bord avec graphiques
- 📦 Gestion plus avancée des stocks
- 🧾 Génération de factures

---

🎓 Difficultés rencontrées

Le développement de SmartMarket nous a permis de travailler sur plusieurs difficultés :

- Organisation d'un projet en plusieurs fichiers
- Manipulation des structures
- Utilisation des tableaux de structures
- Passage des paramètres par adresse
- Gestion des saisies utilisateur
- Calcul des statistiques
- Gestion et vérification des dates
- Organisation des différentes fonctionnalités dans un menu

---

👩🏽‍💻 Projet universitaire

SmartMarket a été réalisé dans le cadre de la formation en Licence 1 Génie Logiciel.

Auteur

Fatimata Sané

📍 Dakar, Sénégal

🎓 Licence 1 — Génie Logiciel

---

⭐ Conclusion

SmartMarket est une première application de gestion développée en langage C permettant de mettre en pratique les concepts fondamentaux de la programmation structurée et modulaire.

Ce projet constitue une base pouvant évoluer vers une application plus complète intégrant une base de données, une interface graphique et une gestion avancée des utilisateurs.

---

⭐ Merci de visiter ce projet !
