#pragma once

#include <SFML/Graphics.hpp>
#include <optional>

struct TTextures {
	TTextures() {
		Doodle.loadFromFile("Texture/Doodle.png");
		Platform.loadFromFile("Texture/Platform.png");
		Background.loadFromFile("Texture/Background.png");
	}

	sf::Texture Doodle;
	sf::Texture Platform;
	sf::Texture Background;
};

inline std::optional<TTextures> GTextures;
