#include "PhysicsSystem.h"

#include "Components/TransformComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/PlatformComponent.h"
#include "Components/PlayerComponent.h"

#include "DeltaTime.h"

#include <iostream>

auto TPhysicsSystem::Update(entt::registry& Registry) -> void {
	auto View = Registry.view<TPhysicsComponent, TTransformComponent>();

	View.each([](TPhysicsComponent& PhysicsComponent, TTransformComponent& TransformComponent) {
		TransformComponent.Position += PhysicsComponent.Velocity * GetDeltaTime();
	});
}
