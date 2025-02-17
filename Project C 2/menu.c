// menu.c
#include <stdio.h>
#include "menu.h"
#include "book_maneger.h"

void showMenu() {
    int choice;
    do {
        printf("\nBook Management System\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Update Book\n");
        printf("4. Search Book\n");
        printf("5. List Books\n");
        printf("6. Sort Books by Price\n");
        printf("7. Exit\n");
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 7);
}
