#pragma once

#include <windows.h>
#include <stdio.h>
#include <string>

#define TOTAL_BYTES_READ    1024
#define OFFSET_BYTES 1024
#define REGISTRY_NECOSCAN TEXT("software\\necoscan")

#define REGISTRY_NECOSCAN_SUBKEY_EXAMYEAR TEXT("ExamYear")
#define REGISTRY_NECOSCAN_SUBKEY_EXAMTYPE TEXT("ExamType")
#define REGISTRY_NECOSCAN_SUBKEY_EXAMINATION TEXT("examination")
#define REGISTRY_NECOSCAN_SUBKEY_JOB TEXT("Job")
#define REGISTRY_NECOSCAN_SUBKEY_DEVICEID TEXT("deviceid")
#define REGISTRY_NECOSCAN_SUBKEY_OPERATORID TEXT("OperatorId")
#define REGISTRY_NECOSCAN_SUBKEY_SHORTSUBJECT TEXT("shortsubj")
#define REGISTRY_NECOSCAN_SUBKEY_PAPER TEXT("Paper")
#define REGISTRY_NECOSCAN_SUBKEY_SOSDIR TEXT("sosDir")
#define REGISTRY_NECOSCAN_SUBKEY_SCANTYPE TEXT("ScanType")

class RegistryHelper
{
public:
	//Read string from registry
	BOOL ReadStringFromRegistry(HKEY hKeyParent, LPCWSTR subkey, LPCTSTR valueName, PWCHAR* readData);


	std::string GetExamType();
	std::string GetExamination();
	std::string GetExamYear();
	std::string GetJobS();
	std::string GetOpeartorId();
	std::string GetDeviceId();
	std::string GetShortSubject();
	std::string GetPaper();
	std::string GetScanType();
	std::string GetSOSDirectory();
};

