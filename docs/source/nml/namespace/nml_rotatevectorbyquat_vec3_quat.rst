:orphan:

nml::vec3 rotateVectorByQuat(const nml::vec3& vec, const nml::quat& qua)
========================================================================

Return a vector which is the vector vec rotated by the quaternion qua.

The rotation of a vector by a quaternion is calculated this way:

:math:`vec + (((\begin{bmatrix} qua.b \\ qua.c \\ qua.d \end{bmatrix} \cross vec) * qua.a) + (\begin{bmatrix} qua.b \\ qua.c \\ qua.d \end{bmatrix} \cross (\begin{bmatrix} qua.b \\ qua.c \\ qua.d \end{bmatrix} \cross vec))) * 2.0`

Example
-------

.. code-block:: cpp

	#include "include/quat.h"
	#include "include/vec3.h"
	#include "include/other.h"
	#include <iostream>

	int main() {
		nml::vec3 direction = nml::vec3(1.0f, 0.0f, 0.0f);
		nml::quat rotation = nml::axisAngleToQuat(nml::vec3(0.0f, 1.0f, 0.0f), nml::toRad(90.0f));
		nml::vec3 rotatedDirection = nml::rotateVectorByQuat(direction, rotation);
		std::cout << nml::to_string(rotatedDirection) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[-0.000000, 0.000000, -1.000000]