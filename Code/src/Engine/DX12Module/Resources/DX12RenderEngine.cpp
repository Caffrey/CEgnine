#include "DX12RenderEngine.h"


DX12RenderEngine* s_Instnace = nullptr;


DX12RenderEngine& DX12RenderEngine::GetInstance()
{
    if(s_Instnace != nullptr)
        return *s_Instnace;
}

void DX12RenderEngine::CreateEngine()
{
    if(s_Instnace == nullptr)
        s_Instnace = new DX12RenderEngine();
}

void DX12RenderEngine::ReleaseEngine()
{
    assert(s_Instnace != nullptr);
    s_Instnace->CleanUp();
    delete s_Instnace;
    s_Instnace = nullptr;
}

HRESULT DX12RenderEngine::IntializeDX12()
{
    CreateDevice();
    CreateComamdQueue();
    CreateSwapChain();
}

void DX12RenderEngine::CreateDevice()
{
    ThrowIfFailed(CreateDXGIFactory1(IID_PPV_ARGS(&m_Factory)));
    
    IDXGIAdapter1* hardwareAdapter;
    for(UINT adapterIndex = 0; ;adapterIndex++)
    {
        if(DXGI_ERROR_NOT_FOUND == m_Factory->EnumAdapters1(adapterIndex,&hardwareAdapter))
        {
            break;
        }

        if(SUCCEEDED(D3D12CreateDevice(hardwareAdapter,D3D_FEATURE_LEVEL_11_0,_uuidof(ID3D12Device),nullptr)))
        {
            break;
        }
        hardwareAdapter->Release();
    }

    ThrowIfFailed(D3D12CreateDevice(hardwareAdapter,D3D_FEATURE_LEVEL_11_0,IID_PPV_ARGS(&m_Device)));
}

void DX12RenderEngine::CreateSwapChain()
{
    DXGI_SWAP_CHAIN_DESC desc = {};
    desc.BufferCount = 2;
    desc.BufferDesc.Width = m_Window->GetWidth();
    desc.BufferDesc.Height = m_Window->GetHeight();
    desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    desc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    desc.OutputWindow = m_Window->GetHandle();
    desc.SampleDesc.Count = 1;
    desc.Windowed = TRUE;
    
    IDXGISwapChain* swapChain;
    if(FAILED(m_Factory->CreateSwapChain(m_CommandQueue.Get(),&desc,&swapChain)))
    {
        throw std::exception("CreateSwapChian  Faild");
    }
    m_SwapChain = static_cast<IDXGISwapChain3*>(swapChain);
    m_frameIndex = m_SwapChain->GetCurrentBackBufferIndex();
}

void DX12RenderEngine::CreateComamdQueue()
{
    D3D12_COMMAND_QUEUE_DESC desc;
    desc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
    desc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;

    ThrowIfFailed(m_Device->CreateCommandQueue(&desc,IID_PPV_ARGS(&m_CommandQueue)));
}

void DX12RenderEngine::CleanUp()
{
    
}

ID3D12Device* DX12RenderEngine::GetDevice()
{
    return m_Device.Get();
}
