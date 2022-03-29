#pragma once
class Car
{
protected:
	int fuelCapacity;
	int fuelConsumption;
	int averageSpeed[3];
	char* name;

public:
	virtual char* GetNume() = 0;
	virtual float MergeMasina(bool&, int, int) = 0;
};