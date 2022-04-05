#pragma once

class DwgReader
{
public:
	static DwgReader* instance();

public:
	OdDbDatabasePtr openDwg(const OdString& filename);

	void setCurrentServices(OdDbSystemServices* pSysServices);

	void unInitServices();

	void release();

private:
	static DwgReader* s_instance;
	static OdDbSystemServices* s_services;

private:
	DwgReader();
	OdString m_filename;
	
};

