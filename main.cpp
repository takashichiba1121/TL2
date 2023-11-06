#include<cstdio>
#include<cstdlib>
#include<DirectXTex.h>
#include<cassert>
#include"TextureConverter.h"

enum Aegument {
	kApplicationPath, //アプリケーションのパス
	kFilePath,        //渡されたファイルのパス

	NumArgument
};

int main(int argc,char* argv[])
{
	assert(argc >= NumArgument);

	//COMライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr,COINIT_MULTITHREADED);
	assert(hr);

	//テクスチャコンバータ
	TextureConverter converter;

	//テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	CoUninitialize();

	system("pause");
	return 0;
}