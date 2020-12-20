#pragma once

#include "CDevices.h"
#include "CForwardPipeline.h"
#include <vector>

#include "CDevices.h"
#include "CForwardPipeline.h"

//用来提供渲染层 抽象接口，

class RHI
{


    
};

class RHIManager
{
    RHIManager();
    ~RHIManager();

public:
    void Init();
    void Release();

private:
    static RHIManager* m_Manager;
    std::vector<RHICompoment> m_Compoments;    
public:
    static RHIManager* GetManager();

public:
    CDevice Device;
    CForwardPipeline Pipeline;

    HWND WindowHinstance;
   
};
