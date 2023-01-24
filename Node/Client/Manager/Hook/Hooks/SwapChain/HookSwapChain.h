#pragma once
#include "../../Hook.h"

class HookSwapChain : public Hook<void> {
public:
	ID3D11Device* d3d11Device = nullptr;
	ID3D12Device* d3d12Device = nullptr;
public:
	HookSwapChain(Manager* mgr) : Hook<void>(mgr) {

		IDXGISwapChain* pSwapChain;

		WNDCLASSEX windowClass;
		windowClass.cbSize = sizeof(WNDCLASSEX);
		windowClass.style = CS_HREDRAW | CS_VREDRAW;
		windowClass.lpfnWndProc = DefWindowProc;
		windowClass.cbClsExtra = 0;
		windowClass.cbWndExtra = 0;
		windowClass.hInstance = GetModuleHandle(NULL);
		windowClass.hIcon = NULL;
		windowClass.hCursor = NULL;
		windowClass.hbrBackground = NULL;
		windowClass.lpszMenuName = NULL;
		windowClass.lpszClassName = L"SwapChain Window";
		windowClass.hIconSm = NULL;

		::RegisterClassEx(&windowClass);

		HWND window = ::CreateWindow(windowClass.lpszClassName, L"DirectX Window", WS_OVERLAPPEDWINDOW, 0, 0, 100, 100, NULL, NULL, windowClass.hInstance, NULL);
		
		HMODULE libDXGI;
		HMODULE libD3D12;
		
		if ((libDXGI = ::GetModuleHandle(L"dxgi.dll")) == NULL || (libD3D12 = ::GetModuleHandle(L"d3d12.dll")) == NULL) {
			
			::DestroyWindow(window);
			::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
			
			Utils::debugOutput("d2d12.dll or dxgi.dll is missing in the current process!");
			return;
		};

		void* CreateDXGIFactory;
		if ((CreateDXGIFactory = ::GetProcAddress(libDXGI, "CreateDXGIFactory")) == NULL) {
			
			::DestroyWindow(window);
			::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
			
			Utils::debugOutput("Failed to get DXGIFactory process");
			return;
		};

		IDXGIFactory* factory;
		if (((long(__stdcall*)(const IID&, void**))(CreateDXGIFactory))(__uuidof(IDXGIFactory), (void**)&factory) < 0) {
			
			::DestroyWindow(window);
			::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
			
			Utils::debugOutput("Failed create DXGIFactory");
			return;

		};

		IDXGIAdapter* adapter;
		if (factory->EnumAdapters(0, &adapter) == DXGI_ERROR_NOT_FOUND) {

			::DestroyWindow(window);
			::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);

			Utils::debugOutput("Failed create Adapter");
			return;

		};

		void* D3D12CreateDevice;
		if ((D3D12CreateDevice = ::GetProcAddress(libD3D12, "D3D12CreateDevice")) == NULL) {

			::DestroyWindow(window);
			::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);

			Utils::debugOutput("Failed get D3D12CreateDevice process");
			return;

		};

		ID3D12Device* device;
		if (((long(__stdcall*)(IUnknown*, D3D_FEATURE_LEVEL, const IID&, void**))(D3D12CreateDevice))(adapter, D3D_FEATURE_LEVEL_11_0, __uuidof(ID3D12Device), (void**)&device) < 0) {

			::DestroyWindow(window);
			::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);

			Utils::debugOutput("Failed create ID3D12Device");
			return;

		};

		D3D12_COMMAND_QUEUE_DESC queueDesc;
		queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
		queueDesc.Priority = 0;
		queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
		queueDesc.NodeMask = 0;

		ID3D12CommandQueue* commandQueue;
		if (device->CreateCommandQueue(&queueDesc, __uuidof(ID3D12CommandQueue), (void**)&commandQueue) < 0) {

			::DestroyWindow(window);
			::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);

			Utils::debugOutput("Failed create Command Queue");
			return;

		};

		ID3D12CommandAllocator* commandAllocator;
		if (device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, __uuidof(ID3D12CommandAllocator), (void**)&commandAllocator) < 0) {

			::DestroyWindow(window);
			::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);

			Utils::debugOutput("Failed create Command Allocator");
			return;

		};

		ID3D12GraphicsCommandList* commandList;
		if (device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, commandAllocator, NULL, __uuidof(ID3D12GraphicsCommandList), (void**)&commandList) < 0) {

			::DestroyWindow(window);
			::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);

			Utils::debugOutput("Failed create Command List");
			return;

		};

		DXGI_RATIONAL refreshRate;
		refreshRate.Numerator = 60;
		refreshRate.Denominator = 1;

		DXGI_MODE_DESC bufferDesc;
		bufferDesc.Width = 100;
		bufferDesc.Height = 100;
		bufferDesc.RefreshRate = refreshRate;
		bufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		bufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

		DXGI_SAMPLE_DESC sampleDesc;
		sampleDesc.Count = 1;
		sampleDesc.Quality = 0;

		DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
		swapChainDesc.BufferDesc = bufferDesc;
		swapChainDesc.SampleDesc = sampleDesc;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.BufferCount = 2;
		swapChainDesc.OutputWindow = window;
		swapChainDesc.Windowed = 1;
		swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
		swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

		IDXGISwapChain* swapChain;
		if (factory->CreateSwapChain(commandQueue, &swapChainDesc, &swapChain) < 0) {
			
			::DestroyWindow(window);
			::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
			
			Utils::debugOutput("Failed create SwapChain");
			return;


		};

		auto sc_methodsTable = (uint64_t*)::calloc(150, sizeof(uint64_t));
		
		::memcpy(sc_methodsTable, *(uint64_t**)device, 44 * sizeof(uint64_t));
		::memcpy(sc_methodsTable + 44, *(uint64_t**)commandQueue, 19 * sizeof(uint64_t));
		::memcpy(sc_methodsTable + 44 + 19, *(uint64_t**)commandAllocator, 9 * sizeof(uint64_t));
		::memcpy(sc_methodsTable + 44 + 19 + 9, *(uint64_t**)commandList, 60 * sizeof(uint64_t));
		::memcpy(sc_methodsTable + 44 + 19 + 9 + 60, *(uint64_t**)swapChain, 18 * sizeof(uint64_t));

		//Utils::debugOutput("Successfully stored SwapChain VTable methods!");

		device->Release();
		device = NULL;

		commandQueue->Release();
		commandQueue = NULL;

		commandAllocator->Release();
		commandAllocator = NULL;

		commandList->Release();
		commandList = NULL;

		swapChain->Release();
		swapChain = NULL;

		::DestroyWindow(window);
		::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);

		new Hook<HRESULT, IDXGISwapChain3*, UINT, UINT>(mgr, "SwapChainPresent", (uintptr_t)sc_methodsTable[140],
			[&](IDXGISwapChain3* ppSwapChain, UINT syncInterval, UINT flags){
				
				auto _this = this->manager->getHook<HRESULT, IDXGISwapChain3*, UINT, UINT>("SwapChainPresent");
				
				if(d3d11Device == nullptr && d3d12Device == nullptr) {

					if (SUCCEEDED(ppSwapChain->GetDevice(IID_PPV_ARGS(&d3d11Device)))) {

						Utils::debugOutput("SwapChain initializing for D3D11");

					}
					else if (SUCCEEDED(ppSwapChain->GetDevice(IID_PPV_ARGS(&d3d11Device)))) {

						Utils::debugOutput("SwapChain initializing for D3D12");

					};

				};
				
				return _this->_Func(ppSwapChain, syncInterval, flags);
				
		});

	};
};