#pragma once
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
//#include <algorithm>
//#include "DataItem.h"
#include "RegistryHelper.h"
#include "HTTPClient.h"
#include "json.hpp"
#include <iostream>
#include <exception>

using json = nlohmann::json;

class FileService
{
public:
	std::vector<std::string> GetData(std::string& fileName);
	void PushData(json& _doc, std::string exams, std::string job);
	void Action(std::string& fileName);
};

