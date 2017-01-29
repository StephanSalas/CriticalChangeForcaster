#pragma once

#include "dlib\matrix.h"

class FeatureGenerator
{
public:
	//! Constructor
	FeatureGenerator(const dlib::matrix<double> data);
	~FeatureGenerator();

	//! Class Methods
	void generateRowWiseDiagSVD(unsigned const int WindowSize);
	void printdiagSvdDataLineByLine();

private:
	dlib::matrix<double> _data;
	dlib::matrix<double> _diagSvdData;
};
