// data.c
#include <stdio.h>
#include "book_maneger.h"
#include "data.h"

void loadBooks() {
    FILE *file = fopen("books.bin", "rb");
    if (file==NULL) {
	    printf(" loi mo file \n");
	}
	bookCount = fread(books, sizeof(Book), 100, file);
	fclose(file);
}

void saveBooks() {
	printf("hertghf");
    FILE *file = fopen("books.bin", "wb");
    if (file==NULL) {
    	printf(" loi mo file \n");
    }
    printf("%s", books[0].author);
    fwrite(&books, sizeof(Book), bookCount, file);
	             
           
           fclose(file);
           printf("Books saved successfully.\n");
    
}
