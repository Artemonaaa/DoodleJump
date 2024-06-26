#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>

class TSpriteSystem {
public:
	auto Update(entt::registry& Registry, sf::RenderWindow& Window) -> void;

};
