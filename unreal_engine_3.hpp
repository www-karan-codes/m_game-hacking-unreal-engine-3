#pragma once

#include "typedefs.hpp"

#include <unordered_map>
#include <list>

namespace gamehacking::unreal_engine_3
{
	namespace hooks
	{
		namespace processevent
		{
#define PROCESS_EVENT_HOOK(hook_name) void __fastcall hook_name(NAMESPACE::OBJECT* uobject, void* unused, NAMESPACE::FUNCTION* ufunction, void* params, void* result)
			typedef void(__fastcall* ProcessEvent)(NAMESPACE::OBJECT*, void*, NAMESPACE::FUNCTION*, void*, void*);
			extern std::unordered_map<NAMESPACE::FUNCTION*, std::list<ProcessEvent>> hooks;
			extern ProcessEvent original_processevent;
			void __fastcall ProcessEventHook(NAMESPACE::OBJECT* uobject, void* unused, NAMESPACE::FUNCTION* ufunction, void* params, void* result);
			void AddHook(NAMESPACE::FUNCTION* function, ProcessEvent hook);
		}

		namespace processinternal
		{

		}

		namespace callfunction
		{

		}
	}

	void Hook(void);
}