#pragma once

using namespace System;

namespace Geometry
{
	public ref class Cirlce3d
	{
	public:
		Cirlce3d(Point3d^ center, Double radius, Vector3d^ normal);

	private:
		Point3d^ m_center;
		double m_radius;
		Vector3d^ m_normal;
	};

}
