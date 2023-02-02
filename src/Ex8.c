#include <ncurses.h>
#include <stdlib.h>

#define SEUIL 2

void fill_screen_with_char(char c) {
    for (int y = 0; y < LINES; ++y) {
        for (int x = 0; x < COLS; ++x) {
            mvaddch(y, x, c);
        }
    }
}

void strange_array() {
    MEVENT ev;
    int touche = 0;
    int n;
    char c;

    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    nodelay(stdscr, TRUE);

    start_color();
    init_pair(1, COLOR_BLACK, COLOR_BLUE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    fill_screen_with_char('0');

    while (touche != 'q') {
        touche = getch();
        if (touche == KEY_MOUSE && getmouse(&ev) == OK) {
            /* Afin d'éviter la création d'un tableau
               l'idée est d'utiliser le terminal comme tableau */
            c = A_CHARTEXT & mvinch(ev.y, ev.x);
            n = c - '0';
            if (c != ' ' && n < SEUIL) {
                mvaddch(ev.y, ev.x, (n + 1) + '0');
            } else if (c != ' ') {
                attron(COLOR_PAIR(1));
                mvaddch(ev.y, ev.x, ' ');
                attroff(COLOR_PAIR(1));
            }
            refresh();
        }
    }
}

int main(void) {
    initscr();

    strange_array();
    endwin();

    return EXIT_SUCCESS;
}
