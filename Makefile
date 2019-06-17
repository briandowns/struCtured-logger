CC = cc
CFLAGS = -Wall -ljson-c
NAME = log

VERSION := 01

UNAME_S := $(shell uname -s)

TSTDIR := ./tests
INCDIR := /usr/local/include

ifeq ($(UNAME_S),Linux)
$(NAME).$(VERSION).so:
	$(CC) -shared -o $(NAME).$(VERSION).so $(NAME).c $(CFLAGS)
endif
ifeq ($(UNAME_S),Darwin)
$(NAME).$(VERSION).dylib:
	$(CC) -dynamiclib -o $(NAME).$(VERSION).dylib $(NAME).c $(CFLAGS)
endif

.PHONY: install
install: 
	cp $(NAME).h $(INCDIR)
ifeq ($(UNAME_S),Linux)
	cp $(NAME).$(VERSION).so $(INCDIR)
endif
ifeq ($(UNAME_S),Darwin)
	cp $(NAME).$(VEWRSION).dylib /usr/local/lib/lib$(NAME).dylib
endif

uninstall:
	rm -f $(INCDIR)/$(NAME).h
	rm -f /usr/local/lib/lib$(NAME).dylib
ifeq ($(UNAME_S),Linux)
	rm -f $(INCDIR)/$(NAME).$(VERSION).so
endif
ifeq ($(UNAME_S),Darwin)
	rm -f $(INCDIR)/$(NAME).$(VERSION).dylib
endif

.PHONY:
test: clean
	$(CC) -o $(TSTDIR)/$(TSTDIR) $(TSTDIR)/$(TSTDIR).c log.c $(TSTDIR)/unity/unity.c $(CFLAGS)
	$(TSTDIR)/$(TSTDIR)
	rm -f $(TSTDIR)/$(TSTDIR)

.PHONY: clean
clean:
	rm -f $(TSTDIR)/$(TSTDIR)
