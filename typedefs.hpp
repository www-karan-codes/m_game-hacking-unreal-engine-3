#pragma once

#define NAMESPACE SDK
#define CONTROLLER AClass_Object_Actor_Controller_PlayerController_PlayerCharacterController
#define PAWN AClass_Object_Actor_Pawn
#define PLAYER_PAWN AClass_Object_Actor_Pawn_Rook_Ragdoll_Character
#define FUNCTION UClass_Object_Field_Struct_Function
#define OBJECT UClass_Object

namespace NAMESPACE
{
	class CONTROLLER;
	class PAWN;
	class PLAYER_PAWN;
	class FUNCTION;
	class OBJECT;
}


namespace gamehacking::unreal_engine_3
{
	typedef NAMESPACE::CONTROLLER Controller;
	typedef NAMESPACE::PAWN Pawn;
	typedef NAMESPACE::PLAYER_PAWN PlayerPawn;
}