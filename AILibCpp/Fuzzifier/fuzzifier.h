#pragma once
class category
{
private:
	char name[30];
	float lowval, highval, midval;					//Represent the values on the graph

public:
	category() {};
	void setname(char *);
	char* getname();
	void setval(float&, float&, float&);
	float getlowval();
	float getmidval();
	float gethighval();


	float getshare(const float&);

	~category() {};
};

int randnum(int);
