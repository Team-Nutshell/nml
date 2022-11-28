:orphan:

vec3: vec3(float _xyz)
======================

Construct a (*_xyz*, *_xyz*, *_xyz*) vector.

Example
-------

.. code-block:: cpp

	#include "include/vec3.h"
	#include <iostream>

	int main() {
		nml::vec3 v(1.0f);
		std::cout << nml::to_string(v) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[1.000000, 1.000000, 1.000000]