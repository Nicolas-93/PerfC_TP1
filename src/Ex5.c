#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 10

void creer_damier() {
    int i, j;
    int mode = 1;

    start_color();
    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    init_pair(2, COLOR_BLACK, COLOR_RED);
    curs_set(FALSE);

    for (j = LINES / 2; j > LINES / 2 - SIZE; --j) {
        for (i = COLS / 2; i < COLS / 2 + SIZE; ++i) {
            mode = (i + j) % 2 + 1;
            attron(COLOR_PAIR(mode));
            mvprintw(j, i, " ");
            attroff(COLOR_PAIR(mode));
        }
    }
    refresh();
}

int main(void) {
    initscr();
    creer_damier();
    getch();
    endwin();
}