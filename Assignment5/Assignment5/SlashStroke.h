#pragma once
#include "DrawingInterfaces.h"

namespace BitmapGraphics
{
	class SlashStroke : public IStroke
	{
	public:
		SlashStroke() = default;
		SlashStroke(const SlashStroke& other) = default;
		SlashStroke(SlashStroke&& other) = default;
		SlashStroke& operator=(const SlashStroke& other) = default;
		SlashStroke& operator=(SlashStroke&& other) = default;
		~SlashStroke() = default;

		void setSize(int size) override final;
		int getSize() const override final;
		void setColor(Color const& color) override final;
		Color getColor() const override final;
		HPen createPen(HCanvas const& canvas) override final;

	private:
		int mySize;
		Color myColor;
	};
}
