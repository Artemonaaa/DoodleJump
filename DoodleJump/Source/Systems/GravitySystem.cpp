#include "GravitySystem.h"

#include "Components/GravityComponent.h"
#include "Components/TransformComponent.h"
#include "Components/PhysicsComponent.h"

#include "DeltaTime.h"

auto TGravitySystem::Update(entt::registry& Registry) -> void {
	auto View = Registry.view<TPhysicsComponent, TGravityComponent>();

	View.each([](TPhysicsComponent& PhysicsComponent) {
		PhysicsComponent.Velocity.y += 300.0F * GetDeltaTime();
	});
}
