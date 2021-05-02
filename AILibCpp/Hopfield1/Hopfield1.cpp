// Hopfield1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "hopfield.h"
#include "network.h"

int main()
{
    std::cout << "Hopfield Network Example!\n";

	int patrn1[] = { 1,0,1,0 }, i;
	int wt1[] = { 0, -3, 3, -3 };
	int wt2[] = { -3, 0, -3, 3 };
	int wt3[] = { 3, -3, 0, -3 };
	int wt4[] = { -3, 3, -3, 0 };

	std::cout << "\nTHIS PROGRAM IS FOR A HOPFIELD NETWORK WITH A SINGLE LAYER OF";
	std::cout << "\n4 FULLY INTERCONNECTED NEURONS. THE NETWORK SHOULD RECALL THE";
	std::cout << "\nPATTERNS 1010 and 0101 CORRECTLY.\n";

	//Initialize the network by calling its constructor.
	//The constructor calls neurons constructor as many times
	//as the number of neurons in the network.
	network h1(wt1, wt2, wt3, wt4);

	//Present a pattern to the network and get the activations
	//of the neurons
	h1.activation(patrn1);

	//Check if the pattern given is correctly recalled and give
	//message relevant
	for(i=0; i<4; i++)
	{
		if (h1.output[i] == patrn1[i])
			std::cout << "\n pattern= " << patrn1[i] << " output = " << h1.output[i] << " component matches";
		else
			std::cout << "\n pattern = " << patrn1[i] << "output = " << h1.output[i] << " discrepancy occurred";
	}

	std::cout << "\n\n";
	int patrn2[] = { 0, 1, 0, 1 };
	h1.activation(patrn2);
	for(i=0; i<4; i++)
	{
		if (h1.output[i] == patrn2[i])
			std::cout << "\n pattern= " << patrn2[i] <<
			" output = " << h1.output[i] << " component matches";
		else
			std::cout << "\n pattern= " << patrn2[i] <<
			" output = " << h1.output[i] <<
			" discrepancy occurred";
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
