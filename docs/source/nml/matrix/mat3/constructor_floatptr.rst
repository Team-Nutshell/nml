:orphan:

mat3: mat3(const float* _ptr)
=============================

Construct a matrix from a pointer.

:math:`\begin{bmatrix} *\_ptr & *(\_ptr + 3) & *(\_ptr + 6) \\ *(\_ptr + 1) & *(\_ptr + 4) & *(\_ptr + 7) \\ *(\_ptr + 2) & *(\_ptr + 5) & *(\_ptr + 8) \end{bmatrix}`

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