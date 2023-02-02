#include <ncurses.h>
#include <unistd.h>

#define DELAI 200000

int question_1() {
    int x, y;
    initscr();

    x = 0;
    y = 0;

    while (1) {
        clear();
        mvaddch(y, x, 'o');

        usleep(DELAI);
        x = (x + 1) % COLS;
        y = (y + 1) % LINES;
        refresh();
    }
    endwin();
    return 0;
}

int question_2a(void) {
    int x, y;
    initscr();

    x = 0;
    y = 0;

    while (1) {
        clear();
        mvaddch(0, 0, '*');
        mvaddch(0, COLS - 1, '*');
        mvaddch(LINES - 1, 0, '*');
        mvaddch(LINES - 1, COLS - 1, '*');

        mvaddch(y, x, 'o');
        refresh();

        usleep(DELAI);
        x = (x + 1) % COLS;
        y = (y + 1) % LINES;
    }
    endwin();
    return 0;
}

int is_corner(int x, int y) {
    return ((x == 0 && y == 0) || (x == COLS && y == 0) ||
            (x == COLS && y == LINES) || (x == 0 && y == LINES));
}

int question_2_corrige(void) {
    int x, y;
    initscr();

    x = 0;
    y = 0;

    mvaddch(0, 0, '*');
    mvaddch(0, COLS - 1, '*');
    mvaddch(LINES - 1, 0, '*');
    mvaddch(LINES - 1, COLS - 1, '*');
    while (1) {
        x = (x + 1) % COLS;
        y = (y + 1) % LINES;
        if (is_corner(x, y))
            continue;
        mvaddch(y, x, 'o');
        refresh();
        mvaddch(y, x, ' ');
        // mvdelch(y, x);
        usleep(DELAI);
    }
    endwin();
    return 0;
}

int main(void) {
    question_2_corrige();
}