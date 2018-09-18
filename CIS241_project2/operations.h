#ifndef OPERATIONS_H_
#define OPERATIONS_H_
#include <ctype.h>
#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20

struct product
{
char name[N];
float quantity_value;
char quantity_unit[N];
float price_value;
char price_unit[N];
struct product *next;
};
typedef struct product product;

// insert a node to the list
void insert(product **l, product *node);

//remove a node from the list
void rmItem(product **l, product *node);

//show list
void showList(product *l);

// load data from file inf
int loadData(char inf[], product **l);

// save data to file outf
int saveData(char outf[], product *l);

// sell product of quantity q
float purchase(product **l, char item[], float q);

//check out price of product p from list
void check_price(product *l, char p[]);

// find a product p from list l
product *findItem(product *l, char p[]);

// the job starts here, start with loading data from
// the file data, and perform the functions by calling
// related functions. Ends at saving data to the file data.
int doIt(char data[]);
#endif //OPERATIONS_H_ 
