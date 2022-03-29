#include "Dacia.h"
#include "Weather.h"
Dacia::Dacia()
{
	fuelCapacity = 40;
	fuelConsumption = 50;
	averageSpeed[Windy] = 20;
	averageSpeed[Rainy] = 30;
	averageSpeed[Cloudy] = 40;
	averageSpeed[Sunny] = 50;
	name = nullptr;
}
char* Dacia::GetNume()
{
    return (char*)"Dacia";
}
float Dacia::MergeMasina(bool& a, int b, int c)
{
	int speed = averageSpeed[b];

	float hours = fuelCapacity / fuelConsumption;
	float distance = hours * speed;

	a = distance > c;
	return (hours * b / distance);
}
