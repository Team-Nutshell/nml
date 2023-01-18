:orphan:

mat4: mat4(float* _ptr)
=======================

Construct a matrix from a pointer.

:math:`\begin{bmatrix} *\_ptr & *(\_ptr + 4) & *(\_ptr + 8) & *(\_ptr + 12) \\ *(\_ptr + 1) & *(\_ptr + 5) & *(\_ptr + 9) & *(\_ptr + 13) \\ *(\_ptr + 2) & *(\_ptr + 6) & *(\_ptr + 10) & *(\_ptr + 14) \\ *(\_ptr + 3) & *(\_ptr + 7) & *(\_ptr + 11) & *(\_ptr + 15) \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/mat4.h"
	#include <array>
	#include <iostream>

	int main() {
		std::array<float, 16> a{ 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f };
		nml::mat4 m(a.data());
		std::cout << nml::to_string(m) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[[1.000000, 2.000000, 3.000000, 4.000000], [5.000000, 6.000000, 7.000000, 8.000000], [9.000000, 10.000000, 11.000000, 12.000000], [13.000000, 14.000000, 15.000000, 16.000000]]