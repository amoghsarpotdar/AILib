#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fuzzifier.h"

#include <iostream>

void category::setname(char *n)
{
#pragma warning(suppress : 4996)
	strcpy(name, n);
}

char * category::getname()
{
	return name;
}

void category::setval(float &h, float &m, float &l)
{
	highval = h;
	midval = m;
	lowval = l;
}

float category::getlowval()
{
	return lowval;
}

float category::getmidval()
{
	return midval;
}

float category::gethighval()
{
	return highval;
}

/// <summary>
/// Returns relative membership of an input in a category
/// with a maximum of 1.0
/// </summary>
/// <param name="input"></param>
/// <returns></returns>
float category::getshare(const float & input)
{
	float output;
	float midlow, highmid;

	midlow = midval - lowval;
	highmid = highval - midval;

	if ((input <= lowval) || (input >= highval))
		output = 0;
	else
	{
		if (input > midval)
			output = (highval - input) / highmid;
		else if (input == midval)
			output = 1.0;
		else
			output = (input - lowval) / midlow;
	}
	return output;
}

/// <summary>
/// Random number generator
/// Will always return an integer in the range up to maxval.
/// </summary>
/// <param name="maxval"></param>
/// <returns></returns>
int randomnum(int maxval)
{
	srand((unsigned)time(NULL));  // NOLINT(cert-msc51-cpp)
	return rand() % maxval;
}

/// <summary>
/// A fuzzifier that takes category low/mid/high and category name
/// and fuzzifies an input based on the total number of categories
/// and the membership in each category.
/// </summary>
void main()
{
	int i = 0, j,numcat, randnum;
	float l, m, h, inval = 1.0;

	char input[30] = "                             ";
	category* ptr[10];
	float relprob[10];
	float total = 0, runtotal = 0;

	//Input the category information; terminate with 'done'

	while(1)
	{
		std::cout << "\nPlease type in a category name, e.g. Cool\n";
		std::cout << "Enter one word without spaces\n";
		std::cout << "When you are done, type 'done':\n\n";

		ptr[i] = new category;
		std::cin >> input;

		if ((input[0] == 'd' && input[1] == 'o' && input[2] == 'n' && input[3] == 'e'))
			break;

		ptr[i]->setname(input);

		std::cout << "\nType in the lowval, midval and highval\n";
		std::cout << "for each category, separated by spaces\n";
		std::cout << "e.g. 1.0 3.0 5.0 : \n\n";

		std::cin >> l >> m >> h;
		ptr[i]->setval(h, m, l);

		i++;
	}

	numcat = i;			//Category count

	//Input the data to fuzzify
	std::cout << "\n\n";
	std::cout << "===================================================\n";
	std::cout << "=====Fuzzifier is ready for the data===============\n";
	std::cout << "===================================================\n";

	while(1)
	{
		std::cout << "\ninput a data value, type 0 to terminate\n";

		std::cin >> inval;

		if (inval == 0) break;

		//calculate relative probabilities of input
		//being in each category.

		total = 0;
		for(j=0; j<numcat; j++)
		{
			relprob[j] = 100 * ptr[j]->getshare(inval);
			total += relprob[j];
		}

		if(total==0)
		{
			std::cout << "data out of range\n";
			exit(1);
		}

		randnum = randomnum((int)total);

		j = 0;
		runtotal = relprob[0];

		while((runtotal<randnum) && (j<numcat))
		{
			j++;
			runtotal += relprob[j];
		}

		std::cout << "\nOutput fuzzy category is ==> " << ptr[j]->getname() << "<== \n";
		std::cout << "category\t" << "membership\n";

		for (j = 0; j < numcat;j++)
		{
			std::cout << ptr[j]->getname() << "\t\t" << (relprob[j] / total) << "\n";
		}
	}
	std::cout << "\n\nAll done. Have a fuzzy day ahead!!! \n";
}
