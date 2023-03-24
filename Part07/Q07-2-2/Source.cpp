#include <iostream>
using namespace std;

class Book {
private:
	char* title;	// å�� ����
	char* isbn;		// ����ǥ�ص�����ȣ
	int price;		// å�� ����

public:
	Book(const char* title, const char* isbn, int price) :price(price) {
		this->title = new char[strlen(title) + 1];
		strcpy_s(this->title, strlen(title) + 1, title);

		this->isbn = new char[strlen(isbn) + 1];
		strcpy_s(this->isbn, strlen(isbn) + 1, isbn);
	}
	void ShowBookInfo() {
		cout << "����: " << title << endl << "ISBN: " << isbn << endl << "����: " << price << endl;
	}
};

class EBook : public Book {
private:
	char* DRMKey;	// ���Ȱ��� Ű
public:
	EBook(const char* title, const char* isbn, int price, const char* DRMKey) :Book(title, isbn, price) {
		this->DRMKey = new char[strlen(DRMKey) + 1];
		strcpy_s(this->DRMKey, strlen(DRMKey) + 1, DRMKey);
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "����Ű: " << DRMKey << endl;
	}
};

int main(void) {
	Book book("���� c++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;

	EBook ebook("���� c++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}