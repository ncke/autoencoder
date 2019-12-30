#include <iostream>
#include <cmath>

using namespace std;

class BaseNeuron {
public:
	void load(double value);
	void add(double value);
	double getOutput();

private:
	double ivalue;
	double ovalue;
};

void BaseNeuron::load(double value) {
	ivalue = value;
	ovalue = value;
}

void BaseNeuron::add(double value) {
	ivalue += value;
}

double BaseNeuron::getOutput() {
	return ovalue;
}

class InterfaceNeuron: BaseNeuron {};

class ComputeNeuron: BaseNeuron {
public:
	void reset();
	void compute();

private:
	double sigmoid(double x);
};

double ComputeNeuron::sigmoid(double x) {
	double ex = exp(ex);
	return ex / (ex + 1.0);
}

void ComputeNeuron::reset() {
	load(0.0);
}

void ComputeNeuron::compute() {
	auto result = sigmoid(sum);
	load(result);
}

class Autoencoder {
public:
	Autoencoder(int sizes[]); 
	
private:
	int *architecture;
};

int main() {
  cout << "autoencoder" << endl;

}
