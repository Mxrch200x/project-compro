#include<windows.h>

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
#define exit_button 1
#define start_button 2

void AddControls(HWND);
void loadImages() ;

HWND hLogo ;
HMENU hMenu ;
HBITMAP hLogoImage ;

int WINAPI WinMain(HINSTANCE hInst , HINSTANCE hPrevInst , LPSTR args , int ncmdshow){
    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1) ; //background color
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst ;
    wc.lpszClassName = L"WindowClass", L"WindowStart"; //window classes

    wc.lpfnWndProc = WindowProcedure ;

    //close program
    if(!RegisterClassW(&wc))
    return -1 ;

    //Parent window
    CreateWindowW(L"WindowClass", L"HANG_MAN", WS_SYSMENU |WS_MINIMIZEBOX | WS_VISIBLE , 100 ,100, 500, 500,
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
    //start button_Action
    if(LOWORD(wp) == start_button){}
    
    //Exit button_Action
    if(LOWORD(wp)== exit_button){
        DestroyWindow(hWnd);
    }
    
    case WM_CREATE:
        loadImages();
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

    hLogo = CreateWindowW(L"Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP , 0, 0, 100, 100, hWnd, NULL, NULL, NULL);
    SendMessageW(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hLogoImage); //create window


    CreateWindowW(L"Button",L"Start", WS_VISIBLE | WS_CHILD | WS_BORDER , 200, 270, 100, 50, hWnd,
                  (HMENU)start_button,NULL,NULL); //create start button

    CreateWindowW(L"Button",L"Exit", WS_VISIBLE | WS_CHILD | WS_BORDER , 200, 350, 100, 50, hWnd,
                  (HMENU)exit_button,NULL,NULL); //create exit button

}

// import logo
void loadImages(){
    hLogoImage = (HBITMAP)LoadImageW(NULL, L"logo.bmp", IMAGE_BITMAP, 500, 250, LR_LOADFROMFILE);
}
