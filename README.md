# Projet push_swap

<div align="center">
  <img src="https://github.com/yourusername/42-project-badges/blob/main/badges/push_swap.png" alt="Badge du projet push_swap">
</div>

## Description

Ce projet a pour but de trier des données sur une pile, en utilisant un ensemble limité d'instructions, et ce, avec le moins d'actions possible. Il s'agit d'appliquer divers types d'algorithmes pour choisir la solution la plus appropriée et optimisée pour un tri de données efficace.

## Tableau des Composants du Projet

| Fichier            | Description                                                               | Responsabilité                                         | Statut   |
|--------------------|---------------------------------------------------------------------------|--------------------------------------------------------|----------|
| `main.c`           | Fichier principal, initialise le programme                                | Initialisation, gestion des arguments                  | Complet  |
| `stack_operations.c`| Gère les opérations sur les piles (push, swap, rotate)                    | Manipulation des piles                                 | Complet  |
| `sorting_logic.c`  | Implémente la logique de tri                                              | Tri des nombres                                        | Complet  |
| `utils.c`          | Fonctions utilitaires pour le traitement des données et des erreurs       | Assistance générale                                    | Complet  |
| `validator.c`      | Valide les entrées et les états des piles                                 | Validation des entrées, vérification de l'état du tri | Complet  |
| `Makefile`         | Fichier pour compiler le projet                                           | Compilation                                            | Complet  |
| `push_swap.h`      | Fichier d'en-tête contenant les déclarations et les macros                | Déclarations                                           | Complet  |

## Installation et Compilation

```bash
git clone git@github.com:votreusername/push_swap.git
cd push_swap
make
```

## Utilisation
```
./push_swap [liste_de_nombres]
```

## Caractéristiques
Manipulation efficace des piles pour le tri de données.
Utilisation minimale d'instructions pour un tri optimisé.
Gestion d'erreurs et validation des entrées pour une robustesse maximale.
Aucune fuite de mémoire, conformément aux standards de l'école 42.

## Fonctions externes autorisées
malloc
free
read
write
exit
