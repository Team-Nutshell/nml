:orphan:

mat2: mat2(const float* _ptr)
=============================

Construct a matrix from a pointer.

:math:`\begin{bmatrix} *\_ptr & *(\_ptr + 2) \\ *(\_ptr + 1) & *(\_ptr + 3) \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/mat2.h"
	#include <array>
	#include <iostream>

	int main() {
		std::array<float, 4> a{ 1.0f, 2.0f, 3.0f, 4.0f };
		nml::mat2 m(a.data());
		std::cout << nml::to_string(m) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[[1.000000, 2.000000], [3.000000, 4.000000]]