#include<iostream>
#include<Windows.h>
#define EXE_FILENAME "C:\\Users\\OneDrive\\Work\\targil3\\Debug\\targil3.exe"
#define PROCESS_ARG "4"
using namespace std;
int main()
{
	STARTUPINFOA si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	// create argument string
	CHAR exe_filename[] = EXE_FILENAME;
	CHAR process_arg[] = PROCESS_ARG;
	INT size = strlen(exe_filename) + strlen(process_arg) + 2;
	PCHAR param = (PCHAR)malloc(size * sizeof(CHAR));
	sprintf_s(param, size, "%s %s", exe_filename, process_arg);
	// Start the child process.
	CreateProcessA(NULL, param, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);
	free(param);
	return 0;
}
