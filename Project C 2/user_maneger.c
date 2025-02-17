// customer_manager.c
#include <stdio.h>
#include <string.h>
#include"user_manager.h"
#define MAX_CUSTOMERS 100

typedef struct {
    int id;
    char name[100];
    char phone[20];
    char address[200];
} Customer;

Customer customers[MAX_CUSTOMERS];
int customerCount = 0;
void   showUserMenu()
               {
    int choice;
    do {
    	system("cls");
    	printf("+---------------------------------+\n");
        printf("\nCustomer Management System\n");
        printf("1. Add Customer\n");
        printf("2. List Customers\n");
        printf("3. Back to Main Menu\n");
        printf("+---------------------------------+\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                //addCustomer();
                break;
            case 2:
                //listCustomers();
                break;
            case 3:
                return;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 3);
}
void addUser() {
    if (customerCount < MAX_CUSTOMERS) {
        printf("Enter customer ID: ");
        scanf("%d", &customers[customerCount].id);
        printf("Enter customer name: ");
        scanf("%s", customers[customerCount].name);
        printf("Enter phone number: ");
        scanf("%s", customers[customerCount].phone);
        printf("Enter address: ");
        scanf("%s", customers[customerCount].address);
        customerCount++;
        printf("Customer added successfully!\n");
    } else {
        printf("Customer database is full!\n");
    }
}

void listCustomers() {
    int i;
    if (customerCount == 0) {
        printf("No customers available.\n");
        return;
    }
    printf("Customer List:\n");
    for (i = 0; i < customerCount; i++) {
        printf("ID: %d, Name: %s, Phone: %s, Address: %s\n", customers[i].id, customers[i].name, customers[i].phone, customers[i].address);
    }
}
