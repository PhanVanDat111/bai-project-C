// book_manager.c
#include <stdio.h>
#include <string.h>
#include "book_maneger.h"
#include <stdlib.h>
#define MAX_BOOKS 100
Book books[MAX_BOOKS];  
int bookCount = 0;   
   
void showBookMenu() {
    int choice;
    do {
    	system("cls");		
        printf("\nBook Management System\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Update Book\n");
        printf("4. Search Book\n");
        printf("5. List Books\n");
        printf("6. Sort Books\n");
        printf("7. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                
                break;
            case 2:
                deleteBook();
               
                break;
            case 3:
                updateBook();
                
                break;
            case 4:
                searchBook();
               
                break;
            case 5:
                listBooks();
                
                break;
            case 6:
                showSortMenu();
              
                break;
            case 7:
                printf("Returning to Main Menu\n");
               
                break;
            default:
                printf("Invalid choice, please try again.\n");// hien thi bao loi id da trung nhau
        }
        while (1) {
			char answer = confirmExitOrBack();
			if (answer == '0') {
				return;
			}else if (answer == 'b') {
				break;
			}
		}
    } while (choice != 7);
}


void addBook() {
	
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }
    
    int id, i;
    
    printf("Enter book ID: ");
    scanf("%d", &id);
    
    for (i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            printf("Error: Book ID already exists\n");// loi trung id
            return;
        }
    }
    
    books[bookCount].id = id;
    fflush(stdin);
    printf("Enter book title: ");
    scanf("%s", books[bookCount].title);
    printf("Enter book author: ");
    scanf("%s", books[bookCount].author);
    printf("Enter book price: ");
    scanf("%f", &books[bookCount].price);
    bookCount++;
    
    printf("Book added successfully!\n");
    saveBooks();
}
// ham xoa sach theo id
void deleteBook() {
    int id, i, found = 0;
    printf("Enter book ID to delete: ");
    scanf("%d", &id);
    for (i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            books[i] = books[bookCount - 1];
            bookCount--;
            found = 1;
            saveBooks();
            printf("Book deleted successfully!\n");
            break;
        }
    }
    if (!found) printf("Book not found!\n");
}
// ham chinh sua sach theo id
void updateBook() {
    int id, i, found = 0;
    printf("Enter book ID to update: ");
    scanf("%d", &id);
    for (i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            printf("Enter new title: ");
            scanf("%s", books[i].title);
            printf("Enter new author: ");
            scanf("%s", books[i].author);
            printf("Enter new price: ");
            scanf("%f", &books[i].price);
            found = 1;
            saveBooks();
            printf("Book updated successfully!\n");
            break;
        }
    }
    if (!found) printf("Book not found!\n");
}
// ham tim kiem sach
void searchBook() {
    char title[100];
    int i, found = 0;
    printf("Enter book title to search: ");
    scanf("%s", title);// nhap tieu de de tim kiem sach
    for (i = 0; i < bookCount; i++) {
        if (strstr(books[i].title, title)) {
            printf("Book found: ID: %d, Title: %s, Author: %s, Price: %.2f\n", books[i].id, books[i].title, books[i].author, books[i].price);
            found = 1;
        }
    }
    if (!found) printf("Book not found!\n");
}
// ham hien thi danh sach 
void listBooks() {
    int i;
    if (bookCount == 0) {
        printf("No books available.\n");// hien thi khi khong co sach nao dc luu
        return;
    }
    printf("\n%-10s/%-20s/%-20s/%-10s\n", "ID", "Title", "Author", "Price");
    printf("+-----------------------------------------------------------------------+\n");  
    for (i = 0; i < bookCount; i++) {
        printf("%-10d/%-20s/%-20s/%-10.2f\n", books[i].id, books[i].title, books[i].author, books[i].price);
    }
}
// ham sap xep sach theo gia tien
void sortBooksByPrice(int order) {
    int i, j;
    Book temp;
    for (i = 0; i < bookCount - 1; i++) {
        for (j = i + 1; j < bookCount; j++) {
            if ((order == 1 && books[i].price > books[j].price) ||
                (order == 2 && books[i].price < books[j].price)) {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    saveBooks();
    printf("Books sorted successfully.\n");
    listBooks();
}
void showSortMenu() {
    int order;
    printf("\nSort Books\n");
    printf("1. Ascending by Price\n");
    printf("2. Descending by Price\n");
    printf("Enter your choice: ");
    scanf("%d", &order);
    sortBooksByPrice(order);
}
char confirmExitOrBack() {
	char choice;
	printf(">> Go back(b) or exit(0): ");
	fflush(stdin);
	scanf("%c", &choice);
	fflush(stdin);
	return choice;
}
