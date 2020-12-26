#include "DX12Utils.h"

DX12DescriptorHeap* DX12Utils::CreateRVTHeap(std::wstring& Name, int FrameCount)
{
    D3D12_DESCRIPTOR_HEAP_DESC desc = {};
    desc.NumDescriptors = FrameCount;
    desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
    desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

    DX12DescriptorHeap *Heap = new  DX12DescriptorHeap(desc,Name.c_str());
    return Heap;    
}

DX12DescriptorHeap* DX12Utils::CreateConstantBufferHeap(std::wstring& Name, int HeapCount)
{
    D3D12_DESCRIPTOR_HEAP_DESC desc = {};
    desc.NumDescriptors = HeapCount;
    desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
    desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

    DX12DescriptorHeap *Heap = new  DX12DescriptorHeap(desc,Name.c_str());
    return Heap;
}

DX12DescriptorHeap* DX12Utils::CreateSamplerHeap(std::wstring& Name, int HeapCount)
{
    D3D12_DESCRIPTOR_HEAP_DESC desc = {};
    desc.NumDescriptors = HeapCount;
    desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER;
    desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

    DX12DescriptorHeap *Heap = new  DX12DescriptorHeap(desc,Name.c_str());
    return Heap;
}

DX12DescriptorHeap* DX12Utils::CreateDepthStencilHeap(std::wstring& Name, int HeapCount)
{
    D3D12_DESCRIPTOR_HEAP_DESC desc = {};
    desc.NumDescriptors = HeapCount;
    desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
    desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

    DX12DescriptorHeap *Heap = new  DX12DescriptorHeap(desc,Name.c_str());
    return Heap;
}
