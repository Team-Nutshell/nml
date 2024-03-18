:orphan:

vec3: nml::vec3 operator-()
===========================

Return the negative of the current *vec3*.

The negative of a *vec3* is calculated this way:

:math:`\begin{bmatrix} x \\ y \\ z \end{bmatrix} = \begin{bmatrix} -x \\ -y \\ -z \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/vec3.h"
	#include <iostream>

	int main() {
		nml::vec3 v(1.0f, 2.0f, 3.0f);
		std::cout << nml::to_string(-v) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[-1.000000, -2.000000, -3.000000]