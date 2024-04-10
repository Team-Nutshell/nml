:orphan:

void nml::decomposeTransform(const nml::mat4& transform, nml::vec3& translation, nml::quat& rotation, nml::vec3& scale)
=======================================================================================================================

Decompose a transform matrix into a translation vector, a rotation quaternion and a scale vector.

The decomposition of a transform matrix into a translation vector, a rotation quaternion and a scale vector is calculated this way:

:math:`translation = \begin{bmatrix} transform.w.x \\ transform.w.y \\ transform.w.z \end{bmatrix}`

:math:`rotation.a = \frac{\sqrt{1 + \frac{transform.x.x}{\left \| transform.x \right \|} + \frac{transform.y.y}{\left \| transform.y \right \|} + \frac{transform.z.z}{\left \| transform.z \right \|}}}{2}`

:math:`rotation.b = \frac{\frac{transform.z.y}{\left \| transform.z \right \|} - \frac{transform.y.z}{\left \| transform.y \right \|}}{4 * rotation.a}`

:math:`rotation.c = \frac{\frac{transform.x.z}{\left \| transform.x \right \|} - \frac{transform.z.x}{\left \| transform.z \right \|}}{4 * rotation.a}`

:math:`rotation.d = \frac{\frac{transform.y.x}{\left \| transform.y \right \|} - \frac{transform.x.y}{\left \| transform.x \right \|}}{4 * rotation.a}`

:math:`scale = \begin{bmatrix} \left \| transform.x \right \| \\ \left \| transform.y \right \| \\ \left \| transform.z \right \| \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/vec3.h"
	#include "include/mat4.h"
	#include "include/quat.h"
	#include <iostream>

	int main() {
		nml::mat4 transform = nml::mat4::identity();
		nml::vec3 translation;
		nml::quat rotation;
		nml::vec3 scale;
		nml::decomposeTransform(transform, translation, rotation, scale);
		std::cout << "Translation: " << nml::to_string(translation) << std::endl << "Rotation: " << nml::to_string(rotation) << std::endl << "Scale: " << nml::to_string(scale) << std::endl; 

		return 0;
	}

Result:

.. code-block::

	Translation: [0.000000, 0.000000, 0.000000]
	Rotation: 1.000000 + 0.000000i + 0.000000j + 0.000000k
	Scale: [1.000000, 1.000000, 1.000000]