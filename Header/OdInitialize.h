#pragma once

#ifndef _ODINITIALIZE_
#define _ODINITIALIZE_


#include "OdaCommon.h"
#include "RxDynamicModule.h"

#ifndef OdModuleInitailize()

#define OdModuleInitailize()\
		ODRX_DECLARE_STATIC_MODULE_ENTRY_POINT(ModelerModule);\
		ODRX_DECLARE_STATIC_MODULE_ENTRY_POINT(OdRecomputeDimBlockModule);\
		ODRX_DECLARE_STATIC_MODULE_ENTRY_POINT(ExFieldEvaluatorModule);\
		ODRX_DECLARE_STATIC_MODULE_ENTRY_POINT(TD_3DSolidHistoryModule);\
		ODRX_BEGIN_STATIC_MODULE_MAP()\
		ODRX_DEFINE_STATIC_APPLICATION(OdModelerGeometryModuleName, ModelerModule)\
		ODRX_DEFINE_STATIC_APPLICATION(OdRecomputeDimBlockModuleName, OdRecomputeDimBlockModule)\
		ODRX_END_STATIC_MODULE_MAP()\

#endif


OdModuleInitailize()

#endif
