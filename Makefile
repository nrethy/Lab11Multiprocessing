CC=gcc
CFLAGS=-c -Wall -g
LDFLAGS=-ljpeg
SOURCES= mandel.c jpegrw.c
MOVIE_SOURCES=mandelmovie.c
OBJECTS=$(SOURCES:.c=.o)
MOVIE_OBJECTS=$(MOVIE_SOURCES:.c=.o)
EXECUTABLE=mandel mandelmovie

all: $(SOURCES) $(EXECUTABLE)

# pull in dependency info for *existing* .o files
-include $(OBJECTS:.o=.d) $(MOVIE_OBJECTS:.o=.d)

mandel: $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

mandelmovie: $(MOVIE_OBJECTS)
	$(CC) $(MOVIE_OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
	$(CC) -MM $< > $*.d

clean:
	rm -rf $(OBJECTS) $(MOVIE_OBJECTS) $(EXECUTABLE) *.d
