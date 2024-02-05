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

	if (argc<NumArgument)
	{
		//使い方を表示する
		TextureConverter::OutputUsage();

		system("pause");
		return 0;
	}

	//COMライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr,COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//テクスチャコンバータ
	TextureConverter converter;

	//テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	CoUninitialize();
	return 0;
}