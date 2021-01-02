#pragma once

#include "Engine/DX12Module/dx12pch.h"
#include "Engine/Win/Window.h"
class DX12RenderEngine
{

//------------Start Engine Module
public:
    static DX12RenderEngine& GetInstance();
    static void CreateEngine();
    static void ReleaseEngine();


    void IntializeDX12();
    
//Static Use , Not Public
   
private:
    static DX12RenderEngine* s_Instnace;

    void CleanUp();

//-----------End Engine Module
    

//-----------Start Render Module
public:
    //Helper
    ID3D12Device* GetDevice();
    

    
private:
    //Create DX12 Thing

    void CreateDevice();
    void CreateSwapChain();
    void CreateComamdQueue();

private:
    //EngineResources
    Microsoft::WRL::ComPtr<ID3D12Device> m_Device;  
    Microsoft::WRL::ComPtr<IDXGIFactory4> m_Factory;
    Microsoft::WRL::ComPtr<IDXGISwapChain3> m_SwapChain;
    Microsoft::WRL::ComPtr<ID3D12CommandQueue> m_CommandQueue;
    
    int m_frameIndex;

    Window* m_Window;//Window is null ,is nothing ,not connect to the engine

    
//----------End Render Module
};