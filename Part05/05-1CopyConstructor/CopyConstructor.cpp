#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS {
	enum { CLERK, SENIOR, ASSIST, MANAGER };
}

class NameCard {
private:
	char* name;
	char* companyName;
	char* phoneNumber;
	int rank;

public:
	NameCard(const char* myname, const char* mycompany, const char* mynumber, const int myrank)
		: rank(myrank)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);

		len = strlen(mycompany) + 1;
		companyName = new char[len];
		strcpy_s(companyName, len, mycompany);

		len = strlen(mynumber) + 1;
		phoneNumber = new char[len];
		strcpy_s(phoneNumber, len, mynumber);

	}
	NameCard(const NameCard& copy) : rank(copy.rank) {
		int len = strlen(copy.name) + 1;
		name = new char[len];
		strcpy_s(name, len, copy.name);

		len = strlen(copy.companyName) + 1;
		companyName = new char[len];
		strcpy_s(companyName, len, copy.companyName);

		len = strlen(copy.phoneNumber) + 1;
		phoneNumber = new char[len];
		strcpy_s(phoneNumber, len, copy.phoneNumber);
	}
	void ShowNameCardInfo() {
		cout << "이름: " << name << endl;
		cout << "회사: " << companyName << endl;
		cout << "전화번호: " << phoneNumber << endl;
		cout << "직급: ";

		switch (rank)
		{
		case 0:
			cout << "사원" << endl << endl;
			break;
		case 1:
			cout << "주임" << endl << endl;
			break;
		case 2:
			cout << "대리" << endl << endl;
			break;
		case 3:
			cout << "과장" << endl << endl;
			break;
		default:
			break;
		}
	}
	~NameCard() {
		delete[]name;
		delete[]companyName;
		delete[]phoneNumber;
	}
};
int main(void) {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSENIOR;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
	return 0;
}