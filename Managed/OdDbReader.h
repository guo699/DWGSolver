#pragma once

using namespace System;
using namespace Geometry;
using namespace System::Collections::Generic;

namespace Managed
{
	public ref class DatabaseReader
	{
	public:
		DatabaseReader(String^ filename);
		List<Line3d^>^ GetAllLine();

	private:
		String^ m_dbpath;
	};
}
