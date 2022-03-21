#pragma once

#include "OdaCommon.h"
#include "OdPlatformSettings.h"
#include "RxDynamicModule.h"
#include "toString.h"

#include "..\Utils\MyServices.hpp"
#include "..\Utils\OdDbUtils.hpp"
#include "..\Header\OdDbHeader.h"
#include "..\Header\OdInitialize.h"

#include "TeighaLibrary.h"
#include "iostream"

OdModuleInitailize()


int getCircleCount()
{
	ODRX_INIT_STATIC_MODULE_MAP();
	OdStaticRxObject<MyServices> service;
	odInitialize(&service);

	OdArray<OdDbCirclePtr> blockrs;
	try
	{
		service.disableOutput(true);

		OdDbDatabasePtr pDb = service.readFile(L"C:\\Users\\IronBin\\Desktop\\test.dwg");

		OdDbUtils::getCircles(pDb, blockrs);
	}
	catch (...)
	{
	}
	try
	{
		odUninitialize();
	}
	catch (...)
	{

	}
	return blockrs.size();
}

namespace TestNamespace
{
	public ref class RefTest
	{
	public:
		static System::Int32 GetCircleCount()
		{
			return getCircleCount();
		}
	};
}