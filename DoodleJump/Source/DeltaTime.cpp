#include "DeltaTime.h"

#include <SFML/Graphics.hpp>

static float GDeltaTime;
static sf::Clock GDeltaTimeClock;

auto GetDeltaTime() -> float {
	return GDeltaTime;
}

auto UpdateDeltaTime() -> void {
	GDeltaTime = GDeltaTimeClock.restart().asSeconds();
}
