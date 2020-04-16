#pragma once
#include "XmlInterfaces.h"
#include "Scene.h"

namespace Framework
{
	class SceneReader
	{
	public:
		SceneReader() = delete;
		SceneReader(const SceneReader& other) = delete;
		SceneReader(SceneReader&& other) = delete;
		SceneReader& operator=(const SceneReader& other) = delete;
		SceneReader& operator=(SceneReader&& other) = delete;
		~SceneReader() = delete;

		static Framework::Scene readScene(Xml::IElement& root);

	private:
		static void readLayer(Framework::Scene& scene, const Xml::HElement layerElement);
		static void readGraphic(Framework::Scene& scene, Framework::Layer& layer, const Xml::HElement graphicElement);
		static VG::VectorGraphic readVectorGraphic(const Xml::HElement vgElement);
	};
}

