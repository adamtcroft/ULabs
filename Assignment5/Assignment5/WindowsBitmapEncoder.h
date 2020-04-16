#pragma once
#include "WindowsBitmapHeader.h"
#include "Color.h"
#include "CodecInterfaces.h"

namespace BitmapGraphics
{
	class WindowsBitmapEncoder : public IBitmapEncoder
	{
	public:
		WindowsBitmapEncoder() = default;
		explicit WindowsBitmapEncoder(HBitmapIterator& iterator);
		WindowsBitmapEncoder(const WindowsBitmapEncoder& other) = default;
		WindowsBitmapEncoder(WindowsBitmapEncoder&& other) = default;
		WindowsBitmapEncoder& operator=(const WindowsBitmapEncoder& other) = default;
		WindowsBitmapEncoder& operator=(WindowsBitmapEncoder&& other) = default;
		~WindowsBitmapEncoder() noexcept = default;

		HBitmapEncoder clone(HBitmapIterator& iterator) override;
		void encodeToStream(std::ostream& destinationStream) override;
		std::string getMimeType() const override;
		uint32_t calculatePadBytes() override;

	private:
		HBitmapIterator myIterator;
		const std::string myMimeType = "image/x-ms-bmp";

		void writeHeader(std::ostream& destinationStream);
		void writeScanlines(std::ostream& destinationStream);
	};
}

