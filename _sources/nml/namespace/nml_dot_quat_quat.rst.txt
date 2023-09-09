:orphan:

float nml::dot(const nml::quat& a, const nml::quat& b)
======================================================

Return the dot product between two *quat*.

The dot product of two *quat* is calculated this way:
	
:math:`\begin{bmatrix} a.a \\ a.b \\ a.c \\ a.d \end{bmatrix} \cdot \begin{bmatrix} b.a \\ b.b \\ b.c \\ b.d \end{bmatrix} = (a.a * b.a) + (a.b * b.b) + (a.c * b.c) + (a.d * b.d)`

Example
-------

.. code-block:: cpp

	#include "include/quat.h"
	#include <iostream>

	int main() {
		nml::quat a(2.0f, -2.0f, 1.0f, 0.0f);
		nml::quat b(0.0f, 1.0f, 0.0f, 0.0f);
		float c = nml::dot(a, b);
		std::cout << c << std::endl;

		return 0;
	}

Result:

.. code-block::

	-2