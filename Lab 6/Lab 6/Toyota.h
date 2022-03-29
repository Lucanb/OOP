#pragma once
#include "Car.h"
class Toyota: public Car
{
public:
	Toyota();
//private:
        char* GetNume() override;
        float MergeMasina(bool&, int, int) override;
};

