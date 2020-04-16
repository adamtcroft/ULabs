#pragma once
#include "WindowsBitmapHeader.h"
#include "Bitmap.h"
#include "BitmapIterator.h"
#include "Color.h"
#include "CodecInterfaces.h"

namespace BitmapGraphics
{
	class WindowsBitmapDecoder : public IBitmapDecoder
	{
	public:
		WindowsBitmapDecoder() = default;
		explicit WindowsBitmapDecoder(std::istream& sourceStream);
		WindowsBitmapDecoder(const WindowsBitmapDecoder& other) = default;
		WindowsBitmapDecoder(WindowsBitmapDecoder&& other) = default;
		WindowsBitmapDecoder& operator=(const WindowsBitmapDecoder& other) = default;
		WindowsBitmapDecoder& operator=(WindowsBitmapDecoder&& other) = default;
		~WindowsBitmapDecoder() noexcept = default;

		HBitmapDecoder clone(std::istream& sourceStream) override;
		HBitmapIterator createIterator() override;
		std::string getMimeType() const noexcept override { return myMimeType; };
		bool isSupported(std::string const& first100) override;
		uint32_t calculatePadBytes() override;

		bool deferDecode(std::istream& sourceStream);
		Bitmap decodeHeader(std::istream& sourceStream);
		void decodeScanlines(std::istream& sourceStream);

	private:
		Bitmap myBitmap;
		const std::string myMimeType = "image/x-ms-bmp";
	};
}
