:orphan:

nml::quat nml::axisAngleToQuat(const nml::vec3& axis, float angle)
==================================================================

Return a quaternion from an axis and an angle.

The conversion from an axis and and angle to a quaternion is calculated this way:

:math:`cos(\frac{angle}{2}) + (axis.x*sin(\frac{angle}{2}))i + (axis.y*sin(\frac{angle}{2}))j + (axis.z*sin(\frac{angle}{2}))k`

Example
-------

.. code-block:: cpp

	#include "include/quat.h"
	#include "include/vec3.h"
	#include "include/other.h"
	#include <iostream>

	int main() {
		nml::vec3 axis = nml::vec3(1.0f, 0.0f, 0.0f);
		nml::quat q = nml::axisAngleToQuat(axis, nml::toRad(10.0f));
		std::cout << nml::to_string(q) << std::endl;

		return 0;
	}

Result:

.. code-block::

	0.996195 + 0.087156i + 0.000000j + 0.000000k