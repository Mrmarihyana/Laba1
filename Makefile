CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = lab1
SRCDIR = src
SOURCES = $(SRCDIR)/main.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

install: $(TARGET)
	install -d $(DESTDIR)/usr/bin
	install -m 755 $(TARGET) $(DESTDIR)/usr/bin/

uninstall:
	rm -f $(DESTDIR)/usr/bin/$(TARGET)

.PHONY: all clean install uninstall
