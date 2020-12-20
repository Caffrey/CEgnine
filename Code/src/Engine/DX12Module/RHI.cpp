#include "RHI.h"

RHIManager* RHIManager::m_Manager = nullptr;

RHIManager::RHIManager()
{
    
}

RHIManager::~RHIManager()
{
}

void RHIManager::Init()
{
    m_Compoments.push_back(Device);
    m_Compoments.push_back(Pipeline);

    for(auto comp : m_Compoments)
    {
        comp.InitCompoment();
    }
}

void RHIManager::Release()
{
}

RHIManager* RHIManager::GetManager()
{
    if(m_Manager == nullptr)
    {
        m_Manager = new RHIManager();
    }
    return m_Manager;
}
