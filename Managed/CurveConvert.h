#pragma once

using namespace Geometry;

class CurveConvert
{
public:
	static Line3d^ Transform(OdDbLinePtr pLine);
};
