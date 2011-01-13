all: pyro embedded

embedded:
	gcc -o embedded embedded.c
	strip -s -o embedded embedded

pyro:
	gcc -o pyro pyro.c
	strip -s -o pyro pyro

clean:
	rm pyro embedded out.bin
