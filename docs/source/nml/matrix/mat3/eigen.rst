:orphan:

mat3: std::array\<std::pair\<float, vec3\>, 3\> eigen() const
=============================================================

Return three eigenvalues and eigenvectors of the matrix.

The method used to calculate these eigenvalues and eigenvectors can be found `here <https://www.researchgate.net/publication/344819102_Eigenvalues_and_Eigenvectors_for_33_Symmetric_Matrices_An_Analytical_Approach>`_.

Example
-------

.. code-block:: cpp

	#include "include/mat3.h"
	#include <iostream>

	int main() {
		nml::mat3 m = nml::mat3::identity();
		std::array<std::pair<float, nml::vec3>, 3> eigen = m.eigen();
		std::cout << eigen[0].first << " - " << nml::to_string(eigen[0].second) << std::endl;
		std::cout << eigen[1].first << " - " << nml::to_string(eigen[1].second) << std::endl;
		std::cout << eigen[2].first << " - " << nml::to_string(eigen[2].second) << std::endl;

		return 0;
	}

Result:

.. code-block::

	1 - [1.000000, 0.000000, 0.000000]
	1 - [0.000000, 1.000000, 0.000000]
	1 - [0.000000, 0.000000, 1.000000]