# Projet-CDataframe

Notre Equipe : Arthur BOUTELIER
Victor PROFFIT
Paul Lesage

Lien du dépôt Git : https://github.com/Arthur-Boutelier/Projet-C

Notre projet consiste a créer en langage c une librairie qui nous permet de manipuler des fichiers et des données.
Pour ce faire nous avons séparé les tâches et donc les fonctions en plusieurs catégories pour permettre une meilleur expertise et une bonne compréhension dans la manipulation des variables et de la mémoire.
Par exemple, une personne va se charger de toute la partie insertion pendant qu'une autre se chargera de trouver toute les informations dans les dataframes afin de donner un maximum d'information à l'utilisateur.


Nous avons choisi de réaliser le projet CDataframe avec les consignes les moins évidente en utilisant des listes doublements chainé pour le dataframe et en créant des colonnes qui peuvent contenir tout type de données, ce qui offre un éventail de possibilité bien plus large pour l'utilisateur afin de répondre aux maximums de ses besoins. 


L'utilisateur pourra entre autre créer un dataframe, le remplir, le modifier, le supprimer, l’afficher, le trier ou encore récupérer des informations sur son contenues.

Les différents programmes sont les suivants : 

main.c :
   * CDATAFRAME by Paul Lesage, Victor Proffit et Arthur Boutelier
   * Ce fichier est celui a lancer pour faire fonctionner le programme. C'est le coeur de ce dernier dans lequel vous pouvez
   * utiliser toutes les fonctions

colonne.c : 
   * CDATAFRAME by Paul Lesage, Victor Proffit et Arthur Boutelier
   * Ce fichier comporte toutes les fonctions permettant de gérer les colonnes

sort.c : 
  * CDATAFRAME by Paul Lesage, Victor Proffit et Arthur Boutelier
  * Ce fichier comporte toutes les fonctions permettant de gérer le tri des colonnes

list.c : 
  * CDATAFRAME by Paul Lesage, Victor Proffit et Arthur Boutelier
  * Ce fichier comporte toutes les fonctions permettant de gérer les listes doublement chainé

cdataframe.c : 
  * CDATAFRAME by Paul Lesage, Victor Proffit et Arthur Boutelier
  * Ce fichier comporte toutes les fonctions permettant de gérer les dataframes


Pour la fonctionnalité lié aux fichiers CSV, il faut bien faire attention de prendre le chemin absolue vers le fichiers et non pas le chemin relatif


Pour lancer le programme, il faut se munir d'un environnement de développement de langage C (comme CLion).
Ouvrir le dossier dans cet environnement et exécuter le fichier main.c .

