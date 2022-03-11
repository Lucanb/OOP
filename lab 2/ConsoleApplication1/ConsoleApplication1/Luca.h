#pragma once
class Luca
{
private:
	char nume[15];
	float notamath;
	float notaeng;
	float notahist;
public:
	void Init();
	void getnume(char s[]);
	float getmath();
	float geteng();
	float gethist();
	bool setmath(float x);  //merge cu inline getmath{
                              //  return getmath() ;
                                //}
    void setnume(const char x[]);
	bool seteng(float x);
	bool sethist(float x);
	float avgMedia();
	void print();
};

