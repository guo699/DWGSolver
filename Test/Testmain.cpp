#pragma once

#include "OdaCommon.h"
#include "OdPlatformSettings.h"
#include "RxDynamicModule.h"
#include "toString.h"

#include "..\Utils\MyServices.hpp"
#include "..\Utils\OdDbUtils.hpp"
#include "..\Utils\OdDbCreate.hpp"
#include "..\Utils\Common.hpp"
#include "..\Utils\DbCurveEx.hpp"

#include "..\Header\OdDbHeader.h"
#include "..\Header\OdInitialize.h"
#include "..\Header\OdGeHeader.h"

#include "TeighaLibrary.h"
#include "iostream"
#include <typeinfo>


using namespace System;
using namespace Autodesk::Revit::ApplicationServices;
using namespace Autodesk::Revit::Attributes;
using namespace Autodesk::Revit::DB; 
using namespace Autodesk::Revit::UI;

//[TransactionAttribute(TransactionMode::Manual)]
//[RegenerationAttribute(RegenerationOption::Manual)]
//public ref class TestCommand :IExternalCommand
//{
//public:
//
//	virtual Autodesk::Revit::UI::Result Execute(Autodesk::Revit::UI::ExternalCommandData^ commandData, System::String^% message, Autodesk::Revit::DB::ElementSet^ elements)
//	{
//		TaskDialog::Show("CPP/CLI", TestNamespace::RefTest::GetCircleCount().ToString());
//
//		return Autodesk::Revit::UI::Result();
//	}
//};

int main()
{
	ODRX_INIT_STATIC_MODULE_MAP();
	OdStaticRxObject<MyServices> service;
	odInitialize(&service);

	OdArray<OdDbCirclePtr> blockrs;
	try
	{
		service.disableOutput(true);

		OdDbDatabasePtr pDb = service.readFile(L"C:\\Users\\IronBin\\Desktop\\test.dwg");

		OdDbCirclePtr c1 = OdDbCreate::AddCircle(pDb, OdGePoint3d(100, 100, 0), 100);
		OdDbCirclePtr c2 = OdDbCreate::AddCircle(pDb, OdGePoint3d(100, 100, 0), 200);
		OdDbCirclePtr c3 = OdDbCreate::AddCircle(pDb, OdGePoint3d(100, 100, 0), 300);
		OdDbCirclePtr c4 = OdDbCreate::AddCircle(pDb, OdGePoint3d(100, 100, 0), 400);

		OdDbEntityPtrArray entities;
		entities.append(c1);
		entities.append(c2);
		entities.append(c3);
		entities.append(c4);

		OdDbGroupPtr pGroup;
		DbCurveUtils::groupEntities(entities, pGroup);

		OdDbCreate::reSave(pDb);
			
	}
	catch (OdError error)
	{
		std::cout << error.description() << std::endl;
	}
	try
	{
		odUninitialize();
	}
	catch (...)
	{

	}
	return 0;
}
