#pragma once

#include <string>
#include <vector>

namespace HMV {
	using namespace std;
	//basic type
	class InformationBasic {
	public:
		virtual const wstring& getInfo();
		int getCode();
		static std::wstring String2WString(const std::string& s);
	protected:
		wstring infoContent;
		int code = 0;
	private:
	};
	//normal information
	class Information :public InformationBasic {
	public:
		Information(wstring info);
		Information(wstring info, wstring file, unsigned int line, wstring function);
	};
	//exception information
	class ExpInformation :public InformationBasic {
	public:
		ExpInformation(wstring info, int errCode);
		ExpInformation(wstring info, int errCode, string file, unsigned int line, string function);
	};
	//manager
	class InformationManager {
	public:
		Information& pushInfo(Information);
		void popInfo();
		void setMaxSize(unsigned int sz);
		unsigned int size();
		void setFreshed();
		void resetFreshed();
		bool isFreshed();
	private:
		vector<Information> infoList;
		unsigned int maxSize = 1000;
		bool freshed;
	};
	class ExceptionManager:public InformationManager {

	};
	class MessageManager :public InformationManager {

	};
};
