#pragma once

#include "Liquid.h"

class Water : public Liquid {
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

	~Water() {
		delete Instance;
	}

protected:
	Water() : Liquid() {}
	static Water* Instance;
};