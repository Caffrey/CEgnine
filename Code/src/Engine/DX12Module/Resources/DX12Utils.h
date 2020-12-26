#pragma once

#include "Engine/DX12Module/dx12pch.h"
#include "Engine/DX12Module/Resources/DX12DescriptorHeap.h"

//----------------------------------Create Heap



class DX12Utils
{
    //Create Heap
    static DX12DescriptorHeap* CreateRVTHeap(std::wstring& Name, int FrameCount);
    static DX12DescriptorHeap* CreateConstantBufferHeap(std::wstring& Name,int HeapCount = 1);
    static DX12DescriptorHeap* CreateSamplerHeap(std::wstring& Name,int HeapCount = 1);
    static DX12DescriptorHeap* CreateDepthStencilHeap(std::wstring& Name,int HeapCount = 1);
    

    
};