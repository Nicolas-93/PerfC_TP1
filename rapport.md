---
title: Perfectionnement à la programmation C
subtitle: TP1
date: 30 janvier 2023
author:
    - Nicolas SEBAN
    - Amir POUYANFAR
geometry: margin=1cm
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

## Exercice 9

| **Prototype**                                      | **Role des paramètres**                                                                         | **Valeur renvoyée**               |                                                    **Résumé**                                                   |   |
|----------------------------------------------------|-------------------------------------------------------------------------------------------------|-----------------------------------|:---------------------------------------------------------------------------------------------------------------:|---|
| ``int addch(chtype ch)``                           | ch : caractère à insérer                                                                        | OK / ERR                          | imprime un caractère en sortie à la position du curseur                                                         |   |
| ``int mvaddch(int y, int x, const chtype ch)``     | y : ordonnée / x : abscisse / ch : caractère à insérer                                          | OK / ERR                          | imprime un caractère en sortie à la position (y, x) demandée                                                    |   |
| int printw(char* fmt [, arg] ...)                  | fmt : chaine de formatage                                                                       | OK / ERR                          | imprime une chaine formatée en sortie à la position du curseur                                                  |   |
| int mvprintw(int y, int x, char* fmt [, arg] ...)  | y : ordonnée / x : abscisse / fmt : chaine de formatage                                         | OK / ERR                          | imprime une chaine formatée en sortie à la position (y, x) demandée                                             |   |
| int attron(int attrs)                              | attrs : attributs (A_NORMAL, A_BOLD, A_BLINK etc. (combinables avec l'opérateur "ou binaire"))  | OK / ERR                          | active des attributs aux textes en sortie (Gras, souligné etc.)                                                 |   |
| int attroff(int attrs)                             | attrs : attributs (A_NORMAL, A_BOLD, A_BLINK etc. (combinables avec l'opérateur "ou binaire"))) | OK / ERR                          | désactive un mode d'affichage ayant été activé préalablement par ``attron``                                     |   |
| int curs_set(int visibility)                       | visibility :  0 --> invisible / 1 --> normal / 2 --> high visibility mode                       | OK / ERR                          | paramètre la visibilité du curseur du terminal                                                                  |   |
| int usleep(useconds_t  usec )                      | usec : nombre de microsecondes                                                                  | Err : -1 / OK : 0                 | suspend l'exécution pour ``n`` microsecondes                                                                    |   |
| int getstr(char * str)                             | str : adresse de destination de la chaine de caractères                                         | OK / ERR                          | récupère une entrée utilisateur, au positionement actuel du curseur                                             |   |
| int noecho(void);                                  |                                                -                                                | OK / ERR                          | désactive le mode echo sur l'écran courant (c'est-à-dire de pas afficher)                                       |   |
| int nodelay(WINDOW *win, bool bf);                 | win : fenetre / bf : booléen                                                                    | OK / ERR                          | paramétre la fonction ``getch`` afin qu'elle soit non bloquante                                                 |   |
| mmask_t mousemask(mmask_t newmask, mmask *oldmask) | newmask : les événements que l'on souhaite récupérer                                            | masque des événements reportables | récupère les événements souris, selon l'argument ``newmask`` précisant les événements que l'on souhaite obtenir |   |
| chtype mvinch(WINDOW *win)                         | win : fenetre                                                                                   | caractère                         | récupère depuis le tampon d'affichage du terminal, un caractère quelconque à une position donnée                |   |

# Conclusion
Pendant ce. TP d'initiation à la programmation d'applications terminal avec ncurses, nous avons découvert la structuration d'un projet utlisant ncurses ainsi que ses fonctions de base.

# Compilation
Nous avons fait le choix d'utiliser un Makefile, dès à présent afin de simplifier la compilation, automatiser le formatage et la création d'un rendu au format ``zip``.
Vous pouvez utiliser la commande ``make``.

Remarque : La norme utilisée pour la compilation a été remplacé par ``gnu17`` au lieu de ``c17``, afin que les warnings liées à ``usleep`` disparaissent.
La fonction ``usleep`` serait dépréciée dans les normes POSIX récentes qui servent à tout.

# Utilisation
Les exercices sont compilés séparément, et placés dans le dossier ``build``.

Par exemple :
```sh
./build/Ex7
```
