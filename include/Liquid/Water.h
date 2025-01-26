#pragma once

#include "Liquid.h"

class Water : public Liquid {
public:
	virtual std::string getName() const override { return "Water"; }
	virtual float coolingLevel() const override { return 0.8f; }
	virtual float weightPerLiter() const override { return 1.0f; }
	virtual void onDrank() const override { return; }
	virtual void onCombusted() const override { return; }
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