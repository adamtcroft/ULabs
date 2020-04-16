#pragma once
#include "CodecInterfaces.h"
#include "WindowsBitmapDecoder.h"
#include "WindowsBitmapEncoder.h"
#include <fstream>
#include <list>

namespace BitmapGraphics
{
	class CodecLibrary
	{
	public:
		CodecLibrary() = default;
		CodecLibrary(const CodecLibrary& other) = default;
		CodecLibrary(CodecLibrary&& other) noexcept = default;
		CodecLibrary& operator=(const CodecLibrary& other) = default;
		CodecLibrary& operator=(CodecLibrary&& other) = default;
		~CodecLibrary() noexcept = default;

		void registerEncoder(HBitmapEncoder const& encoder);
		void registerDecoder(HBitmapDecoder const& decoder);

		HBitmapDecoder createDecoder(std::istream& sourceStream);
		HBitmapDecoder createDecoder(std::string const& mimeType, std::istream& sourceStream);

		HBitmapEncoder createEncoder(std::string const& mimeType, HBitmapIterator& bitmapIterator);

	private:
		std::vector<HBitmapDecoder> myDecoders;
		std::vector<HBitmapEncoder> myEncoders;
	};

}

