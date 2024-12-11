#include <windows.h>
#include <d3d9.h>

// Глобальные переменные
LPDIRECT3D9 d3d = NULL; // Указатель на интерфейс Direct3D
LPDIRECT3DDEVICE9 d3ddev = NULL; // Устройство Direct3D

// Прототипы функций
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void InitD3D(HWND hwnd);
void RenderFrame();
void CleanD3D();

// Входная точка программы
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    HWND hwnd;
    WNDCLASS wc = {0};

    // Определение класса окна
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "WindowClass";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    RegisterClass(&wc);

    // Создание окна
    hwnd = CreateWindowEx(0, "WindowClass", "Direct3D Cube", WS_OVERLAPPEDWINDOW, 100, 100, 800, 600, NULL, NULL, hInstance, NULL);
    ShowWindow(hwnd, nCmdShow);

    // Инициализация Direct3D
    InitD3D(hwnd);

    // Главный цикл
    MSG msg;
    while (TRUE) {
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                CleanD3D();
                return msg.wParam;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        RenderFrame(); // Рендеринг кадра
    }

    return 0;
}

// Обработчик окна
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// Инициализация Direct3D
void InitD3D(HWND hwnd) {
    d3d = Direct3DCreate9(D3D_SDK_VERSION);

    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp));

    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.hDeviceWindow = hwnd;

    d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &d3ddev);
}

// Очистка Direct3D
void CleanD3D() {
    d3ddev->Release();
    d3d->Release();
}

// Рендеринг кадра
void RenderFrame() {
    d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
    d3ddev->BeginScene();

    // Здесь будет отрисовка куба

    d3ddev->EndScene();
    d3ddev->Present(NULL, NULL, NULL, NULL);
}
