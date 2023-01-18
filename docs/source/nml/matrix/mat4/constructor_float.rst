:orphan:

mat4: mat4(float _value)
========================

Construct a ([*_value*, *_value*, *_value*, *_value*], [*_value*, *_value*, *_value*, *_value*], [*_value*, *_value*, *_value*, *_value*]) matrix.

:math:`\begin{bmatrix} \_value & \_value & \_value & \_value \\ \_value & \_value & \_value & \_value \\ \_value & \_value & \_value & \_value \\ \_value & \_value & \_value & \_value \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/mat4.h"
	#include <iostream>

	int main() {
		nml::mat4 m(1.0f);
		std::cout << nml::to_string(m) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[[1.000000, 1.000000, 1.000000, 1.000000], [1.000000, 1.000000, 1.000000, 1.000000], [1.000000, 1.000000, 1.000000, 1.000000], [1.000000, 1.000000, 1.000000, 1.000000]]