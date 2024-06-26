#include "BackgroundSystem.h"

#include "Components/TransformComponent.h"
#include "Components/SpriteComponent.h"

#include "Texture.h"

auto TBackgroundSystem::Init(entt::registry& Registry, sf::RenderWindow& Window) -> entt::entity {
    auto Entity = Registry.create();

    Registry.emplace<TTransformComponent>(Entity, sf::Vector2f(500.0F, 300.0F));
    Registry.emplace<TSpriteComponent>(Entity, GetCentered(sf::Sprite(GTextures->Background)), 0);

    return Entity;
}

auto TBackgroundSystem::Update(entt::registry& Registry) -> void {
	//auto View = Registry.view<TSpriteComponent, TTransformComponent>();
}
