:orphan:

nml::vec3 nml::quatToEulerAngles(const nml::quat& qua)
======================================================

Return a *vec3* representing euler angles in radians from a quaternion.

The conversion from quaternion to euler angles is calculated by :doc:`converting the quaternion to a rotation matrix </nml/namespace/nml_quattorotationmatrix_quat>` and :doc:`converting this rotation matrix to euler angles </nml/namespace/nml_rotationmatrixtoeulerangles_mat4>`.

Example
-------

.. code-block:: cpp

	#include "include/vec3.h"
	#include "include/quat.h"
	#include <iostream>

	int main() {
		nml::quat q(1.0f, 1.0f, 1.0f, 1.0f);
		q = nml::normalize(q);
		nml::vec3 v = nml::quatToEulerAngles(q);
		std::cout << nml::to_string(v) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[1.570796, 0.000000, 1.570796]