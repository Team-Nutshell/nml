:orphan:

nml::mat4 perspectiveLH(const float fovY, const float aspectRatio, const float near, const float far)
=====================================================================================================

Return a left-hand perspective projection matrix.

The left-hand perspective projection matrix is calculated this way:

:math:`\begin{bmatrix} \frac{1.0}{aspectRatio * tan(\frac{fovY}{2.0})} & 0.0 & 0.0 & 0.0 \\ 0.0 & \frac{1.0}{tan(\frac{fovY}{2.0})} & 0.0 & 0.0 \\ 0.0 & 0.0 & \frac{far}{far - near} & -\frac{far * near}{far - near} \\ 0.0 & 0.0 & 1.0 & 0.0 \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "../nml/include/mat4.h"
	#include <iostream>

	int main() {
		nml::mat4 m = nml::perspectiveLH(0.785f, 16.0f / 9.0f, 0.03f, 100.0f);
		std::cout << nml::to_string(m) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[[1.358760, 0.000000, 0.000000, 0.000000], [0.000000, 2.415574, 0.000000, 0.000000], [0.000000, 0.000000, 1.000300, 1.000000], [0.000000, 0.000000, -0.030009, 0.000000]]