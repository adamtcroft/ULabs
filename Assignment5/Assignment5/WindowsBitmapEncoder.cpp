#include "WindowsBitmapEncoder.h"

namespace BitmapGraphics
{
	WindowsBitmapEncoder::WindowsBitmapEncoder(HBitmapIterator& iterator) :
		myIterator(iterator)
	{
	}

	HBitmapEncoder WindowsBitmapEncoder::clone(HBitmapIterator& iterator)
	{
		return std::make_shared<WindowsBitmapEncoder>(iterator);
	}

	void WindowsBitmapEncoder::encodeToStream(std::ostream& destinationStream)
	{
		if (!myIterator)
			throw std::runtime_error("Error: Cannot encode stream before creating bitmap.");
		else
		{
			writeHeader(destinationStream);
			writeScanlines(destinationStream);
		}
	}

	std::string WindowsBitmapEncoder::getMimeType() const
	{
		return myMimeType;
	}

	uint32_t WindowsBitmapEncoder::calculatePadBytes()
	{
		const auto remainder = (myIterator->getBitmapWidth() * 3) % 4;
		return (remainder == 0) ? 0 : (4 - remainder);
	}

	void WindowsBitmapEncoder::writeHeader(std::ostream & destinationStream)
	{
		WindowsBitmapHeader header;

		uint32_t fileSize = ((myIterator->getBitmapWidth() * 3) + 31) / 32 * 4;
		header.setFileSize(fileSize);
		uint32_t width = myIterator->getBitmapWidth();
		header.setBitmapWidth(width);
		uint32_t height = myIterator->getBitmapHeight();
		header.setBitmapHeight(height);

		header.writeFileHeader(destinationStream);
		header.writeInfoHeader(destinationStream);
	}

	void WindowsBitmapEncoder::writeScanlines(std::ostream& destinationStream)
	{
		while (!myIterator->isEndOfImage())
		{
			while (!myIterator->isEndOfScanLine())
			{
				auto color = myIterator->getColor();
				destinationStream << color.getBlue();
				destinationStream << color.getGreen();
				destinationStream << color.getRed();
				myIterator->nextPixel();
			}

			for (auto pad = 0; pad < calculatePadBytes(); ++pad)
			{
				Binary::Byte(0).write(destinationStream);
			}

			myIterator->nextScanLine();
		}
	}
}
