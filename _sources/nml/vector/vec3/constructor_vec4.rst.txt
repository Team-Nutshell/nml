:orphan:

vec3: vec3(const nml::vec4& _xyzw)
==================================

Construct a (*_xyzw.x*, *_xyzw.y*, *_xyzw.z*) vector.

:math:`\begin{bmatrix} \_xyzw.x \\ \_xyzw.y \\ \_xyzw.z \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/vec3.h"
	#include "include/vec4.h"
	#include <iostream>

	int main() {
		nml::vec4 a(1.0f, 2.0f, 3.0f, 4.0f);
		nml::vec3 b(a);
		std::cout << nml::to_string(b) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[1.000000, 2.000000, 3.000000]