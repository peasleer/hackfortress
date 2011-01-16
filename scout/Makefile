all: clean idaclean scout strip

scout: 
	gcc -o scout scout.c

strip:
	strip -K main -K banner -K doPrint -o scout scout

altstart: all
	bvi -f scout.bvi scout

clean:
	rm -f scout

idaclean:
	rm -f *.id* *.til *.nam
