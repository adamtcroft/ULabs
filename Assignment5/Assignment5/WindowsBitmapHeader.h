#pragma once
#include <iostream>
#include <fstream>
#include "SizedWord.h"
#include "VerifyEquality.h"

namespace BitmapGraphics
{
	class WindowsBitmapHeader
	{
	public:
		WindowsBitmapHeader() = default;
		explicit WindowsBitmapHeader(std::istream& bitmapStream);
		WindowsBitmapHeader(const WindowsBitmapHeader& other) = default;
		WindowsBitmapHeader(WindowsBitmapHeader&& other) = default;
		WindowsBitmapHeader& operator=(const WindowsBitmapHeader& other) = default;
		WindowsBitmapHeader& operator=(WindowsBitmapHeader&& other) = default;
		~WindowsBitmapHeader() noexcept = default;

		void readFileHeader(std::istream& sourceStream);
		void writeFileHeader(std::ostream& destinationStream) const;

		void readInfoHeader(std::istream& sourceStream);
		void writeInfoHeader(std::ostream& destinationStream) const;

		void read(std::istream& sourceStream);
		void write(std::ostream& destinationStream) const;

		void writeFileHeaderStart(std::ostream& destinationStream) const;
		void writeFileHeaderEnd(std::ostream& destinationStream) const;
		void writeInfoHeaderStart(std::ostream& destinationStream) const;
		void writeInfoHeaderEnd(std::ostream& destinationStream) const;

		Binary::DoubleWord::data_type getFileSize() const noexcept { return static_cast<uint32_t>(fileSize); }
		Binary::DoubleWord::data_type getBitmapWidth() const noexcept { return static_cast<uint32_t>(bitmapWidth); }
		Binary::DoubleWord::data_type getBitmapHeight() const noexcept { return static_cast<uint32_t>(bitmapHeight); }

		void setFileSize(uint32_t& size) { fileSize = Binary::DoubleWord{ size }; }
		void setBitmapWidth(uint32_t& width) { bitmapWidth = Binary::DoubleWord{ width }; }
		void setBitmapHeight(uint32_t& height) { bitmapHeight = Binary::DoubleWord{ height }; }

	private:
		// File Header
		const static Binary::Byte firstIdentifier;
		const static Binary::Byte secondIdentifier;
		Binary::DoubleWord fileSize;
		const static Binary::DoubleWord reserved;
		const static Binary::DoubleWord rawImageByteOffset;

		// Info Header
		const static Binary::DoubleWord infoHeaderBytes;
		Binary::DoubleWord bitmapWidth;
		Binary::DoubleWord bitmapHeight;
		const static Binary::Word numberOfPlanes;
		const static Binary::Word bitsPerPixel;
		const static Binary::DoubleWord compressionType;
		const static Binary::DoubleWord compressedImageSize;
		const static Binary::DoubleWord horizontalPixelsPerMeter;
		const static Binary::DoubleWord verticalPixelsPerMeter;
		const static Binary::DoubleWord numberOfColors;
		const static Binary::DoubleWord numberOfImportantColors;
	};
}

