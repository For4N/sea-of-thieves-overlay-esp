#pragma once
class Offsets
{
public:
	// :APlayerController:PlayerCameraManager:SoT_Engine_classes.hpp
	static constexpr int PlayerCameraManager = 0x0520;

	// :APlayerCameraManager:DefaultFOV:SoT_Engine_classes.hpp
	static constexpr int DefaultFOV = 0x04A8;

	// :AAthenaCharacter:HealthComponent:SoT_Athena_classes.hpp
	static constexpr int HealthComponent = 0x0858;

	// :APlayerCameraManager:CameraCache:SoT_Engine_classes.hpp
	static constexpr int CameraCache = 0x0500;

	// :FCameraCacheEntry:POV:SoT_Engine_structs.hpp
	static constexpr int CameraCachePOV = CameraCache + 0x0010;
	static constexpr int CameraRotation = CameraCachePOV + 0x0C;

	// :UIslandDataAsset:IslandDataEntries:SoT_Athena_classes.hpp
	static constexpr int IslandDataEntries = 0x0040;
	static constexpr int IslandDataEntriesCount = IslandDataEntries + 0x8;

	// :UIslandDataAssetEntry:IslandName:SoT_Athena_classes.hpp
	static constexpr int IslandName = 0x0028;

	// :UIslandDataAssetEntry:TreasureMaps:SoT_Athena_classes.hpp
	static constexpr int TreasureMaps = 0x0030;

	// :AXMarksTheSpotMap:MapTexturePath:SoT_Athena_classes.hpp
	static constexpr int MapTexturePath = 0x0890;

	// :AXMarksTheSpotMap:Marks:SoT_Athena_classes.hpp
	static constexpr int Marks = 0x08D0;
	static constexpr int MarksCount = Marks + 0x8;

	// :UPlayer:PlayerController:SoT_Engine_classes.hpp
	static constexpr int PlayerController = 0x0030;

	// :AActor:RootComponent:SoT_Engine_classes.hpp
	static constexpr int RootComponent = 0x0170;

	// :APawn:PlayerState:SoT_Engine_classes.hpp
	static constexpr int PlayerState = 0x04B0;

	// :AController:Pawn:SoT_Engine_classes.hpp
	static constexpr int Pawn = 0x0498; // LocalPlayer

	// :APlayerState:PlayerName:SoT_Engine_classes.hpp
	static constexpr int PlayerName = 0x0498;

	// :APlayerState:PlayerId:SoT_Engine_classes.hpp
	static constexpr int PlayerId = 0x04B8;

#pragma region almost never changing offsets
	// UObject
	static constexpr int Id = 0x18;

	// :UWorld:PersistentLevel:SoT_Engine_classes.hpp
	static constexpr int PersistentLevel = 0x0030; // ULevel
	static constexpr int ActorsTArray = 0xA0; // Uknown offsets
	static constexpr int ActorsTArrayCount = ActorsTArray + 0x08;

	// :UWorld:OwningGameInstance:SoT_Engine_classes.hpp
	static constexpr int OwningGameInstance = 0x01C0;

	// :UGameInstance:LocalPlayers:SoT_Engine_classes.hpp
	static constexpr int LocalPlayers = 0x0038;

	// :UHealthComponent:CurrentHealth:SoT_Athena_classes.hpp
	static constexpr int CurrentHealth = 0x00E4;

	// :UHealthComponent:MaxHealth:SoT_Athena_classes.hpp
	static constexpr int MaxHealth = 0x00F8;

	// :USceneComponent:RelativeLocation:SoT_Engine_classes.hpp
	static constexpr int RelativeLocation = 0x01C0;
	static constexpr int RelativeRotation = RelativeLocation + 0x0C;
	static constexpr int RelativeRotationYaw = RelativeRotation + 0x04;

	// :AIslandService:IslandDataAsset:SoT_Athena_classes.hpp
	static constexpr int IslandDataAsset = 0x04F0;

	// :FTreasureMapData:FTreasureMapData:SoT_Athena_structs.hpp
	static constexpr int TreasureLocations = 0x0010;
	static constexpr int TreasureLocationsCount = TreasureLocations + 0x08;
#pragma endregion
};