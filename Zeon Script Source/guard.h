#pragma once
#include <iostream>
#include "xorstr.hpp"
#include <tlhelp32.h>
#include <fstream>
#include <filesystem>

bool IsProcessRunningQQ(const wchar_t* processName)
{
	bool exists = false;
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);


	return exists;
}

void Crack_Önleyici()
{
	if (IsProcessRunningQQ(_xor_(L"KsDumperClient.exe").c_str()))
	{
		_xor_("KsDumper");
	}
	else if (IsProcessRunningQQ(_xor_(L"HTTPDebuggerUI.exe").c_str()))
	{
		_xor_("HTTP Debugger");
	}
	else if (IsProcessRunningQQ(_xor_(L"HTTPDebuggerSvc.exe").c_str()))
	{
		_xor_("HTTP Debugger Service");
	}
	else if (IsProcessRunningQQ(_xor_(L"FolderChangesView.exe").c_str()))
	{
		_xor_("FolderChangesView");
	}
	else if (IsProcessRunningQQ(_xor_(L"ProcessHacker.exe").c_str()))
	{
		_xor_("Process Hacker");
	}
	else if (IsProcessRunningQQ(_xor_(L"procmon.exe").c_str()))
	{
		_xor_("Process Monitor");
	}
	else if (IsProcessRunningQQ(_xor_(L"idaq.exe").c_str()))
	{
		_xor_("IDA");
	}
	else if (IsProcessRunningQQ(_xor_(L"idaq64.exe").c_str()))
	{
		_xor_("IDA");
	}
	else if (IsProcessRunningQQ(_xor_(L"Wireshark.exe").c_str()))
	{
		_xor_("WireShark");
	}
	else if (IsProcessRunningQQ(_xor_(L"Fiddler.exe").c_str()))
	{
		_xor_("Fiddler");
	}
	else if (IsProcessRunningQQ(_xor_(L"Xenos64.exe").c_str()))
	{
		_xor_("Xenos64");
	}
	else if (IsProcessRunningQQ(_xor_(L"Cheat Engine.exe").c_str()))
	{
		_xor_("Cheat Engine");
	}
	else if (IsProcessRunningQQ(_xor_(L"HTTP Debugger Windows Service (32 bit).exe").c_str()))
	{
		_xor_("HTTP Debugger");
	}
	else if (IsProcessRunningQQ(_xor_(L"KsDumper.exe").c_str()))
	{
		_xor_("KsDumper");
	}
	else if (IsProcessRunningQQ(_xor_(L"x64dbg.exe").c_str()))
	{
		_xor_("x64DBG");
	}
}
void killdbg()
{

}
