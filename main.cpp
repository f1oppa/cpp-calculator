#include <windows.h>

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
void AddControls(HWND);

HMENU hMenu;
char op[] = "";

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow){
    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH) COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"windowClass";
    wc.lpfnWndProc = WindowProcedure;
    
    if (!RegisterClassW(&wc))
        return -1;

    CreateWindowW(L"windowClass", L"Test window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 350, 350, NULL, NULL, NULL, NULL);

    MSG msg = {0};

    while (GetMessage(&msg, NULL, NULL, NULL)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_COMMAND:
			switch (wp) {
				case 1:	
					strncat(op, "1", 1);
					SetDlgItemText(hWnd, 90, op);
					break;
				case 2:
					strncat(op, "2", 1);
					SetDlgItemText(hWnd, 90, op);
					break;
				case 3:
					strncat(op, "3", 1);
					SetDlgItemText(hWnd, 90, op);
					break;
				case 4:
					strncat(op, "4", 1);
					SetDlgItemText(hWnd, 90, op);
					break;
				case 5:
					strncat(op, "5", 1);
					SetDlgItemText(hWnd, 90, op);
					break;
				case 6:
					strncat(op, "6", 1);
					SetDlgItemText(hWnd, 90, op);
					break;
				case 7:
					strncat(op, "7", 1);
					SetDlgItemText(hWnd, 90, op);
					break;
				case 8:
					strncat(op, "8", 1);
					SetDlgItemText(hWnd, 90, op);
					break;
				case 9:
					strncat(op, "9", 1);
					SetDlgItemText(hWnd, 90, op);
					break;
				case 0:
					strncat(op, "0", 1);
					SetDlgItemText(hWnd, 90, op);
					break;
			}
            break;
        case WM_CREATE:
            AddControls(hWnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcW(hWnd, msg, wp, lp);
    }
}

void AddControls(HWND hWnd){
    CreateWindow("STATIC", op, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFTNOWORDWRAP, 10, 10, 320, 50, hWnd, (HMENU) 90, NULL, NULL);
	
	CreateWindow("BUTTON", "1", WS_VISIBLE | WS_CHILD | WS_BORDER, 10, 70, 100, 50, hWnd, (HMENU) 1, NULL, NULL);
	CreateWindow("BUTTON", "2", WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 70, 100, 50, hWnd, (HMENU) 2, NULL, NULL);
	CreateWindow("BUTTON", "3", WS_VISIBLE | WS_CHILD | WS_BORDER, 230, 70, 100, 50, hWnd, (HMENU) 3, NULL, NULL);
	
	CreateWindow("BUTTON", "4", WS_VISIBLE | WS_CHILD | WS_BORDER, 10, 130, 100, 50, hWnd, (HMENU) 4, NULL, NULL);
	CreateWindow("BUTTON", "5", WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 130, 100, 50, hWnd, (HMENU) 5, NULL, NULL);
	CreateWindow("BUTTON", "6", WS_VISIBLE | WS_CHILD | WS_BORDER, 230, 130, 100, 50, hWnd, (HMENU) 6, NULL, NULL);
	
	CreateWindow("BUTTON", "7", WS_VISIBLE | WS_CHILD | WS_BORDER, 10, 190, 100, 50, hWnd, (HMENU) 7, NULL, NULL);
	CreateWindow("BUTTON", "8", WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 190, 100, 50, hWnd, (HMENU) 8, NULL, NULL);
	CreateWindow("BUTTON", "9", WS_VISIBLE | WS_CHILD | WS_BORDER, 230, 190, 100, 50, hWnd, (HMENU) 9, NULL, NULL);
	
	CreateWindow("BUTTON", "0", WS_VISIBLE | WS_CHILD | WS_BORDER, 10, 250, 100, 50, hWnd, (HMENU) 0, NULL, NULL);
	CreateWindow("BUTTON", "+", WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 250, 100, 50, hWnd, (HMENU) 80, NULL, NULL);
	CreateWindow("BUTTON", "=", WS_VISIBLE | WS_CHILD | WS_BORDER, 230, 250, 100, 50, hWnd, (HMENU) 88, NULL, NULL);
}