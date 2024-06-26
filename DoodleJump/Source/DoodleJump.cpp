#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>

#include "Systems/PlayerSystem.h"
#include "Systems/SpriteSystem.h"
#include "Systems/PhysicsSystem.h"
#include "Systems/GravitySystem.h"
#include "Systems/PlatformSystem.h"
#include "Systems/BackgroundSystem.h"

#include "Texture.h"
#include "DeltaTime.h"

int main() {
    GTextures.emplace();

    auto Window = sf::RenderWindow(sf::VideoMode(1000, 600), "SFML works!");
    auto Registry = entt::registry();

    auto PlayerSystem = TPlayerSystem();
    auto PhysicsSystem = TPhysicsSystem();
    auto SpriteSystem = TSpriteSystem();
    auto GravitySystem = TGravitySystem();
    auto PlatformSystem = TPlatformSystem();
    auto BackgroundSystem = TBackgroundSystem();
        
    PlayerSystem.Init(Registry);
    PlatformSystem.Init(Registry);
    BackgroundSystem.Init(Registry, Window);

    while (Window.isOpen()) {
        UpdateDeltaTime();
        auto Event = sf::Event();
        while (Window.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                Window.close();
        }

        GravitySystem.Update(Registry);
        PlayerSystem.Update(Registry, Window);
        PhysicsSystem.Update(Registry);

        Window.clear();
        SpriteSystem.Update(Registry, Window);
        Window.display();
    }

    return 0;
}