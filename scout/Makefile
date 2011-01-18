all: noalt 
	bvi -f scout.bvi scout

noalt: clean idaclean scout strip

scout: 
	gcc -o scout scout.c

strip:
	strip -K main -K banner -K doPrint -o scout scout

clean:
	rm -f scout

idaclean:
	rm -f *.id* *.til *.nam
