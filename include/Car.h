#pragma once

#include "GameObject.h"
#include "Engine.h"
#include "Coolant.h"
#include "Wheel.h"
#include <string>
#include <map>

class Car : public GameObject {
public:
	Engine* engine;
	Coolant* coolant;
	std::map<std::string, Wheel*> wheels = {
		{"Front Left", nullptr},
		{"Front Right", nullptr},
		{"Rear Left", nullptr},
		{"Rear Right", nullptr}
	};

private:
	virtual std::pair<aiScene*, btCollisionShape*> getModelAndbtShape()
		const noexcept = 0;
public:

	Car(glm::vec3 position, glm::vec3 scale, glm::quat rotation) :
		GameObject(position, scale, rotation, getModelAndbtShape().first,
			getModelAndbtShape().second) {
	}

	~Car() {
		delete engine;
		delete coolant;
	}
};