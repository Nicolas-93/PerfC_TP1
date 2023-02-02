CC=gcc
BUILD_DIR=build
SRC_DIR=src
INC_DIR=include
INCLUDE=-I$(INC_DIR)
LIBS=-lncurses -lm
CFLAGS=-fdiagnostics-color=always -Wall -pedantic -std=gnu17 -g
NOM_ZIP=SEBAN_POUYANFAR.zip

SOURCES=$(wildcard $(SRC_DIR)/*.c)
HEADERS=$(wildcard $(INC_DIR)/*.h)
PROGS=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%,$(SOURCES))
CONTENU_ZIP=$(SOURCES) .clang-format .clang-tidy Makefile rapport.pdf
#$(info $(PROGS))

all: $(PROGS)

$(BUILD_DIR)/%: $(SRC_DIR)/%.c
	@mkdir --parents $(BUILD_DIR)
	$(CC) $(INCLUDE) $(CFLAGS) $^ -o $@ $(LIBS)

rapport: rapport.pdf

rapport.pdf: rapport.md
	pandoc --toc rapport.md -o rapport.pdf

format: $(SOURCES) $(HEADERS)
	clang-format -i --style=file $?
	clang-tidy --fix $?

clean:
	rm $(PROGS)
	rm -f $(NOM_ZIP)

zip:
	zip -FSr $(NOM_ZIP) $(CONTENU_ZIP)

rendu:
	@$(MAKE) --no-print-directory rapport
	@$(MAKE) --no-print-directory zip

.PHONY: clean all
