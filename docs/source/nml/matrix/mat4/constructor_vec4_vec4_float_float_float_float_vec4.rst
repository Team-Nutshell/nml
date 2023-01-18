:orphan:

mat4: mat4(nml::vec4 _x, nml::vec4 _y, float _zx, float _zy, float _zz, float _zw, nml::vec4 _w)
================================================================================================

Construct a ([*_x.x*, *_x.y*, *_x.z*, *_x.w*], [*_y.x*, *_y.y*, *_y.z*, *_y.w*], [*_zx*, *_zy*, *_zz*, *_zw*], [*_w.x*, *_w.y*, *_w.z*, *_w.w*]) matrix.

:math:`\begin{bmatrix} \_x.x & \_y.x & \_zx & \_w.x \\ \_x.y & \_y.y & \_zy & \_w.y \\ \_x.z & \_y.z & \_zz & \_w.z \\ \_x.w & \_y.w & \_zw & \_w.w \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/mat4.h"
	#include <iostream>

	int main() {
		nml::mat4 m(nml::vec4(1.0f, 2.0f, 3.0f, 4.0f), nml::vec4(5.0f, 6.0f, 7.0f, 8.0f), 9.0f, 10.0f, 11.0f, 12.0f, nml::vec4(13.0f, 14.0f, 15.0f, 16.0f));
		std::cout << nml::to_string(m) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[[1.000000, 2.000000, 3.000000, 4.000000], [5.000000, 6.000000, 7.000000, 8.000000], [9.000000, 10.000000, 11.000000, 12.000000], [13.000000, 14.000000, 15.000000, 16.000000]]