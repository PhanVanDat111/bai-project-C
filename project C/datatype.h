// noi khai bao cac struct
#include<stdbool.h>

struct date{
	int month,day,year;// ngay, thang , nam
};

struct book{
	Book books[100];
	int bookCount=0;
	char bookID[10];// khai bao dia chi id cua sach
	char title[30];// tieu de sach
	char author[20];// khai bao tac gia
	int quantity;// khai bao so luong sach
	int price;// gia tien cua sach
	struct date pudlication;
};


struct member{
	char memberID[10];
	char name[25];
	char phone[10];
	char status;
	char book brrowedbooks[];

};
Book books[MAX_BOOKS];
Customer customers[MAX_CUSTOMERS];
int book_count = 0;
int customer_count = 0;
