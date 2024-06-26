#pragma once 

#include "entt/entt.hpp"
#include <SFML/Graphics.hpp>

class TPlatformSystem {
public:
	auto Update(entt::registry& Registry) -> void;

	auto Init(entt::registry& Registry) -> void;

private: 
	unsigned int NumberOfPlatforms = 20;

};