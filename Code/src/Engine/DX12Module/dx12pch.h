#pragma once
#include "d3d12.h"
#include <exception>
#include <string>
#include <wrl/client.h>
#include <dxgi1_4.h>


inline void ThrowIfFailed(HRESULT hr)
{
    if (FAILED(hr))
    {
        // Set a breakpoint on this line to catch DirectX API errors
        throw std::exception();
    }
}