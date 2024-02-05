#pragma once
#include <d3d12.h>
#include <d3dx12.h>
#include <dxgi1_6.h>
#include<DirectXTex.h>
#include<string>
class TextureConverter
{
public:
	/// <summary>
	/// �g�p���@���o��(�\��)����
	/// </summary>
	static void OutputUsage();

private:
	/// <summary>
	/// �}���`�o�C�g����������C�h������ɕϊ�
	/// </summary>
	/// <param name="mString"></param>
	/// <returns></returns>
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);
public:
	/// <summary>
	/// �e�N�X�`����WIC����DDS�ɕϊ�����
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X</param>
	void ConvertTextureWICToDDS(const std::string& filePath);
private:

	/// <summary>
	/// �e�N�X�`���t�@�C���̓ǂݍ���
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X</param>
	void LoadWICTextureFromFile(const std::string& filePath);

private:
	/// <summary>
	/// �t�H���_�p�X�ƃt�@�C�����𕪗����܂��B
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X</param>
	void SeparateFilePath(const std::wstring& filePath);

	/// <summary>
	/// DDS�t�@�C���Ƃ��ăt�@�C�������o��
	/// </summary>
	void SaveDDSTextureToFile();
private:
	//�摜�̏��
	DirectX::TexMetadata metadata_;
	DirectX::ScratchImage scratchImage_;
	//�f�B���N�g���p�X
	std::wstring directryPath_;
	//�t�@�C����
	std::wstring fileName_;
	//�t�@�C���g���q
	std::wstring fileExt_;
};

