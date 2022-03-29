#pragma once
#include "Car.h"
class Dacia : public Car
{
public:
	Dacia();
//private:
	char* GetNume() override;
	float MergeMasina(bool&, int, int) override;
};

