#include "..\\odstd.h"
#include "Point3d.h"

namespace Geometry
{
	Point3d::Point3d()
	{
		this->m_x = 0.0;
		this->m_y = 0.0;
		this->m_z = 0.0;
	}

	Point3d::Point3d(double xx, double yy, double zz)
	{
		this->m_x = xx;
		this->m_y = yy;
		this->m_z = zz;
	}
}
