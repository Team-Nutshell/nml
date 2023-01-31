:orphan:

mat2: mat2(nml::mat3 _mat)
==========================

Construct a ([*_mat.x.x*, *_mat.x.y*], [*_mat.y.x*, *_mat.y.y*]) matrix.

:math:`\begin{bmatrix} \_mat.x.x & \_mat.y.x \\ \_mat.x.y & \_mat.y.y \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/mat2.h"
	#include "include/mat3.h"
	#include <iostream>

	int main() {
		nml::mat3 a(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
		nml::mat2 b(a);
		std::cout << nml::to_string(b) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[[1.000000, 2.000000], [4.000000, 5.000000]]