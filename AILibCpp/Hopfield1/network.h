#ifndef __NETWORK_H__
#define __NETWORK_H__

#include "hopfield.h"

class network
{
public:
	neuron nrn[4];
	int output[4];
	int threshold(int);
	void activation(int j[4]);
	network(int*, int*, int*, int*);
};

#endif

