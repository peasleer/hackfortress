all: clean pyro embedded strip appender

nostrip: clean pyro embedded appender

embedded:
	gcc -o embedded embedded.c

pyro:
	gcc -o pyro pyro.c

strip:
	strip -s -o embedded embedded
	strip -s -o pyro pyro

appender:
	gcc -o appender appender.c

deploy:
	./appender embedded pyro
	rm embedded appender

clean:
	rm --force pyro embedded out.bin appender /tmp/pyro
