// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyShooter/Shooter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShooter() {}
// Cross Module References
	MYSHOOTER_API UClass* Z_Construct_UClass_AShooter_NoRegister();
	MYSHOOTER_API UClass* Z_Construct_UClass_AShooter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_MyShooter();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USoundCue_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	MYSHOOTER_API UClass* Z_Construct_UClass_AWeapon_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
// End Cross Module References
	DEFINE_FUNCTION(AShooter::execGetCrosshairSpreadMultiplier)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetCrosshairSpreadMultiplier();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AShooter::execAutoFireReset)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AutoFireReset();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AShooter::execFinishCrosshairBulletFire)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->FinishCrosshairBulletFire();
		P_NATIVE_END;
	}
	void AShooter::StaticRegisterNativesAShooter()
	{
		UClass* Class = AShooter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AutoFireReset", &AShooter::execAutoFireReset },
			{ "FinishCrosshairBulletFire", &AShooter::execFinishCrosshairBulletFire },
			{ "GetCrosshairSpreadMultiplier", &AShooter::execGetCrosshairSpreadMultiplier },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AShooter_AutoFireReset_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AShooter_AutoFireReset_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Shooter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AShooter_AutoFireReset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AShooter, nullptr, "AutoFireReset", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AShooter_AutoFireReset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AShooter_AutoFireReset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AShooter_AutoFireReset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AShooter_AutoFireReset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AShooter_FinishCrosshairBulletFire_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AShooter_FinishCrosshairBulletFire_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Shooter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AShooter_FinishCrosshairBulletFire_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AShooter, nullptr, "FinishCrosshairBulletFire", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AShooter_FinishCrosshairBulletFire_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AShooter_FinishCrosshairBulletFire_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AShooter_FinishCrosshairBulletFire()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AShooter_FinishCrosshairBulletFire_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AShooter_GetCrosshairSpreadMultiplier_Statics
	{
		struct Shooter_eventGetCrosshairSpreadMultiplier_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AShooter_GetCrosshairSpreadMultiplier_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Shooter_eventGetCrosshairSpreadMultiplier_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AShooter_GetCrosshairSpreadMultiplier_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AShooter_GetCrosshairSpreadMultiplier_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AShooter_GetCrosshairSpreadMultiplier_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Shooter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AShooter_GetCrosshairSpreadMultiplier_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AShooter, nullptr, "GetCrosshairSpreadMultiplier", nullptr, nullptr, sizeof(Shooter_eventGetCrosshairSpreadMultiplier_Parms), Z_Construct_UFunction_AShooter_GetCrosshairSpreadMultiplier_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AShooter_GetCrosshairSpreadMultiplier_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AShooter_GetCrosshairSpreadMultiplier_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AShooter_GetCrosshairSpreadMultiplier_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AShooter_GetCrosshairSpreadMultiplier()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AShooter_GetCrosshairSpreadMultiplier_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AShooter_NoRegister()
	{
		return AShooter::StaticClass();
	}
	struct Z_Construct_UClass_AShooter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseTurnRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseTurnRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseLookUpRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseLookUpRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MouseVerticalSensitivity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MouseVerticalSensitivity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MouseHorizontalSensitivity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MouseHorizontalSensitivity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HipMouseVerticalSensitivity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HipMouseVerticalSensitivity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HipMouseHorizontalSensitivity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HipMouseHorizontalSensitivity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AimMouseVerticalSensitivity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AimMouseVerticalSensitivity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AimMouseHorizontalSensitivity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AimMouseHorizontalSensitivity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FireSound_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FireSound;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MuzzleFlash_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MuzzleFlash;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HipFireMontage_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HipFireMontage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ImpactParticles_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ImpactParticles;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BeamParticles_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BeamParticles;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsAiming_MetaData[];
#endif
		static void NewProp_bIsAiming_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsAiming;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FollowCameraAimSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_FollowCameraAimSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CrosshairSpreadMultiplier_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CrosshairSpreadMultiplier;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CrosshairSpreadAir_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CrosshairSpreadAir;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CrosshairSpreadMotion_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CrosshairSpreadMotion;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CrosshairSpreadAim_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CrosshairSpreadAim;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CrosshairSpreadHip_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CrosshairSpreadHip;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EquippedWeapon_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_EquippedWeapon;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultWeaponClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_DefaultWeaponClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AShooter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_MyShooter,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AShooter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AShooter_AutoFireReset, "AutoFireReset" }, // 2715194660
		{ &Z_Construct_UFunction_AShooter_FinishCrosshairBulletFire, "FinishCrosshairBulletFire" }, // 4080436575
		{ &Z_Construct_UFunction_AShooter_GetCrosshairSpreadMultiplier, "GetCrosshairSpreadMultiplier" }, // 59761186
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Shooter.h" },
		{ "ModuleRelativePath", "Shooter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Shooter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_CameraBoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_CameraBoom_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Shooter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_FollowCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_FollowCamera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_BaseTurnRate_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Shooter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_BaseTurnRate = { "BaseTurnRate", nullptr, (EPropertyFlags)0x0040000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, BaseTurnRate), METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_BaseTurnRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_BaseTurnRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_BaseLookUpRate_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Shooter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_BaseLookUpRate = { "BaseLookUpRate", nullptr, (EPropertyFlags)0x0040000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, BaseLookUpRate), METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_BaseLookUpRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_BaseLookUpRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_MouseVerticalSensitivity_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/*current vertical mouse sens*/" },
		{ "ModuleRelativePath", "Shooter.h" },
		{ "ToolTip", "current vertical mouse sens" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_MouseVerticalSensitivity = { "MouseVerticalSensitivity", nullptr, (EPropertyFlags)0x0040000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, MouseVerticalSensitivity), METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_MouseVerticalSensitivity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_MouseVerticalSensitivity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_MouseHorizontalSensitivity_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/*current horizontal mouse sens*/" },
		{ "ModuleRelativePath", "Shooter.h" },
		{ "ToolTip", "current horizontal mouse sens" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_MouseHorizontalSensitivity = { "MouseHorizontalSensitivity", nullptr, (EPropertyFlags)0x0040000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, MouseHorizontalSensitivity), METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_MouseHorizontalSensitivity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_MouseHorizontalSensitivity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_HipMouseVerticalSensitivity_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/* vertical mouse sens when hip firing*/" },
		{ "ModuleRelativePath", "Shooter.h" },
		{ "ToolTip", "vertical mouse sens when hip firing" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_HipMouseVerticalSensitivity = { "HipMouseVerticalSensitivity", nullptr, (EPropertyFlags)0x0040000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, HipMouseVerticalSensitivity), METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_HipMouseVerticalSensitivity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_HipMouseVerticalSensitivity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_HipMouseHorizontalSensitivity_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/*horizontal mouse sens when hip firing*/" },
		{ "ModuleRelativePath", "Shooter.h" },
		{ "ToolTip", "horizontal mouse sens when hip firing" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_HipMouseHorizontalSensitivity = { "HipMouseHorizontalSensitivity", nullptr, (EPropertyFlags)0x0040000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, HipMouseHorizontalSensitivity), METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_HipMouseHorizontalSensitivity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_HipMouseHorizontalSensitivity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_AimMouseVerticalSensitivity_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/*vertical mouse sens when aiming*/" },
		{ "ModuleRelativePath", "Shooter.h" },
		{ "ToolTip", "vertical mouse sens when aiming" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_AimMouseVerticalSensitivity = { "AimMouseVerticalSensitivity", nullptr, (EPropertyFlags)0x0040000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, AimMouseVerticalSensitivity), METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_AimMouseVerticalSensitivity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_AimMouseVerticalSensitivity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_AimMouseHorizontalSensitivity_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/*horizontal mouse sens when aiming*/" },
		{ "ModuleRelativePath", "Shooter.h" },
		{ "ToolTip", "horizontal mouse sens when aiming" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_AimMouseHorizontalSensitivity = { "AimMouseHorizontalSensitivity", nullptr, (EPropertyFlags)0x0040000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, AimMouseHorizontalSensitivity), METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_AimMouseHorizontalSensitivity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_AimMouseHorizontalSensitivity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_FireSound_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Shooter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_FireSound = { "FireSound", nullptr, (EPropertyFlags)0x0040000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, FireSound), Z_Construct_UClass_USoundCue_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_FireSound_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_FireSound_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_MuzzleFlash_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Shooter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_MuzzleFlash = { "MuzzleFlash", nullptr, (EPropertyFlags)0x0040000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, MuzzleFlash), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_MuzzleFlash_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_MuzzleFlash_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_HipFireMontage_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Shooter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_HipFireMontage = { "HipFireMontage", nullptr, (EPropertyFlags)0x0040000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, HipFireMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_HipFireMontage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_HipFireMontage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_ImpactParticles_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Shooter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_ImpactParticles = { "ImpactParticles", nullptr, (EPropertyFlags)0x0040000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, ImpactParticles), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_ImpactParticles_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_ImpactParticles_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_BeamParticles_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Shooter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_BeamParticles = { "BeamParticles", nullptr, (EPropertyFlags)0x0040000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, BeamParticles), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_BeamParticles_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_BeamParticles_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_bIsAiming_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/* Stores the state of aiming*/" },
		{ "ModuleRelativePath", "Shooter.h" },
		{ "ToolTip", "Stores the state of aiming" },
	};
#endif
	void Z_Construct_UClass_AShooter_Statics::NewProp_bIsAiming_SetBit(void* Obj)
	{
		((AShooter*)Obj)->bIsAiming = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_bIsAiming = { "bIsAiming", nullptr, (EPropertyFlags)0x0040000000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AShooter), &Z_Construct_UClass_AShooter_Statics::NewProp_bIsAiming_SetBit, METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_bIsAiming_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_bIsAiming_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_FollowCameraAimSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/* Follow Camera Aim zoom speed*/" },
		{ "ModuleRelativePath", "Shooter.h" },
		{ "ToolTip", "Follow Camera Aim zoom speed" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_FollowCameraAimSpeed = { "FollowCameraAimSpeed", nullptr, (EPropertyFlags)0x0040000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, FollowCameraAimSpeed), METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_FollowCameraAimSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_FollowCameraAimSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadMultiplier_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Crosshair" },
		{ "Comment", "/* stores the value proportional to the total crosshair spread due to several factors*/" },
		{ "ModuleRelativePath", "Shooter.h" },
		{ "ToolTip", "stores the value proportional to the total crosshair spread due to several factors" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadMultiplier = { "CrosshairSpreadMultiplier", nullptr, (EPropertyFlags)0x0040000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, CrosshairSpreadMultiplier), METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadMultiplier_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadMultiplier_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadAir_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Crosshair" },
		{ "Comment", "/*Stores the component of crosshair spread while in air*/" },
		{ "ModuleRelativePath", "Shooter.h" },
		{ "ToolTip", "Stores the component of crosshair spread while in air" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadAir = { "CrosshairSpreadAir", nullptr, (EPropertyFlags)0x0040000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, CrosshairSpreadAir), METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadAir_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadAir_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadMotion_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Crosshair" },
		{ "Comment", "/*Stores the component of crosshair spread while in motion*/" },
		{ "ModuleRelativePath", "Shooter.h" },
		{ "ToolTip", "Stores the component of crosshair spread while in motion" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadMotion = { "CrosshairSpreadMotion", nullptr, (EPropertyFlags)0x0040000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, CrosshairSpreadMotion), METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadMotion_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadMotion_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadAim_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Crosshair" },
		{ "Comment", "/*Stores the componenet of crosshair spread while aiming*/" },
		{ "ModuleRelativePath", "Shooter.h" },
		{ "ToolTip", "Stores the componenet of crosshair spread while aiming" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadAim = { "CrosshairSpreadAim", nullptr, (EPropertyFlags)0x0040000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, CrosshairSpreadAim), METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadAim_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadAim_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadHip_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Crosshair" },
		{ "Comment", "/*Stores the component of crosshair spread while hip aiming*/" },
		{ "ModuleRelativePath", "Shooter.h" },
		{ "ToolTip", "Stores the component of crosshair spread while hip aiming" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadHip = { "CrosshairSpreadHip", nullptr, (EPropertyFlags)0x0040000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, CrosshairSpreadHip), METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadHip_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadHip_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_EquippedWeapon_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Combat" },
		{ "Comment", "/* Currently Equipped weapon*/" },
		{ "ModuleRelativePath", "Shooter.h" },
		{ "ToolTip", "Currently Equipped weapon" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_EquippedWeapon = { "EquippedWeapon", nullptr, (EPropertyFlags)0x0040000000020015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, EquippedWeapon), Z_Construct_UClass_AWeapon_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_EquippedWeapon_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_EquippedWeapon_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter_Statics::NewProp_DefaultWeaponClass_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Combat" },
		{ "Comment", "/*Set this in blueprints for the default weapon class*/" },
		{ "ModuleRelativePath", "Shooter.h" },
		{ "ToolTip", "Set this in blueprints for the default weapon class" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShooter_Statics::NewProp_DefaultWeaponClass = { "DefaultWeaponClass", nullptr, (EPropertyFlags)0x0044000000010015, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooter, DefaultWeaponClass), Z_Construct_UClass_AWeapon_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::NewProp_DefaultWeaponClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::NewProp_DefaultWeaponClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AShooter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_CameraBoom,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_FollowCamera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_BaseTurnRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_BaseLookUpRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_MouseVerticalSensitivity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_MouseHorizontalSensitivity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_HipMouseVerticalSensitivity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_HipMouseHorizontalSensitivity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_AimMouseVerticalSensitivity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_AimMouseHorizontalSensitivity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_FireSound,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_MuzzleFlash,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_HipFireMontage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_ImpactParticles,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_BeamParticles,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_bIsAiming,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_FollowCameraAimSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadMultiplier,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadAir,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadMotion,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadAim,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_CrosshairSpreadHip,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_EquippedWeapon,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooter_Statics::NewProp_DefaultWeaponClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AShooter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AShooter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AShooter_Statics::ClassParams = {
		&AShooter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AShooter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AShooter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AShooter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AShooter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AShooter, 2730637505);
	template<> MYSHOOTER_API UClass* StaticClass<AShooter>()
	{
		return AShooter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AShooter(Z_Construct_UClass_AShooter, &AShooter::StaticClass, TEXT("/Script/MyShooter"), TEXT("AShooter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AShooter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
