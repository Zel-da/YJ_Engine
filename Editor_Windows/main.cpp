// Editor_Windows.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Editor_Windows.h"

#include "..\\YJEngine_SOURCE\\yjApplication.h"

//#pragma comment (lib, "..\\x64\\Debug\\YJEngine.lib")

Application app;

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, //프로그램의 인스턴스 핸들
                     _In_opt_ HINSTANCE hPrevInstance, //바로앞에 실행된 현재 프로그램의 인스턴스 핸들 - 사용 X
                     _In_ LPWSTR    lpCmdLine, //명령행으로 입력된 프로그램 인수
                     _In_ int       nCmdShow) //윈도우 창의 초기 표시 방법(실행될 형태
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.
	app.test();
    //

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EDITORWINDOWS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EDITORWINDOWS));

    MSG msg;

	//GetMessage 함수는 메시지 큐에서 메시지를 꺼내오는 역할을 합니다.
	//메세지큐에 아무것도 없다면? 대기상태에 들어갑니다.

	//PeekMessage 메세지큐에 메세지 유무에 상관없이 함수가 리턴된다
	//리턴값이 true이면 메시지가 있다는 뜻이고 false이면 메시지가 없다는 뜻이다.

    while(true)
    {
        // 메시지가 있으면 꺼내고 없으면 바로 false 리턴
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            // 메시지가 없을 때 수행할 게임 로직이나 렌더링 코드를 여기에 작성합니다.
        }
	}


    // 기본 메시지 루프입니다:
    //while (GetMessage(&msg, nullptr, 0, 0))
    //{
    //    if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
    //    {
    //        TranslateMessage(&msg);
    //        DispatchMessage(&msg);
    //    }
    //}

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EDITORWINDOWS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EDITORWINDOWS);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   // 2개 이상의 윈도우도 만들 수 있다.
   // HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
   //     CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
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
			HDC hdc = BeginPaint(hWnd, &ps); // 그리기를 위한 디바이스 컨텍스트를 가져옵니다.

			HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255)); // 파랑 브러시를 생성합니다.
			HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush); // DC에 파랑 브러시를 선택합니다, 흰색 브러시 반환

			Rectangle(hdc, 100, 100, 200, 200); // 사각형을 그립니다.

			(HBRUSH)SelectObject(hdc, oldBrush); // 이전 브러시로 복원합니다. (흰색 원본)
			DeleteObject(brush); // 파랑 브러시를 삭제합니다.

			HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // 빨강 펜을 생성합니다. GDI오브젝트 만들기

			HPEN oldPen = (HPEN)SelectObject(hdc, redPen); // DC에 빨강 펜을 선택합니다.

			Ellipse(hdc, 200, 200, 300, 300); // 원을 그립니다.

			SelectObject(hdc, oldPen); // 이전 펜으로 복원합니다.
			DeleteObject(redPen); // 빨강 펜을 삭제합니다. 

			// DC란 화면이나 프린터 등 출력 장치에 그래픽을 그리기 위한 정보를 담고 있는 구조체입니다.
			// GDI모듈에 의해 관리되며, GDI함수를 사용하여 그래픽을 그릴 때 이 DC를 통해 출력 장치에 접근합니다.
			// 어떤 폰트를 사용할지, 어떤 색상을 사용할지, 현재 커서 위치는 어디인지 등의 정보가 포함되어 있습니다.
            // 화면 출력에 필요한 모든 경우는 WINAPI에서는 DC를 통해서 작업할 수 있다
            // 
            // 
			// 기본으로 자주 사용되는 GDI 오브젝트를 미리 만들어서 제공한다.
			// GetStockObject() 함수를 사용하여 얻을 수 있다.

            HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
			oldBrush = (HBRUSH)SelectObject(hdc, grayBrush);

			Rectangle(hdc, 400, 400, 500, 500);
			SelectObject(hdc, oldBrush);

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

// 정보 대화 상자의 메시지 처리기입니다.
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
