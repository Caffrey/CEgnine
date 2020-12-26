#pragma once

#include "Engine/DX12Module/dx12pch.h"
class DX12DescriptorHeap
{
public:
    DX12DescriptorHeap(const D3D12_DESCRIPTOR_HEAP_DESC& i_Desc,
        const wchar_t * i_Name = L"Unnamed Descriptor Heap");
    ~DX12DescriptorHeap();

    ID3D12DescriptorHeap *			GetDescriptorHeap() const;
    // CPU descriptor handle
    CD3DX12_CPU_DESCRIPTOR_HANDLE	GetCPUDescriptorHandle() const;
    CD3DX12_CPU_DESCRIPTOR_HANDLE	GetCPUDescriptorHandle(UINT i_Index) const;
    // GPU descriptor handle
    CD3DX12_GPU_DESCRIPTOR_HANDLE	GetGPUDescriptorHandle() const;
    CD3DX12_GPU_DESCRIPTOR_HANDLE	GetGPUDescriptorHandle(UINT i_Index) const;
    
    // information
    int						GetDescriptorSize() const;
    int						GetDescriptorCount() const;
    const wchar_t *			GetName() const;
private:
    ID3D12DescriptorHeap* m_DescriptorHeap;

    int m_Size;
    int m_Count;
    const std::wstring m_Name;  
};