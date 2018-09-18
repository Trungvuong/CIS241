#include "operations.h"
/**********************************************************************
 * This is all the implemented functions using the operations.h file.
 * All the functions are declared and will be used by the main.c
 * program.
 *********************************************************************/
/** This function inserts a product into a node */
void insert(product **l, product *node){
//    product *head = (product *)malloc(sizeof(product));
//    head = node;
    product * current = *l;
    product * temp = (product *) malloc(sizeof(product));
    strcpy(temp->name, node->name);
    temp->quantity_value = node->quantity_value;
    strcpy(temp->quantity_unit, node->quantity_unit);
    temp->price_value = node->price_value;
    strcpy(temp->price_unit, node->price_unit);
    if(*l == NULL){
        *l = temp;
       // printf("%s: %8f %s left, Cost: %8f %s\n", temp->name, temp->quantity_value, temp->quantity_unit, temp->price_value, temp->price_unit);
    }
    else{
        while(current->next != NULL)
            current = current->next;	
    	 // printf("%s: %8f %s left, Cost: %8f %s\n", temp->name, temp->quantity_value, temp->quantity_unit, temp->price_value, temp->price_unit);
    	current->next = temp;
    }
}

/** This function removes a node from the list */
void rmItem(product **l, product *node){
    product *head = (product *)malloc(sizeof(product));
    head = node;
    product * temp = *l;
    while(temp != NULL && strcmp(temp->name, temp->name) != 0){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("node not found...");
    }
    else if(temp->next != NULL){
        temp->next = head->next;
    }
    else{
        *l = NULL;
    }
}

/** This functions shows the list of products in the store */
void showList(product *l){
    product *temp = l;
    while(temp != NULL){
        printf("%s: %f %s is left, Cost: %f %s\n", temp->name, temp->quantity_value, temp->quantity_unit, temp->price_value, temp->price_unit);
        temp = temp->next;
    }
}

/** This function load a data file that is in-line argument */
int loadData(char inf[], product **l){
    //*l = NULL;
    char name[N];
    float quantity_value;
    char quantity_unit[N];
    float price_value;
    char price_unit[N];
    product *temp;
    FILE * fin = fopen(inf,"r");
    if(fin == NULL){
        puts("No load file. Starting with an empty store.\n");
        return 0;
    }
    while(fscanf(fin, "%s %f %s %f %s\n", name, &quantity_value, quantity_unit, &price_value, price_unit) == 5){
        printf("After while loop");
	temp = (product *) malloc(sizeof(product));
        strcpy(temp->name, name);
        temp->quantity_value = quantity_value;
        strcpy(temp->quantity_unit, quantity_unit);
        temp->price_value = price_value;
        strcpy(temp->price_unit, price_unit);
	//temp->next = NULL;
        insert(l, temp);
        printf("loadData: Name: %s\n", name);
        }
    fclose(fin);
    showList(*l);
    return 1;
}

/** saves any inputted store data into a file */
int saveData(char outf[], product *l){
    FILE * fout = fopen(outf, "w");
    if(fout == NULL){
        puts("Save failed...");
        return;
    }
    product *temp = l;
    while(temp != NULL) {
        fprintf(fout, "%s %f %s %f %s\n", temp->name, temp->quantity_value, temp->quantity_unit, temp->price_value, temp->price_unit);
        temp = temp->next;
    }
    fclose(fout);
}

/** This function simulates purchasing a product */
float purchase(product **l, char item[], float q){
    product *temp = findItem(*l, item);
    float total = 0.0;
    if(temp != NULL){
        if(temp->quantity_value >= q){
	    temp->quantity_value -= q;
	    total = temp->price_value * q;
	    printf("%s: %8f %s left, Cost: %8f %s\n", temp->name, temp->quantity_value, temp->quantity_unit, temp->price_value, temp->price_unit);

	}
	else
	    printf("Quantity '%8f' is unavailable\n", q);
    }
    return total;
}

/** This function checks the price of an item */
void check_price(product *l, char p[]){
    product *temp = findItem(l, p);
    if(temp != NULL)
	printf("%s costs %.2f %s.\n", temp->name, temp->price_value, temp->price_unit);
    else
        printf("Product not found");
}

/** This functions finds a specified item in the grocery store */
product *findItem(product *l, char p[]){
    product *temp = l;
    while (temp != NULL && strcmp(temp->name, p) != 0)
        temp = temp->next;
    if (temp == NULL) {
        temp = NULL;
        printf("Product not found... ");
    }
    else{
        printf("Product found: %s\n", temp->name);
        printf("%s: %8f %s left, Cost: %8f %s\n", temp->name, temp->quantity_value, temp->quantity_unit, temp->price_value, temp->price_unit);
    }	
    return temp;
}

/** This function runs the majority of the other functions in the main program */
int doIt(char data[]){
    product *list;
    list = NULL;
    loadData("data.txt", &list);
    int choice;
    do{
        printf("");
        printf("\nWelcome to Trungvuong Pham's grocery store!\n");
        printf("Please let me know what you want to do by typing a number.\n");
        printf("=====================================================================\n");
        printf("1: Add product to store                 2: Purchase products in store\n");
        printf("3: Check price of a product             4: Show products in store\n");
        printf("5: Clean up a product from store        6: Find product\n");
        printf("7: Inventory                            8: Done for the day\n");
        printf("=====================================================================\n");
        printf("What do you want to do?\n");
        scanf("%d", &choice);
        fflush(stdin);

        product *temp = (product *)malloc(sizeof(product));
	char str[N];
	static float total = 0.0;
        switch (choice)
        {
            case 1:
                printf("--ADD PRODUCT TO STORE--\n");
	        printf("Please enter the name of the product:\n ");
	        scanf("%s", temp->name);
	        fflush(stdin);
	        printf("Please enter quantity:\n ");
	        scanf("%8f",&(temp->quantity_value));
	        fflush(stdin);
	        printf("Please enter the quantity unit:\n ");
	        scanf("%s", temp->quantity_unit);
	        fflush(stdin);
                printf("Please enter the price:\n ");
	        scanf("%8f", &(temp->price_value));
		fflush(stdin);
		printf("Please enter the price unit:\n ");
		scanf("%s", temp->price_unit);
		fflush(stdin);
		temp->next = NULL;
		insert(&list, temp);
		break;
            case 2:
                printf("--PURCHASE PRODUCT FROM STORE--\n");
                printf("\nEnter item name: ");
                scanf("%s", str);
		fflush(stdin);
		int quantity = 0;
                printf("\nEnter quantity of item:\n ");
                scanf("%d", &quantity);
                fflush(stdin);
		total += purchase(&list, str, quantity);
                break;
            case 3:
            	printf("--PRICE CHECK FOR PRODUCT--\n");
            	printf("\nEnter item name: ");
            	scanf("%20s", str);
            	check_price(list, str);
            	break;
            case 4:
            	printf("--SHOW PRODUCTS IN STORE--\n");
            	showList(list);
            	break;
            case 5:
                printf("--REMOVE--\n");
            	printf("\nEnter item name: ");
            	scanf("%s", str);
           	printf("\nStr: %s\n", str);
            	temp = findItem(list, str);
		rmItem(&list, temp);
           	fflush(stdin);
            	break;
            case 6:
            	printf("--FINDING AN ITEM--\n");
            	printf("Enter item name:\n ");
            	scanf("%s", str);
            	temp = findItem(list, str);
            	break;
            	scanf("%s", str);
            	temp = findItem(list, str);
            	break;
            case 7:
            	printf("--INVENTORY--\n");
		printf("Total Sales: %8f\n", total);
            	showList(list);
            	break;
            case 8:
            	printf("--DONE FOR TODAY--\n");
           	printf("\nExit has been chosen. Have a nice day\n");
                saveData("data.txt", list);
            	break;
            default:
            	puts("Error! Wrong code. Please try again.\n");
            	break;
            }
	}while(choice != 8);
	//saveData("data.txt", list);
    return 0;
}
