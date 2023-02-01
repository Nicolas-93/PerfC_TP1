#include <ncurses.h>
#include <unistd.h>

void question_1b(void) {
    char chaine[128];
    initscr();
    mvgetstr(2, 4, chaine);
    mvprintw(0, 0, "%s", chaine);
    refresh();
}

void question_1c(void) {
    int n;
    int x = 0, y = 0;
    do {
        mvscanw(y, x, "%d", &n);
        refresh();
        ++x;
        ++y;
    } while (n != 0);
}

void question_2(void) {
    int touche;
    int x, y;
    int step = 1;
    int x_prec, y_prec;

    initscr();
    noecho();

    x = COLS / 2;
    y = LINES / 2;

    mvaddch(y, x, 'o');

    while (1) {
        x_prec = x;
        y_prec = y;

        touche = getch();
        if (touche == 'q')
            x -= step;
        if (touche == 'd')
            x += step;
        if (touche == 'z')
            y -= step;
        if (touche == 's')
            y += step;
        if (touche == 'i') {
            x = COLS / 2;
            y = LINES / 2;
        }
        if (touche == 'p')
            ++step;
        if (touche == 'm')
            if (step >= 1)
                --step;

        if (x < 0)
            x = 0;
        if (x > COLS)
            x = COLS - 1;
        if (y < 0)
            y = 0;
        if (y > LINES)
            y = LINES - 1;

        mvaddch(y_prec, x_prec, ' ');
        mvaddch(y, x, 'o');
        mvprintw(LINES - 1, 0, "Pas : %d", step);
        // noecho();
        refresh();
    }
}

void question_3(void) {

    int touche, val, delai;

    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    val = 0;
    delai = 1000000;

    mvprintw(0, 0, "Valeur: ");
    attron(A_BOLD);
    printw("%3d", val);
    attroff(A_BOLD);

    while (1) {
        touche = getch();
        if (touche != ERR) {
            if (touche == 'r')
                val = 0;
            if (touche == KEY_DOWN)
                delai /= 2;
            if (touche == KEY_UP)
                delai *= 2;
            if (touche == 'q')
                break;
        }

        mvprintw(0, 0, "Valeur: ");
        attron(A_BOLD);
        printw("%3d", val);
        attroff(A_BOLD);

        refresh();

        val = (val + 1) % 128;
        usleep(delai);
    }

    getch();
    endwin();
}

int main(void) {
    question_3();
    getch();
    endwin();
}