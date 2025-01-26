#pragma once

#include "Liquid.h"

class Gasoline : public Liquid {
public:
	virtual std::string getName() const override { return "Gasoline"; }
	virtual float coolingLevel() const override { return 0.1f; }
	virtual float weightPerLiter() const override { return 0.75f; }
	virtual void onDrank() const override { return; }
	virtual void onCombusted() const override { return; }
	static Gasoline* getInstance() {
		if (Instance == nullptr) {
			Instance = new Gasoline();
		}
		return Instance;
	}

	~Gasoline() {
		delete Instance;
	}

protected:
	Gasoline() : Liquid() {}
	static Gasoline* Instance;
};