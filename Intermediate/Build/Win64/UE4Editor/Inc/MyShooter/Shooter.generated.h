// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MYSHOOTER_Shooter_generated_h
#error "Shooter.generated.h already included, missing '#pragma once' in Shooter.h"
#endif
#define MYSHOOTER_Shooter_generated_h

#define MyShooter_Source_MyShooter_Shooter_h_12_SPARSE_DATA
#define MyShooter_Source_MyShooter_Shooter_h_12_RPC_WRAPPERS
#define MyShooter_Source_MyShooter_Shooter_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define MyShooter_Source_MyShooter_Shooter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAShooter(); \
	friend struct Z_Construct_UClass_AShooter_Statics; \
public: \
	DECLARE_CLASS(AShooter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MyShooter"), NO_API) \
	DECLARE_SERIALIZER(AShooter)


#define MyShooter_Source_MyShooter_Shooter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAShooter(); \
	friend struct Z_Construct_UClass_AShooter_Statics; \
public: \
	DECLARE_CLASS(AShooter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MyShooter"), NO_API) \
	DECLARE_SERIALIZER(AShooter)


#define MyShooter_Source_MyShooter_Shooter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AShooter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AShooter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AShooter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AShooter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AShooter(AShooter&&); \
	NO_API AShooter(const AShooter&); \
public:


#define MyShooter_Source_MyShooter_Shooter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AShooter(AShooter&&); \
	NO_API AShooter(const AShooter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AShooter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AShooter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AShooter)


#define MyShooter_Source_MyShooter_Shooter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AShooter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(AShooter, FollowCamera); } \
	FORCEINLINE static uint32 __PPO__BaseTurnRate() { return STRUCT_OFFSET(AShooter, BaseTurnRate); } \
	FORCEINLINE static uint32 __PPO__BaseLookUpRate() { return STRUCT_OFFSET(AShooter, BaseLookUpRate); } \
	FORCEINLINE static uint32 __PPO__MouseVerticalSensitivity() { return STRUCT_OFFSET(AShooter, MouseVerticalSensitivity); } \
	FORCEINLINE static uint32 __PPO__MouseHorizontalSensitivity() { return STRUCT_OFFSET(AShooter, MouseHorizontalSensitivity); } \
	FORCEINLINE static uint32 __PPO__FireSound() { return STRUCT_OFFSET(AShooter, FireSound); } \
	FORCEINLINE static uint32 __PPO__MuzzleFlash() { return STRUCT_OFFSET(AShooter, MuzzleFlash); } \
	FORCEINLINE static uint32 __PPO__HipFireMontage() { return STRUCT_OFFSET(AShooter, HipFireMontage); } \
	FORCEINLINE static uint32 __PPO__ImpactParticles() { return STRUCT_OFFSET(AShooter, ImpactParticles); } \
	FORCEINLINE static uint32 __PPO__BeamParticles() { return STRUCT_OFFSET(AShooter, BeamParticles); } \
	FORCEINLINE static uint32 __PPO__bIsAiming() { return STRUCT_OFFSET(AShooter, bIsAiming); } \
	FORCEINLINE static uint32 __PPO__FollowCameraAimSpeed() { return STRUCT_OFFSET(AShooter, FollowCameraAimSpeed); }


#define MyShooter_Source_MyShooter_Shooter_h_9_PROLOG
#define MyShooter_Source_MyShooter_Shooter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyShooter_Source_MyShooter_Shooter_h_12_PRIVATE_PROPERTY_OFFSET \
	MyShooter_Source_MyShooter_Shooter_h_12_SPARSE_DATA \
	MyShooter_Source_MyShooter_Shooter_h_12_RPC_WRAPPERS \
	MyShooter_Source_MyShooter_Shooter_h_12_INCLASS \
	MyShooter_Source_MyShooter_Shooter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MyShooter_Source_MyShooter_Shooter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyShooter_Source_MyShooter_Shooter_h_12_PRIVATE_PROPERTY_OFFSET \
	MyShooter_Source_MyShooter_Shooter_h_12_SPARSE_DATA \
	MyShooter_Source_MyShooter_Shooter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	MyShooter_Source_MyShooter_Shooter_h_12_INCLASS_NO_PURE_DECLS \
	MyShooter_Source_MyShooter_Shooter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MYSHOOTER_API UClass* StaticClass<class AShooter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MyShooter_Source_MyShooter_Shooter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
