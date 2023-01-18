:orphan:

mat4: mat4(nml::vec4 _x, float _yx, float _yy, float _yz, float _yw, nml::vec4 _z, float _wx, float _wy, float _wz, float _ww)
==============================================================================================================================

Construct a ([*_x.x*, *_x.y*, *_x.z*, *_x.w*], [*_yx*, *_yy*, *_yz*, *_yw*], [*_z.x*, *_z.y*, *_z.z*, *_z.w*], [*_wx*, *_wy*, *_wz*, *_ww*]) matrix.

:math:`\begin{bmatrix} \_x.x & \_yx & \_z.x & \_wx \\ \_x.y & \_yy & \_z.y & \_wy \\ \_x.z & \_yz & \_z.z & \_wz \\ \_x.w & \_yw & \_z.w & \_ww \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/mat4.h"
	#include <iostream>

	int main() {
		nml::mat4 m(nml::vec4(1.0f, 2.0f, 3.0f, 4.0f), 5.0f, 6.0f, 7.0f, 8.0f, nml::vec4(9.0f, 10.0f, 11.0f, 12.0f), 13.0f, 14.0f, 15.0f, 16.0f);
		std::cout << nml::to_string(m) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[[1.000000, 2.000000, 3.000000, 4.000000], [5.000000, 6.000000, 7.000000, 8.000000], [9.000000, 10.000000, 11.000000, 12.000000], [13.000000, 14.000000, 15.000000, 16.000000]]