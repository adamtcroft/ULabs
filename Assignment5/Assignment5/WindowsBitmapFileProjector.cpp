#include "WindowsBitmapFileProjector.h"

namespace BitmapGraphics
{
	WindowsBitmapFileProjector::WindowsBitmapFileProjector(std::string const& filename, CodecLibrary& library) :
		myFilename(filename), myLibrary(&library)
	{
	}

	void WindowsBitmapFileProjector::projectCanvas(HCanvas const & canvas)
	{
		const std::string msBmp{ "image/x-ms-bmp" };
		auto iterator = canvas->createBitmapIterator();
		HBitmapEncoder encoder{ myLibrary->createEncoder(msBmp, iterator) };
		std::ofstream outFile{ myFilename, std::ios::binary };
		encoder->encodeToStream(outFile);
		outFile.close();
	}
}
