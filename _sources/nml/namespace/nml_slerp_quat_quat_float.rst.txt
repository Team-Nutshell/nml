:orphan:

quat nml::slerp(const quat& a, const quat& b, const float interpolationValue)
=============================================================================

Return the spherical linear interpolation between two *quat* and an interpolation value.

Example
-------

.. code-block:: cpp

	#include "include/quat.h"
	#include <iostream>

	int main() {
		nml::quat a = nml::quat(1.0f, 2.0f, 3.0f, 4.0f);
		nml::quat b = nml::quat(4.0f, 3.0f, 2.0f, 1.0f);
		std::cout << nml::to_string(nml::slerp(a, b, 0.5f)) << std::endl;

		return 0;
	}

Result:

.. code-block::

	0.500000 + 0.500000i + 0.500000j + 0.500000k