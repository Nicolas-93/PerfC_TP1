#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void dessiner_chat(int y, int x) {
    mvprintw(y, x, "*****");
    mvprintw(y + 1, x, "* * *");
    mvprintw(y + 2, x, "*****");
}

void effacer_chat(int y, int x) {
    mvprintw(y, x, "     ");
    mvprintw(y + 1, x, "     ");
    mvprintw(y + 2, x, "     ");
}

int main() {
    int touche;
    int chat_x, chat_y;
    int souris_x, souris_y;
    MEVENT ev;

    srand(time(NULL));
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    chat_x = rand() % (COLS - 4);
    chat_y = rand() % (LINES - 2);
    while (1) {
        touche = getch();
        if (touche == KEY_MOUSE && getmouse(&ev) == OK) {
            souris_x = ev.x;
            souris_y = ev.y;

            if (!((souris_x == chat_x || souris_x == chat_x + 4) &&
                  souris_y == chat_y + 1)) {

                if ((chat_x <= souris_x) && (souris_x <= chat_x + 4) &&
                    (chat_y <= souris_y) && (souris_y <= chat_y + 2)) {

                    // Afficher le message Attrape
                    mvprintw(LINES / 2, COLS / 2, "Attrape !");
                    refresh();
                    usleep(500000);
                    mvprintw(LINES / 2, COLS / 2, "         ");

                    effacer_chat(chat_y, chat_x);
                    chat_x = rand() % (COLS - 4);
                    chat_y = rand() % (LINES - 2);
                }
            }
        }

        dessiner_chat(chat_y, chat_x);
        if ((souris_x == chat_x || souris_x == chat_x + 4) &&
            souris_y == chat_y + 1) {
            dessiner_chat(chat_y, chat_x);
            mvaddch(souris_y, souris_x, 'X');
            refresh();
            continue;
        }

        refresh();
    }
    getch();
    endwin();
    return 0;
}
