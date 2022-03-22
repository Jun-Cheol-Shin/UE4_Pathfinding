// Fill out your copyright notice in the Description page of Project Settings.


#include "GridActor.h"

#include "DrawDebugHelpers.h"
#include "Components/BillboardComponent.h"

// Sets default values
AGridActor::AGridActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	G_Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	G_Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));

	if(G_Scene)
	{
		RootComponent = G_Scene;
		if(G_Billboard) G_Billboard->SetupAttachment(RootComponent);
	}

	GridBoxColor = FColor(0,0,255);
	BottomLeftColor = FColor(255,0,0);
	GridSizeWorld = FVector2D(500, 500);
}

// Called when the game starts or when spawned
void AGridActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGridActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FVector AGridActor::gridBottomLeft()
{
	FVector temp = GridSizeWorld.X * RootComponent->GetRightVector();
	FVector temp2 = GridSizeWorld.Y * RootComponent->GetForwardVector();

	return (GridLocation - temp) - temp2;
}

FVector2D AGridActor::gridTileNumber()
{
	FVector2D temp = GridSizeWorld / TileSize;

	temp.X = round(temp.X) - 1;
	temp.Y = round(temp.Y) - 1;

	return temp;
}

void AGridActor::DrawTile()
{
	FVector2D temp = gridTileNumber();
	
	for(int i = 0; i <= temp.X; ++i)
	{
		for(int j = 0; j <= temp.Y; ++j)
		{

			FVector a = RootComponent->GetRightVector() * (i * (TileSize * 2) + TileSize);
			FVector b = RootComponent->GetForwardVector() * (j * (TileSize * 2) + TileSize);

			FVector TilePosition = gridBottomLeft() + a + b;


			DrawDebugSolidPlane(GetWorld(), FPlane(0,0,1,TilePosition.Z), TilePosition, TileSize - 5,
				FColor(0,255,0), true, -1.f, 0);
		}
	}
	
}



void AGridActor::OnConstruction(const FTransform& Transform)
{
	FlushPersistentDebugLines(GetWorld());
	GridLocation = RootComponent->GetComponentToWorld().GetLocation();
	DrawDebugBox(GetWorld(), GridLocation,
		FVector(GridSizeWorld.X, GridSizeWorld.Y, 5), GridBoxColor,
		true, -1.f, 0, 10);

	DrawDebugBox(GetWorld(), gridBottomLeft(),
		FVector(20,20,20),BottomLeftColor,
		true, -1., 0, 10);
	DrawTile();
}





