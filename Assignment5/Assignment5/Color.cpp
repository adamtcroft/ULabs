#include "Color.h"

namespace BitmapGraphics
{
	Color::Color(
		const Binary::Byte & redInput,
		const Binary::Byte & greenInput,
		const Binary::Byte & blueInput) noexcept :
		red(redInput), green(greenInput), blue(blueInput)
	{
	}

	Color Color::read(std::istream& sourceStream)
	{
		Color myColor;

		myColor.blue = Binary::Byte::read(sourceStream);
		myColor.green = Binary::Byte::read(sourceStream);
		myColor.red = Binary::Byte::read(sourceStream);
		return myColor;
	}

	void Color::write(std::ostream& destinationStream) const
	{
		blue.write(destinationStream);
		green.write(destinationStream);
		red.write(destinationStream);
	}

	bool Color::operator==(const Color& rhs) const
	{
		return (red == rhs.getRed()) && (green == rhs.getGreen()) && (blue == rhs.getBlue());
	}

	bool Color::operator!=(const Color& rhs) const
	{
		return !(*this == rhs);
	}

	Color Color::operator+(int const& rhs) const
	{
		uint8_t redValue = std::clamp(static_cast<int>(red.getValue()) + rhs, MIN_COLOR_VALUE, MAX_COLOR_VALUE);
		auto newRed = Binary::Byte{ redValue };

		uint8_t greenValue = std::clamp(static_cast<int>(blue.getValue()) + rhs, MIN_COLOR_VALUE, MAX_COLOR_VALUE);
		auto newBlue = Binary::Byte{ greenValue };

		uint8_t blueValue = std::clamp(static_cast<int>(green.getValue()) + rhs, MIN_COLOR_VALUE, MAX_COLOR_VALUE);
		auto newGreen = Binary::Byte{ blueValue };

		return Color(newRed, newGreen, newBlue);
	}

	Color Color::operator/(int const& rhs) const
	{
		Color temp;
		return temp;
	}

	Color operator-(const int& lhs, const Color& rhs)
	{
		auto red = Binary::Byte{ static_cast<uint8_t>(lhs - rhs.getRed().getValue()) };
		auto green = Binary::Byte{ static_cast<uint8_t>(lhs - rhs.getGreen().getValue()) };
		auto blue = Binary::Byte{ static_cast<uint8_t>(lhs - rhs.getBlue().getValue()) };

		return Color(red, green, blue);
	}

	std::ostream& operator<<(std::ostream& os, const BitmapGraphics::Color& color)
	{
		color.write(os);
		return os;
	}
}
