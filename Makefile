all:
	mkdir build
	gcc -o build/database database.c

clean:
	rm -rf build/
