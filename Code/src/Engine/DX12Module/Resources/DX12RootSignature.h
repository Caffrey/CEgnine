#pragma once
#include "Engine/DX12Module/dx12pch.h"



class DX12RootSignature
{

public:
    ID3D12RootSignature* GetRootSignature() const {return nullptr;}



//Test Code
private:
    void CreateSimpleRootSingTest();
//Test Code



private:
    ID3D12RootSignature* m_RootSignature;
};