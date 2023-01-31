:orphan:

mat2: mat2(nml::vec2 _x, nml::vec2 _y)
======================================

Construct a ([*_x.x*, *_x.y*], [*_y.x*, *_y.y*]) matrix.

:math:`\begin{bmatrix} \_x.x & \_y.x \\ \_x.y & \_y.y \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/mat2.h"
	#include <iostream>

	int main() {
		nml::mat2 m(nml::vec2(1.0f, 2.0f), nml::vec2(3.0f, 4.0f));
		std::cout << nml::to_string(m) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[[1.000000, 2.000000], [3.000000, 4.000000]]