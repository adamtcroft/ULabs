#pragma once
#include "DrawingInterfaces.h"

namespace BitmapGraphics
{
	class SquareStroke final : public IStroke
	{
	public:
		SquareStroke() = default;
		SquareStroke(const SquareStroke& other) = default;
		SquareStroke(SquareStroke&& other) = default;
		SquareStroke& operator=(const SquareStroke& other) = default;
		SquareStroke& operator=(SquareStroke&& other) = default;
		~SquareStroke() = default;

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
