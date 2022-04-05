#include "..\\odstd.h"
#include "DwgReader.h"

//modules
ODRX_DECLARE_STATIC_MODULE_ENTRY_POINT(ModelerModule);
ODRX_DECLARE_STATIC_MODULE_ENTRY_POINT(OdRecomputeDimBlockModule);
ODRX_DECLARE_STATIC_MODULE_ENTRY_POINT(ExFieldEvaluatorModule);
ODRX_DECLARE_STATIC_MODULE_ENTRY_POINT(TD_3DSolidHistoryModule);

ODRX_BEGIN_STATIC_MODULE_MAP()
ODRX_DEFINE_STATIC_APPLICATION(OdModelerGeometryModuleName, ModelerModule)
ODRX_DEFINE_STATIC_APPLICATION(OdRecomputeDimBlockModuleName, OdRecomputeDimBlockModule)
ODRX_END_STATIC_MODULE_MAP()

//global services
OdStaticRxObject<MyServices> service;

DwgReader::DwgReader()
{
	ODRX_INIT_STATIC_MODULE_MAP();
	if (s_instance == nullptr)
	{
		service.setRecomputeDimBlocksRequired(false);
		service.disableOutput(true);
		setCurrentServices(&service);
	}
}

DwgReader* DwgReader::instance()
{
	if (s_instance == nullptr)
	{
		s_instance = new DwgReader();
	}

	return s_instance;
}


OdDbDatabasePtr DwgReader::openDwg(const OdString& filename)
{
	OdDbDatabasePtr pDb;
	try
	{
		if (s_services != nullptr)
		{
			pDb = service.readFile(filename);
		}
	}
	catch (OdError& error)
	{

	}
	catch (...)
	{

	}

	return pDb;
}

void DwgReader::setCurrentServices(OdDbSystemServices* pSysServices)
{
	unInitServices();
	s_services = pSysServices;
	odInitialize(s_services);
}

void DwgReader::unInitServices()
{
	if (s_services != nullptr)
	{
		odUninitialize();
	}

	s_services = nullptr;
}

void DwgReader::release()
{
	if (s_instance != nullptr)
	{
		delete s_instance;
		s_instance = nullptr;
	}
}

DwgReader* DwgReader::s_instance = nullptr;
OdDbSystemServices* DwgReader::s_services = nullptr;
