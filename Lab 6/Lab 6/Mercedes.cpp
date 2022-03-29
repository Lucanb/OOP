#include "Mercedes.h"
#include "Weather.h"
Mercedes::Mercedes()
{
	fuelCapacity = 40;
	fuelConsumption = 50;
	averageSpeed[Windy] = 20;
	averageSpeed[Rainy] = 30;
	averageSpeed[Cloudy] = 40;
	averageSpeed[Sunny] = 50;
	name = nullptr;
}
char* Mercedes::GetNume()
{
    return (char*)"Mercedes";
}
float Mercedes::MergeMasina(bool& a, int b, int c)
{
	int speed = averageSpeed[b];

	float hours = fuelCapacity / fuelConsumption;
	float distance = hours * speed;

	a = distance > c;
	return (hours * b / distance);
}
