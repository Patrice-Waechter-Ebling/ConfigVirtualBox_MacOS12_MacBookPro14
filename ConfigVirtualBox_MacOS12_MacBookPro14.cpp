// ConfigVirtualBox_MacOS12_MacBookPro14.cpp : Définit le point d'entrée de l'application.
//

#include "framework.h"
#include "ConfigVirtualBox_MacOS12_MacBookPro14.h"

#define MAX_LOADSTRING 100

// Variables globales :
CHAR szTitle[MAX_LOADSTRING]; 
CHAR szWindowClass[MAX_LOADSTRING];
WNDCLASSEX wcex;
HWND hWnd;
MSG msg;

// Déclarations anticipées des fonctions incluses dans ce module de code :
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance,_In_ LPWSTR    lpCmdLine,_In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadString(hInstance, IDC_CONFIGVIRTUALBOXMACOS12MACBOOKPRO14, szWindowClass, MAX_LOADSTRING);
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CONFIGVIRTUALBOXMACOS12MACBOOKPRO14));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(0x01/*CTLCOLOR_MSGBOX + 1 */ );
    wcex.lpszMenuName   = MAKEINTRESOURCE(IDC_CONFIGVIRTUALBOXMACOS12MACBOOKPRO14);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = wcex.hIcon;
    if (!RegisterClassEx(&wcex))    {        return FALSE;    }
    hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPED | WS_BORDER |  WS_SYSMENU |WS_CAPTION, 320, 120,640, 480, nullptr, nullptr, hInstance, nullptr);
    if (!hWnd)    {        return FALSE;    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CONFIGVIRTUALBOXMACOS12MACBOOKPRO14));
    

    // Boucle de messages principale :
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}




LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Analyse les sélections de menu :
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(wcex.hInstance, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Ajoutez ici le code de dessin qui utilise hdc...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Gestionnaire de messages pour la boîte de dialogue À propos de.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
