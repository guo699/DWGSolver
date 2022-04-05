#include "..\\odstd.h"
#include "CurveConvert.h"

using namespace Geometry;

Line3d^ CurveConvert::Transform(OdDbLinePtr pLine)
{
	OdGePoint3d start = pLine->startPoint();
	OdGePoint3d end = pLine->endPoint();

	Point3d^ p0 = gcnew Point3d(start.x, start.y, start.z);
	Point3d^ p1 = gcnew Point3d(end.x, end.y, end.z);

	Line3d^ line = gcnew Line3d(p0, p1);

	return line;
}
