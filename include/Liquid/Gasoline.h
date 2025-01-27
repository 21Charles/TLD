#pragma once

#include "Liquid.h"

class Gasoline : public Liquid {
public:
	virtual std::string getName() const noexcept override 
	{ return "Gasoline"; }

	virtual float coolingLevel() const noexcept override 
	{ return 0.1f; }

	virtual float weightPerLiter() const noexcept override 
	{ return 0.75f; }

	virtual void onDrank() const noexcept override 
	{ return; }

	virtual void onCombusted(Engine* engine) const noexcept override 
	{ return; }

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