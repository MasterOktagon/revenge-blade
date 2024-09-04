INC_DIR = ./src
CFLAGS=-Wall -Wextra -Werror -I$(INC_DIR)
#DEPS = split.h

default: main
link := -I"/usr/local/include/SDL2" -L"/usr/lib/x86_64-linux-gnu" -lSDL2 -lSDL2_image -I"./src"


main: app.o main.o sprite.o helper.o draw.o userinput.o
	g++ build/main.o build/helper.o build/app.o build/sprite.o build/draw.o build/userinput.o -o revenge-Blade $(link)

main.o: src/main.cpp
	g++ -c src/main.cpp -o build/main.o $(link)
	
app.o: src/app.cpp src/app.hpp
	g++ -c src/app.cpp -o build/app.o $(link)

draw.o: src/draw.cpp src/draw.hpp
	g++ -c src/draw.cpp -o build/draw.o $(link)

helper.o: src/helper.cpp src/helper.h
	g++ -c src/helper.cpp -o build/helper.o $(link)

sprite.o: src/sprite.cpp src/sprite.hpp
	g++ -c src/sprite.cpp -o build/sprite.o $(link)

userinput.o: src/userinput.cpp src/userinput.h
	g++ -c src/userinput.cpp -o build/userinput.o $(link)

clean:
	-rm -f build/main.o
	-rm -f build/app.o
	-rm -f build/sprite.o
	-rm -f build/userinput.o

cleanall: clean
	-rm -f build/main.o
	-rm -f build/sprite.o
	-rm -f build/app.o
	-rm -f build/userinput.o
	-rm -f revenge-Blade

# -l"/usr/local/include/SDL2"
