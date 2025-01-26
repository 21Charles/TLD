#pragma once

#include <ASSIMP/scene.h>
#include <BULLET/btBulletCollisionCommon.h>
#include <GLM/vec3.hpp>
#include <GLM/gtc/quaternion.hpp>

class GameObject {
public:
	void setScale(float newScale);
	float getScale() const;

	void setPosition(glm::vec3 newPosition);
	inline glm::vec3 getPosition() const;

	void setRotation(glm::quat newRotation);
	inline glm::quat getRotation() const;

	inline aiScene getModel() const { 
		return *_model; 
	}

	inline btCollisionShape* getCollisionShape() const { 
		return _collisionShape; 
	}

	~GameObject() {
		delete _model;
		delete _collisionShape;
	}

private:
	float _weight;
	float _scale;
	glm::vec3 _position;
	glm::quat _rotation;
	aiScene* _model;
	btCollisionShape* _collisionShape;
};