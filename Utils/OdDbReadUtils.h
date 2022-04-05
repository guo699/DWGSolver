#pragma once

/*
从database读取图元的若干方法
*/

class OdDbReadUtils
{
public:
	static int getEntities(const OdDbDatabasePtr& pDb, OdArray<OdDbEntityPtr>& entities);

	static int getLines(const OdDbDatabasePtr& pDb, OdArray<OdDbLinePtr>& lines);

	static int getCircles(const OdDbDatabasePtr& pDb, OdArray<OdDbCirclePtr>& circles);

	static int getLayers(const OdDbDatabasePtr& pDb, OdArray<OdDbLayerTableRecordPtr>& layers);

	static int getEntitiesGivenLayer(const OdDbDatabasePtr& pDb, const OdDbLayerTableRecordPtr& layer, OdArray<OdDbEntityPtr>& entities);

	static int getEntitiesGivenLayer(const OdDbDatabasePtr& pDb, OdString layerName, OdArray<OdDbEntityPtr>& entities);

	static int getBlocks(const OdDbDatabasePtr& pDb, OdArray<OdDbBlockTableRecordPtr>& blocks);

	static int getBlockReferences(const OdDbDatabasePtr& pDb, OdArray<OdDbBlockReferencePtr>& blockrs);

	static void getDBObjectFromHandle(OdDbDatabasePtr& pDb, int value, OdDbObjectPtr& pDbobj);
};
