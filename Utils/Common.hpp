#pragma once

#include "..\Header\OdDbHeader.h"
#include "..\Header\OdGeHeader.h"
#include "OdString.h"

namespace OdaUtils
{
	/// <summary>
	/// dst �Ƿ���ȫ�� source ����
	/// </summary>
	bool isInclude(const OdGeExtents3d& source, const OdGeExtents3d& dst)
	{
		OdGePoint3d smin = source.minPoint();
		OdGePoint3d smax = source.maxPoint();
		OdGePoint3d dmin = dst.minPoint();
		OdGePoint3d dmax = dst.maxPoint();

		return smin.x < dmin.x && smin.y < dmin.y && smin.z < dmin.z && smax.x > dmax.x && smax.y > dmax.y && smax.z > dmax.z;
	}

	/// <summary>
	/// dst �Ƿ��� source �ཻ
	/// </summary>
	bool isIntersect(const OdGeExtents3d& source, const OdGeExtents3d& dst)
	{
		return true;
	}
}