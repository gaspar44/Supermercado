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

void sortBysize(Products *product){};
