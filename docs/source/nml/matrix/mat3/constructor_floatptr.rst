:orphan:

mat3: mat3(float* _xxxyxzyxyyyzzxzyzz)
======================================

Construct a ([*_xxxyxzyxyyyzzxzyzz*, \**(_xxxyxzyxyyyzzxzyzz + 1)*, \**(_xxxyxzyxyyyzzxzyzz + 2)*], [\**(_xxxyxzyxyyyzzxzyzz + 3)*, \**(_xxxyxzyxyyyzzxzyzz + 4)*, \**(_xxxyxzyxyyyzzxzyzz + 5)*], [\**(_xxxyxzyxyyyzzxzyzz + 6)*, \**(_xxxyxzyxyyyzzxzyzz + 7)*, \**(_xxxyxzyxyyyzzxzyzz + 8)*]) matrix.

:math:`\begin{bmatrix} *\_xxxyxzyxyyyzzxzyzz & *(\_xxxyxzyxyyyzzxzyzz + 3) & *(\_xxxyxzyxyyyzzxzyzz + 6) \\ *(\_xxxyxzyxyyyzzxzyzz + 1) & *(\_xxxyxzyxyyyzzxzyzz + 4) & *(\_xxxyxzyxyyyzzxzyzz + 7) \\ *(\_xxxyxzyxyyyzzxzyzz + 2) & *(\_xxxyxzyxyyyzzxzyzz + 5) & *(\_xxxyxzyxyyyzzxzyzz + 8) \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/mat3.h"
	#include <array>
	#include <iostream>

	int main() {
		std::array<float, 9> a{ 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f };
		nml::mat3 m(a.data());
		std::cout << nml::to_string(m) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[[1.000000, 2.000000, 3.000000], [4.000000, 5.000000, 6.000000], [7.000000, 8.000000, 9.000000]]