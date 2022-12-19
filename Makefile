CFLAGS += -Wall -Wextra -Werror -std=c89 -pedantic

monty: $(wildcard *.c)
	$(LINK.c) $^ -o $@ $(LDLIBS)