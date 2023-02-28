#include <iostream>
using namespace std;

class Car
{
private:
	int gasolineGauge;
public:
	Car() : gasolineGauge(10) 
	{
		cout << "���ָ� ������" << endl;
	}
	int GetGasGauge() {
		return gasolineGauge;
	}
};

class HybridCar : public Car
{
private:
	int electricGauge;
public:
	HybridCar() : Car(), electricGauge(50) {
		cout << "���̺긮�� ������" << endl;
	}
	int GetElecGauge() {
		return electricGauge;
	}
};

class HybridWaterCar :public HybridCar {
private:
	int waterGauge;
public:
	HybridWaterCar() : HybridCar(), waterGauge(100) {
		cout << "���� ������" << endl;
	}
	void ShowCurrentGauge() {
		cout << "�ܿ� ���ָ�: " << GetGasGauge() << endl;
		cout << "�ܿ� ���ⷮ: " << GetElecGauge() << endl;
		cout << "�ܿ� ���ͷ�: " << waterGauge << endl;
	}
};
int main(void) {
	HybridWaterCar waterCar;
	waterCar.ShowCurrentGauge();

	return 0;
}