#include "CDevices.h"
#include "dx12pch.h"


void CDevice::InitCompoment()
{
    CreateDevice();
}

void CDevice::DestoryCompoment()
{
    DestoryDevice();   
}

void CDevice::CreateDevice()
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

void CDevice::DestoryDevice()
{
    
}
