CC = g++
CFLAGS = `pkg-config --cflags cairo gtk4`
LIBS = `pkg-config --libs cairo gtk4`
main: main.cpp
	$(CC) $(CFLAGS) $(LIBS) main.cpp -o ./app.out
run:
	./app.out

clean:
	rm ./app.out
