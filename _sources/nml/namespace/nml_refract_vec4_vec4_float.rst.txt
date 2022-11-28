:orphan:

nml::vec4 nml::refract(const nml::vec4& i, const nml::vec4& n, float eta)
=========================================================================

Return the refracted direction between the incident vector *i*, the normal *n* and the ratio of indices of refraction *eta*. *n* should be normalized.

The refracted direction between the incident vector *i*, the normal *n* and the ratio of indices of refraction *eta* is calculated this way:

:math:`k = 1.0 - eta * eta * (1.0 - dot(\begin{bmatrix} n.x \\ n.y \\ n.z \\ n.w \end{bmatrix}, \begin{bmatrix} i.x \\ i.y \\ i.z \\ i.w \end{bmatrix}) * dot(\begin{bmatrix} n.x \\ n.y \\ n.z \\ n.w \end{bmatrix}, \begin{bmatrix} i.x \\ i.y \\ i.z \\ i.w \end{bmatrix}))`

:math:`\begin{cases} \begin{bmatrix} 0.0 \\ 0.0 \\ 0.0 \\ 0.0 \end{bmatrix}, & \text{if } k < 0.0 \\ eta * \begin{bmatrix} i.x \\ i.y \\ i.z \\ i.w \end{bmatrix} - (eta * dot(\begin{bmatrix} n.x \\ n.y \\ n.z \\ n.w \end{bmatrix}, \begin{bmatrix} i.x \\ i.y \\ i.z \\ i.w \end{bmatrix}) + \sqrt{k}) * \begin{bmatrix} n.x \\ n.y \\ n.z \\ n.w \end{bmatrix}, & \text{otherwise} \end{cases}`

**The refract function does not normalize the vector n.**

Example
-------

.. code-block:: cpp

	#include "include/vec4.h"
	#include <iostream>

	int main() {
		nml::vec4 i(2.0f, -2.0f, 1.0f, 0.0f);
		nml::vec4 n(0.0f, 4.0f, 0.0f, 0.0f); // n is not normalized
		n = nml::normalize(n); // Normalize n
		nml::vec4 c = nml::refract(i, n, 0.5f);
		std::cout << nml::to_string(c) << std::endl;

		return 0;
	}

Result:

.. code-block::

	[1.000000, -1.322876, 0.500000, 0.000000]