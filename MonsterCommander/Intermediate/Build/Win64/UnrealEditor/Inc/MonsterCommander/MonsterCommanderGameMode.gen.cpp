// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MonsterCommander/MonsterCommanderGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMonsterCommanderGameMode() {}
// Cross Module References
	MONSTERCOMMANDER_API UClass* Z_Construct_UClass_AMonsterCommanderGameMode_NoRegister();
	MONSTERCOMMANDER_API UClass* Z_Construct_UClass_AMonsterCommanderGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_MonsterCommander();
// End Cross Module References
	void AMonsterCommanderGameMode::StaticRegisterNativesAMonsterCommanderGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMonsterCommanderGameMode);
	UClass* Z_Construct_UClass_AMonsterCommanderGameMode_NoRegister()
	{
		return AMonsterCommanderGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AMonsterCommanderGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMonsterCommanderGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_MonsterCommander,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMonsterCommanderGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "MonsterCommanderGameMode.h" },
		{ "ModuleRelativePath", "MonsterCommanderGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMonsterCommanderGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMonsterCommanderGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMonsterCommanderGameMode_Statics::ClassParams = {
		&AMonsterCommanderGameMode::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AMonsterCommanderGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMonsterCommanderGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMonsterCommanderGameMode()
	{
		if (!Z_Registration_Info_UClass_AMonsterCommanderGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMonsterCommanderGameMode.OuterSingleton, Z_Construct_UClass_AMonsterCommanderGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMonsterCommanderGameMode.OuterSingleton;
	}
	template<> MONSTERCOMMANDER_API UClass* StaticClass<AMonsterCommanderGameMode>()
	{
		return AMonsterCommanderGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMonsterCommanderGameMode);
	struct Z_CompiledInDeferFile_FID_MonsterCommander_Source_MonsterCommander_MonsterCommanderGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MonsterCommander_Source_MonsterCommander_MonsterCommanderGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMonsterCommanderGameMode, AMonsterCommanderGameMode::StaticClass, TEXT("AMonsterCommanderGameMode"), &Z_Registration_Info_UClass_AMonsterCommanderGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMonsterCommanderGameMode), 2685078469U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MonsterCommander_Source_MonsterCommander_MonsterCommanderGameMode_h_101181784(TEXT("/Script/MonsterCommander"),
		Z_CompiledInDeferFile_FID_MonsterCommander_Source_MonsterCommander_MonsterCommanderGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MonsterCommander_Source_MonsterCommander_MonsterCommanderGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
