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
Durant ce TP nous découvrons la bibliothèque ``ncurses`` permettant de créer des ``TUI``s (*Terminal User Interface*)

# Réponses

## Exercice 1

1.
    a) L'origine est positionnée en $(y=0, x=0)$, et les positions sont indéxées de $0$ à ``COLS``$-1$ et ``LINES``$-1$.

    b) ``LINES`` et ``COLS`` représentent respectivemet le nombre de lignes, et de colonnes dans le terminal.

    c) La fonction ``move`` déplace le curseur à la $y^{ème}$ ligne et $x^{ème}$ colonne.

    d)
    - ``addchr`` imprime un caractère en sortie à la position du curseur.
    - ``mvaddch`` imprime un caractère en sortie à la position (y, x) demandée.
    - ``printw`` imprime une chaine formatée en sortie à la position du curseur.
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

\pagebreak

## Exercice 9

- ``int addch(chtype ch)``{.c}
    - Imprime un caractère en sortie à la position actuelle du curseur
    - Paramètres :
        - ``ch`` : caractère à insérer
    - Retourne : OK / ERR

- ``int mvaddch(int y, int x, const chtype ch)``{.c}
    - imprime un caractère en sortie à la position (y, x) demandée
    - Paramètres :
        - ``y`` : ordonnée
        - ``x`` : abscisse
        - ``ch`` : caractère à insérer
    - Retourne : OK / ERR

- ``int printw(char* fmt, ...)``{.c}
    - Imprime une chaine formatée en sortie à la position du curseur. (analogue à ``printf``)
    - Paramètres :
        - ``fmt`` : chaine de formatage
        - ``...`` : Liste des valeurs à formatter
    - Retourne : OK / ERR

- ``int mvprintw(int y, int x, char* fmt, ...)``{.c}
    - Imprime une chaine formatée en sortie à la position (y, x) demandée
    - Paramètres :
        - ``y`` : ordonnée
        - ``x`` : abscisse
        - ``fmt`` : chaine de formatage
        - ``...`` : Liste des valeurs à formatter
    - Retourne : OK / ERR

- ``int attron(int attrs)``{.c}
    - Active des modes d'affichage aux textes en sortie (Gras, souligné, clignotement, etc.)
    - Paramètres :
        - ``attrs`` : attributs à activer (``A_NORMAL``, ``A_BOLD``, ``A_BLINK``, etc.), ils sont combinables avec l'opérateur "OU binaire")
    - Retourne : OK / ERR

- ``int attroff(int attrs) ``{.c}
    - Désactive des modes d'affichage ayant été activés préalablement par ``attron``
    - Paramètres :
        - ``attrs`` : attributs à désactiver (``A_NORMAL``, ``A_BOLD``, ``A_BLINK``, etc.), ils sont combinables avec l'opérateur "OU binaire")
    - Retourne : OK / ERR

- ``int curs_set(int visibility)``{.c}
    - Règle la visibilité du curseur du terminal.
    - Paramètres :
        - ``visibility`` :
            - FALSE : invisible
            - TRUE : visibilité normale
            - 2 : visibilité importante
    - Retourne : OK / ERR

\pagebreak

- ``int getstr(char* str)``{.c}
    - Récupère une entrée utilisateur, au positionement actuel du curseur et l'écrit dans ``str``
    - Paramètres :
        - ``str`` : adresse de la chaine de caractères.
    - Retourne : OK / ERR

- ``int usleep(useconds_t usec)``{.c}
    - Suspend l'exécution du programme pour $n$ microsecondes
    - Paramètres :
        - ``usec`` : Durée en microsecondes
    - Retourne : ``-1`` en cas d'erreur, ``0`` sinon

- ``int noecho(void)``{.c}
    - Désactive l'affichage des entrées utilisateur sur la fenêtre standard.
    - Retourne : OK / ERR

- ``int nodelay(WINDOW *win, bool bf)``{.c}
    - Ajuste la fonction ``getch`` afin qu'elle soit bloquante ou non, sur la fenêtre ``win``.
    - Paramètres :
        - ``win`` : fenêtre
        - ``bf`` : booléen
            - ``TRUE`` : ``getch`` devient non bloquant.
            - ``FALSE`` : ``getch`` attend une entrée.

- ``mmask_t mousemask(mmask_t newmask, mmask *oldmask)``{.c}
    - Configure les évènements souris, selon l'argument ``newmask`` afin de préciser les événements que l'on souhaite obtenir.
    - Paramètres :
        - ``newmask`` : les événements que l'on souhaite récupérer, analaloguement à ``attron/offf``, nous pouvons utiliser l'opérateur ``OU`` binaire afin de récupérer différents évènements : ``BUTTON1_CLICKED``, ``BUTTON_SHIFT``, ``ALL_MOUSE_EVENTS``, ``REPORT_MOUSE_POSITION`` etc.
        - ``oldmask`` : Adresse où stocker l'ancienne configuration des évènements (Ignorable avec ``NULL``)
    - Retourne : La nouvelle configuration (masque) des évènements.

- ``chtype mvinch(WINDOW *win)``{.c}
    - Récupère depuis le tampon d'affichage du terminal, un caractère quelconque à une position donnée.
    - Paramètres :
        - ``win`` : fenêtre
    - Retourne : le caractère lu depuis le terminal, avec son mode d'affichage. Pour récupérer le caractère "brut", il est nécessaire d'appliquer le masque ``A_CHARTEXT`` avec l'opérateur ``ET`` binaire. 

\pagebreak

# Conclusion
Pendant ce. TP d'initiation à la programmation d'applications terminal avec ncurses, nous avons découvert la structuration d'un projet utlisant ncurses ainsi que ses fonctions de base.

# Compilation
Nous avons fait le choix d'utiliser un Makefile, dès à présent afin de simplifier la compilation, automatiser le formatage et la création d'un rendu au format ``zip``.
Vous pouvez utiliser la commande ``make``.

Remarque : La norme utilisée pour la compilation a été remplacé par ``gnu17`` au lieu de ``c17``, afin que les warnings liées à ``usleep`` disparaissent.
La fonction ``usleep`` serait dépréciée dans les normes POSIX récentes.

# Utilisation
Les exercices sont compilés séparément, et placés dans le dossier ``build``.

Par exemple :
```sh
./build/Ex7
```
