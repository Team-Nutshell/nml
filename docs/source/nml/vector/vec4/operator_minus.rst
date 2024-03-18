:orphan:

vec4: nml::vec4 operator-()
===========================

Return the negative of the current *vec4*.

The negative of a *vec4* is calculated this way:

:math:`\begin{bmatrix} x \\ y \\ z \\ w \end{bmatrix} = \begin{bmatrix} -x \\ -y \\ -z \\ -w \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/vec4.h"
	#include <iostream>

	int main() {
		nml::vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
		std::cout << nml::to_string(-v) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[-1.000000, -2.000000, -3.000000, -4.000000]