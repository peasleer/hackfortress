all: spy sniper pyro

clean:
	rm -rf bin
	cd spy && make clean
	cd sniper && make clean
	cd pyro && make clean

spy:
	cd spy && make spy

sniper:
	cd sniper && make sniper

pyro:
	cd pyro && make pyro && make deploy

gather: all
	mkdir -p bin
	cp spy/spy bin
	cp sniper/sniper bin
	cp pyro/pyro bin
