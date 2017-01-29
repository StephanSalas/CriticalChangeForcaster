#pragma once
#include "dlib\matrix.h"

namespace Utils {
	template <typename T>
	void printMatrixLinebyLine(dlib::matrix<T>* m) {
		if (*m.nc == 0 && *m.nr() == 0) {
			std::cout << "Nothing in This Matrix" << std::endl;
		}
		for (int i = 0; i < *m.nr(); i++) {
			for (int j = 0; j < *m.nc(); i++) {
				std::cout << *m(i, j) << 
					" " << '\n';
			}
			std::cin.ignore();
		}
	}
}
