/*
 * Products.c
 *
 *  Created on: 28 oct. 2018
 *      Author: gaspar
 */
#include "Products.h"
#include <stdlib.h>

void insertProduct(Products *actualBuyCar,Products *productToInsert){
	if (actualBuyCar->nextProduct == NULL)
		actualBuyCar->nextProduct = productToInsert;

	else
		insertProduct(actualBuyCar->nextProduct,productToInsert);
}

void sortBysize(Products *product){
	char *tempName;
	int tempSize = 0;
	int tempProcessTime = 0;
	Products *actualElement = (Products*)malloc(sizeof(Products));
	Products *nextElement = (Products*)malloc(sizeof(Products));

	for ( actualElement = product ; actualElement ->nextProduct != NULL;actualElement= actualElement->nextProduct){

		for (nextElement = actualElement->nextProduct; nextElement != NULL; nextElement = nextElement->nextProduct){

			if (actualElement->size < nextElement -> size){
				tempName = nextElement ->name;
				tempSize = nextElement -> size;
				tempProcessTime = nextElement -> processTime;

				nextElement -> name = actualElement -> name;
				nextElement -> processTime = actualElement -> processTime;
				nextElement -> size = actualElement -> size;

				actualElement -> name = tempName;
				actualElement -> size = tempSize;
				actualElement -> processTime = tempProcessTime;
			}

		}
	}
	free(actualElement);
	free(nextElement);

};
