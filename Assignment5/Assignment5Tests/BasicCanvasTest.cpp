#include "TestHarness.h"
#include "BasicCanvas.h"

using namespace BitmapGraphics;

TEST(BackgroundColor, BasicCanvas)
{
    Color expected(Binary::Byte(255), Binary::Byte(255), Binary::Byte(255));
    BasicCanvas canvas(10, 10, expected);

    Color actual = canvas.getPixelColor(VG::Point(8, 6));

	CHECK(expected == actual);
    //CHECK_EQUAL(expected, actual);
}

TEST(setPixelColor, BasicCanvas)
{
    Color background(Binary::Byte(255), Binary::Byte(255), Binary::Byte(255));
    BasicCanvas canvas(300, 300, background);

    Color expected(Binary::Byte(100), Binary::Byte(100), Binary::Byte(200));
    canvas.setPixelColor(VG::Point(5, 5), expected);

    Color actual = canvas.getPixelColor(VG::Point(5, 5));
	CHECK(expected == actual);
    //CHECK_EQUAL(expected, actual);
}

TEST(setPixelColorGetBackgroundColor, BasicCanvas)
{
    Color expected(Binary::Byte(255), Binary::Byte(255), Binary::Byte(255));
    BasicCanvas canvas(300, 300, expected);

    Color color(Binary::Byte(100), Binary::Byte(100), Binary::Byte(200));
    canvas.setPixelColor(VG::Point(5, 5), color);

    Color actual = canvas.getPixelColor(VG::Point(7, 5));
	CHECK(expected == actual);
    //CHECK_EQUAL(expected, actual);
}

TEST(getDimensions, BasicCanvas)
{
    BasicCanvas canvas(99, 100, Color(Binary::Byte(1), Binary::Byte(2), Binary::Byte(3)));

    CHECK_EQUAL(99, canvas.getWidth());
    CHECK_EQUAL(100, canvas.getHeight());
}

TEST(setPixelOutsideDimensions, BasicCanvas)
{
    BasicCanvas canvas(99, 100, Color(Binary::Byte(1), Binary::Byte(2), Binary::Byte(3)));

    try
    {
        canvas.setPixelColor(VG::Point(105, 205), Color(Binary::Byte(1), Binary::Byte(2), Binary::Byte(3)));
        CHECK(false);
    }
    catch (const std::exception& exc)
    {
        std::cout << exc.what() << std::endl;
        CHECK(true);
    }
}

TEST(getPixelOutsideDimensions, BasicCanvas)
{
    BasicCanvas canvas(99, 100, Color(Binary::Byte(1), Binary::Byte(2), Binary::Byte(3)));

    try
    {
        canvas.getPixelColor(VG::Point(105, 205));
    }
    catch (const std::exception& exc)
    {
        std::cout << exc.what() << std::endl;
        CHECK(true);
    }
}

TEST(IBitmapIterator, BasicCanvas)
{
    Color backColor(Binary::Byte(1), Binary::Byte(2), Binary::Byte(3));
    BasicCanvas canvas(8, 9, backColor);

    HBitmapIterator bitmapIterator = canvas.createBitmapIterator();

    CHECK_EQUAL(8, bitmapIterator->getBitmapWidth());
    CHECK_EQUAL(9, bitmapIterator->getBitmapHeight());

    int rows = 0;
    while (!bitmapIterator->isEndOfImage())
    {
        int columns = 0;
        while (!bitmapIterator->isEndOfScanLine())
        {
			CHECK(backColor == bitmapIterator->getColor());
            //CHECK_EQUAL(backColor, bitmapIterator->getColor());
            bitmapIterator->nextPixel();
            columns++;
        }

        CHECK_EQUAL(8, columns);

        bitmapIterator->nextScanLine();
        rows++;
    }

    CHECK_EQUAL(9, rows);
}
