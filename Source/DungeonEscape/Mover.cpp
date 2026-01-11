// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();
    
    AActor* MyOwner = GetOwner();
    
    //FString MyOwnerName = MyOwner->GetActorNameOrLabel();
    
    StartLocation = MyOwner->GetActorLocation();
    
    //UE_LOG(LogTemp,Display,TEXT("%s is at location %s"),*MyOwnerName,*StartLocation.ToCompactString());
    
    TargetLocation = StartLocation + MoveOffset;

	// ...
	
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    
    if(ShouldMove)
    {
        FVector CurrentLocation = GetOwner()->GetActorLocation();
        
        float Speed = MoveOffset.Length()/MoveTime;
        
        FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation,TargetLocation,DeltaTime,Speed);
        
        GetOwner()->SetActorLocation(NewLocation);
    }
    
    
    
    
    

	// ...
}

