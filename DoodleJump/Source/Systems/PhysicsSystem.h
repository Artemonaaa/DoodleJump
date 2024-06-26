#pragma once

#include <entt/entt.hpp>

class TPhysicsSystem {
public:
	auto Update(entt::registry& Registry) -> void;
};
