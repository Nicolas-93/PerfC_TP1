---
title: Perfectionnement à la programmation C
subtitle: TP1
date: 30 janvier 2023
author:
    - Nicolas SEBAN
    - Amir POUYANFAR
geometry: margin=3cm
...

\pagebreak

# Introduction

# Réponses

## Exercice 1

1.
    a) L'origine est positionnée en $(y=0, x=0)$, et les positions sont indéxées de $0$ à ``COLS``$-1$ et ``LINES``$-1$.
  
    b) ``LINES`` ET ``COLS`` représentent respectivemet le nombre de lignes, et de colonnes dans le terminal.

    c) La fonction ``move`` déplace le curseur à la $y$ème ligne et $x$ème colonne.

    d)
    - ``addchr`` permet d'imprimer un caractère en sortie à la position du curseur.
    - ``mvaddch`` permet d'imprimer un caractère en sortie à la position (y, x) demandée.
    - ``printw`` permet d'imprimer une chaine formatée en sortie à la position du curseur.
    - ``mvprintw`` permet d'imprimer une chaine formatée en sortie à la position (y, x) demandée.
2.
    a) La fonction ``attron`` permet d'activer des attributs aux textes en sortie (Gras, souligné, etc...)

    b) La fonction ``attroff`` permet de désactiver un mode d'affichage ayant été activé préalablement par ``attron``.
3. 
    a) La fonction ``curs_set`` permet de paramétrer la visibilité du curseur du terminal.


## Exercice 2

1. 
    a) La fonction clear permet d'effacer le contenu du terminal.
    
    b) Déplacer le clear avant le refresh (sans rien avoir afficher entre), fait que plus rien n'est affiché.

    c) Rien de particulier.

    d) La fonction ``usleep`` suspend l'exécution pour $n$ microsecondes.
2. 
   a) Nous n'avons pas constaté de problèmes particuliers. Les étoiles affichées n'étaient pas scintillantes.

## Exercice 3

1. a) La fonction ``getstr`` permet de récupérer une entrée utilisateur, au positionement actuel du curseur, et ``mvscanw`` permet de récupérer une entrée utilsateur formatée (de manière analogue à la fonction ``scanf``.

2. a) La fonction ``noecho`` permet de désactiver le mode echo sur l'écran courant (c'est-à-dire de pas affcher . 
3. a) La fonction ``nodelay`` permet de paramétrer la fonction ``getch`` afin qu'elle soit non bloquante.

## Exercice 4

1. La fonction ``mousemask`` permet de récupérer les événements souris, selon l'argument ``mask`` précisant les événements que l'on souhaite obtenir (Clics gauche/droit, touche modificatrice pressée pendant le clic, etc...).

## Exercice 5

## Exercice 6

## Exercice 7

## Exercice 8

Pour cet exercice, sans implémentations spécifique demandées, nous avons fait le choix d'utiliser le terminal comme notre tableau, afin d'éviter une allocation assez lourde pour un petit exercice. Nous avons ainsi découvert une fonction nommée ``mvinch`` nous permettant de récupérer depuis le tampon d'affichage du terminal, un caractère quelconque à une position donnée.

On remarque ainsi une limitation de ncurses : en cas de réduction du terminal, puis agrandissement, les caractères ayant été affichés sont supprimés.

# Conclusion
Pendant ce TP d'initiation à la programmation d'applications terminal avec ncurses, nous avons découvert la structuration d'un projet utlisant ncurses ainsi que ses fonctions de base.

# Compilation
Nous avons fait le choix d'utiliser un Makefile, dès à présent 
Vous pouvez utiliser la commande ``make``.

# Utilisation
Les exercice sont compilés séparément, et sont placés dans le dossier ``build``.
