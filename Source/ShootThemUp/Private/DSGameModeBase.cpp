// Shoot Them Up Game. All Rights Reserved.


#include "DSGameModeBase.h"
#include "Player/DSBaseCharacter.h"
#include "Player/DSPlayerController.h"


ADSGameModeBase::ADSGameModeBase()
{
	DefaultPawnClass = ADSBaseCharacter::StaticClass();
	PlayerControllerClass = ADSPlayerController::StaticClass();
}
