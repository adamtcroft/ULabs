#pragma once
#include "DrawingInterfaces.h"
#include "CodecLibrary.h"
#include <stack>

namespace BitmapGraphics
{
	class WindowsBitmapFileProjector final : public IProjector
	{
	public:
		WindowsBitmapFileProjector() = default;
		WindowsBitmapFileProjector(std::string const& filename, CodecLibrary& library);
		WindowsBitmapFileProjector(const WindowsBitmapFileProjector& other) = default;
		WindowsBitmapFileProjector(WindowsBitmapFileProjector&& other) = default;
		WindowsBitmapFileProjector& operator=(const WindowsBitmapFileProjector& other) = default;
		WindowsBitmapFileProjector& operator=(WindowsBitmapFileProjector&& other) = default;
		~WindowsBitmapFileProjector() = default;

		void projectCanvas(HCanvas const & canvas) override final;

	private:
		CodecLibrary* myLibrary;
		std::string myFilename;
	};
}

