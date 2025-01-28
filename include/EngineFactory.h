#pragma once

#include <string>
#include <unordered_map>

class EngineFactory {
public:
	static EngineFactory* getInstance() {
		if (Instance == nullptr) {
			Instance = new EngineFactory();
		}
		return Instance;
	}


	~EngineFactory() {
		delete Instance;
	}

	EngineFactory(const EngineFactory& other) = delete;
	void operator=(const EngineFactory& other) = delete;
private:
	template<Engine engine>
	void addEngine(std::string code) {

	}

	static EngineFactory* Instance;
	EngineFactory() {
		
	}
};
