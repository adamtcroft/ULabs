#pragma once
#include "SizedWord.h"
#include "Color.h"
#include "binary_ostream_iterator.h"
#include "CodecInterfaces.h"
#include "WindowsBitmapHeader.h"
#include "Point.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

namespace BitmapGraphics
{

	class Bitmap
	{
	public:
		using ScanLine = std::vector<Color>;
	private:
		using ScanLineCollection = std::vector<ScanLine>;
	public:
		using ScanLineCollectionIterator = ScanLineCollection::iterator;

		Bitmap() = default;
		Bitmap(const uint32_t& width, const uint32_t& height);
		Bitmap(const Bitmap& other) = default;
		Bitmap(Bitmap&& other) = default;
		Bitmap& operator=(const Bitmap& other) = default;
		Bitmap& operator=(Bitmap&& other) = default;
		~Bitmap() noexcept = default;

		ScanLineCollectionIterator begin() noexcept { return slCollection.begin(); }
		ScanLineCollectionIterator end() noexcept { return slCollection.end(); }
		void setPixelColor(VG::Point const& location, Color const& color);
		Color getPixelColor(VG::Point const& location) const { return slCollection[location.getX()][location.getY()]; };
		uint32_t getWidth() const noexcept { return bitmapWidth; }
		uint32_t getHeight() const noexcept { return bitmapHeight; }
		void push_back(const ScanLine& scanline) { slCollection.push_back(scanline); }
		void clearCollection() { slCollection.clear(); }

		HBitmapIterator createIterator();

	private:
		uint32_t bitmapWidth{ 0 };
		uint32_t bitmapHeight{ 0 };
		ScanLineCollection slCollection;
	};
}

