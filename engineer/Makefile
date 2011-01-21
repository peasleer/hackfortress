all: clean idaclean engineer strip

engineer: 
	gcc -o engineer engineer.c

strip:
	strip -K main -o engineer engineer

altstart: all
	bvi -f engineer.bvi engineer

clean:
	rm -f engineer

idaclean:
	rm -f *.id* *.til *.nam
