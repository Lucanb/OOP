#pragma once
#include "Car.h"
class Mazda : public Car
{
public:
	Mazda();
//private:
	virtual char* GetNume() override;
	virtual float MergeMasina(bool&, int, int) override;
};

