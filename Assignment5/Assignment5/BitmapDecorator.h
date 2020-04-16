#pragma once
#include "CodecInterfaces.h"

namespace BitmapGraphics
{
	class BitmapDecorator :	public IBitmapIterator
	{
	public:
		BitmapDecorator() = default;
		explicit BitmapDecorator(HBitmapIterator const& iterator);
		BitmapDecorator(const BitmapDecorator&) noexcept = default;
		BitmapDecorator(BitmapDecorator &&) noexcept  = default;
		BitmapDecorator& operator=(const BitmapDecorator&) = default;
		BitmapDecorator& operator=(BitmapDecorator&&) = default;

		virtual ~BitmapDecorator() = default;

		void nextScanLine() override final;
		bool isEndOfImage() override final;
		void nextPixel() override final;
		bool isEndOfScanLine() override final;
		int getBitmapWidth() const override final;
		int getBitmapHeight() const override final;
		int getBitmapFileSize() const override final;

	protected:
		HBitmapIterator originalIterator;
	};

}

