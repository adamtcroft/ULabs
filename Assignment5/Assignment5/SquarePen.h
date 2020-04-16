#pragma once
#include "SquareStroke.h"
#include "DrawingInterfaces.h"

namespace BitmapGraphics
{
	class SquarePen final : public IPen
	{
	public:
		SquarePen() = default;
		explicit SquarePen(SquareStroke& stroke) : myStroke(&stroke) {};
		SquarePen(const SquarePen& other) = default;
		SquarePen(SquarePen&& other) = default;
		SquarePen& operator=(const SquarePen& other) = default;
		SquarePen& operator=(SquarePen&& other) = default;
		~SquarePen() = default;

		void drawPoint(const HCanvas&, const VG::Point&) override final;

	private:
		SquareStroke* myStroke;
	};
}

