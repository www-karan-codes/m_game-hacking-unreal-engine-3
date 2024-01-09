#include "unreal_engine_3.hpp"

#include <Windows.h>
#include "../Detours/include/detours.h"

#include <iostream>

namespace gamehacking::unreal_engine_3
{
	namespace hooks
	{
		namespace processevent
		{
			std::unordered_map<NAMESPACE::FUNCTION*, std::list<ProcessEvent>> hooks;
			ProcessEvent original_processevent = (ProcessEvent)nullptr;
			
			void __fastcall ProcessEventHook(NAMESPACE::OBJECT* uobject, void* unused, NAMESPACE::FUNCTION* ufunction, void* params, void* result)
			{
				bool hook_found = false;
				if (hooks.find(ufunction) != hooks.end()) {
					hook_found = true;
					auto& hooks_ = hooks[ufunction];
					for (auto& hook : hooks_)
					{
						(*hook)(uobject, NULL, ufunction, params, result);
					}
				}

				if (!hook_found)
				{
					auto& hooks_ = hooks[nullptr];
					for (auto& hook : hooks_)
					{
						(*hook)(uobject, NULL, ufunction, params, result);
					}
				}

				//std::cout << uobject->GetFullName() << "" << std::endl;

				original_processevent(uobject, NULL, ufunction, params, result);
			}
			

			void AddHook(NAMESPACE::FUNCTION* function, ProcessEvent hook) {
				if (hooks.find(function) == hooks.end()) {
					hooks[function] = std::list<ProcessEvent>();
				}
				hooks[function].push_back(hook);
			}
		}

		namespace processinternal
		{

		}

		namespace callfunction
		{

		}
	}

	void Hook(void)
	{
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach((void**)&hooks::processevent::original_processevent, hooks::processevent::ProcessEventHook);
		DetourTransactionCommit();
	}
}