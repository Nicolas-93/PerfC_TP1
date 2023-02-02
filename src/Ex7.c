#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

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
    int delai = 100000, touche;
    int pause = false;
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    curs_set(FALSE);

    while (1) {
        touche = getch();

        if (touche != ERR) {
            if (touche == KEY_DOWN)
                delai *= 2;
            if (touche == KEY_UP)
                delai /= 2;
            if (touche == '\n')
                pause ^= 1;
            if (touche == 'q')
                break;
        }
        if (pause)
            continue;

        mvaddch(person.y, person.x, 'x');
        if (random_bool())
            person.x += random_direction();
        else
            person.y += random_direction();

        number_truncate(&person.x, 0, COLS - 1);
        number_truncate(&person.y, 0, LINES - 1);

        usleep(delai);

        attron(A_BOLD);
        mvaddch(person.y, person.x, '0');
        attroff(A_BOLD);

        refresh();
    }
}

int main(void) {
    initscr();
    marche_aleatoire();
    getch();
    endwin();
}
