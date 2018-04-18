
#include "stdafx.h"

int main()
{
	auto nn = make_mlp<activation::sigmoid>({ 2, 8, 1 });

	std::vector<vec_t> input{ { 0, 0 },{ 0, 1 },{1,0},{1,1} };
	std::vector<vec_t> output{ { 0 },{ 1 },{1},{0} };

	adagrad optimizer;
	nn.fit<mse>(optimizer, input, output, 1, 30);

	for(auto i = input.begin(); i != input.end(); ++i)
	{
		std::cout << nn.predict(*i)[0] << std::endl;
	}
}

