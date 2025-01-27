#pragma once

#include "GameObject.h"

class Wheel : public GameObject {
public:
	virtual inline float handleLevel() const = 0;
private:
	virtual std::pair<aiScene*, btCollisionShape*> getModelAndbtShape()
		const noexcept = 0;
public:
	Wheel(glm::vec3 position, glm::vec3 scale, glm::quat rotation) :
		GameObject(position, scale, rotation, getModelAndbtShape().first,
			getModelAndbtShape().second) {
	}

	~Wheel() = default;
};