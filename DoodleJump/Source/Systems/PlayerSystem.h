#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>

class TPlayerSystem {
public:
	auto Init(entt::registry& Registry) -> entt::entity;

	auto Update(entt::registry& Registry, sf::RenderWindow& Window) -> void;
};

