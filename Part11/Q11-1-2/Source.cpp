#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(const char* title, const char* isbn, int value)
		: price(value) {
		this->title = new char[strlen(title) + 1];
		this->isbn = new char[strlen(isbn) + 1];
		strcpy_s(this->title, strlen(title) + 1, title);
		strcpy_s(this->isbn, strlen(isbn) + 1, isbn);
	}
	Book(const Book& ref)
		: price(ref.price) { // ���� ������
		cout << "�θ� Ŭ���� ���� ������" << endl;
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy_s(title, strlen(ref.title) + 1, ref.title);
		strcpy_s(isbn, strlen(ref.isbn) + 1, ref.isbn);
	}
	Book& operator=(const Book& ref) { // ���� ������
		cout << "�θ� Ŭ���� ���� ������" << endl;
		delete[] title;
		delete[] isbn;

		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy_s(title, strlen(ref.title) + 1, ref.title);
		strcpy_s(isbn, strlen(ref.isbn) + 1, ref.isbn);

		price = ref.price;

		return *this;
	}
	void ShowBookInfo() {
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
	}
	~Book() {
		delete[] title;
		delete[] isbn;
	}
};

class EBook : public Book {
private:
	char* DRMKey;
public:
	EBook(const char* title, const char* isbn, int value, const char* key)
		:Book(title, isbn, value) {
		DRMKey = new char[strlen(key) + 1];
		strcpy_s(DRMKey, strlen(key) + 1, key);
	}
	EBook(const EBook& ref) 
		: Book(ref){
		cout << "�ڽ� Ŭ���� ���� ������" << endl;

		DRMKey = new char[strlen(ref.DRMKey)+1];
		strcpy_s(DRMKey, strlen(ref.DRMKey) + 1, ref.DRMKey);
	}
	EBook& operator=(const EBook& ref) {
		cout << "�ڽ� Ŭ���� ���� ������" << endl;
		Book::operator=(ref);
		delete[] DRMKey;
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy_s(DRMKey, strlen(ref.DRMKey) + 1, ref.DRMKey);
		return *this;
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "����Ű: " << DRMKey << endl;
	}
	~EBook() {
		delete[] DRMKey;
	}
};
int main(void) {
	Book b1("abcde", "fghij", 3);
	Book b2 = b1;	// ���� ������
	b1.ShowBookInfo();
	b2.ShowBookInfo();

	Book b3("hihi", "byebye", 13);
	b1 = b3;	// ���� ������
	b1.ShowBookInfo();
	b3.ShowBookInfo();

	EBook e1("eoeo", "ioio", 442, "flower");
	EBook e2 = e1;	// ���� ������
	e1.ShowBookInfo();
	e2.ShowBookInfo();

	EBook e3("moumou", "cowcouw", 9, "dog");
	e1 = e3;	// ���� ������
	e1.ShowBookInfo();
	e3.ShowBookInfo();


	return 0;
}