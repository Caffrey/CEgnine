#pragma once

#include "Engine/DX12Module/dx12pch.h"

class DX12Shader
{
public:
    enum EShaderType
    {
        ePixel = 0,
        eVertex = 1,
        eCompute = 2
    };

    struct ShaderCode
    {
        const std::wstring &		Code;
        const D3D_SHADER_MACRO *	Defines = nullptr;
    };

    DX12Shader(EShaderType i_Type, const wchar_t *i_Filename, const D3D_SHADER_MACRO * i_Defines = nullptr);
    DX12Shader(EShaderType i_Type, ID3DBlob* i_Blob);
    DX12Shader(EShaderType i_Type, const ShaderCode & i_Code);
    ~DX12Shader();
    
    const D3D12_SHADER_BYTECODE &	GetByteCode() const;
    bool							IsLoaded() const;
    EShaderType						GetType() const;

private:
    const EShaderType m_ShaderType;
    bool m_IsLoaded;
    wchar_t m_Name[128];

    D3D12_SHADER_BYTECODE m_ShdaderByteCode;
};