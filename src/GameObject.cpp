#include "GameObject.h"

void GameObject::setScale(float newScale) {
	_scale = newScale;
}
float GameObject::getScale() const {
	return _scale;
}

void GameObject::setPosition(glm::vec3 newPosition) {
	_position = newPosition;
}
inline glm::vec3 GameObject::getPosition() const {
	return _position;
}

void GameObject::setRotation(glm::quat newRotation) {
	_rotation = newRotation;
}
inline glm::quat GameObject::getRotation() const {
	return _rotation;
}