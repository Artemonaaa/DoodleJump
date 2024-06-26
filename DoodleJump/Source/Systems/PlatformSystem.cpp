#include "PlatformSystem.h"

#include "Components/PlatformComponent.h"
#include "Components/TransformComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/SpriteComponent.h"

#include "Texture.h"
#include "Random.h"

auto CreatePlatform(entt::registry& Registry, sf::Vector2f Position) -> entt::entity {
    auto Entity = Registry.create();

    Registry.emplace<TPlatformComponent>(Entity);
    Registry.emplace<TPhysicsComponent>(Entity);
    Registry.emplace<TSpriteComponent>(Entity, GetCentered(sf::Sprite(GTextures->Platform)), 1);
    Registry.emplace<TTransformComponent>(Entity, Position);

    return Entity;
}


auto TPlatformSystem::Update(entt::registry& Registry) -> void {
	//auto View = Registry.view<TTransformComponent, TPlatformComponent>();
    //
	//View.each([](TTransformComponent& TransformComponent, TPlatformComponent& PlatformComponent) {
    //    
	//});

}

auto TPlatformSystem::Init(entt::registry& Registry) -> void {
    for (size_t I = 0; I < NumberOfPlatforms; ++I) {
        CreatePlatform(Registry, sf::Vector2f(RandomFloat() * 1000.0F, RandomFloat() * 600.0F));
    }
}

