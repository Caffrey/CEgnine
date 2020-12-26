#pragma once
#include "d3d12.h"
#include "d3dx12.h"
#include <exception>
#include <string>
#include <wrl/client.h>
#include <dxgi1_4.h>
#include <cassert>


inline void ThrowIfFailed(HRESULT hr)
{
    if (FAILED(hr))
    {
        // Set a breakpoint on this line to catch DirectX API errors
        throw std::exception();
    }
}



#define SAFE_RELEASE(p) { if ( (p) ) { (p)->Release(); (p) = nullptr; } }