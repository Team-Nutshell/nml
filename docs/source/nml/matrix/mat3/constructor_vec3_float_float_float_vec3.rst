:orphan:

mat3: mat3(const nml::vec3& _x, float _yx, float _yy, float _yz, const nml::vec3& _z)
=====================================================================================

Construct a ([*_x.x*, *_x.y*, *_x.z*], [*_yx*, *_yy*, *_yz*], [*_z.x*, *_z.y*, *_z.z*]) matrix.

:math:`\begin{bmatrix} \_x.x & \_yx & \_z.x \\ \_x.y & \_yy & \_z.y \\ \_x.z & \_yz & \_z.z \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/mat3.h"
	#include <iostream>

	int main() {
		nml::mat3 m(nml::vec3(1.0f, 2.0f, 3.0f), 4.0f, 5.0f, 6.0f, nml::vec3(7.0f, 8.0f, 9.0f));
		std::cout << nml::to_string(m) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[[1.000000, 2.000000, 3.000000], [4.000000, 5.000000, 6.000000], [7.000000, 8.000000, 9.000000]]