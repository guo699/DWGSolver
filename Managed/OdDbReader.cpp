#include "..\\odstd.h"
#include "..\\Utils\\OdDbReadUtils.h"
#include "..\\Common\DwgReader.h"
#include "..\Managed\CurveConvert.h"
#include "OdDbReader.h"

using namespace Geometry;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;


Managed::DatabaseReader::DatabaseReader(String^ filename)
{
	this->m_dbpath = filename;
}

List<Line3d^>^ Managed::DatabaseReader::GetAllLine()
{
	List<Line3d^>^ lines = gcnew List<Line3d^>();

	OdString filepath = StringUtils::ToOdString(m_dbpath);

	DwgReader* reader = DwgReader::instance();
	OdDbDatabasePtr pDb = reader->openDwg(filepath);

	OdArray<OdDbLinePtr> linearray;
	OdDbReadUtils::getLines(pDb, linearray);

	for (int i = 0; i < linearray.size(); i++)
	{
		OdDbLinePtr pline = linearray[i];
		Line3d^ line = CurveConvert::Transform(pline);
		lines->Add(line);
	}

	return lines;
}
