build:
	gcc -fPIC -shared -I ./include ./src/pix.c -o ./pix.so

random96p: build
	gcc -I ./include ./pix.so ./examples/random96p.c -o ./random96p.bin
	./random96p.bin
	rm ./random96p.bin
