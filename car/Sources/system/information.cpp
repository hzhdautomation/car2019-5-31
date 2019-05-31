#include "information.h"

using namespace std;
using namespace HMV;

std::wstring InformationBasic::String2WString(const std::string& s){
	std::string strLocale = setlocale(LC_ALL, "");
	const char* chSrc = s.c_str();
	size_t nDestSize = mbstowcs(NULL, chSrc, 0) + 1;
	wchar_t* wchDest = new wchar_t[nDestSize];
	wmemset(wchDest, 0, nDestSize);
	mbstowcs(wchDest, chSrc, nDestSize);
	std::wstring wstrResult = wchDest;
	delete[]wchDest;
	setlocale(LC_ALL, strLocale.c_str());
	return wstrResult;
}
//informationBasic
const wstring& InformationBasic::getInfo() {
	return infoContent;
}
int InformationBasic::getCode() {
	return code;
}
//information
Information::Information(wstring info) {
	infoContent = L" \"" + info + L"\"" + L"\n";
}
Information::Information(wstring info, wstring file, unsigned int line, wstring function) {
	infoContent = L" \"" + info + L"\"" + L" file(" + file + L") line(" + to_wstring(line) + L") function(" + function + L")\n";
}
//exp information
HMV::ExpInformation::ExpInformation(wstring info, int errCode) {
	infoContent = L" \"" + info + L"\"" + L"\n";
}
HMV::ExpInformation::ExpInformation(wstring info, int errCode, string file, unsigned int line, string function) {
	infoContent = L"(" + to_wstring(errCode) + L")" + L" \"" + info + L"\"" + L" file(" + String2WString(file) + L") line(" + to_wstring(line) + L") function(" + String2WString(function) + L")\n";
}
//manager
Information& InformationManager::pushInfo(Information info) {
	setFreshed();
	while (size() > maxSize) {
		infoList.erase(infoList.begin());
	}
	infoList.push_back(info);
	setFreshed();
	return infoList.back();
}
void InformationManager::popInfo() {
	infoList.pop_back();
}
void InformationManager::setMaxSize(unsigned int sz) {
	maxSize = sz;
}
unsigned int HMV::InformationManager::size() {
	return infoList.size();
}
void InformationManager::setFreshed() {
	freshed = true;
}
void InformationManager::resetFreshed() {
	freshed = false;
}
bool InformationManager::isFreshed() {
	return freshed;
}
