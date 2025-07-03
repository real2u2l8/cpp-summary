#include "pch.h"
#include "MessageHookee.h"

BOOL g_bMessageHookee = FALSE;

BOOL MessageBoxHookee()
{
	std::cout << "Hookee console test program started." << std::endl;
	MessageBoxA(NULL, "This is a Hookee test message.", "Hookee", MB_OK | MB_ICONINFORMATION);
	std::cout << "Message box closed. Exiting program." << std::endl;
	
	return FALSE;
}