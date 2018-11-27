#ifndef PROCMEM_H
#define PROCMEM_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <tlhelp32.h>

class ProcMem {
protected:

public:
	uintptr_t *base; // stores module base address
	uintptr_t Proc_ID; // variable to store process id
	HANDLE hProcess;
	DWORD dwPID;
	DWORD dwProtection;
	DWORD dwCaveAddress;
	BOOL bPOn, bIOn, bProt;

public:
	ProcMem();
	~ProcMem();
	int chSizeOfArray(char *chArray);
	int iSizeOfArray(char *iArray);
	bool iFind(int *iAry, int iVal);

#pragma region template memory functions
	template <class cData>
	cData Read(uintptr_t dwAddress)
	{
		cData cRead;
		ReadProcessMemory(hProcess, (LPVOID)dwAddress, &cRead, sizeof(cData), NULL);
		return cRead;
	}

	template <class cData>
	cData Read(uintptr_t dwAddress, char *Offset, BOOL Type)
	{
		int iSize = iSizeOfArray(Offset) - 1;
		dwAddress = Read<uintptr_t>(dwAddress);

		for (int i = 0; i < iSize; i++)
			dwAddress = Read<uintptr_t>(dwAddress + Offset[i]);

		if (!Type)
			return dwAddress + Offset[iSize];
		else
			return Read<cData>(dwAddress + Offset[iSize]);
	}

	template <class cData>
	void Read(uintptr_t dwAddress, cData Value)
	{
		ReadProcessMemory(hProcess, (LPVOID)dwAddress, &Value, sizeof(cData), NULL);
	}

	template <class cData>
	void Read(uintptr_t dwAddress, char *Offset, cData Value)
	{
		Read<cData>(Read<cData>(dwAddress, Offset, false), Value);
	}

	virtual void Process(char* ProcessName);
	virtual void Patch(uintptr_t dwAddress, char *chPatch_Bts, char *chDefault_Bts);
	virtual uintptr_t AOB_Scan(uintptr_t dwAddress, uintptr_t dwEnd, char *chPattern);
	virtual uintptr_t Module(LPSTR ModuleName);

	// write memory
	template <class cData>

	cData Write(uintptr_t(Address), cData B) {
		try {
			if (Proc_ID > 0) {
				WriteProcessMemory(hProcess, (LPVOID)(Address), &B, sizeof(B), NULL);
				return B;
			}
			else {
				throw 1; // throw error number / defined in catch
			}
		} // try end
		catch (int error) {
		} // catch end
		return 0;
	} // write end
#pragma endregion
};
#endif