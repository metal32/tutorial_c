#pragma once

namespace uiuc {
	class Cube {
	private:
		double length_;
	public:
		Cube(double length);
		double getVolume();
		double getSurfaceArea();
		void setLength(double length);
	};
}
