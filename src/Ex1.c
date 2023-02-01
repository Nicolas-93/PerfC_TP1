#include <ncurses.h>

void question_e_move_addch(void);
void question_e_mvaddch(void);
void question_e_mvprintw(void);

int initiation(void) {
    initscr();

    move(1, 0);
    printw("1");

    move(2, 10);
    addch('2');
    addch('3');
    // addch('3');
    // addch('3');
    //  addch('4');

    move(LINES - 1, COLS - 1);
    addch('4');
    mvaddch(4, 2, '5');
    mvprintw(3, 3, "ABCD");
    mvprintw(3, 3, "ABCDEF");

    refresh();
    getch();
    endwin();

    return 0;
}

void question_1e_move_addch(void) {
    move(8, 4);
    addch('4');
    addch('!');
    addch('+');
    addch('2');
    addch('!');
    refresh();
}

void question_1e_mvaddch(void) {
    mvaddch(8, 4 + 0, '4');
    mvaddch(8, 4 + 1, '!');
    mvaddch(8, 4 + 2, '+');
    mvaddch(8, 4 + 3, '2');
    mvaddch(8, 4 + 4, '!');
    refresh();
}

void question_1e_mvprintw(void) {
    mvprintw(8, 4, "4!+2!");
    refresh();
}

void question_2c(void) {
    attron(A_BOLD | A_UNDERLINE);
    mvprintw(0, 0, "*10*");
    attron(A_NORMAL);
    refresh();
}

void question3(void) {

    initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_CYAN);
    init_pair(2, COLOR_GREEN, COLOR_BLUE);

    curs_set(FALSE);

    attron(COLOR_PAIR(1));
    mvprintw(2, 3, "Abc123 **  *");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    mvprintw(2, 16, "2121");
    attroff(COLOR_PAIR(2));

    refresh();
}

int main(void) {
    initscr();
    question3();
    getch();
    endwin();
}
