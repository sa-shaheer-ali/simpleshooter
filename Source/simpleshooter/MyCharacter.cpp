// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"),this,&AMyCharacter::MoveForward);
    PlayerInputComponent->BindAxis(TEXT("LookUp"),this,&APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("MoveSide"),this,&AMyCharacter::MoveSide);
	PlayerInputComponent->BindAxis(TEXT("LookSide"),this,&APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"),this,&AMyCharacter::LookUpRate);
	PlayerInputComponent->BindAction(TEXT("Jump"),EInputEvent::IE_Pressed,this,&ACharacter::Jump);
	
}

void AMyCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector()* AxisValue);
}


// Void AMyCharacter::LookUp(float AxisValue)
//  {
//  	AddControllerPitchInput(AxisValue);
//  }

void AMyCharacter::MoveSide(float AxisValue)
{
	AddMovementInput(GetActorRightVector()* AxisValue);
}

void AMyCharacter::LookUpRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue*RotationRate* GetWorld()->GetDeltaSeconds());
}

