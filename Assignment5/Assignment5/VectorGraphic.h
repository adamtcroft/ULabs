#pragma once
#include <vector>
#include <functional>
#include <algorithm>
#include "Point.h"
#include "Color.h"
#include "DrawingInterfaces.h"
#include "StrokeFactory.h"
#include "LineIterator.h"

namespace VG
{
	class VectorGraphic;
	using HVectorGraphic = std::shared_ptr<VectorGraphic>;
	using Points = std::vector<VG::Point>;

	class VectorGraphic
	{
	public:
		VectorGraphic() = default;
		VectorGraphic(const VectorGraphic& other) = default;
		VectorGraphic(VectorGraphic&& other) = default;
		VectorGraphic& operator=(const VectorGraphic& other) = default;
		VectorGraphic& operator=(VectorGraphic&& other) = default;
		~VectorGraphic() = default;

		template<class C> void addPoint(C&& p)
		{
			myPath.emplace_back(std::forward<C>(p));
		}

		void setStroke(std::string& tip, std::string& color, int size);

		void removePoint(const VG::Point& p);
		void erasePoint(int index);

		void openShape();
		void closeShape();

		bool isOpen() const;
		bool isClosed() const;

		int getWidth() const;
		int getHeight() const;

		size_t getPointCount() const;
		const Point& getPoint(int index) const;

		void draw(BitmapGraphics::HCanvas& canvas, Point const& offset);

		bool operator==(const VG::VectorGraphic& rhs) const;
		bool operator!=(const VG::VectorGraphic& rhs) const;
		friend std::ostream& operator<<(std::ostream& output, VG::VectorGraphic& vg);

	private:
		Points myPath;
		BitmapGraphics::HStroke myStroke;
		enum class Openness { Open, Closed } shapeOpenness = Openness::Closed;
		
		Point calculatePointOffset(Point const& initial, Point const& offset);
	};
}
