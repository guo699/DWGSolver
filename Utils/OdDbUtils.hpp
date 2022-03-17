#pragma once

#include "OdaCommon.h"
#include "DbBlockTableRecord.h"
#include "DbLayerTableRecord.h"
#include "DbLayerTable.h"
#include "DbEntity.h"
#include "DbDatabase.h"
#include "OdArray.h"
#include "DbLine.h"
#include "DbCircle.h"

class OdDbUtils
{
public:
	static int getEntities(const OdDbDatabasePtr& pDb, OdArray<OdDbEntityPtr>& entities)
	{
		OdDbBlockTableRecordPtr pRecord = pDb->getModelSpaceId().safeOpenObject(OdDb::OpenMode::kForRead);

		OdDbObjectIteratorPtr it = pRecord->newIterator();
		for (it->start(); !it->done(); it->step()) {
			entities.append(it->entity());
		}

		return entities.size();
	}

	static int getLines(const OdDbDatabasePtr& pDb, OdArray<OdDbLinePtr>& lines)
	{
		OdDbBlockTableRecordPtr pRecord = pDb->getModelSpaceId().safeOpenObject(OdDb::OpenMode::kForRead);

		OdDbLinePtr line;
		OdDbObjectIteratorPtr it = pRecord->newIterator();
		for (it->start(); !it->done(); it->step()) 
		{
			line = OdDbLine::cast(it->entity());
			if (line != nullptr)
			{
				lines.append(line);
			}
		}

		return lines.size();
	}

	static int getCircles(const OdDbDatabasePtr& pDb, OdArray<OdDbCirclePtr>& circles)
	{
		OdDbBlockTableRecordPtr pRecord = pDb->getModelSpaceId().safeOpenObject(OdDb::OpenMode::kForRead);

		OdDbCirclePtr circle;
		OdDbObjectIteratorPtr it = pRecord->newIterator();
		for (it->start(); !it->done(); it->step())
		{
			circle = OdDbCircle::cast(it->entity());
			if (circle != nullptr)
			{
				circles.append(circle);
			}
		}

		return circles.size();
	}

	static int getLayers(const OdDbDatabasePtr& pDb, OdArray<OdDbLayerTableRecordPtr>& layers)
	{
		OdDbLayerTablePtr pLayer = pDb->getLayerTableId().safeOpenObject(OdDb::OpenMode::kForRead);

		OdDbSymbolTableIteratorPtr it = pLayer->newIterator();

		for (it->start(); !it->done(); it->step())
		{
			layers.append(it->getRecord());
		}

		return layers.size();
	}

	static int getEntitiesGivenLayer(const OdDbDatabasePtr& pDb, const OdDbLayerTableRecordPtr& layer, OdArray<OdDbEntityPtr>& entities)
	{
		OdDbBlockTableRecordPtr pRecord = pDb->getModelSpaceId().safeOpenObject(OdDb::OpenMode::kForRead);

		OdDbObjectIteratorPtr it = pRecord->newIterator();
		for (it->start(); !it->done(); it->step()) 
		{
			OdDbEntityPtr entity = it->entity();
			if (entity->layerId() == layer->objectId())
			{
				entities.append(entity);
			}
		}

		return entities.size();
	}
};