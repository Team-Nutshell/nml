:orphan:

vec4: vec4(float _value)
========================

Construct a (*_value*, *_value*, *_value*, *_value*) vector.

:math:`\begin{bmatrix} \_value \\ \_value \\ \_value \\ \_value \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/vec4.h"
	#include <iostream>

	int main() {
		nml::vec4 v(1.0f);
		std::cout << nml::to_string(v) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[1.000000, 1.000000, 1.000000, 1.000000]