#pragma once
#include <wrl/client.h>

#include "dx12pch.h"
#include "RHICompoment.h"

class CDevice : public RHICompoment
{
public:
    CDevice(){};
    ~CDevice(){};

    void InitCompoment() override;
    void DestoryCompoment() override;




    
protected:

    void CreateDevice();
    void DestoryDevice();

    
    
private: 
    Microsoft::WRL::ComPtr<ID3D12Device> m_Device;  
    Microsoft::WRL::ComPtr<IDXGIFactory4> m_Factory;


public:
    Microsoft::WRL::ComPtr<ID3D12Device> GetDevice(){ return m_Device;}
    Microsoft::WRL::ComPtr<IDXGIFactory4> GetFactory(){ return m_Factory;}
    
};

