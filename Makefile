CC=gcc
SRC_DIR=src
INCLUDE=-Iinclude
LIBS=-lncurses -lm
CFLAGS=-fdiagnostics-color=always -Wall -pedantic -std=c17 -g
NOM_ZIP=SEBAN_POUYANFAR.zip

SOURCES=$(wildcard $(SRC_DIR)/*.c)
PROGS=$(patsubst %.c, %, $(SOURCES))
CONTENU_ZIP=$(SOURCES) .clang-format .clang-tidy Makefile rapport.pdf

all: $(PROGS)

%: %.c
	$(CC) $(INCLUDE) $(CFLAGS) $^ -o $@ $(LIBS)

rapport: rapport.pdf

rapport.pdf: rapport.md
	pandoc --toc rapport.md -o rapport.pdf

format:
	clang-format -i --style=file $(SOURCES)
	clang-tidy --fix $(SOURCES)

clean:
	rm $(PROGS)
	rm -f $(NOM_ZIP)

zip:
	zip -FSr $(NOM_ZIP) $(CONTENU_ZIP)

rendu:
	make rapport
	make zip

.PHONY: clean all
