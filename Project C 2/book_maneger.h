#ifndef BOOK_MANAGER_H
#define BOOK_MANAGER_H

#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[100];
    char author[100];
    float price;
} Book;

extern Book books[MAX_BOOKS];  
extern int bookCount;          

void addBook();
void deleteBook();
void updateBook();
void listBooks();
void loadBooks();
void saveBooks();
char  confirmExitOrBack();
void searchBook ();
#endif
