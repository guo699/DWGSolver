#pragma once

namespace Geometry
{
	public ref class Point3d
	{
	public:
		Point3d();
		Point3d(double xx, double yy, double zz);

		property System::Double X
		{
			System::Double get() { return m_x; }
			void set(System::Double xx) { m_x = xx; }
		}

		property System::Double Y
		{
			System::Double get() { return m_y; }
			void set(System::Double yy) { m_y = yy; }
		}

		property System::Double Z
		{
			System::Double get() { return m_z; }
			void set(System::Double zz) { m_z = zz; }
		}

	private:
		double m_x;
		double m_y;
		double m_z;
	};
}

