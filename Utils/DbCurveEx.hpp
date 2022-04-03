#pragma once

#include "..\Header\OdDbHeader.h"
#include "..\Header\OdGeHeader.h"

namespace DbCurveUtils
{
	void explodeBlockReference(OdDbBlockReferencePtr block, OdRxObjectPtrArray& pRxobjs)
	{
		block->explode(pRxobjs);
	}

	void groupEntities(OdDbEntityPtrArray entities,OdDbGroupPtr& pGroup)
	{
		pGroup = OdDbGroup::createObject();
		for (int i = 0; i < entities.size(); i++)
		{
			pGroup->append(entities[i]->objectId());
		}
	}
}

