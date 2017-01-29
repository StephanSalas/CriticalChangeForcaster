#include "dlib\all\source.cpp"
#include "FeatureGenerator.h"
#include "dlib\matrix.h"

int main() {
	dlib::matrix<double> a(10, 10);
	for (int i = 0; i < a.nr(); i++) {
		for (int j = 0; j < a.nc(); j++) {
			a(i, j) = i * j * std::sin(i*j);
		}
	}

	FeatureGenerator b(a);
	b.generateRowWiseDiagSVD(3);
	b.printdiagSvdDataLineByLine();
}
