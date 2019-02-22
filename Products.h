/*
 * Products.h
 *
 *  Created on: 28 oct. 2018
 *      Author: gaspar
 */

#ifndef PRODUCTS_H_
#define PRODUCTS_H_

typedef struct Product{
	char name[15];
	int size;
	int processTime;
	struct Product *nextProduct;
}Products;

void sortBysize(Products *product);
void insertProduct(Products *actualBuyCar, Products *productToInsert);
void mostrar(Products *lista);
void setDefaultNextProduct(Products *inventory,int numberOfProductsInStock);
Products* loadInventory(char * routeToFile);

#endif /* PRODUCTS_H_ */
