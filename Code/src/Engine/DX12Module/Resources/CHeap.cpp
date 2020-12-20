#include "CHeap.h"

#include <wrl/client.h>


#include "Engine/DX12Module/RHI.h"


void CHeap::CreateHeap(D3D12_DESCRIPTOR_HEAP_DESC desc)
{
    m_Desc = desc;
    if(FAILED( RHIManager::GetManager()->Device.GetDevice()->CreateDescriptorHeap(&m_Desc,IID_PPV_ARGS(&m_Heap))))
    {
        throw std::exception("CreateHeap  Faild");
    }
    
    m_DescriptorSize = RHIManager::GetManager()->Device.GetDevice()->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
}


CHeap* CHeap::CreateRVTHeap(int FrameCount)
{   
    D3D12_DESCRIPTOR_HEAP_DESC  rvtHeapDesc = {};
    rvtHeapDesc.NumDescriptors = FrameCount;
    rvtHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
    rvtHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

    CHeap *Heap = new CHeap();
    Heap->CreateHeap(rvtHeapDesc);
    return nullptr;
   
}

void CHeap::Release()
{
}
