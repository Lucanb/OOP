#pragma once
#include"GlobalFunctions.h";
#include<cstring>
int compareByName (Luca& a, Luca& b)
{
	char s[101]="";
	char c[101] = "";
	a.getnume(s);
	b.getnume(c);
	return strcmp(s, c);
}
int Math(Luca& a, Luca& b)

	{
		if (a.getmath() > b.getmath())
			return 1;
		else
			if (a.getmath() < b.getmath())
				return -1;
			else
				return 0;
	}

int History(Luca& a, Luca& b)
	{
		if (a.gethist() > b.gethist())
			return 1;
		else
			if (a.gethist() < b.gethist())
				return -1;
			else
				return 0;
	}
int Eng(Luca& a, Luca& b)
{
	
		if (a.gethist() > b.gethist())
			return 1;
		else
			if (a.gethist() < b.gethist())
				return -1;
			else
				return 0;
}
int Compareavg(Luca& a, Luca& b)
{
		if (a.avgMedia() > b.avgMedia())
			return 1;
		else
			if (a.avgMedia() < b.avgMedia())
				return -1;
			else
				return 0;
}