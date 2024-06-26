#pragma once

#include <entt/entt.hpp>

class TGravitySystem {
public:
	auto Update(entt::registry& Registry) -> void;
};
