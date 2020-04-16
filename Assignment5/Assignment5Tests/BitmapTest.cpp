#include "TestHarness.h"
#include "Bitmap.h"
#include "WindowsBitmapHeader.h"

using namespace BitmapGraphics;

TEST(BitmapSizeTest, Bitmap)
{
	std::ifstream bitmapStream{ "../basic.bmp", std::ios::binary };
	CHECK(bitmapStream.is_open());

	WindowsBitmapHeader bitmapHeader{ bitmapStream };
	Bitmap bitmap{ bitmapHeader.getBitmapWidth(), bitmapHeader.getBitmapHeight()};

	CHECK_EQUAL(100, bitmap.getWidth());
	CHECK_EQUAL(100, bitmap.getHeight());
}

TEST(BitmapPushBack, Bitmap)
{
	Bitmap bitmap{ 100,100 };

	Color testColor{ Binary::Byte{0}, Binary::Byte{0}, Binary::Byte{0} };
	std::vector<Color> scanline;

	int count = 5;
	while (count > 0)
	{
		scanline.push_back(testColor);
		count--;
	}

	bitmap.push_back(scanline);

	CHECK(*(bitmap.begin()) == scanline);
}

TEST(BitmapClear, Bitmap)
{
	Bitmap bitmap{ 100,100 };

	Color testColor{ Binary::Byte{0}, Binary::Byte{0}, Binary::Byte{0} };
	std::vector<Color> scanline;

	int count = 5;
	while (count > 0)
	{
		scanline.push_back(testColor);
		count--;
	}

	bitmap.push_back(scanline);

	CHECK(*(bitmap.begin()) == scanline);

	bitmap.clearCollection();

	CHECK(bitmap.begin() == bitmap.end());
}
