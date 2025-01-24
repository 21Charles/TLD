#include "GameObject.h"

void GameObject::setScale(float newScale) {
	_scale = newScale;
}
float GameObject::getScale() {
	return _scale;
}

void GameObject::setPosition(glm::vec3 newPosition) {
	_position = newPosition;
}
glm::vec3 GameObject::getPosition() {
	return _position;
}

void GameObject::setRotation(glm::quat newRotation) {
	_rotation = newRotation;
}
glm::quat GameObject::getRotation() {
	return _rotation;
}