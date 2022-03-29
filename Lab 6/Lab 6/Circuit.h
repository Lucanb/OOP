#pragma once
#include "Dacia.h"
#include "Toyota.h"
#include "Mercedes.h"
#include "Ford.h"
#include "Mazda.h"
#include <string>
class Circuit
{
private:
	int Distance;
	Car* car[12];
	float timp[20];
	float Final[13];

	int masini;
	int vreme;

public:
	Circuit();
   
	void SetLenght(int);
	void SetWeather(int);
	void AddCar(Car* c);

	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
  
};