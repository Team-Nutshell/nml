:orphan:

mat4: nml::mat4 nml::mat4::identity()
=====================================

Return a ([1.0, 0.0, 0.0, 0.0], [0.0, 1.0, 0.0, 0.0], [0.0, 0.0, 1.0, 0.0], [0.0, 0.0, 0.0, 1.0]) identity matrix.

:math:`\begin{bmatrix} 1.0 & 0.0 & 0.0 & 0.0 \\ 0.0 & 1.0 & 0.0 & 0.0 \\ 0.0 & 0.0 & 1.0 & 0.0 \\ 0.0 & 0.0 & 0.0 & 1.0 \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/mat4.h"
	#include <iostream>

	int main() {
		nml::mat4 m = nml::mat4::identity();
		std::cout << nml::to_string(m) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[[1.000000, 0.000000, 0.000000, 0.000000], [0.000000, 1.000000, 0.000000, 0.000000], [0.000000, 0.000000, 1.000000, 0.000000], [0.000000, 0.000000, 0.000000, 1.000000]]