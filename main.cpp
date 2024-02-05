#include<cstdio>
#include<cstdlib>
#include<DirectXTex.h>
#include<cassert>
#include"TextureConverter.h"

enum Aegument {
	kApplicationPath, //�A�v���P�[�V�����̃p�X
	kFilePath,        //�n���ꂽ�t�@�C���̃p�X

	NumArgument
};

int main(int argc,char* argv[])
{

	if (argc<NumArgument)
	{
		//�g������\������
		TextureConverter::OutputUsage();

		system("pause");
		return 0;
	}

	//COM���C�u�����̏�����
	HRESULT hr = CoInitializeEx(nullptr,COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//�e�N�X�`���R���o�[�^
	TextureConverter converter;

	//�e�N�X�`���ϊ�
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	CoUninitialize();
	return 0;
}