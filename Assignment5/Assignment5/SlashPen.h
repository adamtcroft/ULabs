#pragma once
#include "DrawingInterfaces.h"
#include "SlashStroke.h"

namespace BitmapGraphics
{
	class SlashPen final : public IPen
	{
	public:
		SlashPen() = default;
		explicit SlashPen(SlashStroke& stroke) : myStroke(&stroke) {};
		SlashPen(const SlashPen& other) = default;
		SlashPen(SlashPen&& other) = default;
		SlashPen& operator=(const SlashPen& other) = default;
		SlashPen& operator=(SlashPen&& other) = default;
		~SlashPen() = default;

		void drawPoint(const HCanvas&, const VG::Point&) override final;

	private:
		SlashStroke* myStroke;
	};
}

