:orphan:

vec2: vec2(nml::vec3 _xyz)
==========================

Construct a (*_xyz.x*, *_xyz.y*) vector.

:math:`\begin{bmatrix} \_xyz.x \\ \_xyz.y \end{bmatrix}`

Example
-------

.. code-block:: cpp

	#include "include/vec2.h"
	#include "include/vec3.h"
	#include <iostream>

	int main() {
		nml::vec3 a(1.0f, 2.0f, 3.0f);
		nml::vec2 b(a);
		std::cout << nml::to_string(b) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[1.000000, 2.000000]