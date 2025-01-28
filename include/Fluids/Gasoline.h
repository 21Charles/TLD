#pragma once

#include "Fluid.h"

class Gasoline : public Fluid {
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

	Gasoline(const Gasoline& other) = delete;
	void operator=(const Gasoline& other) = delete;

	~Gasoline() {
		delete Instance;
	}

protected:
	Gasoline() : Fluid() {}
	static Gasoline* Instance;
};