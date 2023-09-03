:orphan:

float nml::toRad(const float degrees)
=====================================

Return the radians of an angle in degrees.

The radians of an angle in degrees is calculated this way:
	
:math:`toRad(degrees) = degrees * \frac{\pi}{180.0}`

Example
-------

.. code-block:: cpp

	#include "include/other.h"
	#include <iostream>

	int main() {
		std::cout << nml::toRad(180.0f) << std::endl;

		return 0;
	}

Result:

.. code-block::

	3.14159