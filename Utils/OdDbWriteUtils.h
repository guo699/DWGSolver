#pragma once


class OdDbWriteUtils
{
public:
	static void AddDbText(OdDbDatabasePtr& pDb, OdString text);

	static OdDbLinePtr AddLine(OdDbDatabasePtr& pDb, const OdGePoint3d& start, const OdGePoint3d& end);

	static OdDbCirclePtr AddCircle(OdDbDatabasePtr& pDb, const OdGePoint3d& center, double radius);

	static OdArray<OdDbLinePtr> AddRectange(OdDbDatabasePtr& pDb, const OdGePoint3d& leftBottom, const OdGePoint3d& rightTop);

	static void reSave(OdDbDatabasePtr& pDb);
};
