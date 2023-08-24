#!/bin/bash

cat  /etc/passwd | sed '/^#/d' | awk 'NR % 2 == 0 {print $0}'  | awk -F ":" '{  print $1 }' | rev | sort -fnr | awk -v FT_LINE1="$FT_LINE1" -v FT_LINE2="$FT_LINE2"  ' NR >= FT_LINE1 && NR <= FT_LINE2 { print $0 }' | tr '\n' ' '  | sed 's+ +, +g' | sed 's+, $+.+g' | tr -d '\n'


# cat /etc/passwd : lire le contenu du fichier /etc/passwd, détails de tous les utilisateurs du système.

# sed '/^#/d' : supprimer toutes les lignes qui commencent par un hashtag (#). Dans le fichier /etc/passwd, ces lignes sont des commentaires.

# awk 'NR % 2 == 0 {print $0}' : imprime chaque ligne (indiquée par $0) où le numéro de la ligne (NR) est un multiple de 2. sélectionne les lignes paires du fichier.

# awk -F ":" '{ print $1 }' : sépare chaque ligne en champs séparés par des deux-points (":"). imprime le premier champ de chaque ligne, qui dans le contexte de /etc/passwd est le nom d'utilisateur.

# rev :inverse chaque ligne, 

# sort -fnr : trie les noms d'utilisateurs inversés en ordre décroissant.

# awk -v FT_LINE1="$FT_LINE1" -v FT_LINE2="$FT_LINE2" 'NR >= FT_LINE1 && NR <= FT_LINE2 { print $0 }' : imprime les lignes dont le numéro est entre FT_LINE1 et FT_LINE2, inclusivement.

# tr '\n' ' ' : mettre des espace a la place de retour a la ligne

# sed 's+ +, +g' : remplace tous les espaces par des virgules suivies d'un espace.

# sed 's+, $+.+g' : remplace la derniere virgule par un point

# tr -d '\n' :supprime tous les retours à la ligne restants.

