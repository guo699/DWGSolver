#pragma once

using namespace System;

namespace Geometry
{
	public ref class Line3d
	{
	public:
		Line3d(Point3d^ start, Point3d^ end);

		property Point3d^ Start
		{
			Point3d^ get() { return m_start; }
			void set(Point3d^ point) { this->m_start = point; }
		}

		property Point3d^ End
		{
			Point3d^ get() { return m_end; }
			void set(Point3d^ point) { this->m_end = point; }
		}

		property System::Double Length
		{
			System::Double get()
			{
				return Math::Sqrt(Math::Pow(m_start->X - m_end->X, 2) + Math::Pow(m_start->Y - m_end->Y, 2) + Math::Pow(m_start->Z - m_end->Z, 2));
			}
		}

	private:
		Point3d^ m_start;
		Point3d^ m_end;
	};

}