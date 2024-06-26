#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>

class TBackgroundSystem {
public: 
	auto Update(entt::registry& Registry) -> void;

	auto Init(entt::registry& Registry, sf::RenderWindow& Window) -> entt::entity;
};