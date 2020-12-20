#pragma once
#include <wrl/client.h>

#include "dx12pch.h"
#include "RHICompoment.h"

class CForwardPipeline : public RHICompoment
{
public:
    static const int FORWARD_PIPELINE_FRAME_COUNT = 2;
    static const int WIDTH = 800;
    static const int HEIGHT = 600;
public:
    CForwardPipeline(){}
    ~CForwardPipeline(){};

    void InitCompoment() override;
    void DestoryCompoment() override;


public:
    Microsoft::WRL::ComPtr<IDXGISwapChain> GetSwapchain(){return m_Swapchain;} 
    Microsoft::WRL::ComPtr<ID3D12CommandQueue> GetCommandQuene(){return m_CommandQueue;} 

protected:

    void CreateComamndQueue();
    void CreateeSwapChain();


private:
    Microsoft::WRL::ComPtr<IDXGISwapChain3> m_Swapchain;
    Microsoft::WRL::ComPtr<ID3D12Resource> m_RenderTarget[FORWARD_PIPELINE_FRAME_COUNT];

    Microsoft::WRL::ComPtr<ID3D12CommandQueue> m_CommandQueue;
    
    D3D12_VIEWPORT m_viewPort;
    D3D12_RECT m_scissorRect;

    int m_frameIndex;
public:    
    
};

