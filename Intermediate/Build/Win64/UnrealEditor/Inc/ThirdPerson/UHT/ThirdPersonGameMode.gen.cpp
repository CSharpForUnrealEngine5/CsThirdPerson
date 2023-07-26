// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ThirdPerson/ThirdPersonGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeThirdPersonGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	THIRDPERSON_API UClass* Z_Construct_UClass_AThirdPersonGameMode();
	THIRDPERSON_API UClass* Z_Construct_UClass_AThirdPersonGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_ThirdPerson();
// End Cross Module References
	void AThirdPersonGameMode::StaticRegisterNativesAThirdPersonGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AThirdPersonGameMode);
	UClass* Z_Construct_UClass_AThirdPersonGameMode_NoRegister()
	{
		return AThirdPersonGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AThirdPersonGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AThirdPersonGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ThirdPerson,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AThirdPersonGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "ThirdPersonGameMode.h" },
		{ "ModuleRelativePath", "ThirdPersonGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AThirdPersonGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AThirdPersonGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AThirdPersonGameMode_Statics::ClassParams = {
		&AThirdPersonGameMode::StaticClass,
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
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AThirdPersonGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AThirdPersonGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AThirdPersonGameMode()
	{
		if (!Z_Registration_Info_UClass_AThirdPersonGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AThirdPersonGameMode.OuterSingleton, Z_Construct_UClass_AThirdPersonGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AThirdPersonGameMode.OuterSingleton;
	}
	template<> THIRDPERSON_API UClass* StaticClass<AThirdPersonGameMode>()
	{
		return AThirdPersonGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AThirdPersonGameMode);
	AThirdPersonGameMode::~AThirdPersonGameMode() {}
	struct Z_CompiledInDeferFile_FID_CSharpForUnrealEngine5_CsThirdPerson_Source_ThirdPerson_ThirdPersonGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CSharpForUnrealEngine5_CsThirdPerson_Source_ThirdPerson_ThirdPersonGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AThirdPersonGameMode, AThirdPersonGameMode::StaticClass, TEXT("AThirdPersonGameMode"), &Z_Registration_Info_UClass_AThirdPersonGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AThirdPersonGameMode), 2425890507U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CSharpForUnrealEngine5_CsThirdPerson_Source_ThirdPerson_ThirdPersonGameMode_h_4283394968(TEXT("/Script/ThirdPerson"),
		Z_CompiledInDeferFile_FID_CSharpForUnrealEngine5_CsThirdPerson_Source_ThirdPerson_ThirdPersonGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CSharpForUnrealEngine5_CsThirdPerson_Source_ThirdPerson_ThirdPersonGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
