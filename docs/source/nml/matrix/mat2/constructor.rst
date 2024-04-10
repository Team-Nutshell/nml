:orphan:

mat2: mat2()
============

Construct a ([0.0, 0.0], [0.0, 0.0]) matrix.

:math:`\begin{bmatrix} 0.0 & 0.0 \\ 0.0 & 0.0 \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/mat2.h"
	#include <iostream>

	int main() {
		nml::mat2 m;
		std::cout << nml::to_string(m) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[[0.000000, 0.000000], [0.000000, 0.000000]]