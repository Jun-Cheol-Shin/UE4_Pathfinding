// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridActor.generated.h"

UCLASS()
class PATHFINDING_API AGridActor : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = "Grid")
		FVector GridLocation;
	UPROPERTY(EditAnywhere, Category = "Grid")
		FVector2D GridSizeWorld;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Sets default values for this actor's properties
	AGridActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditAnywhere)
		USceneComponent* G_Scene;
	UPROPERTY(EditAnywhere)
		UBillboardComponent* G_Billboard;

	
	UPROPERTY(EditAnywhere)
		FColor GridBoxColor;
	UPROPERTY(EditAnywhere)
		FColor BottomLeftColor;
	UPROPERTY(EditAnywhere)
		float TileSize = 50;
	UPROPERTY(EditAnywhere)
		float TileSizeMinus = 5;
	
	FVector gridBottomLeft();
	FVector2D gridTileNumber();
	void DrawTile();

	bool mySphereTrace(const FVector& Location, const float& size, const ECollisionChannel& type, FHitResult& result);
};
