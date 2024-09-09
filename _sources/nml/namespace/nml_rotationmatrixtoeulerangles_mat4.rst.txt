:orphan:

nml::vec3 nml::rotationMatrixToEulerAngles(const nml::mat4& mat)
================================================================

Return a *vec3* representing euler angles in radians from a 3D rotation matrix.

The conversion from a rotation matrix to euler angles is calculated this way:

:math:`eulerAngles.y = asin(clamp(mat.z.z, -1, 1))`

:math:`if eulerAngles.y \lt (1 - \varepsilon)`

:math:`eulerAngles.x = atan2(-mat.z.y, mat.z.z) \\ eulerAngles.z = atan2(-mat.y.x, mat.x.x)`

:math:`else`

:math:`eulerAngles.x = atan2(mat.y.z, mat.y.y) \\ eulerAngles.z = 0`

Example
-------

.. code-block:: cpp

	#include "include/vec3.h"
	#include "include/mat4.h"
	#include <iostream>

	int main() {
		nml::mat4 m = nml::rotate(nml::toRad(-10.0f), nml::vec3(1.0f, 0.0f, 0.0f)) * nml::rotate(nml::toRad(20.0f), nml::vec3(0.0f, 1.0f, 0.0f)) * nml::rotate(nml::toRad(30.0f), nml::vec3(0.0f, 0.0f, 1.0f));
		nml::vec3 v = nml::rotationMatrixToEulerAngles(m);
		std::cout << nml::to_string(m) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[-10.000000, 19.999998, 30.000000]