#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    int x;
    int y;
} Point;

int random_bool();
int random_direction();

/**
 * @brief Renvoie un booléen aléatoire.
 *
 * @return int
 */
inline int random_bool() {
    return rand() > (RAND_MAX / 2);
}

/**
 * @brief Renvoie aléatoirement un entier négatif
 * ou positif.
 *
 * @return int
 */
inline int random_direction() {
    return random_bool() == 0 ? -1 : 1;
}

int number_truncate(int* n, int min, int max) {
    if (*n > max) {
        *n = max;
        return 0;
    } else if (*n < min) {
        *n = min;
        return 0;
    }
    return 1;
}

void marche_aleatoire(void) {
    Point person = {COLS / 2, LINES / 2};
    nodelay(stdscr, TRUE);
    cbreak();
    noecho();
    curs_set(FALSE);

    while (1) {
        mvaddch(person.y, person.x, 'x');

        if (random_bool())
            person.x += random_direction();
        else
            person.y += random_direction();

        number_truncate(&person.x, 0, COLS - 1);
        number_truncate(&person.y, 0, LINES - 1);

        usleep(100000);

        mvaddch(person.y, person.x, 'o');

        refresh();
    }
}

int main(void) {
    initscr();
    marche_aleatoire();
    getch();
    endwin();
}
