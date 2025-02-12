#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "datatype.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int book_count = 0;
int customer_count = 0;

int main() {
	struct Book book1[100];
	int choice;
	while(1){
		showMenu();
		printf ("Select the feature you want to use: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				displayBook(book1, book_count);
				break;
			case 2:
				addBooks(book1, &book_count);			
				break;
			case 3:
				editBook(book1, &book_count);
			default:
				break;
		}
	}
}	
