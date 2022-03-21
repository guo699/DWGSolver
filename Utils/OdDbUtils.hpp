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
#include "DbBlockReference.h"

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


	/// <summary>
	/// 获取所有图层
	/// </summary>
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

	/// <summary>
	/// 获取某一图层内的所有实体
	/// </summary>

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

	/// <summary>
	/// 获取某一图层内的所有实体
	/// </summary>
	static int getEntitiesGivenLayer(const OdDbDatabasePtr& pDb, OdString layerName, OdArray<OdDbEntityPtr>& entities)
	{
		OdDbBlockTableRecordPtr pRecord = pDb->getModelSpaceId().safeOpenObject(OdDb::OpenMode::kForRead);

		OdDbObjectIteratorPtr it = pRecord->newIterator();
		for (it->start(); !it->done(); it->step())
		{
			OdDbEntityPtr entity = it->entity();
			if (entity->layer() == layerName)
			{
				entities.append(entity);
			}
		}

		return entities.size();
	}

	/// <summary>
	/// 获取所有的块
	/// </summary>

	static int getBlocks(const OdDbDatabasePtr& pDb,OdArray<OdDbBlockTableRecordPtr>& blocks)
	{
		OdDbBlockTablePtr pBt = pDb->getBlockTableId().safeOpenObject(OdDb::OpenMode::kForRead);
		
		OdDbSymbolTableIteratorPtr pSt = pBt->newIterator();
		for (pSt->start(); !pSt->done(); pSt->step())
		{
			OdDbBlockTableRecordPtr pRecord = pSt->getRecord();
			blocks.append(pRecord);
		}

		return blocks.size();
	}

	/// <summary>
	/// 获取所有的块引用
	/// </summary>

	static int getBlockReferences(const OdDbDatabasePtr& pDb, OdArray<OdDbBlockReferencePtr>& blockrs)
	{
		OdDbBlockTableRecordPtr pRecord = pDb->getModelSpaceId().safeOpenObject(OdDb::OpenMode::kForRead);

		OdDbBlockReferencePtr blockRef;
		OdDbObjectIteratorPtr it = pRecord->newIterator();
		for (it->start(); !it->done(); it->step())
		{
			blockRef = OdDbBlockReference::cast(it->entity());
			if (blockRef != nullptr)
			{
				blockrs.append(blockRef);
			}
		}

		return blockrs.size();
	}

	/// <summary>
	/// 根据句柄获取对象
	/// </summary>

	static OdDbObjectPtr getDBObjectFromHandle(OdDbDatabasePtr& pDb, int value)
	{
		OdDbHandle handle(value);
		OdDbObjectPtr pObj = pDb->getOdDbObjectId(handle).safeOpenObject(OdDb::OpenMode::kForRead);

		return pObj;
	}	
};