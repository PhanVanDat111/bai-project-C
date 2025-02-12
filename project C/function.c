#include <stdio.h>
#include <string.h>
#include "datatype.h"

 void showMenu (){
	printf("+-----------------------------+\n");
	printf("++book management system++c\n");
	printf("1.Add new books\n");
	printf("2.Display all books\n");
	printf("3.Edit books\n");
	printf("4.Edit book information\n");
	printf("5.Delete books\n");
	printf("6.Exit\n");
	printf("+------------------------------+\n");	     
}
void displayBook(struct Book *book1, int book_count){
	printf("\nID/Author/Price/quantity/Title\n");
	for(int i=0;i< book_count ;i++){
		printf("%s/%s/%s/%d/%d \n",book1[i].bookID, book1[i].author, book1[i].title, book1[i].price, book1[i].quantity);
	}	
}
void addBooks(struct Book *book1, int *book_count){
	if(*book_count>=100){
		printf("danh sach da du");
		return;
	}
	 	fflush(stdin);
	    printf("Enter book ID: ");
	   	fgets(book1[*book_count].bookID, 10, stdin);
	   	book1[*book_count].bookID[strcspn(book1[*book_count].bookID, "\n")] = '\0';
	   	printf("Enter book title: ");
		fgets(book1[*book_count].title, 30, stdin);
		book1[*book_count].title[strcspn(book1[*book_count].title, "\n")] = '\0';
	    printf("Enter book author: ");
	 	fgets(book1[*book_count].author, 20, stdin);
		book1[*book_count].author[strcspn(book1[*book_count].author, "\n")] = '\0';
	    printf("Enter book price: ");
	    fflush(stdin);
	 	scanf("%d", &book1[*book_count].price);
	 	printf("Enter book quantity: ");
		fflush(stdin);
		scanf("%d", &book1[*book_count].quantity);
	    (*book_count)++;
	    printf("Book added successfully!\n");
}
    void editBook(struct Book *book1, int book_count){
      char id[10];
      printf("nhap id sach ban muon sua");
      fflush(stdin);
      fgets(id,10,stdin);
      fgets(id,10,stdin);   
	  id[strcspn(id, "\n")] = '\0';  
      
      int found = -1;
      for(int i=0;i<book_count;i++){
	  	if(strcmp(book1[i].bookID, id) == 0){
		   found = i;
		   break;
		  }
	  }
      if(found==-1){
	  	printf(" ID sach khong ton tai\n");
	  	return;
	  }
	 
	    printf("Thong tin hien thi :\n");
	    printf("ID: %s, Title: %s, author: %s, price: %.2f, quantity: %d\n", book1->bookID, book1->title, book1->author, book1->price,book1->quantity);
	    //dung de them thong tin sach moi
	    fflush(stdin);
		printf("New book ID: ");
		fgets(book1[book_count].bookID, 10, stdin);
		book1[book_count].bookID[strcspn(book1[book_count].bookID, "\n")] = '\0';
		printf("New book title: ");
		fgets(book1[book_count].title, 30, stdin);
		book1[book_count].title[strcspn(book1[book_count].title, "\n")] = '\0';
		printf("New book author: ");
		fgets(book1[book_count].author, 20, stdin);
		book1[book_count].author[strcspn(book1[book_count].author, "\n")] = '\0';
		printf("New book price: ");
		fflush(stdin);
		scanf("%d", &book1[book_count].price);
		printf("New book quantity: ");
		fflush(stdin);
		scanf("%d", &book1[book_count].quantity);
		(book_count)++;
		printf("Book added successfully!\n");
	}	

		

	
	
	
	
	
	
	
	
	
