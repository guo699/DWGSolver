#pragma once

#include "..\Header\OdDbHeader.h"
#include "..\Header\OdGeHeader.h"
#include "..\Utils\Common.hpp"
#include "OdString.h"
#include "DbDatabase.h"

class EntitiesFilter
{
public:
	EntitiesFilter() = default;

	EntitiesFilter(const OdString fileName)
	{
		this->m_fileName = fileName;
		m_pDb = nullptr;
	}

	EntitiesFilter(OdDbDatabasePtr pDb)
	{
		this->m_pDb = pDb;
	}

	EntitiesFilter(OdDbEntityPtrArray entArray):m_pEntArray(entArray)
	{}

	void setSource(OdDbEntityPtrArray source)
	{
		this->m_pEntArray = source;
	}

	int FilterRange(const OdGeExtents3d& range, OdDbEntityPtrArray& innerEnts)
	{
		for (size_t i = 0; i < m_pEntArray.size(); i++)
		{
			OdGeExtents3d box;
			m_pEntArray[i]->getGeomExtents(box);
			if (OdaUtils::isInclude(range, box))
			{
				innerEnts.append(m_pEntArray[i]);
			}
		}
		return innerEnts.size();
	}

private:
	OdString m_fileName;
	OdDbDatabasePtr m_pDb;
	OdDbEntityPtrArray m_pEntArray;
};