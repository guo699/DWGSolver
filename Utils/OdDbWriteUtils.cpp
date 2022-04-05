#pragma once

#include "..\\odstd.h"
#include "OdDbWriteUtils.h"

void OdDbWriteUtils::AddDbText(OdDbDatabasePtr& pDb, OdString text)
{
}

OdDbLinePtr OdDbWriteUtils::AddLine(OdDbDatabasePtr& pDb, const OdGePoint3d& start, const OdGePoint3d& end)
{
	OdDbBlockTableRecordPtr pRecord = pDb->getModelSpaceId().safeOpenObject(OdDb::OpenMode::kForWrite);
	OdDbLinePtr line = OdDbLine::createObject();
	line->setStartPoint(start);
	line->setEndPoint(end);
	line->setDatabaseDefaults(pDb);
	pRecord->appendOdDbEntity(line);

	return line;
}

OdDbCirclePtr OdDbWriteUtils::AddCircle(OdDbDatabasePtr& pDb, const OdGePoint3d& center, double radius)
{
	OdDbBlockTableRecordPtr pRecord = pDb->getModelSpaceId().safeOpenObject(OdDb::OpenMode::kForWrite);
	OdDbCirclePtr circle = OdDbCircle::createObject();
	circle->setCenter(center);
	circle->setRadius(radius);
	circle->setNormal(OdGeVector3d::kZAxis);

	circle->setDatabaseDefaults(pDb);
	pRecord->appendOdDbEntity(circle);

	return circle;
}

OdArray<OdDbLinePtr> OdDbWriteUtils::AddRectange(OdDbDatabasePtr& pDb, const OdGePoint3d& leftBottom, const OdGePoint3d& rightTop)
{
	OdArray<OdDbLinePtr> rect;
	OdDbBlockTableRecordPtr pRecord = pDb->getModelSpaceId().safeOpenObject(OdDb::OpenMode::kForWrite);

	OdDbLinePtr line1 = OdDbLine::createObject();
	OdDbLinePtr line2 = OdDbLine::createObject();
	OdDbLinePtr line3 = OdDbLine::createObject();
	OdDbLinePtr line4 = OdDbLine::createObject();

	rect.append(line1);
	rect.append(line2);
	rect.append(line3);
	rect.append(line4);

	OdGePoint3d leftTop(leftBottom.x, rightTop.y, 0);
	OdGePoint3d rightBottom(rightTop.x, leftBottom.y, 0);

	line1->setStartPoint(leftTop);
	line1->setEndPoint(rightTop);

	line2->setStartPoint(rightTop);
	line2->setEndPoint(rightBottom);

	line3->setStartPoint(rightBottom);
	line3->setEndPoint(leftBottom);

	line4->setStartPoint(leftBottom);
	line4->setEndPoint(leftTop);


	line1->setDatabaseDefaults(pDb);
	line2->setDatabaseDefaults(pDb);
	line3->setDatabaseDefaults(pDb);
	line4->setDatabaseDefaults(pDb);

	pRecord->appendOdDbEntity(line1);
	pRecord->appendOdDbEntity(line2);
	pRecord->appendOdDbEntity(line3);
	pRecord->appendOdDbEntity(line4);

	return rect;
}

void OdDbWriteUtils::reSave(OdDbDatabasePtr& pDb)
{
	OdString file = pDb->getFilename();
	pDb->writeFile(file, OdDb::SaveType::kDwg, OdDb::DwgVersion::kDHL_CURRENT);
}


