
#include "TomClimbingFormulas.h"
#include "ToM/Character/TomCharacterStates.h"

FVector UTomClimbingFormulas::GetSlideSurfaceVelocity(const FVector StartSlideVelocity,
                                                      const float SlideDuration,
                                                      const ETomCharacterStates StateBeforeFalling)
{
    if (!IsValidFormulaCollection<UTomClimbingFormulas>())
    {
        return FVector::ZeroVector;
    }

    return GetFormulaCollection<UTomClimbingFormulas>()->GetSlideSurfaceVelocityBP(
        StartSlideVelocity, SlideDuration, StateBeforeFalling);
}

FVector UTomClimbingFormulas::GetSlideLadderVelocity(const FVector StartSlideVelocity,
    const float SlideDuration, const ETomCharacterStates StateBeforeFalling)
{
    if (!IsValidFormulaCollection<UTomClimbingFormulas>())
    {
        return FVector::ZeroVector;
    }

    return GetFormulaCollection<UTomClimbingFormulas>()->GetSlideLadderVelocityBP(
        StartSlideVelocity, SlideDuration, StateBeforeFalling);
}

bool UTomClimbingFormulas::CanHoldOnClimbable(const ETomClimbableType ClimbableType,
                                              const FVector CharacterVelocity,
                                              const ETomCharacterStates CharacterStateBeforeFalling)
{
    if (!IsValidFormulaCollection<UTomClimbingFormulas>())
    {
        return false;
    }

    return GetFormulaCollection<UTomClimbingFormulas>()->CanHoldOnClimbableBP(
        ClimbableType, CharacterVelocity, CharacterStateBeforeFalling);
}

void UTomClimbingFormulas::GetQuantizedPoleJumpVelocity(
    const float SwingAngle, const float SwingVelocity,
    const ETomPoleSwingDirection PoleSwingDirection, FVector& OutJumpVelocity)
{
    if (!IsValidFormulaCollection<UTomClimbingFormulas>())
    {
        return;
    }

    return GetFormulaCollection<UTomClimbingFormulas>()->GetQuantizedPoleJumpVelocityBP(
        SwingAngle, SwingVelocity, PoleSwingDirection, OutJumpVelocity);
}

bool UTomClimbingFormulas::TurnCharacterInDirectionOfPoleJump(const float SwingAngle)
{
    if (!IsValidFormulaCollection<UTomClimbingFormulas>())
    {
        return false;
    }

    return GetFormulaCollection<UTomClimbingFormulas>()->TurnCharacterInDirectionOfPoleJumpBP(
        SwingAngle);
}
