:orphan:

mat3: mat3(float _xxxyxzyxyyyzzxzyzz)
=====================================

Construct a ([*_xxxyxzyxyyyzzxzyzz*, *_xxxyxzyxyyyzzxzyzz*, *_xxxyxzyxyyyzzxzyzz*], [*_xxxyxzyxyyyzzxzyzz*, *_xxxyxzyxyyyzzxzyzz*, *_xxxyxzyxyyyzzxzyzz*], [*_xxxyxzyxyyyzzxzyzz*, *_xxxyxzyxyyyzzxzyzz*, *_xxxyxzyxyyyzzxzyzz*]) matrix.

Example
-------

.. code-block:: cpp

	#include "include/mat3.h"
	#include <iostream>

	int main() {
		nml::mat3 m(1.0f);
		std::cout << nml::to_string(m) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[[1.000000, 1.000000, 1.000000], [1.000000, 1.000000, 1.000000], [1.000000, 1.000000, 1.000000]]