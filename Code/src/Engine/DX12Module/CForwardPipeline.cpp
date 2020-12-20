#include "CForwardPipeline.h"

#include "RHI.h"

using namespace Microsoft::WRL;

void CForwardPipeline::InitCompoment()
{
    CreateComamndQueue();
    CreateeSwapChain();
}

void CForwardPipeline::DestoryCompoment()
{
    
}

void CForwardPipeline::CreateComamndQueue()
{
    D3D12_COMMAND_QUEUE_DESC desc;
    desc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
    desc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;

    ComPtr<ID3D12Device> device = RHIManager::GetManager()->Device.GetDevice();
    ThrowIfFailed(device->CreateCommandQueue(&desc,IID_PPV_ARGS(&m_CommandQueue)));
}

void CForwardPipeline::CreateeSwapChain()
{

    DXGI_SWAP_CHAIN_DESC desc = {};
    desc.BufferCount = FORWARD_PIPELINE_FRAME_COUNT;
    desc.BufferDesc.Width = WIDTH;
    desc.BufferDesc.Height = HEIGHT;
    desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    desc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    desc.OutputWindow = RHIManager::GetManager()->WindowHinstance;
    desc.SampleDesc.Count = 1;
    desc.Windowed = TRUE;
    
    IDXGISwapChain* swapChain;
    ComPtr<IDXGIFactory4> Factory = RHIManager::GetManager()->Device.GetFactory();
    if(FAILED(Factory->CreateSwapChain(m_CommandQueue.Get(),&desc,&swapChain)))
    {
        throw std::exception("CreateSwapChian  Faild");
    }
    m_Swapchain = static_cast<IDXGISwapChain3*>(swapChain);
    m_frameIndex = m_Swapchain->GetCurrentBackBufferIndex();
}
