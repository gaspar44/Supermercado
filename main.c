/*
 * main.c
 *
 *  Created on: 28 oct. 2018
 *      Author: gaspar
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Products.h"

int main(int argc, char **argv) {
	Products *a = (Products*) malloc(sizeof(Products));
	Products *b = (Products*) malloc(sizeof(Products));
	Products *c = (Products*) malloc(sizeof(Products));
	Products *d = (Products*) malloc(sizeof(Products));
	a -> size = 5;
	strcpy(d -> name,"hola");
	b -> size = 10;
	c -> size = 15;
	d -> size = 13;
	a -> nextProduct = b;
	b -> nextProduct = c;
	c -> nextProduct = d;

	sortBysize(a);
	mostrar(a);
	Products* inventory = loadInventory("./Entrada1.txt");
	Products mierda = *(inventory + 4);
	//printf("%d", mierda.size);
	return 0;
}
