#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::ChangeScene(int next)
{
	m_bChangeScene = true;
	m_NextScene = next;
}