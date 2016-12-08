#pragma once
#include  "DXWindow.h"
#include <d3d11_1.h>
#include <directxcolors.h>

struct SimpleVertex
{
	DirectX::XMFLOAT3 Pos;
};

class Device
{
public:
	Device(DXWindow * window);

	~Device();

	void Render() const;

private:

	HRESULT InitDevice();

	void CleanupDevice();

	static HRESULT CompileShaderFromFile(WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut);


	DXWindow * m_window;

	const D3D_DRIVER_TYPE         m_driverType = D3D_DRIVER_TYPE_HARDWARE;	// or D3D_DRIVER_TYPE_WARP, D3D_DRIVER_TYPE_REFERENCE
	D3D_FEATURE_LEVEL       m_featureLevel;
	ID3D11Device*           m_pd3dDevice = nullptr;
	ID3D11DeviceContext*    m_pImmediateContext = nullptr;
	IDXGISwapChain*         m_pSwapChain = nullptr;
	ID3D11RenderTargetView* m_pRenderTargetView = nullptr;
	ID3D11VertexShader*     m_pVertexShader = nullptr;
	ID3D11PixelShader*      m_pPixelShader = nullptr;
	ID3D11InputLayout*      m_pVertexLayout = nullptr;
	ID3D11Buffer*           m_pVertexBuffer = nullptr;
};

