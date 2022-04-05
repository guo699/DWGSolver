#pragma once

#include "..\\odstd.h"
#include "..\\Utils\OdDbReadUtils.h"

#include "iostream"
#include <typeinfo>

OdModuleInitailize()

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

		OdGePoint3d center(0, 0, 0);
		OdGeVector3d normal(0, 0, 1);
		double radius = 100;
		OdGeCircArc3d circle(center,normal,radius);

		
			
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
