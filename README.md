# Tetris 

## Avant propos
Le jeu tetris et son concept sont attribué à Alekseï Pajitnov, pour plus d'information consulter [le lien](https://fr.wikipedia.org/wiki/Tetris).

## Préambule
Ce jeu a été réalisé dans un cadre universitaire en tant que projet de programmation impérative pour la seconde année de licence en informatique à l'université Jean Monnet. 
Les personnes ayant participé au projet sont :
- Adrien.Defay
- Gaultier.Peyrard

## Prérequis
Pour pouvoir exécuter le Makefile du projet, il vous faut installer la librairie MLV pour plus d'information veuillez consulter le site officiel de MLV et rendez vous dans la rubrique installation : [MLV_INSTALATION](http://www-igm.univ-mlv.fr/~boussica/mlv/api/French/html/installation.html)  


## Module et structure du code

le code est aagencer en différent module :

   - MainWindow: gestion de la fentre de menu principal
   - Plateau: gestion et création du plateau de jeu
   - Piece: gestion et création des piéce du jeu
   - Main: le module principale
   - Scoreboard: module pour gerer gestion de la savegarde du scoreboard
   - Save: module de gestion des sauvegarde
   - Gamewindow: module de gestion de la fenetre de jeux  

## Condition d'utilisation

Toutes forment de distribution illégale à des fins monétaire est strictement interdites et sans l'autorisation des auteurs.

## GITIGNORE

Le fichier .gitignore permet d'ignorer les modifications effectuées sur le dossier '/build' ou sont stocker les fichiers objet du projet. Il ne faut donc pas mettre de fichier important dans ce répertoire.

## COMPILATION

1) clonner le projet utiliser:
     ```bash
     git clone https://github.com/Defani042/Tetris

2) Netoyage du projet
   ```bash
   male clean

3) compilation du projet
   ```bash
   make

4)lancement de l'executable
   ```bash
   .\Tetris

 ## PORTABILITE

le projet est stable sur les systeêmes d'exploitations suivant:
   - ubuntu
   - debian

   
     
