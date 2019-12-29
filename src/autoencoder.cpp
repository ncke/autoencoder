#include <iostream>
#include <cmath>

using namespace std;

class Neuron {

	private:

	double sum;

	double sigmoid(double x) {
		double ex = exp(x);
		return ex / (ex + 1.0);
	}

	public:

	void reset() {
		sum = 0.0;
	}

	void addInput(double input) {
		sum += input;
	}

	double getOutput() {
		return sigmoid(sum);
	}

};

class Layer {

	private:

	Neuron *neurons;

	public:

	Layer(int neuronCount) {
		neurons = new Neuron[neuronCount];
		for ( int n = 0; n < neuronCount; n++ ) {
			neurons[n] = Neuron();	
		}
	}

};

int main() {
  cout << "autoencoder" << endl;

	Layer layer = Layer(20);
}
