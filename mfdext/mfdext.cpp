#include "mfdext.h"

EXTERN_C __declspec(dllexport) HRESULT CALLBACK DebugExtensionInitialize(
	_In_ PULONG Version, 
	_In_ PULONG Flags
)
{
	*Version = DEBUG_EXTENSION_VERSION(1, 0);
	*Flags = 0;
	return S_OK;
}

EXTERN_C __declspec(dllexport) VOID CALLBACK DebugExtensionNotify(
	_In_ ULONG Notify, 
	_In_ ULONG64 Argument
)
{
	UNREFERENCED_PARAMETER(Argument);

	switch (Notify)
	{
	case DEBUG_NOTIFY_SESSION_ACTIVE:
		break;
	case DEBUG_NOTIFY_SESSION_INACTIVE:
		break;
	case DEBUG_NOTIFY_SESSION_ACCESSIBLE:
		break;
	case DEBUG_NOTIFY_SESSION_INACCESSIBLE:
		break;
	}

	return;
}

 EXTERN_C __declspec(dllexport) HRESULT CALLBACK mfdcommand(
	_In_ PDEBUG_CLIENT pDebugClient,
	_In_ PCSTR pchArgs
)
{
	HRESULT hr = S_OK;
	PDEBUG_CONTROL debugControl = NULL;

	UNREFERENCED_PARAMETER(pDebugClient);
	UNREFERENCED_PARAMETER(pchArgs);

	hr = pDebugClient->QueryInterface(__uuidof(IDebugControl), (PVOID*)&debugControl);

	if (hr != S_OK)
	{
		return hr;
	}

	debugControl->Output(DEBUG_OUTCTL_ALL_CLIENTS, "mfdcommand running...\n");

	debugControl->Release();

	return hr;
}

 EXTERN_C __declspec(dllexport) VOID CALLBACK DebugExtensionUninitialize()
{
	return;
}