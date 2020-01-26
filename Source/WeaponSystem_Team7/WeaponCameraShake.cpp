#include "WeaponCameraShake.h"

UWeaponCameraShake::UWeaponCameraShake()
{
	// Default Values 
	MinPitchAmplitude = 5.0f;
	MaxPitchAmplitude = 10.0f;

	MinPitchFrequency = 25.0f;
	MaxPitchFrequency = 35.0f;

	MinYawAmplitude = 5.0f;
	MaxYawAmplitude = 10.0f;

	MinYawFrequency = 25.0f;
	MaxYawFrequency = 35.0f;

	OscillationDuration = 0.25f;
	OscillationBlendInTime = 0.05f;
	OscillationBlendOutTime = 0.05f;

	RotOscillation.Pitch.Amplitude = FMath::RandRange(MinPitchAmplitude, MaxPitchAmplitude);
	RotOscillation.Pitch.Frequency = FMath::RandRange(MinPitchFrequency, MaxPitchFrequency);

	RotOscillation.Yaw.Amplitude = FMath::RandRange(MinYawAmplitude, MaxYawAmplitude);
	RotOscillation.Yaw.Frequency = FMath::RandRange(MinYawFrequency, MaxYawFrequency);
}