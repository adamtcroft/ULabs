#pragma once
#include "Scene.h"
#include "XmlFactories.h"
#include "Parse.h"
#include "Element.h"

namespace Framework
{
	class SceneWriter
	{
	public:
		SceneWriter() = delete;
		SceneWriter(const SceneWriter& other) = delete;
		SceneWriter(SceneWriter&& other) = delete;
		SceneWriter& operator=(const SceneWriter& other) = delete;
		SceneWriter& operator=(SceneWriter&& other) = delete;
		~SceneWriter() = delete;

		static Xml::HElement writeScene(const Scene& scene);
	};
}

