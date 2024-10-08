:orphan:

mat2: mat2(float _xx, float _xy, const nml::vec2& _y)
=====================================================

Construct a ([*_xx*, *_xy*], [*_y.x*, *_y.y*]) matrix.

:math:`\begin{bmatrix} \_xx & \_y.x \\ \_xy & \_y.y \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/mat2.h"
	#include <iostream>

	int main() {
		nml::mat2 m(1.0f, 2.0f, nml::vec2(3.0f, 4.0f));
		std::cout << nml::to_string(m) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[[1.000000, 2.000000], [3.000000, 4.000000]]