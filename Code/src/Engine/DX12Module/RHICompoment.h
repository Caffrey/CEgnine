

#pragma once

class RHICompoment
{
public:
    RHICompoment() = default;
    ~RHICompoment(){};

    virtual void InitCompoment(){}
    virtual void  DestoryCompoment(){}
};