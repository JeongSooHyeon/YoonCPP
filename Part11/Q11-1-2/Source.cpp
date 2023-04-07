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
		: price(ref.price) { // 복사 생성자
		cout << "부모 클래스 복사 생성자" << endl;
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy_s(title, strlen(ref.title) + 1, ref.title);
		strcpy_s(isbn, strlen(ref.isbn) + 1, ref.isbn);
	}
	Book& operator=(const Book& ref) { // 대입 연산자
		cout << "부모 클래스 대입 연산자" << endl;
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
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
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
		cout << "자식 클래스 복사 생성자" << endl;

		DRMKey = new char[strlen(ref.DRMKey)+1];
		strcpy_s(DRMKey, strlen(ref.DRMKey) + 1, ref.DRMKey);
	}
	EBook& operator=(const EBook& ref) {
		cout << "자식 클래스 대입 연산자" << endl;
		Book::operator=(ref);
		delete[] DRMKey;
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy_s(DRMKey, strlen(ref.DRMKey) + 1, ref.DRMKey);
		return *this;
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
	~EBook() {
		delete[] DRMKey;
	}
};
int main(void) {
	Book b1("abcde", "fghij", 3);
	Book b2 = b1;	// 복사 생성자
	b1.ShowBookInfo();
	b2.ShowBookInfo();

	Book b3("hihi", "byebye", 13);
	b1 = b3;	// 대입 연산자
	b1.ShowBookInfo();
	b3.ShowBookInfo();

	EBook e1("eoeo", "ioio", 442, "flower");
	EBook e2 = e1;	// 복사 생성자
	e1.ShowBookInfo();
	e2.ShowBookInfo();

	EBook e3("moumou", "cowcouw", 9, "dog");
	e1 = e3;	// 대입 연산자
	e1.ShowBookInfo();
	e3.ShowBookInfo();


	return 0;
}