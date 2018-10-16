#pragma once
#include <stdlib.h>


#define MAXSIZE 20
typedef int KeyType;
typedef int* InfoType;
typedef struct {
	KeyType key;
	InfoType otherinfo;
}RedType;
typedef struct {
	RedType r[MAXSIZE + 1];
	int length;
}Sqlist;

void MergeSort(Sqlist *L);

