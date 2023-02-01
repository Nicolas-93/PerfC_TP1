#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

void triangle(int n) {
    int stars = 1;
    for (int i = 0; i < n; ++i) {
        for (int i = 0; i < stars; ++i) {
            addch('*');
        }
        ++stars;
        addch('\n');
    }
    refresh();
}

int main(void) {
    int n;
    initscr();
    mvprintw(0, 0, "Entrez un nombre : ");
    scanw("%d", &n);
    triangle(n);
    getch();
    endwin();
}
