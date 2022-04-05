#include "..\\odstd.h"
#include "Line3d.h"

namespace Geometry
{
	Line3d::Line3d(Point3d^ start, Point3d^ end)
	{
		this->m_start = start;
		this->m_end = end;
	}
}