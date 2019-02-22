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

	Products* inventory = loadInventory("./Entrada1.txt");
	sortBysize(inventory);
	return 0;
}
