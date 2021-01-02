#include "DX12RootSignature.h"
#include "DX12RenderEngine.h"

void DX12RootSignature::CreateSimpleRootSingTest()
{
    CD3DX12_ROOT_SIGNATURE_DESC desc;
    desc.Init(0,nullptr,0,nullptr,D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

    ID3DBlob* signature;
    ThrowIfFailed(D3D12SerializeRootSignature(&desc,D3D_ROOT_SIGNATURE_VERSION_1,&signature,nullptr));

    ID3D12Device *device = DX12RenderEngine::GetInstance().GetDevice();

    ThrowIfFailed(device->CreateRootSignature(0,signature->GetBufferPointer(),signature->GetBufferSize(),IID_PPV_ARGS(&m_RootSignature)));
 
}
