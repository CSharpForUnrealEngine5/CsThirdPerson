#include "CSharpCharacter.h"
ACSharpCharacter::ACSharpCharacter()
{
GetCapsuleComponent()->InitCapsuleSize(42.0f,96.0f);
bUseControllerRotationPitch=false;
bUseControllerRotationYaw=false;
bUseControllerRotationRoll=false;
GetCharacterMovement()->bOrientRotationToMovement=true;
GetCharacterMovement()->RotationRate=FRotator(0.0f,500.0f,0.0f);
GetCharacterMovement()->JumpZVelocity=700.0f;
GetCharacterMovement()->AirControl=0.35f;
GetCharacterMovement()->MaxWalkSpeed=500.0f;
GetCharacterMovement()->MinAnalogWalkSpeed=20.0f;
GetCharacterMovement()->BrakingDecelerationWalking=2000.0f;
CameraBoom=CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
CameraBoom->SetupAttachment(RootComponent);
CameraBoom->TargetArmLength=400.0f;
CameraBoom->bUsePawnControlRotation=true;
FollowCamera=CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
FollowCamera->SetupAttachment(CameraBoom,USpringArmComponent::SocketName);
FollowCamera->bUsePawnControlRotation=false;
}
void ACSharpCharacter::BeginPlay()
{
Super::BeginPlay();
GLog->Log(TEXT("C#"),ELogVerbosity::Warning,TEXT("Hello from C#"));
GEngine->AddOnScreenDebugMessage(0,100,FColor::Orange,TEXT("Hello From C#"),true,FVector2D::UnitVector);
 APlayerController* PlayerController=Cast<APlayerController>(Controller);
if (PlayerController!=nullptr)
{
 UEnhancedInputLocalPlayerSubsystem* Subsystem=ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
if (Subsystem!=nullptr)
{
Subsystem->AddMappingContext(DefaultMappingContext,0);
}
}
}
void ACSharpCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
 UEnhancedInputComponent* EnhancedInputComponent=CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
if (EnhancedInputComponent!=nullptr)
{
EnhancedInputComponent->BindAction(JumpAction,ETriggerEvent::Triggered,this,TEXT("Jump"));
EnhancedInputComponent->BindAction(JumpAction,ETriggerEvent::Completed,this,TEXT("StopJumping"));
EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,TEXT("Move"));
EnhancedInputComponent->BindAction(LookAction,ETriggerEvent::Triggered,this,TEXT("Look"));
}
}
void ACSharpCharacter::Move(FInputActionValue Value)
{
 FVector2D MovementVector=Value.Get<FVector2D>();
if (Controller!=nullptr)
{
 FRotator Rotation=Controller->GetControlRotation();
 FRotator YawRotation=FRotator(0,Rotation.Yaw,0);
 FVector ForwardDirection=FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
 FVector RightDirection=FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
AddMovementInput(ForwardDirection,(float)(MovementVector.Y),false);
AddMovementInput(RightDirection,(float)(MovementVector.X),false);
}
}
void ACSharpCharacter::Look(FInputActionValue Value)
{
 FVector2D LookAxisVector=Value.Get<FVector2D>();
if (Controller!=nullptr)
{
AddControllerYawInput((float)(LookAxisVector.X));
AddControllerPitchInput((float)(LookAxisVector.Y));
}
}
