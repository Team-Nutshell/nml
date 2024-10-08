:orphan:

mat3: mat3(float _xx, float _xy, float _xz, const nml::vec3& _y, float _zx, float _zy, float _zz)
=================================================================================================

Construct a ([*_xx*, *_xy*, *_xz*], [*_y.x*, *_y.y*, *_y.z*], [*_zx*, *_zy*, *_zz*]) matrix.

:math:`\begin{bmatrix} \_xx & \_y.x & \_zx \\ \_xy & \_y.y & \_zy \\ \_xz & \_y.z & \_zz \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/mat3.h"
	#include <iostream>

	int main() {
		nml::mat3 m(1.0f, 2.0f, 3.0f, nml::vec3(4.0f, 5.0f, 6.0f), 7.0f, 8.0f, 9.0f);
		std::cout << nml::to_string(m) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[[1.000000, 2.000000, 3.000000], [4.000000, 5.000000, 6.000000], [7.000000, 8.000000, 9.000000]]