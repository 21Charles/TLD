#pragma once

#include "Fluid.h"

class Water : public Fluid {
public:
	virtual std::string getName() const noexcept override 
	{ return "Water"; }

	virtual float coolingLevel() const noexcept override 
	{ return 0.8f; }

	virtual float weightPerLiter() const noexcept override 
	{ return 1.0f; }

	virtual void onDrank() const noexcept override
	{ return; }

	virtual void onCombusted(Engine* engine) const noexcept override 
	{ return; }

	static Water* getInstance() {
		if (Instance == nullptr) {
			Instance = new Water();
		}
		return Instance;
	}

	Water(const Water& other) = delete;
	void operator=(const Water& other) = delete;

	~Water() {
		delete Instance;
	}

protected:
	Water() : Fluid() {}
	static Water* Instance;
};