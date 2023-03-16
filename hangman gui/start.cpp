#include<windows.h>

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInst , HINSTANCE hPrevInst , LPSTR args , int ncmdshow){
    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1) ;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst ;
    wc.lpszClassName = L"Windowgame";

    wc.lpfnWndProc = WindowProcedure ;

    if(!RegisterClassW(&wc))
    return -1 ;

    CreateWindowW(L"Windowgame", L"HANG_MAN", WS_SYSMENU |WS_MINIMIZEBOX | WS_VISIBLE , 100 ,100, 500, 500,
                  NULL, NULL, NULL, NULL);

    MSG msg = {0};

    while( GetMessage(&msg, NULL, NULL, NULL)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0 ;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd,UINT msg, WPARAM wp, LPARAM lp ){
    switch(msg){
        case WM_DESTROY :
        PostQuitMessage(0);
        break ;
    
    default :
    return DefWindowProcW(hWnd, msg, wp, lp); }
}

