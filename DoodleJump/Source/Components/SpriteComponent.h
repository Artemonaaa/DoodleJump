#pragma once

#include <SFML/Graphics.hpp>

class TSpriteComponent {
public:
	sf::Sprite Sprite;
    int Layer = 0;
};


inline auto GetCentered(sf::Sprite Sprite) -> sf::Sprite {
    Sprite.setOrigin(sf::Vector2f(Sprite.getTexture()->getSize()) / 2.0F);
    return Sprite;
}