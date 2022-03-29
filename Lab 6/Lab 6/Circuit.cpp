#include "Weather.h"
#include "Circuit.h"
#include <iostream>
#include "Car.h"
#include <string>
using namespace std;

Circuit::Circuit()
{
	
	masini = 0;
	vreme = Sunny;
	Distance = 0;
	Final[14] = { 0 };
	timp[21] = { 0 };
}
void Circuit::SetLenght(int n)
{
	Distance = n;
}
void Circuit::SetWeather(int a)
{
	vreme = a;
}
void Circuit::AddCar(Car* c)
{
	car[masini++] = c;
}
void Circuit::Race()
{
	for (int i = 0; i < masini; i++) {
		bool a = false;
		timp[i] = car[i]->MergeMasina(a, vreme, masini);
		Final[i] = a;
	}
}
void Circuit::ShowFinalRanks()
{
	for (int i = 0; i < masini; i++)
		cout << car[i]->GetNume() << ' ' << timp[i] << '\n';
}
void Circuit::ShowWhoDidNotFinish()
{
	for (int i = 0; i < masini; i++) {
		if (!Final[i]) {
			cout << car[i]->GetNume() <<' '<< timp[i] << '\n';
		}
	}
}





