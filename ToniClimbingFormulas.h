
#pragma once

#include "CoreMinimal.h"
#include "TomFormulaCollection.h"
#include "TomClimbingFormulas.generated.h"

enum class ETomClimbableType : uint8;
enum class ETomCharacterStates : uint8;
enum class ETomPoleSwingDirection : uint8;

/**
 * Contains formulas for the TomClimbingComponent and it's functions.
 */
UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class TOM_API UTomClimbingFormulas : public UTomFormulaCollection
{
    GENERATED_BODY()

public:
    /**
     * Get the current slide velocity for the character, depending how long he is already sliding.
     * @param StartSlideVelocity
     * @param SlideDuration Since we started sliding.
     * @param StateBeforeFalling
     * @return
     */
    UFUNCTION(BlueprintCallable, Category = "Climbing|Wall Slide")
    static FVector GetSlideSurfaceVelocity(const FVector StartSlideVelocity,
                                           const float SlideDuration,
                                           const ETomCharacterStates StateBeforeFalling);

    /**
     * Get the current slide velocity for the character, depending how long he is already sliding.
     * @param StartSlideVelocity
     * @param SlideDuration Since we started sliding.
     * @param StateBeforeFalling
     * @return
     */
    UFUNCTION(BlueprintCallable, Category = "Climbing|Ladder Slide")
    static FVector GetSlideLadderVelocity(const FVector StartSlideVelocity,
                                           const float SlideDuration,
                                           const ETomCharacterStates StateBeforeFalling);

    /**
     * Can a character cling on a climbable with his current CharacterVelocity?
     * If the character can NOT hold on a surface this will end up with a Wall-Slide.
     * @param ClimbableType 
     * @param CharacterVelocity 
     * @param CharacterStateBeforeFalling 
     * @return 
     */
    UFUNCTION(BlueprintCallable, Category = "Climbing|Wall Slide")
    static bool CanHoldOnClimbable(const ETomClimbableType ClimbableType,
                                   const FVector CharacterVelocity,
                                   const ETomCharacterStates CharacterStateBeforeFalling);

    /**
     * Returns a quantized JumpVelocity.
     * @param SwingAngle Current Character Pitch. Value between -90 and 90.
     * @param SwingVelocity In percent. Value between 0 and 1.
     * @param PoleSwingDirection
     * @param OutJumpVelocity 
     */
    UFUNCTION(BlueprintCallable, Category = "Climbing|Pole Jump")
    static void GetQuantizedPoleJumpVelocity(const float SwingAngle, const float SwingVelocity,
                                             const ETomPoleSwingDirection PoleSwingDirection,
                                             FVector& OutJumpVelocity);

    /* Do not rotate the character if he is jumping from the "red zone". */
    UFUNCTION(BlueprintCallable, Category = "Climbing|Pole Jump")
    static bool TurnCharacterInDirectionOfPoleJump(const float SwingAngle);

protected:
    /**
     * Get the current slide velocity for the character, depending how long he is already sliding.
     * @param StartSlideVelocity
     * @param SlideDuration Since we started sliding.
     * @param StateBeforeFalling
     * @return
     */
    UFUNCTION(BlueprintImplementableEvent, Category = "Climbing|Wall Slide")
    FVector GetSlideSurfaceVelocityBP(const FVector StartSlideVelocity, const float SlideDuration,
                                      const ETomCharacterStates StateBeforeFalling);

    /**
     * Get the current slide velocity for the character, depending how long he is already sliding.
     * @param StartSlideVelocity
     * @param SlideDuration Since we started sliding.
     * @param StateBeforeFalling
     * @return
     */
    UFUNCTION(BlueprintImplementableEvent, Category = "Climbing|Ladder Slide")
    FVector GetSlideLadderVelocityBP(const FVector StartSlideVelocity, const float SlideDuration,
                                      const ETomCharacterStates StateBeforeFalling);

    /**
     * Can a character cling on a climbable with his current CharacterVelocity?
     * If the character can NOT hold on a surface this will end up with a Wall-Slide.
     * @param ClimbableType 
     * @param CharacterVelocity 
     * @param CharacterStateBeforeFalling 
     * @return 
     */
    UFUNCTION(BlueprintImplementableEvent, Category = "Climbing|Wall Slide")
    bool CanHoldOnClimbableBP(const ETomClimbableType ClimbableType,
                              const FVector CharacterVelocity,
                              const ETomCharacterStates CharacterStateBeforeFalling);

    /**
     * Returns a quantized JumpVelocity.
     * @param SwingAngle Current Character Pitch. Value between -90 and 90.
     * @param SwingVelocity In percent. Value between 0 and 1.
     * @param PoleSwingDirection
     * @param OutJumpVelocity 
     */
    UFUNCTION(BlueprintImplementableEvent, Category = "Climbing|Pole Jump")
    void GetQuantizedPoleJumpVelocityBP(const float SwingAngle, const float SwingVelocity,
                                        const ETomPoleSwingDirection PoleSwingDirection,
                                        FVector& OutJumpVelocity);

    /* Do not rotate the character if he is jumping from the "red zone". */
    UFUNCTION(BlueprintImplementableEvent, Category = "Climbing|Pole Jump")
    bool TurnCharacterInDirectionOfPoleJumpBP(const float SwingAngle);
};
