#pragma once
#include "Car.h"
class Ford : public Car
{
public:
	Ford();
//private:
       char* GetNume() override;
	   float MergeMasina(bool&, int, int) override;
};

