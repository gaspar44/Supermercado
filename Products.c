/*
 * Products.c
 *
 *  Created on: 28 oct. 2018
 *      Author: gaspar
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Products.h"

void insertProduct(Products *actualBuyCar,Products *productToInsert){
	if (actualBuyCar->nextProduct == NULL)
		actualBuyCar->nextProduct = productToInsert;

	else
		insertProduct(actualBuyCar->nextProduct,productToInsert);
}

void sortBysize(Products *product){
	char tempName[15];
	int tempSize = 0;
	int tempProcessTime = 0;
	Products *actualElement = (Products*)malloc(sizeof(Products));
	Products *nextElement = (Products*)malloc(sizeof(Products));

	for ( actualElement = product ; actualElement ->nextProduct != NULL;actualElement= actualElement->nextProduct){

		for (nextElement = actualElement->nextProduct; nextElement != NULL; nextElement = nextElement->nextProduct){

			if (actualElement->size > nextElement -> size){
				strcpy(tempName,nextElement ->name);
				tempSize = nextElement -> size;
				tempProcessTime = nextElement -> processTime;

				strcpy(nextElement -> name,actualElement -> name);
				nextElement -> processTime = actualElement -> processTime;
				nextElement -> size = actualElement -> size;

				strcpy(actualElement -> name,tempName);
				actualElement -> size = tempSize;
				actualElement -> processTime = tempProcessTime;
			}

		}
	}
}

void mostrar(Products *lista){

	if (lista->nextProduct == NULL) // En este caso está vacía
		printf("%s\t%d\n",lista->name,lista->size ); // Mostramos el valor

	else {
		Products *otro = (Products*) malloc(sizeof(Products));  // Creamos un nodo
		otro = lista->nextProduct;  // Actualizamo la lista con el siguiente nodo
		printf("%s\t%d\n",lista->name,lista->size ); // Mostramos el valor actual
		mostrar(otro); // Volvemos a llamar a la función
	}
}

Products* loadInventory(char * routeToFile){
	FILE* file = fopen(routeToFile,"r");
	if (file == NULL){
		printf("hubo error\n");
		exit(1);
	}
	int numberOfLines = 0;

	while (!feof(file)){
		if ( fgetc(file) == '\n')
			numberOfLines = numberOfLines + 1;
	}

	fclose(file);
	file = fopen(routeToFile,"r");
	char* actualLine = NULL;
	size_t lineSize = 0;
	ssize_t charsInTheLine;
	Products* inventory = (Products*) calloc(numberOfLines,sizeof(Products));
	Products* inventoryToReturn = inventory;

	char* readedName = 0;
	char* readedSize = 0;
	char* readedProcessTime = 0;

	while ( getline(&actualLine,&lineSize,file) != -1 ){
		Products product;
		readedName = strtok(actualLine,"\t");
		readedSize = strtok(NULL,"\t");
		readedProcessTime = strtok(NULL,"\r\n");

		strcpy(product.name,readedName);
		product.size = atoi(readedSize);
		product.processTime = atoi(readedProcessTime);

		*inventory = product;
		inventory++;

	}

	fclose(file);
	setDefaultNextProduct(inventoryToReturn,numberOfLines);
	return inventoryToReturn;

}

void setDefaultNextProduct(Products *inventory,int numberOfProductsInStock) {
	for (int i = 0 ; i < numberOfProductsInStock - 1; i++){
		(inventory + i)-> nextProduct = NULL;
	}
}
