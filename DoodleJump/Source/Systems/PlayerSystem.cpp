#include "PlayerSystem.h"

#include "Components/TransformComponent.h"
#include "Components/PlayerComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/GravityComponent.h"
#include "Components/PlatformComponent.h"
#include "Components/SpriteComponent.h"

#include "Texture.h"
#include "Maths.h"
#include "DeltaTime.h"

auto TPlayerSystem::Init(entt::registry& Registry) -> entt::entity {
    auto Entity = Registry.create();

    Registry.emplace<TPlayerComponent>(Entity);
    Registry.emplace<TGravityComponent>(Entity);
	Registry.emplace<TSpriteComponent>(Entity, GetCentered(sf::Sprite(GTextures->Doodle)), 2);
    Registry.emplace<TTransformComponent>(Entity, sf::Vector2f(400.0F, 300.0F));
    Registry.emplace<TPhysicsComponent>(Entity, sf::Vector2f(0.0F, 0.0F));

    return Entity;
}

auto TPlayerSystem::Update(entt::registry& Registry, sf::RenderWindow& Window) -> void {
    auto View = Registry.view<TPhysicsComponent, TTransformComponent, TPlayerComponent>();
	//auto ViewPlatform = Registry.view<TPlatformComponent, TPhysicsComponent, TTransformComponent>();

	View.each([&Window, &Registry](TPhysicsComponent& PhysicsComponent, TTransformComponent& TransformComponent) {
		auto Offset = sf::Vector2f();
		float Speed = 400.0F;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			Offset.x += -1.0F;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			Offset.x += 1.0F;
		}

		Offset = GetNormalized(Offset);
		TransformComponent.Position += Offset * Speed * GetDeltaTime();

		if (TransformComponent.Position.x <= 0) {
			TransformComponent.Position.x = 1000.0f;
		}
		if (TransformComponent.Position.x >= 1001.0f) {
			TransformComponent.Position.x = 0.0f;
		}
		if (TransformComponent.Position.y <= 0.0f) {
			TransformComponent.Position.y = 600.0f;
		}
		if (TransformComponent.Position.y >= 601.0f) {
			TransformComponent.Position.y = 0.0f;
		}

		//auto& PlayerTransformComponent = TransformComponent;
		//ViewPlatform.each([&PlayerTransformComponent](TTransformComponent& TransformComponent) {
		//
		//});
    });
}


