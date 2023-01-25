// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MonsterCommander/CommandManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCommandManager() {}
// Cross Module References
	MONSTERCOMMANDER_API UClass* Z_Construct_UClass_UCommandManager_NoRegister();
	MONSTERCOMMANDER_API UClass* Z_Construct_UClass_UCommandManager();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
	UPackage* Z_Construct_UPackage__Script_MonsterCommander();
// End Cross Module References
	void UCommandManager::StaticRegisterNativesUCommandManager()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCommandManager);
	UClass* Z_Construct_UClass_UCommandManager_NoRegister()
	{
		return UCommandManager::StaticClass();
	}
	struct Z_Construct_UClass_UCommandManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_castDistance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_castDistance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_castRadius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_castRadius;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCommandManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USceneComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_MonsterCommander,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCommandManager_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "CommandManager.h" },
		{ "ModuleRelativePath", "CommandManager.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCommandManager_Statics::NewProp_castDistance_MetaData[] = {
		{ "Category", "CommandManager" },
		{ "ModuleRelativePath", "CommandManager.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCommandManager_Statics::NewProp_castDistance = { "castDistance", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCommandManager, castDistance), METADATA_PARAMS(Z_Construct_UClass_UCommandManager_Statics::NewProp_castDistance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCommandManager_Statics::NewProp_castDistance_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCommandManager_Statics::NewProp_castRadius_MetaData[] = {
		{ "Category", "CommandManager" },
		{ "ModuleRelativePath", "CommandManager.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCommandManager_Statics::NewProp_castRadius = { "castRadius", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCommandManager, castRadius), METADATA_PARAMS(Z_Construct_UClass_UCommandManager_Statics::NewProp_castRadius_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCommandManager_Statics::NewProp_castRadius_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCommandManager_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCommandManager_Statics::NewProp_castDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCommandManager_Statics::NewProp_castRadius,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCommandManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCommandManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCommandManager_Statics::ClassParams = {
		&UCommandManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UCommandManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UCommandManager_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UCommandManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCommandManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCommandManager()
	{
		if (!Z_Registration_Info_UClass_UCommandManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCommandManager.OuterSingleton, Z_Construct_UClass_UCommandManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCommandManager.OuterSingleton;
	}
	template<> MONSTERCOMMANDER_API UClass* StaticClass<UCommandManager>()
	{
		return UCommandManager::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCommandManager);
	struct Z_CompiledInDeferFile_FID_MonsterCommander_Source_MonsterCommander_CommandManager_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MonsterCommander_Source_MonsterCommander_CommandManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCommandManager, UCommandManager::StaticClass, TEXT("UCommandManager"), &Z_Registration_Info_UClass_UCommandManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCommandManager), 3186050492U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MonsterCommander_Source_MonsterCommander_CommandManager_h_1722954903(TEXT("/Script/MonsterCommander"),
		Z_CompiledInDeferFile_FID_MonsterCommander_Source_MonsterCommander_CommandManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MonsterCommander_Source_MonsterCommander_CommandManager_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
