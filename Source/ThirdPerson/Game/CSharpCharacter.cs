using GameFramework;

namespace Game
{
    public class ACSharpCharacter : ACharacter
    {
        USpringArmComponent CameraBoom;

        /** Follow camera */

        UCameraComponent FollowCamera;

        /** MappingContext */
        UInputMappingContext DefaultMappingContext;

        /** Jump Input Action */
        UInputAction JumpAction;


        UInputAction MoveAction;

        /** Look Input Action */
        UInputAction LookAction;

        ACSharpCharacter()
        {
            // Set size for collision capsule
            GetCapsuleComponent().InitCapsuleSize(42.0f, 96.0f);

            // Don't rotate when the controller rotates. Let that just affect the camera.
            bUseControllerRotationPitch = false;
            bUseControllerRotationYaw = false;
            bUseControllerRotationRoll = false;

            // Configure character movement
            GetCharacterMovement().bOrientRotationToMovement = true; // Character moves in the direction of input...	
            GetCharacterMovement().RotationRate = new FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

            // Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
            // instead of recompiling to adjust them
            GetCharacterMovement().JumpZVelocity = 700.0f;
            GetCharacterMovement().AirControl = 0.35f;
            GetCharacterMovement().MaxWalkSpeed = 500.0f;
            GetCharacterMovement().MinAnalogWalkSpeed = 20.0f;
            GetCharacterMovement().BrakingDecelerationWalking = 2000.0f;

            // Create a camera boom (pulls in towards the player if there is a collision)
            CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
            CameraBoom.SetupAttachment(RootComponent);
            CameraBoom.TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
            CameraBoom.bUsePawnControlRotation = true; // Rotate the arm based on the controller

            // Create a follow camera
            FollowCamera = CreateDefaultSubobject<UCameraComponent>("FollowCamera");
            FollowCamera.SetupAttachment(CameraBoom, USpringArmComponent.SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
            FollowCamera.bUsePawnControlRotation = false; // Camera does not rotate relative to arm

            // Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
            // are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
        }
        void BeginPlay()
        {
            // Call the base class  
            base.BeginPlay();

            Log("C#", ELogVerbosity.Warning, "Hello from C#");
            AddOnScreenDebugMessage(0, 100, FColor.Orange, "Hello From C#", true, FVector2D.UnitVector);

            //Add Input Mapping Context
            APlayerController PlayerController = Cast<APlayerController>(Controller);
            if (PlayerController != null)
            {
                UEnhancedInputLocalPlayerSubsystem Subsystem = ULocalPlayer.GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController.GetLocalPlayer());
                if (Subsystem != null)
                {
                    Subsystem.AddMappingContext(DefaultMappingContext, 0);
                }
            }
        }

        //////////////////////////////////////////////////////////////////////////
        // Input

        void SetupPlayerInputComponent(UInputComponent PlayerInputComponent)
        {
            // Set up action bindings
            UEnhancedInputComponent EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);

            if (EnhancedInputComponent != null)
            {

                //Jumping
                EnhancedInputComponent.BindAction(JumpAction, ETriggerEvent.Triggered, this, "Jump");
                EnhancedInputComponent.BindAction(JumpAction, ETriggerEvent.Completed, this, "StopJumping");

                //Moving
                EnhancedInputComponent.BindAction(MoveAction, ETriggerEvent.Triggered, this, "Move");

                //Looking
                EnhancedInputComponent.BindAction(LookAction, ETriggerEvent.Triggered, this, "Look");

            }

        }

        void Move(FInputActionValue Value)
        {
            // input is a Vector2D
            FVector2D MovementVector = Value.Get<FVector2D>();

            if (Controller != null)
            {
                // find out which way is forward
                FRotator Rotation = Controller.GetControlRotation();
                FRotator YawRotation = new FRotator(0, Rotation.Yaw, 0);

                // get forward vector
                FVector ForwardDirection = new FRotationMatrix(YawRotation).GetUnitAxis(EAxis.X);

                // get right vector 
                FVector RightDirection = new FRotationMatrix(YawRotation).GetUnitAxis(EAxis.Y);

                // add movement 
                AddMovementInput(ForwardDirection, (float) MovementVector.Y, false);
                AddMovementInput(RightDirection, (float) MovementVector.X, false);
            }
        }

        void Look(FInputActionValue Value)
        {
            // input is a Vector2D
            FVector2D LookAxisVector = Value.Get<FVector2D>();

            if (Controller != null)
            {
                // add yaw and pitch input to controller
                AddControllerYawInput((float) LookAxisVector.X);
                AddControllerPitchInput((float)LookAxisVector.Y);
            }
        }

    }
}
