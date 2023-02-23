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
	void ShowNameCardInfo() {
		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << companyName << endl;
		cout << "��ȭ��ȣ: " << phoneNumber << endl;
		cout << "����: ";

		switch (rank)
		{
		case 0:
			cout << "���" << endl << endl;
			break;
		case 1:
			cout << "����" << endl << endl;
			break;
		case 2:
			cout << "�븮" << endl << endl;
			break;
		case 3:
			cout << "����" << endl << endl;
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
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();

	return 0;
}