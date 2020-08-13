OS_NAME := $(shell uname -s)

# Création d'une variable pour nommer le compilateur, dépendant du système d'exploitation.
ifeq ($(OS_NAME), Darwin)
	cc := clang
else
	cc := gcc
endif


# La cible par défault sera le programme de test.
.DEFAULT_GOAL := test

.PHONY: clean

# Efface tous les fichiers temporaires et les produits finaux.
clean:
	rm -rf build

# Crée le répertoire qui acceuille les fichiers temporaires et les produits finaux (ROT13.o, chiffrage.a, test, etc.).
build:
	mkdir -p build

build/liste.o: lib/liste.c | build
	$(cc) -Wall -pedantic -g -c lib/liste.c -I ./lib -o build/liste.o

build/libliste.a: build/liste.o | build
	ar crs build/libliste.a build/liste.o

build/arbre.o: lib/arbre.c | build
	$(cc) -Wall -pedantic -g -c lib/arbre.c -I ./lib -o build/arbre.o

build/libarbre.a: build/arbre.o | build
	ar crs build/libarbre.a build/arbre.o

build/test.o: test/test.c | build
	$(cc) -Wall -pedantic -g -c test/test.c -I ./lib -o build/test.o

build/test: build/test.o build/libliste.a build/libarbre.a | build
	$(cc) build/test.o -Lbuild -lliste -larbre -o build/test

test: build/test

check: test
	./build/test
