INC_DIR = ./src
CFLAGS=-Wall -Wextra -Werror -I$(INC_DIR)
#DEPS = split.h

default: main
link := -I"/usr/local/include/SDL2" -L"/usr/lib/x86_64-linux-gnu" -lSDL2 -I"./src"


main: app.o main.o
	g++ build/main.o build/app.o -o revenge-Blade $(link)

main.o: src/main.cpp src/app.hpp
	g++ -c src/main.cpp -o build/main.o $(link)
	
app.o: src/app.cpp src/app.hpp
	g++ -c src/app.cpp -o build/app.o $(link)

clean:
	-rm -f build/main.o
	-rm -f build/app.o

cleanall: clean
	-rm -f build/main.o
	-rm -f build/app.o
	-rm -f revenge-Blade

# -l"/usr/local/include/SDL2"
