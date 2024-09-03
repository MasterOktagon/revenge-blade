default: main
link := -I"/usr/local/include/SDL2" -L"/usr/lib/x86_64-linux-gnu" -lSDL2

main: main.o
	g++ build/main.o -o revenge-Blade -I"/usr/local/include/SDL2" -L"/usr/lib/x86_64-linux-gnu" -lSDL2

main.o: src/main.cpp
	g++ -c src/main.cpp -o build/main.o -I"/usr/local/include/SDL2" -L"/usr/lib/x86_64-linux-gnu" -lSDL2

clean:
	-rm -f build/main.o

cleanall: clean
	-rm -f build/main.o
	-rm -f revenge-Blade

# -l"/usr/local/include/SDL2"
