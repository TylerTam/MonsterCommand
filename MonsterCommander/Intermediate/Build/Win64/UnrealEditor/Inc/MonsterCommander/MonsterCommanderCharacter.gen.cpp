// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MonsterCommander/MonsterCommanderCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMonsterCommanderCharacter() {}
// Cross Module References
	MONSTERCOMMANDER_API UClass* Z_Construct_UClass_AMonsterCommanderCharacter_NoRegister();
	MONSTERCOMMANDER_API UClass* Z_Construct_UClass_AMonsterCommanderCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_MonsterCommander();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
// End Cross Module References
	void AMonsterCommanderCharacter::StaticRegisterNativesAMonsterCommanderCharacter()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMonsterCommanderCharacter);
	UClass* Z_Construct_UClass_AMonsterCommanderCharacter_NoRegister()
	{
		return AMonsterCommanderCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AMonsterCommanderCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TurnRateGamepad_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TurnRateGamepad;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMonsterCommanderCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_MonsterCommander,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMonsterCommanderCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MonsterCommanderCharacter.h" },
		{ "ModuleRelativePath", "MonsterCommanderCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMonsterCommanderCharacter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Camera boom positioning the camera behind the character */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MonsterCommanderCharacter.h" },
		{ "ToolTip", "Camera boom positioning the camera behind the character" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMonsterCommanderCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMonsterCommanderCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMonsterCommanderCharacter_Statics::NewProp_CameraBoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMonsterCommanderCharacter_Statics::NewProp_CameraBoom_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMonsterCommanderCharacter_Statics::NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Follow camera */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MonsterCommanderCharacter.h" },
		{ "ToolTip", "Follow camera" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMonsterCommanderCharacter_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMonsterCommanderCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMonsterCommanderCharacter_Statics::NewProp_FollowCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMonsterCommanderCharacter_Statics::NewProp_FollowCamera_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMonsterCommanderCharacter_Statics::NewProp_TurnRateGamepad_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */" },
		{ "ModuleRelativePath", "MonsterCommanderCharacter.h" },
		{ "ToolTip", "Base turn rate, in deg/sec. Other scaling may affect final turn rate." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMonsterCommanderCharacter_Statics::NewProp_TurnRateGamepad = { "TurnRateGamepad", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMonsterCommanderCharacter, TurnRateGamepad), METADATA_PARAMS(Z_Construct_UClass_AMonsterCommanderCharacter_Statics::NewProp_TurnRateGamepad_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMonsterCommanderCharacter_Statics::NewProp_TurnRateGamepad_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMonsterCommanderCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMonsterCommanderCharacter_Statics::NewProp_CameraBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMonsterCommanderCharacter_Statics::NewProp_FollowCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMonsterCommanderCharacter_Statics::NewProp_TurnRateGamepad,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMonsterCommanderCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMonsterCommanderCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMonsterCommanderCharacter_Statics::ClassParams = {
		&AMonsterCommanderCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AMonsterCommanderCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AMonsterCommanderCharacter_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMonsterCommanderCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMonsterCommanderCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMonsterCommanderCharacter()
	{
		if (!Z_Registration_Info_UClass_AMonsterCommanderCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMonsterCommanderCharacter.OuterSingleton, Z_Construct_UClass_AMonsterCommanderCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMonsterCommanderCharacter.OuterSingleton;
	}
	template<> MONSTERCOMMANDER_API UClass* StaticClass<AMonsterCommanderCharacter>()
	{
		return AMonsterCommanderCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMonsterCommanderCharacter);
	struct Z_CompiledInDeferFile_FID_MonsterCommander_Source_MonsterCommander_MonsterCommanderCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MonsterCommander_Source_MonsterCommander_MonsterCommanderCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMonsterCommanderCharacter, AMonsterCommanderCharacter::StaticClass, TEXT("AMonsterCommanderCharacter"), &Z_Registration_Info_UClass_AMonsterCommanderCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMonsterCommanderCharacter), 1621248107U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MonsterCommander_Source_MonsterCommander_MonsterCommanderCharacter_h_1629464268(TEXT("/Script/MonsterCommander"),
		Z_CompiledInDeferFile_FID_MonsterCommander_Source_MonsterCommander_MonsterCommanderCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MonsterCommander_Source_MonsterCommander_MonsterCommanderCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
