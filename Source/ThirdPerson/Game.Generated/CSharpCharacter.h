#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "CSharpCharacter.generated.h"
UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ACSharpCharacter : public ACharacter {
GENERATED_BODY()
public:
UPROPERTY(BlueprintReadWrite,EditAnywhere)
USpringArmComponent* CameraBoom;
UPROPERTY(BlueprintReadWrite,EditAnywhere)
UCameraComponent* FollowCamera;
UPROPERTY(BlueprintReadWrite,EditAnywhere)
UInputMappingContext* DefaultMappingContext;
UPROPERTY(BlueprintReadWrite,EditAnywhere)
UInputAction* JumpAction;
UPROPERTY(BlueprintReadWrite,EditAnywhere)
UInputAction* MoveAction;
UPROPERTY(BlueprintReadWrite,EditAnywhere)
UInputAction* LookAction;
ACSharpCharacter();
UFUNCTION(BlueprintCallable)
virtual void BeginPlay();
UFUNCTION(BlueprintCallable)
virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);
UFUNCTION(BlueprintCallable)
virtual void Move(FInputActionValue Value);
UFUNCTION(BlueprintCallable)
virtual void Look(FInputActionValue Value);
};
