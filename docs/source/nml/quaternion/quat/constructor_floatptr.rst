:orphan:

quat: quat(const float* _ptr)
=============================

Construct a quaternion from a pointer.

:math:`*\_ptr + *(\_ptr + 1)i + *(\_ptr + 2)j + *(\_ptr + 3)k`

Example
-------

.. code-block:: cpp

	#include "include/quat.h"
	#include <array>
	#include <iostream>

	int main() {
		std::array<float, 4> a{ 1.0f, 0.25f, 0.5f, 0.75f };
		nml::quat q(a.data());
		std::cout << nml::to_string(q) << std::endl;

		return 0;
	}

Result:

.. code-block::

	1.000000 + 0.250000i + 0.500000j + 0.750000k