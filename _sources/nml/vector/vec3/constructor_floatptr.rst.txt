:orphan:

vec3: vec3(float* _xyz)
=======================

Construct a (\**_xyz*, \**(_xyz + 1)*, \**(_xyz + 2)*) vector.

:math:`\begin{bmatrix} *\_xyz \\ *(\_xyz + 1) \\ *(\_xyz + 2) \end{bmatrix}`

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