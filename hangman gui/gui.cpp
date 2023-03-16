#include<windows.h>

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
#define exit_button 1
#define start_button 2

void AddControls(HWND);
void loadImage() ;

HWND hLogo ;
HMENU hMenu ;
HBITMAP hLogoImage ;

int WINAPI WinMain(HINSTANCE hInst , HINSTANCE hPrevInst , LPSTR args , int ncmdshow){
    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW ;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst ;
    wc.lpszClassName = L"WindowClass";
    wc.lpfnWndProc = WindowProcedure ;

    if(!RegisterClassW(&wc))
    return -1 ;

    CreateWindowW(L"WindowClass", L"HANG_MAN", WS_OVERLAPPEDWINDOW | WS_VISIBLE , 100 ,100, 500, 500,
                  NULL, NULL, NULL, NULL);

    MSG msg = {0};

    while( GetMessage(&msg, NULL, NULL, NULL)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0 ;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd,UINT msg, WPARAM wp, LPARAM lp ){
    switch (msg){
    case WM_COMMAND:
    if (LOWORD(wp) == start_button){
        
    }
    if(LOWORD(wp)== exit_button){
DestroyWindow(hWnd);
    }
    
    case WM_CREATE:
        loadImage();
        AddControls(hWnd);
        break ;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default :
    return DefWindowProcW(hWnd, msg, wp, lp);
    }
}

void AddControls(HWND hWnd){
    hLogo = CreateWindowW(L"static",NULL,WS_VISIBLE | WS_CHILD | SS_CENTER |
     SS_BITMAP , 200, 100,100, 50,hWnd, NULL, NULL, NULL);

    SendMessageW(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hLogoImage);

    CreateWindowW(L"Button",L"Start", WS_VISIBLE | WS_CHILD | WS_BORDER , 200, 204, 100, 50, hWnd,
                  (HMENU)start_button,NULL,NULL);

    CreateWindowW(L"Button",L"Exit", WS_VISIBLE | WS_CHILD | WS_BORDER , 200, 300, 100, 50, hWnd,
                  (HMENU)exit_button,NULL,NULL);

}

void loadImage(){
    hLogoImage = (HBITMAP)LoadImageW(NULL, L"gui\\picture\\logo.bmp",IMAGE_BITMAP, 0,0,LR_LOADFROMFILE);
}
