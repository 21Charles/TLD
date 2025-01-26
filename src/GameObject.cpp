#include "GameObject.h"

void GameObject::setScale(const glm::vec3 newScale) {
	_scale = newScale;
}
glm::vec3 GameObject::getScale() const {
	return _scale;
}

void GameObject::setPosition(const glm::vec3 newPosition) {
	_position = newPosition;
}
inline glm::vec3 GameObject::getPosition() const {
	return _position;
}

void GameObject::setRotation(const glm::quat newRotation) {
	_rotation = newRotation;
}
inline glm::quat GameObject::getRotation() const {
	return _rotation;
}

inline GameObject GameObject::withScale(const glm::vec3& scale) const {
	return GameObject(_position, scale, _rotation, _model, _collisionShape);
}
inline GameObject GameObject::withPosition(const glm::vec3& position) const {
	return GameObject();
}
inline GameObject GameObject::withRotation(const glm::quat& rotation) const {
	return GameObject();
}
