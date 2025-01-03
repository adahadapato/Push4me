#include "FileService.h"

std::vector<std::string> FileService::GetData(std::string& fileName)
{
    std::fstream file(fileName, std::ios::in);
    std::string line;
    std::vector<std::string> lines;
    if (!file.is_open()) {
        return std::vector<std::string>();
    }

    

    while (std::getline(file, line)) {
        if (line != "") {
            lines.push_back(line);
        }
    }

    file.close();

    return lines;
}

void FileService::Action(std::string& fileName) {
    try {


        std::unique_ptr<RegistryHelper> _regHelper = std::make_unique<RegistryHelper>();
        bool IsDiscard = false;
        std::string Exams;
        std::string subject;

        std::string ExamYear = _regHelper->GetExamYear();

        IsDiscard = fileName.find("Disc_") != std::string::npos;
        std::string Job = _regHelper->GetJobS();
        Exams = _regHelper->GetExamType();
        std::string scanType{};
        std::string Userid = _regHelper->GetOpeartorId();


        std::filesystem::path _path = fileName;
        std::string FileName = _path.filename().string();
        std::string systemNo = _regHelper->GetDeviceId();

        subject = _regHelper->GetShortSubject();
        int paper = std::stoi(_regHelper->GetPaper());
        std::string scanDir;

        if (IsDiscard)
        {
            std::string tempDir = _regHelper->GetSOSDirectory();
            scanDir = tempDir.substr(3, (tempDir.length() - 3));
            scanType = "Disc_" + systemNo;
        }
        else
        {
            std::string tempDir = _regHelper->GetSOSDirectory();
            scanDir = tempDir.substr(3, (tempDir.length() - 3));
            scanType = _regHelper->GetScanType() + "_" + systemNo;
        }

        auto scanData = GetData(fileName);
        json data;
        data["ScanFile"] = FileName;
        data["JobDir"] = scanDir;
        data["Responses"] = scanData;
        data["Job"] = Job;
        data["ExamType"] = Exams == "SSCE" ? Exams + " " + _regHelper->GetExamination() : Exams;
        data["ScanType"] = scanType;
        data["SystemNo"] = systemNo;

        data["OperatorId"] = Userid;
        data["Subject"] = (Exams.find("NCEE") != std::string::npos || Exams.find("GIFTED") != std::string::npos) ? paper + " " + subject : subject;
        data["ExamYear"] = ExamYear;
        PushData(data, Exams, Job);
    }
    catch (std::exception& e) {
        std::cout << e.what();
    }
}


void FileService::PushData(json& _doc, std::string exams, std::string job)
{
    try {


        std::unique_ptr<RegistryHelper> _regHelper = std::make_unique<RegistryHelper>();
        std::unique_ptr<HTTPClient> _client = std::make_unique<HTTPClient>();
        std::string examType = exams;
        if (exams == "SSCE")
        {
            if (_regHelper->GetExamination() == "Internal")
            {
                examType = "ssce";
            }
            else
            {
                examType = "nov";
            }
        }
        std::string Url;
        Url.append(HTTP_SERVER_31_MANAGER_API_BASE_URL);
        Url.append("scanning");
        Url.append("/");
        Url.append(examType);
        Url.append("/");
        Url.append(job);
        Url.append("/");
        Url.append("save");
        std::string _data = _doc.dump();
        _client->Post(Url, _data);
    }
    catch (std::exception& e) {
        std::cout << e.what();
    }
}
