:orphan:

quat: nml::quat operator-()
===========================

Return the negative of the current *quat*.

The negative of a *quat* is calculated this way:

:math:`a + bi + cj + dk = -a + -bi + -cj + -dk`

Example
-------

.. code-block:: cpp

	#include "include/quat.h"
	#include <iostream>

	int main() {
		nml::quat q(1.0f, 0.25f, 0.5f, 0.75f);
		std::cout << nml::to_string(-q) << std::endl;

		return 0;
	}

Result:

.. code-block::

	-0.500000 + -0.125000i + -0.250000j + -0.375000k