#include "Scene.h"

namespace Framework
{
	Scene::Scene(int initialWidth, int initialHeight) :
		width(initialWidth), height(initialHeight)
	{
	}

	void Scene::remove(const Layer&& layer)
	{
		layers.remove(layer);
	}

	Scene::LayerIterator Framework::Scene::begin() const
	{
		return layers.begin();
	}

	Scene::LayerIterator  Framework::Scene::end() const
	{
		return layers.end();
	}

	void Scene::setWidth(size_t w)
	{
		width = w;
	}

	void Scene::setHeight(size_t h)
	{
		height = h;
	}

	void Scene::draw(BitmapGraphics::HCanvas& canvas)
	{
		for (auto& layer : layers)
		{
			layer.draw(canvas);
		}
	}

	int const Scene::getWidth() const
	{
		return width;
	}

	int const Scene::getHeight() const
	{
		return height;
	}

	bool Scene::operator==(const Scene& rhs) const
	{
		return (width == rhs.width)
			&& (height == rhs.height)
			&& (layers == rhs.layers);
	}

	bool Scene::operator!=(const Scene& rhs) const
	{
		return !(*this == rhs);
	}
}
