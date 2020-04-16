#pragma once
#include "Color.h"
#include <string>

namespace BitmapGraphics
{
	class IBitmapDecoder;
	class IBitmapEncoder;
	class IBitmapIterator;

	using HBitmapDecoder = std::shared_ptr<IBitmapDecoder>;
	using HBitmapEncoder = std::shared_ptr<IBitmapEncoder>;
	using HBitmapIterator = std::shared_ptr<IBitmapIterator>;

	class IBitmapDecoder
	{
	public:
		virtual ~IBitmapDecoder() = default;
		virtual HBitmapDecoder clone(std::istream& sourceStream) = 0;
		virtual HBitmapIterator createIterator() = 0;
		virtual std::string getMimeType() const noexcept = 0;
		virtual bool isSupported(std::string const& first100) = 0;
		virtual uint32_t calculatePadBytes() = 0;
	};

	class IBitmapEncoder
	{
	public: 
		virtual ~IBitmapEncoder() = default;
		virtual HBitmapEncoder clone(HBitmapIterator& iterator) = 0;
		virtual void encodeToStream(std::ostream& destinationStream) = 0;
		virtual std::string getMimeType() const = 0;
		virtual uint32_t calculatePadBytes() = 0;
	};

	class IBitmapIterator
	{
	public:
		virtual ~IBitmapIterator() = default;
		virtual void nextScanLine() = 0;
		virtual bool isEndOfImage() = 0;
		virtual void nextPixel() = 0;
		virtual bool isEndOfScanLine() = 0;
		virtual BitmapGraphics::Color getColor() const = 0;
		virtual int getBitmapWidth() const = 0;
		virtual int getBitmapHeight() const = 0;
		virtual int getBitmapFileSize() const = 0;
	};
}
