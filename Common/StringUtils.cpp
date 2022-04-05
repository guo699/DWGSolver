#include "..\\odstd.h"
#include "StringUtils.h"

OdString StringUtils::ToOdString(String^ ss)
{
	wchar_t* ptr = (wchar_t*)System::Runtime::InteropServices::Marshal::StringToHGlobalUni(ss).ToPointer();
	OdString str(ptr);

	delete ptr;
	return str;
}
