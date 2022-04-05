#pragma once

#include "..\\odstd.h"

#include "..\\Common\DwgReader.h"
#include "..\\Utils\OdDbReadUtils.h"
#include "..\\Managed\OdDbReader.h"

#include "iostream"
#include <typeinfo>


using namespace System;
using namespace Managed;

using namespace std;

//int main()
//{
//	String^ ss = "C:\\Users\\IronBin\\Desktop\\test.dwg";
//	
//	DatabaseReader^ reader = gcnew DatabaseReader(ss);
//	List<Line3d^>^ lines = reader->GetAllLine();
//
//	cout << lines->Count << endl;
//
//	return 0;
//}
