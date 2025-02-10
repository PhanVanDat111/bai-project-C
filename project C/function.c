// ham show chuc nang quan li sach

 void showMenu (){
	printf("+-----------------------------+\n");
	printf("++book management system++c\n");
	printf("1.Add new books\n");
	printf("2.Display all books\n");
	printf("3.Search for books\n");
	printf("4.Edit book information\n");
	printf("5.Delete books\n");
	printf("6.Exit\n");
	printf("+------------------------------+\n");	     
}


// ham dung de hien thi sach
void displaybooks() {
    printf("\n--- Book List ---\n");
    for (int i = 0; i <bookcount; i++) {
    printf("ID: %d, Title: %s, Author: %s, Year: %d, Price: %.2f\n", books[i].bookID, books[i].title, books[i].author, books[i].year, books[i].price);
    
// ham them sach
Book newBook;
    printf("\nEnter new book details:\n");
    printf("ID: ");
    scanf("%d", &newBook.bookID);
    printf("Title: ");
    scanf("%s", newBook.title);
    printf("Author: ");
    scanf("%s", newBook.author);
    printf("Price: ");
    scanf("%f", &newBook.price);
    bookList[bookCount++] = newBook;
    printf("Book added successfully!\n");
}
