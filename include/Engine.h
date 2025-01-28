#pragma once

#include <string>
#include <utility>
#include "Fluid.h"
#include "FluidRegistry.h"
#include "Coolant.h"
#include "GameObject.h"

class Engine : public GameObject {
public:
	virtual inline std::string Name()				const noexcept = 0;
	virtual inline int maxRpm()						const noexcept = 0;
	virtual inline int Torque()						const noexcept = 0;
	virtual inline int Power()						const noexcept = 0;
	virtual inline float coolingLevel()				const noexcept = 0;
	virtual inline float FuelConsuption()			const noexcept = 0;
	virtual inline Fluid* Fuel()					const noexcept = 0;
	virtual inline bool matchCoolingLevel(Coolant*)	const noexcept = 0;
private:
	virtual std::pair<aiScene*, btCollisionShape*> getModelAndbtShape()
		const noexcept = 0;

public:

	Engine(glm::vec3 position, glm::vec3 scale, glm::quat rotation) : 
		GameObject(position, scale, rotation, getModelAndbtShape().first, 
			getModelAndbtShape().second) {}

	~Engine() = default;
};