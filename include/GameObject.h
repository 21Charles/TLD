#pragma once

#include <ASSIMP/scene.h>
#include <BULLET/btBulletCollisionCommon.h>
#include <GLM/vec3.hpp>
#include <GLM/gtc/quaternion.hpp>

class GameObject {
	void setScale(float newScale);
	float getScale();

	void setPosition(glm::vec3 newPosition);
	glm::vec3 getPosition();

	void setRotation(glm::quat newRotation);
	glm::quat getRotation();

	aiScene getModel() { return *_model; }
	btCollisionShape* getCollisionShape() { return _collisionShape; }
private:
	float _weight;
	float _scale;
	glm::vec3 _position;
	glm::quat _rotation;
	aiScene* _model;
	btCollisionShape* _collisionShape;
};