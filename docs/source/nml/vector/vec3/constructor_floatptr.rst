:orphan:

vec3: vec3(const float* _ptr)
=============================

Construct a vector from a pointer.

:math:`\begin{bmatrix} *\_ptr \\ *(\_ptr + 1) \\ *(\_ptr + 2) \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/vec3.h"
	#include <array>
	#include <iostream>

	int main() {
		std::array<float, 3> a{ 1.0f, 2.0f, 3.0f };
		nml::vec3 v(a.data());
		std::cout << nml::to_string(v) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[1.000000, 2.000000, 3.000000]