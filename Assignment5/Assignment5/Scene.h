#pragma once
#include <string>
#include <list>
#include "Layer.h"
#include "DrawingInterfaces.h"

namespace Framework
{
	using LayerCollection = std::list<Layer>;

	class Scene
	{
	public:
		Scene() = delete;
		Scene(int initialWidth, int initialHeight);
		Scene(const Scene& other) = default;
		Scene(Scene&& other) = default;
		Scene& operator=(const Scene& other) = default;
		Scene& operator=(Scene&& other) = default;
		~Scene() = default;

		template <class L> void pushBack(L&& layer)
		{
			layers.push_back(std::forward<L>(layer));
		}
		void remove(const Layer&& layer);

		using LayerIterator = LayerCollection::const_iterator;
		LayerIterator begin() const;
		LayerIterator end() const;

		void setWidth(size_t w);
		void setHeight(size_t h);

		void draw(BitmapGraphics::HCanvas& canvas);

		int const getWidth() const;
		int const getHeight() const;

		bool operator==(const Scene& rhs) const;
		bool operator!=(const Scene& rhs) const;

	private:
		LayerCollection layers;
		size_t width, height;
	};

}