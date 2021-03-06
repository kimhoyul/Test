// Shoot Them Up Game. All Rights Reserved.


#include "Player/DSBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ADSBaseCharacter::ADSBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void ADSBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADSBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADSBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this,&ADSBaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this,&ADSBaseCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this,&ADSBaseCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this,&ADSBaseCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAction("jump",IE_Pressed, this, &ADSBaseCharacter::Jump);
}

void ADSBaseCharacter::MoveForward(float Amount)
{
	AddMovementInput(GetActorForwardVector(),Amount);
	
}

void ADSBaseCharacter::MoveRight(float Amount)
{
	AddMovementInput(GetActorRightVector(), Amount);
}