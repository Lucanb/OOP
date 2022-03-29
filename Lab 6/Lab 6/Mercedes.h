#pragma once
#include "Car.h"
class Mercedes : public Car
{
public:
	Mercedes();
//private:
	 char* GetNume() override;
	 float MergeMasina(bool&, int, int) override;
};

