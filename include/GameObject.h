#pragma once

#include <ASSIMP/scene.h>
#include <BULLET/btBulletCollisionCommon.h>
#include <GLM/vec3.hpp>
#include <GLM/gtc/quaternion.hpp>

class GameObject {
public:

	GameObject(glm::vec3 position = glm::vec3(0.0f), glm::vec3 scale = glm::vec3(1.0f), 
		glm::quat rotation = glm::quat(), aiScene* model, btCollisionShape* collisionShape)
		: _position(position), _scale(scale), _rotation(rotation), _model(model), _collisionShape(collisionShape) 
	{}
	
	void setScale(const glm::vec3);
	glm::vec3 getScale() const;

	void setPosition(const glm::vec3);
	inline glm::vec3 getPosition() const;

	void setRotation(const glm::quat);
	inline glm::quat getRotation() const;

	inline aiScene getModel() const { 
		return *_model; 
	}

	inline btCollisionShape* getCollisionShape() const { 
		return _collisionShape; 
	}

	inline GameObject withScale(const glm::vec3&) const;
	inline GameObject withPosition(const glm::vec3&) const;
	inline GameObject withRotation(const glm::quat&) const;

	~GameObject() {
		delete _model;
		delete _collisionShape;
	}

private:
	float _weight;
	glm::vec3 _scale;
	glm::vec3 _position;
	glm::quat _rotation;
	aiScene* _model;
	btCollisionShape* _collisionShape;
};