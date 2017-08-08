#include <vector>
#include <iostream>


class Neuron{};

typedef std::vector<Neuron> layer;

class ANN{
public:
	ANN(const std::vector<unsigned> &structure);
	void feedForward(const std::vector<double> &x0){} ;
	void compute_grad(const std::vector<double> &y ){};
	void getResults(std::vector<double> &y_hat) const{};

private:
	std::vector<layer> m_layers; //2D array

};

ANN::ANN(const std::vector<unsigned> &structure){
	unsigned numLayers = structure.size();
	for( unsigned layerNum=0;layerNum<numLayers;layerNum++){

		m_layers.push_back(layer());
		
		for(unsigned neuronNum=0;neuronNum<=structure[layerNum];neuronNum++){
			m_layers.back().push_back(Neuron());
			std::cout <<"Made a Neuron!"<<std::endl;
		}
	}

}








int main()
{
	std::vector<unsigned> structure;
	structure.push_back(3);
	structure.push_back(2);
	structure.push_back(1);
	ANN Net(structure);

	std::vector<double> x0;
	Net.feedForward(x0);

	std::vector<double> y;
	Net.compute_grad(y);

	std::vector<double> y_hat;
	Net.getResults(y_hat);

	return 0;

}