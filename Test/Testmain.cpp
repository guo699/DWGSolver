#include "OdaCommon.h"
#include "OdPlatformSettings.h"
#include "RxDynamicModule.h"
#include "toString.h"

#include "..\Utils\MyServices.h"
#include "..\Utils\OdDbUtils.hpp"
#include "..\Header\OdDbHeader.h"

#include "TeighaLibrary.h"

#include "iostream"

ODRX_DECLARE_STATIC_MODULE_ENTRY_POINT(ModelerModule);
ODRX_DECLARE_STATIC_MODULE_ENTRY_POINT(OdRecomputeDimBlockModule);
ODRX_DECLARE_STATIC_MODULE_ENTRY_POINT(ExFieldEvaluatorModule);
ODRX_DECLARE_STATIC_MODULE_ENTRY_POINT(TD_3DSolidHistoryModule);

ODRX_BEGIN_STATIC_MODULE_MAP()
ODRX_DEFINE_STATIC_APPLICATION(OdModelerGeometryModuleName, ModelerModule)
ODRX_DEFINE_STATIC_APPLICATION(OdRecomputeDimBlockModuleName, OdRecomputeDimBlockModule)
ODRX_END_STATIC_MODULE_MAP()

#define DWGFILEPATH L"C:\\Users\\IronBin\\Desktop\\test.dwg"

int main()
{
	ODRX_INIT_STATIC_MODULE_MAP();
	OdStaticRxObject<MyServices> service;
	odInitialize(&service);

	try
	{
		OdDbDatabasePtr pDb = service.readFile(DWGFILEPATH);
		OdDbBlockTableRecordPtr pRecord = pDb->getModelSpaceId().safeOpenObject(OdDb::OpenMode::kForRead);

		OdArray<OdDbLinePtr> lines;
		OdArray<OdDbEntityPtr> entities;
		OdArray<OdDbCirclePtr> circles;
		OdArray<OdDbLayerTableRecordPtr> layers;

		OdDbUtils::getEntities(pDb, entities);
		OdDbUtils::getLines(pDb, lines);
		OdDbUtils::getCircles(pDb, circles);
		OdDbUtils::getLayers(pDb, layers);

		std::cout << "entities size = " << entities.size() << std::endl;
		std::cout << "lines size = " << lines.size() << std::endl;
		std::cout << "circles size = " << circles.size() << std::endl;
		std::cout << "layers size = " << layers.size() << std::endl;

		for (auto layer = layers.begin();layer!=layers.end();layer++)
		{
			std::cout << (*layer)->getName() << std::endl;
		}
	}
	catch (...)
	{
		odPrintConsoleString(L"Error On Business Logic");
	}

	try
	{
		odUninitialize();
	}
	catch (...)
	{
		odPrintConsoleString(L"Error On odUninitialze");
	}

	return 0;
}