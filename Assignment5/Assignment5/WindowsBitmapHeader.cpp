#include "WindowsBitmapHeader.h"

namespace BitmapGraphics
{
	// File Header Fields
	const Binary::Byte WindowsBitmapHeader::firstIdentifier = Binary::Byte{ 'B' };
	const Binary::Byte WindowsBitmapHeader::secondIdentifier = Binary::Byte{ 'M' };
	const Binary::DoubleWord WindowsBitmapHeader::reserved{ 0 };
	const Binary::DoubleWord WindowsBitmapHeader::rawImageByteOffset{ 54 };

	// Info Header Fields
	const Binary::DoubleWord WindowsBitmapHeader::infoHeaderBytes{ 40 };
	const Binary::Word WindowsBitmapHeader::numberOfPlanes{ 1 };
	const Binary::Word WindowsBitmapHeader::bitsPerPixel{ 24 };
	const Binary::DoubleWord WindowsBitmapHeader::compressionType{ 0 };

	// Extraneous for our purposes, set to 0
	const Binary::DoubleWord WindowsBitmapHeader::compressedImageSize{ 0 };
	const Binary::DoubleWord WindowsBitmapHeader::horizontalPixelsPerMeter{ 0 };
	const Binary::DoubleWord WindowsBitmapHeader::verticalPixelsPerMeter{ 0 };
	const Binary::DoubleWord WindowsBitmapHeader::numberOfColors{ 0 };
	const Binary::DoubleWord WindowsBitmapHeader::numberOfImportantColors{ 0 };

	WindowsBitmapHeader::WindowsBitmapHeader(std::istream& sourceStream)
	{
		read(sourceStream);
	}

	void WindowsBitmapHeader::read(std::istream& sourceStream)
	{
		readFileHeader(sourceStream);
		readInfoHeader(sourceStream);
	}

	void WindowsBitmapHeader::readFileHeader(std::istream& sourceStream)
	{
		verifyEquality(firstIdentifier, Binary::Byte::read(sourceStream), "firstIdentifier does not match 'B'");
		verifyEquality(secondIdentifier, Binary::Byte::read(sourceStream), "secondIdentifier does not match 'M'");
		fileSize = Binary::DoubleWord::readLittleEndian(sourceStream);
		verifyEquality(reserved, Binary::DoubleWord::readLittleEndian(sourceStream), "reserved does not match '0'");
		verifyEquality(rawImageByteOffset, Binary::DoubleWord::readLittleEndian(sourceStream), "rawImageByteOffset does not match '54'");
	}


	void WindowsBitmapHeader::readInfoHeader(std::istream& sourceStream)
	{
		verifyEquality(infoHeaderBytes, Binary::DoubleWord::readLittleEndian(sourceStream), "infoHeaderBytes does not match '40'");
		bitmapWidth = Binary::DoubleWord::readLittleEndian(sourceStream);
		bitmapHeight = Binary::DoubleWord::readLittleEndian(sourceStream);
		verifyEquality(numberOfPlanes, Binary::Word::readLittleEndian(sourceStream), "numberOfPlanes does not match '1'");
		verifyEquality(bitsPerPixel, Binary::Word::readLittleEndian(sourceStream), "bitsPerPixel does not match '24'");
		verifyEquality(compressionType, Binary::DoubleWord::readLittleEndian(sourceStream), "compressionType does not match '0'");
		Binary::DoubleWord::readLittleEndian(sourceStream); // compressedImageSize
		Binary::DoubleWord::readLittleEndian(sourceStream); // horizontalPixelsPerMeter
		Binary::DoubleWord::readLittleEndian(sourceStream); // verticalPixelsPerMeter
		Binary::DoubleWord::readLittleEndian(sourceStream); // numberOfColors
		Binary::DoubleWord::readLittleEndian(sourceStream); // numberOfImportantColors
	}

	void WindowsBitmapHeader::write(std::ostream& destinationStream) const
	{
		writeFileHeader(destinationStream);
		writeInfoHeader(destinationStream);
	}

	void WindowsBitmapHeader::writeFileHeader(std::ostream& destinationStream) const
	{
		firstIdentifier.write(destinationStream);
		secondIdentifier.write(destinationStream);
		fileSize.writeLittleEndian(destinationStream);
		reserved.writeLittleEndian(destinationStream);
		rawImageByteOffset.writeLittleEndian(destinationStream);
	}

	void WindowsBitmapHeader::writeInfoHeader(std::ostream& destinationStream) const
	{
		infoHeaderBytes.writeLittleEndian(destinationStream);
		bitmapWidth.writeLittleEndian(destinationStream);
		bitmapHeight.writeLittleEndian(destinationStream);
		numberOfPlanes.writeLittleEndian(destinationStream);
		bitsPerPixel.writeLittleEndian(destinationStream);
		compressionType.writeLittleEndian(destinationStream);
		compressedImageSize.writeLittleEndian(destinationStream);
		horizontalPixelsPerMeter.writeLittleEndian(destinationStream);
		verticalPixelsPerMeter.writeLittleEndian(destinationStream);
		numberOfColors.writeLittleEndian(destinationStream);
		numberOfImportantColors.writeLittleEndian(destinationStream);
	}

	void WindowsBitmapHeader::writeFileHeaderStart(std::ostream& destinationStream) const
	{
		firstIdentifier.write(destinationStream);
		secondIdentifier.write(destinationStream);
	}

	void WindowsBitmapHeader::writeFileHeaderEnd(std::ostream& destinationStream) const
	{
		reserved.writeLittleEndian(destinationStream);
		rawImageByteOffset.writeLittleEndian(destinationStream);
	}

	void WindowsBitmapHeader::writeInfoHeaderStart(std::ostream& destinationStream) const
	{
		infoHeaderBytes.writeLittleEndian(destinationStream);
	}

	void WindowsBitmapHeader::writeInfoHeaderEnd(std::ostream& destinationStream) const
	{
		numberOfPlanes.writeLittleEndian(destinationStream);
		bitsPerPixel.writeLittleEndian(destinationStream);
		compressionType.writeLittleEndian(destinationStream);
		compressedImageSize.writeLittleEndian(destinationStream);
		horizontalPixelsPerMeter.writeLittleEndian(destinationStream);
		verticalPixelsPerMeter.writeLittleEndian(destinationStream);
		numberOfColors.writeLittleEndian(destinationStream);
		numberOfImportantColors.writeLittleEndian(destinationStream);
	}
}
