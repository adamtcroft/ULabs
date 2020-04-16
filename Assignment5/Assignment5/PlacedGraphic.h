#pragma once
#include "PlacedGraphic.h"
#include "VectorGraphic.h"
#include "Point.h"
#include "DrawingInterfaces.h"

namespace Framework
{
	class PlacedGraphic
	{
	public:
		PlacedGraphic();
		PlacedGraphic(const VG::Point& p, const VG::VectorGraphic& vg);
		PlacedGraphic(const PlacedGraphic& other) = default;
		PlacedGraphic(PlacedGraphic&& other) = default;
		PlacedGraphic& operator=(const PlacedGraphic& other) = default;
		PlacedGraphic& operator=(PlacedGraphic&& other) = default;
		~PlacedGraphic() = default;

		template <class P> void setPlacementPoint(P&& p)
		{
			placementPoint = std::forward<P>(p);
		}

		template <class G> void setGraphic(G&& g)
		{
			graphic = std::forward<G>(g);
		}

		VG::Point const& getPlacementPoint() const;
		VG::VectorGraphic const& getGraphic() const;

		void draw(BitmapGraphics::HCanvas& canvas);

	private:
		VG::Point placementPoint;
		VG::VectorGraphic graphic;
	};

	bool operator==(const PlacedGraphic& lhs, const PlacedGraphic& rhs);
	bool operator!=(const PlacedGraphic& lhs, const PlacedGraphic& rhs);
}