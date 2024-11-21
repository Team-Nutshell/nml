:orphan:

void nml::decomposeTransform(const nml::mat4& transform, nml::vec3& translation, nml::quat& rotation, nml::vec3& scale)
=======================================================================================================================

Decompose a transform matrix into a translation vector, a rotation quaternion and a scale vector.

The decomposition of a transform matrix into a translation vector, a rotation quaternion and a scale vector is calculated this way:

:math:`translation = \begin{bmatrix} transform.w.x \\ transform.w.y \\ transform.w.z \end{bmatrix}`

:math:`rotationMatrix = \begin{bmatrix} \frac{transform.x}{scale.x} & 0 \\ \frac{transform.y}{scale.y} & 0 \\ \frac{transform.z}{scale.z} & 0 \\ (0, 0, 0) & 1 \end{bmatrix}`

rotation = :doc:`rotationMatrixToQuat(rotationMatrix) </nml/namespace/nml_rotationmatrixtoquat_mat4>`

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