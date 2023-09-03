:orphan:

float nml::toDeg(const float radians)
=====================================

Return the degrees of an angle in radians.

The degrees of an angle in radians is calculated this way:
	
:math:`toDeg(radians) = radians * \frac{180.0}{\pi}`

Example
-------

.. code-block:: cpp

	#include "include/other.h"
	#include <iostream>

	int main() {
		std::cout << nml::toDeg(nml::PI) << std::endl;

		return 0;
	}

Result:

.. code-block::

	180