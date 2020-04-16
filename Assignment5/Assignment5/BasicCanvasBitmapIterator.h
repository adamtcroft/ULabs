#pragma once
#include "BasicCanvas.h"
#include "CodecInterfaces.h"

namespace BitmapGraphics
{
	class BasicCanvasBitmapIterator final : public IBitmapIterator
	{
	public:
		BasicCanvasBitmapIterator() = default;
		BasicCanvasBitmapIterator(BasicCanvas& canvas);
		BasicCanvasBitmapIterator(const BasicCanvasBitmapIterator& other) = default;
		BasicCanvasBitmapIterator(BasicCanvasBitmapIterator&& other) = default;
		BasicCanvasBitmapIterator& operator=(const BasicCanvasBitmapIterator& other) = default;
		BasicCanvasBitmapIterator& operator=(BasicCanvasBitmapIterator&& other) = default;
		~BasicCanvasBitmapIterator() = default;

		void nextScanLine() final override;
		bool isEndOfImage() final override;
		void nextPixel() final override;
		bool isEndOfScanLine() final override;
		BitmapGraphics::Color getColor() const final override;
		int getBitmapWidth() const final override;
		int getBitmapHeight() const final override;
		int getBitmapFileSize() const { return 0; }

	private:
		BasicCanvas* myCanvas;
		unsigned int myX;
		unsigned int myY;
	};
}

