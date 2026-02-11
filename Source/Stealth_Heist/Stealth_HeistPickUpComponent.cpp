// Copyright Epic Games, Inc. All Rights Reserved.

#include "Stealth_HeistPickUpComponent.h"

UStealth_HeistPickUpComponent::UStealth_HeistPickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UStealth_HeistPickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UStealth_HeistPickUpComponent::OnSphereBeginOverlap);
}

void UStealth_HeistPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AStealth_HeistCharacter* Character = Cast<AStealth_HeistCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
