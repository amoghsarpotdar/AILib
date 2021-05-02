#include <stdio.h>
#include <iostream>
#include "network.h"
#include "hopfield.h"

int network::threshold(int k)
{
	if (k >= 0)
		return 1;
	else
		return 0;
}

network::network(int a[4], int b[4], int c[4], int d[4])
{
	nrn[0] = neuron(a);
	nrn[1] = neuron(b);
	nrn[2] = neuron(c);
	nrn[3] = neuron(d);
}

void network::activation(int *patrn)
{
	int i, j;

	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			std::cout << "\n nrn [" << i << "].weightv[" << j << "] is "
				<< nrn[i].weightv[j];
		}
		nrn[i].activation = nrn[i].act(4, patrn);
		std::cout << "\nactivation is " << nrn[i].activation;
		output[i] = threshold(nrn[i].activation);
		std::cout << "\noutput value is " << output[i] << "\n";
	}
}
