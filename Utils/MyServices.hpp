#pragma once

#ifndef _MYSERVICES_
#define _MYSERVICES_

#include "OdaCommon.h"
#include "OdPlatformSettings.h"
#include "ExSystemServices.h"
#include "ExHostAppServices.h"

class MyServices :public ExSystemServices, public ExHostAppServices
{

};

#endif