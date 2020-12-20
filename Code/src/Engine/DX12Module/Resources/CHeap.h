#pragma once
#include <wrl/client.h>

#include "Engine/DX12Module/dx12pch.h"
#include "CResourcesBase.h"

class CHeap :public CResourcesBasic
{

public:
    static CHeap* CreateRVTHeap(int FrameCount);

//Interface
public:
    int GetDescriptorSize(){return m_DescriptorSize;}
    Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> GetHeap(){return m_Heap;}
    
public:
    CHeap(){};
    ~CHeap(){};
    void CreateHeap(D3D12_DESCRIPTOR_HEAP_DESC desc);
    

public:
    void Release() override;

    
    
private:
   Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_Heap;
    D3D12_DESCRIPTOR_HEAP_DESC m_Desc;
    int m_DescriptorSize;
       
};
