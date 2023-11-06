#include "TextureConverter.h"
#include<Windows.h>

std::wstring TextureConverter::ConvertMultiByteStringToWideString(const std::string& mString)
{
	//ワイド文字に変換した際の文字列を計算
	int filePathBufferSize = MultiByteToWideChar(CP_ACP,0,mString.c_str(),-1,nullptr,0);

	//ワイド文字列
	std::wstring wString;
	wString.resize(filePathBufferSize);

	//ワイド文字列に変換
	MultiByteToWideChar(CP_ACP,0,mString.c_str(),-1,&wString[0],filePathBufferSize);

	return wString;
}

void TextureConverter::ConvertTextureWICToDDS(const std::string& filePath)
{
	LoadWICTextureFromFile(filePath);
}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath)
{
	std::wstring wfilePath = ConvertMultiByteStringToWideString(filePath);
}
