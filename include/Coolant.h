#pragma once

#include "Fluid.h"
#include "GameObject.h"

class Coolant : public GameObject {
public:
	virtual inline float baseCoolingLevel() const noexcept = 0;
	virtual inline float coolingLevelWithCoolant(Fluid*) const noexcept = 0;

private:
	virtual std::pair<aiScene*, btCollisionShape*> getModelAndbtShape()
		const noexcept = 0;

public:
	Coolant(glm::vec3 position, glm::vec3 scale, glm::quat rotation) :
		GameObject(position, scale, rotation, getModelAndbtShape().first,
			getModelAndbtShape().second) {
	}
	~Coolant() = default;
};