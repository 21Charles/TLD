#pragma once

#include "Engine.h"

class GasolineEngine : public Engine {
public:
	virtual inline Liquid* Fuel() const noexcept override {
		return LiquidRegistry::getInstance()->getLiquid("Gasoline");
	}

	GasolineEngine(glm::vec3 position, glm::vec3 scale, glm::quat rotation) : 
		Engine(position, scale, rotation) {}
	}
};