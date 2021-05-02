#ifndef __HOPFIELD_H__
#define __HOPFIELD_H__

#include <stdio.h>
#include <iostream>
#include <math.h>

class neuron
{
protected:
	int activation;
	friend class network;
public:
	int weightv[4];
	neuron() {};
	neuron(int* j);
	int act(int, int*);
};

#endif