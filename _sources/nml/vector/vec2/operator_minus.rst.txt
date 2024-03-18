:orphan:

vec2: nml::vec2 operator-()
===========================

Return the negative of the current *vec2*.

The negative of a *vec2* is calculated this way:

:math:`\begin{bmatrix} x \\ y \end{bmatrix} = \begin{bmatrix} -x \\ -y \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/vec2.h"
	#include <iostream>

	int main() {
		nml::vec2 v(1.0f, 2.0f);
		std::cout << nml::to_string(-v) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[-1.000000, -2.000000]