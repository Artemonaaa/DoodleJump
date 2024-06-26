#include "SpriteSystem.h"

#include "Components/TransformComponent.h"
#include "Components/SpriteComponent.h"

#include "Texture.h"
#include "Maths.h"

auto TSpriteSystem::Update(entt::registry& Registry, sf::RenderWindow& Window) -> void {
    auto View = Registry.view<TSpriteComponent, const TTransformComponent>();

    Registry.sort<TSpriteComponent>([](const TSpriteComponent& A, const TSpriteComponent& B) {
        return A.Layer < B.Layer;
    });
    
    View.each([&Window](TSpriteComponent& SpriteComponent, const TTransformComponent& TransformComponent) {
        SpriteComponent.Sprite.setPosition(TransformComponent.Position);

        Window.draw(SpriteComponent.Sprite);
    });
}

