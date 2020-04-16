#include "PlacedGraphic.h"

namespace Framework
{
	PlacedGraphic::PlacedGraphic() :
		placementPoint(VG::Point(0, 0)),
		graphic(VG::VectorGraphic())
	{
	}

	PlacedGraphic::PlacedGraphic(const VG::Point& p, const VG::VectorGraphic& vg) :
		placementPoint(p),
		graphic(vg)
	{
	}
	VG::Point const& PlacedGraphic::getPlacementPoint() const
	{
		return placementPoint;
	}

	VG::VectorGraphic const& PlacedGraphic::getGraphic() const
	{
		return graphic;
	}

	void PlacedGraphic::draw(BitmapGraphics::HCanvas& canvas)
	{
		graphic.draw(canvas, placementPoint);
	}

	bool operator==(const PlacedGraphic& lhs, const PlacedGraphic& rhs)
	{
		return (lhs.getPlacementPoint() == rhs.getPlacementPoint())
			&& (lhs.getGraphic() == rhs.getGraphic());
	}

	bool operator!=(const PlacedGraphic& lhs, const PlacedGraphic& rhs)
	{
		return !(lhs == rhs);
	}
}
