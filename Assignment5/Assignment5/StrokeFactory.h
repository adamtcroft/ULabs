#pragma once
#include <map>
#include "SquareStroke.h"
#include "SlashStroke.h"
#include "DrawingInterfaces.h"

namespace BitmapGraphics
{
	class StrokeFactory
	{
	public:
		StrokeFactory();
		StrokeFactory(const StrokeFactory& other) = default;
		StrokeFactory(StrokeFactory&& other) noexcept = default;
		StrokeFactory& operator=(const StrokeFactory& other) = default;
		StrokeFactory& operator=(StrokeFactory&& other) = default;
		~StrokeFactory() noexcept = default;

		void addStroke(std::string const& tip, HStroke const& stroke);
		HStroke createStroke(std::string const& tip, std::string& color, int size);

	private:
		std::map<std::string, HStroke> myStrokes;
	};
}

