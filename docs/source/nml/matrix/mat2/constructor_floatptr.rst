:orphan:

mat2: mat2(float* _xxxyyxyy)
============================

Construct a ([\**_xxxyyxyy*, \**(_xxxyyxyy + 1)*], [\**(_xxxyyxyy + 2)*, \**(_xxxyyxyy + 3)*]) matrix.

:math:`\begin{bmatrix} *\_xxxyyxyy & *(\_xxxyyxyy + 2) \\ *(\_xxxyyxyy + 1) & *(\_xxxyyxyy + 3) \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/mat2.h"
	#include <array>
	#include <iostream>

	int main() {
		std::array<float, 4> a{ 1.0f, 2.0f, 3.0f, 4.0f };
		nml::mat2 m(a.data());
		std::cout << nml::to_string(m) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[[1.000000, 2.000000], [3.000000, 4.000000]]