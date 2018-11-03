/*
 * Products.h
 *
 *  Created on: 28 oct. 2018
 *      Author: gaspar
 */

#ifndef PRODUCTS_H_
#define PRODUCTS_H_

typedef struct Product{
	char *name;
	int size;
	int processTime;
	struct Product *nextProduct;
}Products;

void sortBysize(Products *product,int itemsInTheBuyCar);
void insertProduct(Products *actualBuyCar, Products *productToInsert);


#endif /* PRODUCTS_H_ */
