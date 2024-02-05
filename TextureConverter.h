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
	/// 使用方法を出力(表示)する
	/// </summary>
	static void OutputUsage();

private:
	/// <summary>
	/// マルチバイト文字列をワイド文字列に変換
	/// </summary>
	/// <param name="mString"></param>
	/// <returns></returns>
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);
public:
	/// <summary>
	/// テクスチャをWICからDDSに変換する
	/// </summary>
	/// <param name="filePath">ファイルパス</param>
	void ConvertTextureWICToDDS(const std::string& filePath);
private:

	/// <summary>
	/// テクスチャファイルの読み込み
	/// </summary>
	/// <param name="filePath">ファイルパス</param>
	void LoadWICTextureFromFile(const std::string& filePath);

private:
	/// <summary>
	/// フォルダパスとファイル名を分離します。
	/// </summary>
	/// <param name="filePath">ファイルパス</param>
	void SeparateFilePath(const std::wstring& filePath);

	/// <summary>
	/// DDSファイルとしてファイル書き出し
	/// </summary>
	void SaveDDSTextureToFile();
private:
	//画像の情報
	DirectX::TexMetadata metadata_;
	DirectX::ScratchImage scratchImage_;
	//ディレクトリパス
	std::wstring directryPath_;
	//ファイル名
	std::wstring fileName_;
	//ファイル拡張子
	std::wstring fileExt_;
};

