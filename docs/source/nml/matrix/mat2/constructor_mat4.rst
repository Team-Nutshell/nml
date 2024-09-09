:orphan:

mat2: mat2(const nml::mat4& _mat)
=================================

Construct a ([*_mat.x.x*, *_mat.x.y*], [*_mat.y.x*, *_mat.y.y*]) matrix.

:math:`\begin{bmatrix} \_mat.x.x & \_mat.y.x \\ \_mat.x.y & \_mat.y.y \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/mat2.h"
	#include "include/mat4.h"
	#include <iostream>

	int main() {
		nml::mat4 a(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
		nml::mat2 b(a);
		std::cout << nml::to_string(b) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[[1.000000, 2.000000], [5.000000, 6.000000]]