﻿#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

// #include <klein/klein.hpp>
// using namespace kln;

#include "pga3d.h"

int main()
{
	// Elements of the even subalgebra (scalar + bivector + pss) of unit length are motors
	PGA3D rot = rotor(PI / 2.0f, e1 * e2);

	// The outer product ^ is the MEET. Here we intersect the yz (x=0) and xz (y=0) planes.
	PGA3D ax_z = e1 ^ e2;

	// line and plane meet in point. We intersect the line along the z-axis (x=0,y=0) with the xy (z=0) plane.
	PGA3D orig = ax_z ^ e3;

	// We can also easily create points and join them into a line using the regressive (vee, &) product.
	PGA3D px = point(1.0, 0.0, 0.0);
	PGA3D line = orig & px;

	// Lets also create the plane with equation 2x + z - 3 = 0
	PGA3D p = plane(2, 0, 1, -3);

	// rotations work on all elements
	PGA3D rotated_plane = rot * p * ~rot;
	PGA3D rotated_line = rot * line * ~rot;
	PGA3D rotated_point = rot * px * ~rot;

	// See the 3D PGA Cheat sheet for a huge collection of useful formulas
	PGA3D point_on_plane = (p | px) * p;

	// Some output.
	printf("a point       : "); px.log();
	printf("a line        : "); line.log();
	printf("a plane       : "); p.log();
	printf("a rotor       : "); rot.log();
	printf("rotated line  : "); rotated_line.log();
	printf("rotated point : "); rotated_point.log();
	printf("rotated plane : "); rotated_plane.log();
	printf("point on plane: "); point_on_plane.normalized().log();
	printf("point on torus: "); point_on_torus(0.0f, 0.0f).log();
	(e0 - 1.0f).log();
	(1.0f - e0).log();

	return 0;
}
