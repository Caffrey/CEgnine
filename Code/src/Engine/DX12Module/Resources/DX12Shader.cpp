#include "DX12Shader.h"
#include <d3dcompiler.h>


DX12Shader::DX12Shader(EShaderType i_Type, const wchar_t* i_Filename, const D3D_SHADER_MACRO* i_Defines)
:m_ShaderType(i_Type)
,m_IsLoaded(false)
{
    wcscpy_s(m_Name,128,i_Filename);

    ID3DBlob* shader;
    ID3DBlob* errorBuff;
    
    char shaderTarget[7] = "*s_5_0";
    switch (i_Type)
    {
    case ePixel:
        shaderTarget[0] = 'p';
        break;
    case eVertex:
        shaderTarget[0] = 'v';
        break;
    }
    ThrowIfFailed(D3DCompileFromFile(i_Filename,
            i_Defines,
            D3D_COMPILE_STANDARD_FILE_INCLUDE,
            "main",
            shaderTarget,
            D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION,
            0,
            &shader,
            &errorBuff));

    
    m_ShdaderByteCode = {};
    m_ShdaderByteCode.BytecodeLength = shader->GetBufferSize();
    m_ShdaderByteCode.pShaderBytecode = shader->GetBufferPointer();

    m_IsLoaded = true;
}

DX12Shader::DX12Shader(EShaderType i_Type, ID3DBlob* i_Blob)
:m_ShaderType(i_Type)
,m_Name(L"FromBlob")
,m_IsLoaded(false)
{
    m_ShdaderByteCode = {};
    m_ShdaderByteCode.BytecodeLength = i_Blob->GetBufferSize();
    m_ShdaderByteCode.pShaderBytecode = i_Blob->GetBufferPointer();

    m_IsLoaded = true;
    
}

DX12Shader::DX12Shader(EShaderType i_Type, const ShaderCode& i_Code)
:m_ShaderType(i_Type)
, m_Name(L"GeneratedShader")
, m_IsLoaded(false)
{
    ID3DBlob* shader; // d3d blob for holding vertex shader bytecode
    ID3DBlob* errorBuff; // a buffer holding the error data if any

    char shaderTarget[7] = "*s_5_0";
    switch (i_Type)
    {
    case ePixel:
        shaderTarget[0] = 'p';
        break;
    case eVertex:
        shaderTarget[0] = 'v';
        break;
    }
    ThrowIfFailed(D3DCompile(i_Code.Code.c_str(),
        i_Code.Code.size(),
        nullptr,
        i_Code.Defines,
        D3D_COMPILE_STANDARD_FILE_INCLUDE,
        "main",
        shaderTarget,
        D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION,
        0,
        &shader,
        &errorBuff));

    
    m_ShdaderByteCode = {};
    m_ShdaderByteCode.BytecodeLength = shader->GetBufferSize();
    m_ShdaderByteCode.pShaderBytecode = shader->GetBufferPointer();

    m_IsLoaded = true;
}

DX12Shader::~DX12Shader()
{
}

const D3D12_SHADER_BYTECODE& DX12Shader::GetByteCode() const
{
    return m_ShdaderByteCode;
}

bool DX12Shader::IsLoaded() const
{
    return m_IsLoaded;
}

DX12Shader::EShaderType DX12Shader::GetType() const
{
    return m_ShaderType;
}
