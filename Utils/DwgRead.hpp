#pragma once

#include "..\Header\OdDbHeader.h"
#include "..\Header\OdGeHeader.h"
#include "OdString.h"

class DwgRead
{
public:
	static DwgRead* getInstance()
	{
	}

	OdDbDatabasePtr openDwg(OdString filename)
	{

	}

	static void setServices(OdDbSystemServicesPtr services)
	{

	}

private:
	DwgRead() = default;
	static DwgRead* s_pRead;
	static OdDbSystemServicesPtr s_pServices;
};