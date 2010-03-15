#include "GameObject.h"

GameObject::GameObject(void)
{
	m_bDestroyed = false;
}

GameObject::~GameObject(void)
{
}

bool GameObject::Intersects(const GameObject& other){
	return false;
}