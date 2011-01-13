all: pyro embedded appender

embedded:
	gcc -o embedded embedded.c
	strip -s -o embedded embedded

pyro:
	gcc -o pyro pyro.c
	strip -s -o pyro pyro

appender:
	gcc -o appender appender.c

clean:
	rm pyro embedded out.bin appender
