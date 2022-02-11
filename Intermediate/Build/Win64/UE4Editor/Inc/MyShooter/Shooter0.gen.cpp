// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyShooter/Shooter0.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShooter0() {}
// Cross Module References
	MYSHOOTER_API UClass* Z_Construct_UClass_AShooter0_NoRegister();
	MYSHOOTER_API UClass* Z_Construct_UClass_AShooter0();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_MyShooter();
// End Cross Module References
	void AShooter0::StaticRegisterNativesAShooter0()
	{
	}
	UClass* Z_Construct_UClass_AShooter0_NoRegister()
	{
		return AShooter0::StaticClass();
	}
	struct Z_Construct_UClass_AShooter0_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AShooter0_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_MyShooter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooter0_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Shooter0.h" },
		{ "ModuleRelativePath", "Shooter0.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AShooter0_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AShooter0>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AShooter0_Statics::ClassParams = {
		&AShooter0::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AShooter0_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AShooter0_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AShooter0()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AShooter0_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AShooter0, 3011291224);
	template<> MYSHOOTER_API UClass* StaticClass<AShooter0>()
	{
		return AShooter0::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AShooter0(Z_Construct_UClass_AShooter0, &AShooter0::StaticClass, TEXT("/Script/MyShooter"), TEXT("AShooter0"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AShooter0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
