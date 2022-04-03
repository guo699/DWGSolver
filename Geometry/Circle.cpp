#include "stdafx.h"
#include "Circle.h"

namespace Geometry
{
	Cirlce3d::Cirlce3d(Point3d^ center, Double radius, Vector3d^ normal)
	{
		this->m_center = center;
		this->m_radius = radius;
		this->m_normal = normal;
	}
}