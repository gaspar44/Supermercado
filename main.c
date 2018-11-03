/*
 * main.c
 *
 *  Created on: 28 oct. 2018
 *      Author: gaspar
 */

#include <stdlib.h>
#include "Products.h"

int main(int argc, char **argv) {
	Products *a = (Products*) malloc(sizeof(Products));
	Products *b = (Products*) malloc(sizeof(Products));
	Products *c = (Products*) malloc(sizeof(Products));
	Products *d = (Products*) malloc(sizeof(Products));
	a -> size = 5;
	//sprintf(a->size,"%s", "hola");
	a->name="hola";
	b -> size = 10;
	c -> size = 15;
	d -> size = 13;
	a -> nextProduct = b;
	b -> nextProduct = c;
	c -> nextProduct = d;

	sortBysize(a);
	mostrar(a);
}
