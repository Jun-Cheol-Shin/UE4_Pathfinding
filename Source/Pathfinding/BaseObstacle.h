// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "BaseObstacle.generated.h"


// 열거형 선언 방법...
UENUM(BlueprintType)
enum class GroundTypes : uint8
{
	NORMAL UMETA(DisplayName = "Normal"),
	DIFFICULT UMETA(DisplayName = "Difficult"),
	REALLY_DIFFICULT UMETA(DisplayName = "Really_Difficult"),
	IMPOSSIBLE UMETA(DisplayName = "Impossible"),
};

UCLASS()
class PATHFINDING_API ABaseObstacle : public AActor
{
	GENERATED_BODY()


private:
	UPROPERTY(EditAnywhere, Category = "Grid")
		GroundTypes Enum_GroundTypes;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	ABaseObstacle();
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere)
		USceneComponent* O_Scene;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* O_Mesh;

	FORCEINLINE void setGroundType(GroundTypes type) { Enum_GroundTypes = type; }
	FORCEINLINE GroundTypes getGroundType() { return Enum_GroundTypes; }
};
