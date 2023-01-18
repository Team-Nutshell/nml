:orphan:

mat3: mat3(float _value)
========================

Construct a ([*_value*, *_value*, *_value*], [*_value*, *_value*, *_value*], [*_value*, *_value*, *_value*]) matrix.

:math:`\begin{bmatrix} \_value & \_value & \_value \\ \_value & \_value & \_value \\ \_value & \_value & \_value \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/mat3.h"
	#include <iostream>

	int main() {
		nml::mat3 m(1.0f);
		std::cout << nml::to_string(m) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[[1.000000, 1.000000, 1.000000], [1.000000, 1.000000, 1.000000], [1.000000, 1.000000, 1.000000]]