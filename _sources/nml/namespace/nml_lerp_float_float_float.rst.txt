:orphan:

float nml::lerp(const float& a, const float& b, const float interpolationValue)
===============================================================================

Return the linear interpolation between two scalars and an interpolation value.

The linear interpolation between two scalars and an interpolation value is calculated this way:

:math:`lerp(a, b, interpolationValue) = a + interpolationValue * (b - a)`

Example
-------

.. code-block:: cpp

	#include "include/other.h"
	#include <iostream>

	int main() {
		std::cout << nml::lerp(0.0f, 2.0f, 0.5f) << std::endl;

		return 0;
	}

Result:

.. code-block::

	1