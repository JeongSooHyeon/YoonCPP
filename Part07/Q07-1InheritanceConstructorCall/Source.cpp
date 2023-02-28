#include <iostream>
using namespace std;

class Car
{
private:
	int gasolineGauge;
public:
	Car() : gasolineGauge(10) 
	{
		cout << "가솔린 생성자" << endl;
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
		cout << "하이브리드 생성자" << endl;
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
		cout << "워터 생성자" << endl;
	}
	void ShowCurrentGauge() {
		cout << "잔여 가솔린: " << GetGasGauge() << endl;
		cout << "잔여 전기량: " << GetElecGauge() << endl;
		cout << "잔여 워터량: " << waterGauge << endl;
	}
};
int main(void) {
	HybridWaterCar waterCar;
	waterCar.ShowCurrentGauge();

	return 0;
}