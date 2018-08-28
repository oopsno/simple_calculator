CFLAGS  := -std=c11
LDFLAGS := -lm

all: challenge-1 challenge-2-settler challenge-2-deity

common.o : common.c common.h
	@echo CC $<
	@$(CC) $(CFLAGS) -c $^

challenge-1: challenge-1.c common.o
	@echo CC $^
	@$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

challenge-2-settler: challenge-2-settler.c common.o
	@echo CC $^
	@$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

challenge-2-deity: challenge-2-deity.c common.o
	@echo CC $^
	@$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

.PHONY: clean

clean:
	@echo RM challenge-1 challenge-2-settler challenge-2-deity common.o common.h.gch
	@rm -f challenge-1 challenge-2-settler challenge-2-deity common.o common.h.gch
