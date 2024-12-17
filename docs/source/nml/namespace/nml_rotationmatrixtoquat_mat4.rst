:orphan:

nml::quat nml::rotationMatrixToQuat(const nml::mat4& mat)
=========================================================

Return a quaternion from a rotation matrix.

The conversion from a rotation matrix to a quaternion is calculated this way:

:math:`trace = mat.x.x + mat.y.y + mat.z.z`

if

:math:`trace \gt 0`

:math:`S = \sqrt{1 + trace} * 2`

:math:`quat.a = \frac{S}{4}`

:math:`quat.b = \frac{mat.y.z - mat.z.y}{S}`

:math:`quat.c = \frac{mat.z.x - mat.x.z}{S}`

:math:`quat.d = \frac{mat.x.y - mat.y.x}{S}`

else if

:math:`(mat.x.x \gt mat.y.y) \&\& (mat.x.x \gt mat.z.z)`

:math:`S = \sqrt{1 + mat.x.x - mat.y.y - mat.z.z} * 2`

:math:`quat.a = \frac{mat.y.z - mat.z.y}{S}`

:math:`quat.b = \frac{S}{4}`

:math:`quat.c = \frac{mat.y.x + mat.x.y}{S}`

:math:`quat.d = \frac{mat.z.x + mat.x.z}{S}`

else if

:math:`(mat.y.y \gt mat.z.z)`

:math:`S = \sqrt{1 + mat.x.x - mat.y.y - mat.z.z} * 2`

:math:`quat.a = \frac{mat.z.x - mat.x.z}{S}`

:math:`quat.b = \frac{mat.y.x + mat.x.y}{S}`

:math:`quat.c = \frac{S}{4}`

:math:`quat.d = \frac{mat.z.y + mat.y.z}{S}`

else

:math:`S = \sqrt{1 + mat.z.z - mat.x.x - mat.y.y} * 2`

:math:`quat.a = \frac{mat.x.y - mat.y.x}{S}`

:math:`quat.b = \frac{mat.z.x + mat.x.z}{S}`

:math:`quat.c = \frac{mat.z.y + mat.y.z}{S}`

:math:`quat.d = \frac{S}{4}`

Example
-------

.. code-block:: cpp

	#include "include/quat.h"
	#include "include/mat4.h"
	#include <iostream>

	int main() {
		nml::mat4 m(-1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
		nml::quat q = nml::rotationMatrixToQuat(m);
		std::cout << nml::to_string(q) << std::endl;

		return 0;
	}

Result:

.. code-block::

	0.000000 + 0.000000i + 1.000000j + 0.000000k