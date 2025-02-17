// main.c
#include <stdio.h>
#include "menu.h"
#include "book_maneger.h"
#include "user_manager.h"
#include "data.h"
#include<stdlib.h>

int main() {
	loadBooks();
    int choice;
    do {
    	system("cls");
        printf("\nMain Menu\n");
        printf("+----------------------+\n");
        printf("1. Book Management\n");
        printf("2. User Management\n");
        printf("3. Exit\n");
        printf("+----------------------+\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showBookMenu();
                
                break;
            case 2:
                showUserMenu();
                break;
            case 3:
                 printf("Exiting\n");
                  
                break;
            default:
                 printf("Invalid choice, please try again.\n");
        }
    } while (choice != 3);
         return 0;}
