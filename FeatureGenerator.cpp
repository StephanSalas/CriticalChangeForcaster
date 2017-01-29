#include "FeatureGenerator.h"
#include "Utils.h"
#include <assert.h>
#include <iostream>

FeatureGenerator::FeatureGenerator(const dlib::matrix<double> data)
{
	assert(data.nc() > 1 && data.nr() > 1);
	_data = data;
}


FeatureGenerator::~FeatureGenerator()
{
}

void FeatureGenerator::generateRowWiseDiagSVD(unsigned const int WindowSize) {
	assert(WindowSize >= _data.nr());
	unsigned int leftOver = WindowSize % _data.nr();

	//! Note: set_size deletes all data from matrix and resizes
	_diagSvdData.set_size(_data.nr() - leftOver, 1);
	dlib::matrix<double> U, S, V;
	for (int i = 0; i < _data.nr() - leftOver - 1; i++) {
		dlib::svd(dlib::rowm(_data, dlib::range(i, i + WindowSize - 1)), U, S, V);
		dlib::set_rowm(_diagSvdData, i) = S(WindowSize - 1, WindowSize - 1);
	}
}

void FeatureGenerator::printdiagSvdDataLineByLine() {
	for (int i = 0; i < _diagSvdData.nr(); i++) {
		for (int j = 0; j < _diagSvdData.nc(); j++) {
			std::cout << _diagSvdData(i, j) << " " << '\n';
		}
		std::cin.ignore();
	}
}