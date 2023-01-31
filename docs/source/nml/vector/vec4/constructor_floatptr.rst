:orphan:

vec4: vec4(const float* _ptr)
=============================

Construct a vector from a pointer.

:math:`\begin{bmatrix} *\_ptr \\ *(\_ptr + 1) \\ *(\_ptr + 2) \\ *(\_ptr + 3) \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/vec4.h"
	#include <array>
	#include <iostream>

	int main() {
		std::array<float, 4> a{ 1.0f, 2.0f, 3.0f, 4.0f };
		nml::vec4 v(a.data());
		std::cout << nml::to_string(v) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[1.000000, 2.000000, 3.000000, 4.000000]