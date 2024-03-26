#include <windows.h>
#include "resource.h"
#include "softwareDefinitions.h"
#include <string>
#include <ctime>
#include <cmath>


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int nCmdShow)
{
    WNDCLASS softwareMainClass = newWindowClass(
        (HBRUSH)COLOR_GRAYTEXT,
        LoadCursor(NULL, IDC_ARROW),
        hInst,
        LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1)),
        //LoadIcon(NULL, IDI_QUESTION),
        L"mainWndClass",
        softwareMainProcedure
    );

    if (!RegisterClassW(&softwareMainClass)) { return -1; }

    MSG softwareMainMessage = { 0 };

    CreateWindow(L"mainWndClass", L"IVTM-01-23 Adiev_KR", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 150, 150, 1000, 550, NULL, NULL, NULL, NULL);
    while (GetMessage(&softwareMainMessage, NULL, NULL, NULL))
    {
        TranslateMessage(&softwareMainMessage);
        DispatchMessage(&softwareMainMessage);
    }

    return 0;
}

WNDCLASS newWindowClass(HBRUSH BGColor, HCURSOR cursor, HINSTANCE hInst, HICON icon, LPCWSTR name, WNDPROC procedure)
{
    WNDCLASS nwc = { 0 };

    nwc.hIcon = icon;
    nwc.hCursor = cursor;
    nwc.hInstance = hInst;
    nwc.lpszClassName = name;
    nwc.hbrBackground = BGColor;
    nwc.lpfnWndProc = procedure;

    return nwc;
}

LRESULT CALLBACK softwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg)
    {
    case WM_CREATE:
        MainWndAddWidgets(hWnd);
        break;

    case WM_TIMER:
        switch (wp)
        {
        case TIMER_SECOND_COUNTER:
            if (gameStatus == true)
            {
                if (needToPress == true)
                {
                    AddText(hEditControl, GetWindowTextLength(hEditControl), "� ���������, �� �� ����� ������ �� ������. ���� ��������...");
                    SetFocus(hWnd);
                    KillTimer(hWnd, TIMER_SECOND_COUNTER);
                    brushRect0 = brushRect1 = brushRect2 = brushRect3 = brushRect4 = brushRect5 = brushRect6 = brushRect7 = brushRect8 = brushRect9 = CreateSolidBrush(RGB(96, 200, 209));
                    brushRectNum0 = brushRectNum1 = brushRectNum2 = brushRectNum3 = brushRectNum4 = brushRectNum5 = brushRectNum6 = brushRectNum7 = brushRectNum8 = brushRectNum9 = CreateSolidBrush(RGB(96, 200, 209));
                    RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);

                    needToPress = false;
                    gameStatus = false;
                    break;
                }
            }

            randIntervalNumber = (std::rand() % 20);
            switch (randIntervalNumber)
            {
            case 0:
                brushRect0 = CreateSolidBrush(RGB(255, 255, 255));
                AddText(hEditControl, GetWindowTextLength(hEditControl), "\r\n���������� ����� 0. ������ ����� � �� ���������� �� 10 ������!");
                break;
            case 1:
                brushRect1 = CreateSolidBrush(RGB(255, 255, 255));
                AddText(hEditControl, GetWindowTextLength(hEditControl), "\r\n���������� ����� 1. ������ ����� � �� ���������� �� 10 ������!");
                break;
            case 2:
                brushRect2 = CreateSolidBrush(RGB(255, 255, 255));
                AddText(hEditControl, GetWindowTextLength(hEditControl), "\r\n���������� ����� 2. ������ ����� � �� ���������� �� 10 ������!");
                break;
            case 3:
                brushRect3 = CreateSolidBrush(RGB(255, 255, 255));
                AddText(hEditControl, GetWindowTextLength(hEditControl), "\r\n���������� ����� 3. ������ ����� � �� ���������� �� 10 ������!");
                break;
            case 4:
                brushRect4 = CreateSolidBrush(RGB(255, 255, 255));
                AddText(hEditControl, GetWindowTextLength(hEditControl), "\r\n���������� ����� 4. ������ ����� � �� ���������� �� 10 ������!");
                break;
            case 5:
                brushRect5 = CreateSolidBrush(RGB(255, 255, 255));
                AddText(hEditControl, GetWindowTextLength(hEditControl), "\r\n���������� ����� 5. ������ ����� � �� ���������� �� 10 ������!");
                break;
            case 6:
                brushRect6 = CreateSolidBrush(RGB(255, 255, 255));
                AddText(hEditControl, GetWindowTextLength(hEditControl), "\r\n���������� ����� 6. ������ ����� � �� ���������� �� 10 ������!");
                break;
            case 7:
                brushRect7 = CreateSolidBrush(RGB(255, 255, 255));
                AddText(hEditControl, GetWindowTextLength(hEditControl), "\r\n���������� ����� 7. ������ ����� � �� ���������� �� 10 ������!");
                break;
            case 8:
                brushRect8 = CreateSolidBrush(RGB(255, 255, 255));
                AddText(hEditControl, GetWindowTextLength(hEditControl), "\r\n���������� ����� 8. ������ ����� � �� ���������� �� 10 ������!");
                break;
            case 9:
                brushRect9 = CreateSolidBrush(RGB(255, 255, 255));
                AddText(hEditControl, GetWindowTextLength(hEditControl), "\r\n���������� ����� 9. ������ ����� � �� ���������� �� 10 ������!");
                break;
            case 10:
                brushRectNum0 = CreateSolidBrush(RGB(255, 255, 255));
                AddText(hEditControl, GetWindowTextLength(hEditControl), "\r\n���������� Num0. ������ ����� � �� ���������� �� 10 ������!");
                break;
            case 11:
                brushRectNum1 = CreateSolidBrush(RGB(255, 255, 255));
                AddText(hEditControl, GetWindowTextLength(hEditControl), "\r\n���������� Num1. ������ ����� � �� ���������� �� 10 ������!");
                break;
            case 12:
                brushRectNum2 = CreateSolidBrush(RGB(255, 255, 255));
                AddText(hEditControl, GetWindowTextLength(hEditControl), "\r\n���������� Num2. ������ ����� � �� ���������� �� 10 ������!");
                break;
            case 13:
                brushRectNum3 = CreateSolidBrush(RGB(255, 255, 255));
                AddText(hEditControl, GetWindowTextLength(hEditControl), "\r\n���������� Num3. ������ ����� � �� ���������� �� 10 ������!");
                break;
            case 14:
                brushRectNum4 = CreateSolidBrush(RGB(255, 255, 255));
                AddText(hEditControl, GetWindowTextLength(hEditControl), "\r\n���������� Num4. ������ ����� � �� ���������� �� 10 ������!");
                break;
            case 15:
                brushRectNum5 = CreateSolidBrush(RGB(255, 255, 255));
                AddText(hEditControl, GetWindowTextLength(hEditControl), "\r\n���������� Num5. ������ ����� � �� ���������� �� 10 ������!");
                break;
            case 16:
                brushRectNum6 = CreateSolidBrush(RGB(255, 255, 255));
                AddText(hEditControl, GetWindowTextLength(hEditControl), "\r\n���������� Num6. ������ ����� � �� ���������� �� 10 ������!");
                break;
            case 17:
                brushRectNum7 = CreateSolidBrush(RGB(255, 255, 255));
                AddText(hEditControl, GetWindowTextLength(hEditControl), "\r\n���������� Num7. ������ ����� � �� ���������� �� 10 ������!");
                break;
            case 18:
                brushRectNum8 = CreateSolidBrush(RGB(255, 255, 255));
                AddText(hEditControl, GetWindowTextLength(hEditControl), "\r\n���������� Num8. ������ ����� � �� ���������� �� 10 ������!");
                break;
            case 19:
                brushRectNum9 = CreateSolidBrush(RGB(255, 255, 255));
                AddText(hEditControl, GetWindowTextLength(hEditControl), "\r\n���������� Num9. ������ ����� � �� ���������� �� 10 ������!");
                break;
            }
            needToPress = true;
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            KillTimer(hWnd, TIMER_SECOND_COUNTER);
            //randIntervalTimer = (std::rand() % 3000) + 1000;
            SetTimer(hWnd, TIMER_SECOND_COUNTER, 1000 * 10, NULL);
            SetFocus(hWnd);
            t0 = clock();
            break;
        default:
            break;
        }
        break;


    // ������ �������� � ��������� ������ � ������� 
    case WM_KEYDOWN:
        if (gameStatus == false)
        {
            t1 = t0 = clock();
            timerReactionNow = 0;
        }
        else
        {
            t1 = clock();
            timerReactionNow = (double)(t1 - t0) / 1000;
            timerReactionTotal += timerReactionNow;
        }

        switch (wp)
        {
        case 0x31:
            keyPressed = int(wp) - '0';
            brushRect1 = CreateSolidBrush(RGB(53, 176, 86));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            AddText(hEditControl, GetWindowTextLength(hEditControl), "����� 1 ������ �� " + std::to_string(timerReactionNow) + " ������");
            SetFocus(hWnd);
            break;
        case 0x32:
            keyPressed = int(wp) - '0';
            brushRect2 = CreateSolidBrush(RGB(53, 176, 86));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            AddText(hEditControl, GetWindowTextLength(hEditControl), "����� 2 ������ �� " + std::to_string(timerReactionNow) + " ������");
            SetFocus(hWnd);
            break;
        case 0x33:
            keyPressed = int(wp) - '0';
            brushRect3 = CreateSolidBrush(RGB(53, 176, 86));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            AddText(hEditControl, GetWindowTextLength(hEditControl), "����� 3 ������ �� " + std::to_string(timerReactionNow) + " ������");
            SetFocus(hWnd);
            break;
        case 0x34:
            keyPressed = int(wp) - '0';
            brushRect4 = CreateSolidBrush(RGB(53, 176, 86));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            AddText(hEditControl, GetWindowTextLength(hEditControl), "����� 4 ������ �� " + std::to_string(timerReactionNow) + " ������");
            SetFocus(hWnd);
            break;
        case 0x35:
            keyPressed = int(wp) - '0';
            brushRect5 = CreateSolidBrush(RGB(53, 176, 86));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            AddText(hEditControl, GetWindowTextLength(hEditControl), "����� 5 ������ �� " + std::to_string(timerReactionNow) + " ������");
            SetFocus(hWnd);
            break;
        case 0x36:
            keyPressed = int(wp) - '0';
            brushRect6 = CreateSolidBrush(RGB(53, 176, 86));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            AddText(hEditControl, GetWindowTextLength(hEditControl), "����� 6 ������ �� " + std::to_string(timerReactionNow) + " ������");
            SetFocus(hWnd);
            break;
        case 0x37:
            keyPressed = int(wp) - '0';
            brushRect7 = CreateSolidBrush(RGB(53, 176, 86));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            AddText(hEditControl, GetWindowTextLength(hEditControl), "����� 7 ������ �� " + std::to_string(timerReactionNow) + " ������");
            SetFocus(hWnd);
            break;
        case 0x38:
            keyPressed = int(wp) - '0';
            brushRect8 = CreateSolidBrush(RGB(53, 176, 86));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            AddText(hEditControl, GetWindowTextLength(hEditControl), "����� 8 ������ �� " + std::to_string(timerReactionNow) + " ������");
            SetFocus(hWnd);
            break;
        case 0x39:
            keyPressed = int(wp) - '0';
            brushRect9 = CreateSolidBrush(RGB(53, 176, 86));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            AddText(hEditControl, GetWindowTextLength(hEditControl), "����� 9 ������ �� " + std::to_string(timerReactionNow) + " ������");
            SetFocus(hWnd);
            break;
        case 0x30:
            keyPressed = int(wp) - '0';
            brushRect0 = CreateSolidBrush(RGB(53, 176, 86));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            AddText(hEditControl, GetWindowTextLength(hEditControl), "����� 0 ������ �� " + std::to_string(timerReactionNow) + " ������");
            SetFocus(hWnd);
            break;

        case VK_NUMPAD1:
            keyPressed = int(0x31) - '0' + 10;
            brushRectNum1 = CreateSolidBrush(RGB(53, 176, 86));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            AddText(hEditControl, GetWindowTextLength(hEditControl), "Num 1 ������ �� " + std::to_string(timerReactionNow) + " ������");
            SetFocus(hWnd);
            break;
        case VK_NUMPAD2:
            keyPressed = int(0x32) - '0' + 10;
            brushRectNum2 = CreateSolidBrush(RGB(53, 176, 86));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            AddText(hEditControl, GetWindowTextLength(hEditControl), "Num 2 ������ �� " + std::to_string(timerReactionNow) + " ������");
            SetFocus(hWnd);
            break;
        case VK_NUMPAD3:
            keyPressed = int(0x33) - '0' + 10;
            brushRectNum3 = CreateSolidBrush(RGB(53, 176, 86));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            AddText(hEditControl, GetWindowTextLength(hEditControl), "Num 3 ������ �� " + std::to_string(timerReactionNow) + " ������");
            SetFocus(hWnd);
            break;
        case VK_NUMPAD4:
            keyPressed = int(0x34) - '0' + 10;
            brushRectNum4 = CreateSolidBrush(RGB(53, 176, 86));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            AddText(hEditControl, GetWindowTextLength(hEditControl), "Num 4 ������ �� " + std::to_string(timerReactionNow) + " ������");
            SetFocus(hWnd);
            break;
        case VK_NUMPAD5:
            keyPressed = int(0x35) - '0' + 10;
            brushRectNum5 = CreateSolidBrush(RGB(53, 176, 86));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            AddText(hEditControl, GetWindowTextLength(hEditControl), "Num 5 ������ �� " + std::to_string(timerReactionNow) + " ������");
            SetFocus(hWnd);
            break;
        case VK_NUMPAD6:
            keyPressed = int(0x36) - '0' + 10;
            brushRectNum6 = CreateSolidBrush(RGB(53, 176, 86));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            AddText(hEditControl, GetWindowTextLength(hEditControl), "Num 6 ������ �� " + std::to_string(timerReactionNow) + " ������");
            SetFocus(hWnd);
            break;
        case VK_NUMPAD7:
            keyPressed = int(0x37) - '0' + 10;
            brushRectNum7 = CreateSolidBrush(RGB(53, 176, 86));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            AddText(hEditControl, GetWindowTextLength(hEditControl), "Num 7 ������ �� " + std::to_string(timerReactionNow) + " ������");
            SetFocus(hWnd);
            break;
        case VK_NUMPAD8:
            keyPressed = int(0x38) - '0' + 10;
            brushRectNum8 = CreateSolidBrush(RGB(53, 176, 86));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            AddText(hEditControl, GetWindowTextLength(hEditControl), "Num 8 ������ �� " + std::to_string(timerReactionNow) + " ������");
            SetFocus(hWnd);
            break;
        case VK_NUMPAD9:
            keyPressed = int(0x39) - '0' + 10;
            brushRectNum9 = CreateSolidBrush(RGB(53, 176, 86));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            AddText(hEditControl, GetWindowTextLength(hEditControl), "Num 9 ������ �� " + std::to_string(timerReactionNow) + " ������");
            SetFocus(hWnd);
            break;
        case VK_NUMPAD0:
            keyPressed = int(0x30) - '0' + 10;
            brushRectNum0 = CreateSolidBrush(RGB(53, 176, 86));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            AddText(hEditControl, GetWindowTextLength(hEditControl), "Num 0 ������ �� " + std::to_string(timerReactionNow) + " ������");
            SetFocus(hWnd);
            break;

        case VK_DELETE:
            SetWindowTextA(hEditControl, "��� ������ ����� ������� SPACE, � ��� ���������� - Enter");
            break;

        case VK_ESCAPE:
            DestroyWindow(hWnd);
            break;

        // ������ ������� ����� ���� (�� Enter)
        case VK_RETURN:
            KillTimer(hWnd, TIMER_SECOND_COUNTER);
            AddText(hEditControl, GetWindowTextLength(hEditControl), "���� ��� ������������� ����������!");
            SetFocus(hWnd);
            brushRect0 = brushRect1 = brushRect2 = brushRect3 = brushRect4 = brushRect5 = brushRect6 = brushRect7 = brushRect8 = brushRect9 = CreateSolidBrush(RGB(96, 200, 209));
            brushRectNum0 = brushRectNum1 = brushRectNum2 = brushRectNum3 = brushRectNum4 = brushRectNum5 = brushRectNum6 = brushRectNum7 = brushRectNum8 = brushRectNum9 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            needToPress = false;
            gameStatus = false;
            break;

        case VK_SPACE:
            AddText(hEditControl, GetWindowTextLength(hEditControl), "���� ���������, �����!");
            SetFocus(hWnd);
            srand(time(NULL));
            randIntervalTimer = (std::rand() % 3000) + 1000;
            correctPress = totalPress = 0;
            timerReactionTotal = 0;
            gameStatus = true;
            SetTimer(hWnd, TIMER_SECOND_COUNTER, randIntervalTimer, NULL);
            break;
        default:
            AddText(hEditControl, GetWindowTextLength(hEditControl), "������ ���������������� ������� �� " + std::to_string(timerReactionNow) + " ������");
            SetFocus(hWnd);
            MessageBoxA(hWnd, "��� ������� �� ��������������", "������!", MB_OK);
            brushRect0 = brushRect1 = brushRect2 = brushRect3 = brushRect4 = brushRect5 = brushRect6 = brushRect7 = brushRect8 = brushRect9 = CreateSolidBrush(RGB(96, 200, 209));
            brushRectNum0 = brushRectNum1 = brushRectNum2 = brushRectNum3 = brushRectNum4 = brushRectNum5 = brushRectNum6 = brushRectNum7 = brushRectNum8 = brushRectNum9 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            break;
        }
        if (gameStatus == true && needToPress == true)
        {
            if (keyPressed != randIntervalNumber)
            {
                AddText(hEditControl, GetWindowTextLength(hEditControl), "������ �� �� �������");
                SetFocus(hWnd);
                MessageBoxA(hWnd, "������ �� �� �������. �������� ���", "������!", MB_OK);
            }
            else
            {
                correctPress++;
            }

            brushRect0 = brushRect1 = brushRect2 = brushRect3 = brushRect4 = brushRect5 = brushRect6 = brushRect7 = brushRect8 = brushRect9 = CreateSolidBrush(RGB(96, 200, 209));
            brushRectNum0 = brushRectNum1 = brushRectNum2 = brushRectNum3 = brushRectNum4 = brushRectNum5 = brushRectNum6 = brushRectNum7 = brushRectNum8 = brushRectNum9 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            SetFocus(hWnd);

            totalPress++;

            if (totalPress < EVENT_COUNT)
            {
                needToPress = false;
                randIntervalTimer = (std::rand() % 3000) + 1000;
                SetTimer(hWnd, TIMER_SECOND_COUNTER, randIntervalTimer, NULL);
            }
            else
            {
                endingMessage = 
                      "\r\n���� ������� � �����.\r\n\t����� ������: " + std::to_string(totalPress) 
                    + " \r\n\t�������� ������ : " + std::to_string(correctPress)
                    + " \r\n\t���������� ������ : " + std::to_string(totalPress - correctPress)
                    + " \r\n\t������� ����� ������� �� �������: " + std::to_string(timerReactionTotal / totalPress);
                
                AddText(hEditControl, GetWindowTextLength(hEditControl), endingMessage);
                SetFocus(hWnd);
                KillTimer(hWnd, TIMER_SECOND_COUNTER);
                
                needToPress = false;
                gameStatus = false;
            }
        }
        break;

    case WM_KEYUP:
        switch (wp)
        {
        case 0x31:
            brushRect1 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            break;
        case 0x32:
            brushRect2 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            break;
        case 0x33:
            brushRect3 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            break;
        case 0x34:
            brushRect4 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            break;
        case 0x35:
            brushRect5 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            break;
        case 0x36:
            brushRect6 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            break;
        case 0x37:
            brushRect7 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            break;
        case 0x38:
            brushRect8 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            break;
        case 0x39:
            brushRect9 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            break;
        case 0x30:
            brushRect0 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            break;

        case VK_NUMPAD1:
            brushRectNum1 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            break;
        case VK_NUMPAD2:
            brushRectNum2 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            break;
        case VK_NUMPAD3:
            brushRectNum3 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            break;
        case VK_NUMPAD4:
            brushRectNum4 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            break;
        case VK_NUMPAD5:
            brushRectNum5 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            break;
        case VK_NUMPAD6:
            brushRectNum6 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            break;
        case VK_NUMPAD7:
            brushRectNum7 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            break;
        case VK_NUMPAD8:
            brushRectNum8 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            break;
        case VK_NUMPAD9:
            brushRectNum9 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            break;
        case VK_NUMPAD0:
            brushRectNum0 = CreateSolidBrush(RGB(96, 200, 209));
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            break;
        }
        break;

    case WM_PAINT:
        BeginPaint(hWnd, &ps);

        FillRect(ps.hdc, &rect1, brushRect1);
        FillRect(ps.hdc, &rect2, brushRect2);
        FillRect(ps.hdc, &rect3, brushRect3);
        FillRect(ps.hdc, &rect4, brushRect4);
        FillRect(ps.hdc, &rect5, brushRect5);
        FillRect(ps.hdc, &rect6, brushRect6);
        FillRect(ps.hdc, &rect7, brushRect7);
        FillRect(ps.hdc, &rect8, brushRect8);
        FillRect(ps.hdc, &rect9, brushRect9);
        FillRect(ps.hdc, &rect0, brushRect0);

        FillRect(ps.hdc, &rectNum1, brushRectNum1);
        FillRect(ps.hdc, &rectNum2, brushRectNum2);
        FillRect(ps.hdc, &rectNum3, brushRectNum3);
        FillRect(ps.hdc, &rectNum4, brushRectNum4);
        FillRect(ps.hdc, &rectNum5, brushRectNum5);
        FillRect(ps.hdc, &rectNum6, brushRectNum6);
        FillRect(ps.hdc, &rectNum7, brushRectNum7);
        FillRect(ps.hdc, &rectNum8, brushRectNum8);
        FillRect(ps.hdc, &rectNum9, brushRectNum9);
        FillRect(ps.hdc, &rectNum0, brushRectNum0);

        SetBkMode(ps.hdc, TRANSPARENT);
        SetTextColor(ps.hdc, RGB(0, 0, 0));
        SelectObject(ps.hdc, fontRect);
        DrawTextA(ps.hdc, "1", 1, &rect1, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_NOCLIP);
        DrawTextA(ps.hdc, "2", 1, &rect2, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_NOCLIP);
        DrawTextA(ps.hdc, "3", 1, &rect3, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_NOCLIP);
        DrawTextA(ps.hdc, "4", 1, &rect4, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_NOCLIP);
        DrawTextA(ps.hdc, "5", 1, &rect5, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_NOCLIP);
        DrawTextA(ps.hdc, "6", 1, &rect6, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_NOCLIP);
        DrawTextA(ps.hdc, "7", 1, &rect7, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_NOCLIP);
        DrawTextA(ps.hdc, "8", 1, &rect8, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_NOCLIP);
        DrawTextA(ps.hdc, "9", 1, &rect9, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_NOCLIP);
        DrawTextA(ps.hdc, "0", 1, &rect0, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_NOCLIP);

        DrawTextA(ps.hdc, "7", 1, &rectNum7, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_NOCLIP);
        DrawTextA(ps.hdc, "8", 1, &rectNum8, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_NOCLIP);
        DrawTextA(ps.hdc, "9", 1, &rectNum9, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_NOCLIP);
        DrawTextA(ps.hdc, "4", 1, &rectNum4, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_NOCLIP);
        DrawTextA(ps.hdc, "5", 1, &rectNum5, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_NOCLIP);
        DrawTextA(ps.hdc, "6", 1, &rectNum6, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_NOCLIP);
        DrawTextA(ps.hdc, "1", 1, &rectNum1, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_NOCLIP);
        DrawTextA(ps.hdc, "2", 1, &rectNum2, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_NOCLIP);
        DrawTextA(ps.hdc, "3", 1, &rectNum3, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_NOCLIP);
        DrawTextA(ps.hdc, "0", 1, &rectNum0, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_NOCLIP);

        EndPaint(hWnd, &ps);
        break;


    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, msg, wp, lp);
    }
}

void MainWndAddWidgets(HWND hWnd)
{
    CreateWindowA("static", "Lab 1 - Win32Api. AdievKR", WS_VISIBLE | WS_CHILD | ES_CENTER, 250, 2, 400, 20, hWnd, NULL, NULL, NULL);

    // �������������� �������� ����
    rect1 = { 30, 80, 80, 30 };
    rect2 = { 100, 80, 150, 30 };
    rect3 = { 170, 80, 220, 30 };
    rect4 = { 240, 80, 290, 30 };
    rect5 = { 310, 80, 360, 30 };
    rect6 = { 380, 80, 430, 30 };
    rect7 = { 450, 80, 500, 30 };
    rect8 = { 520, 80, 570, 30 };
    rect9 = { 590, 80, 640, 30 };
    rect0 = { 660, 80, 710, 30 };

    // NumPad
    rectNum7 = { 800, 150, 750, 100 };
    rectNum8 = { 870, 150, 820, 100 };
    rectNum9 = { 940, 150, 890, 100 };
    rectNum4 = { 800, 220, 750, 170 };
    rectNum5 = { 870, 220, 820, 170 };
    rectNum6 = { 940, 220, 890, 170 };
    rectNum1 = { 800, 290, 750, 240 };
    rectNum2 = { 870, 290, 820, 240 };
    rectNum3 = { 940, 290, 890, 240 };
    rectNum0 = { 870, 360, 750, 310 };

    hEditControl = CreateWindowA("edit", "��� ������ ����� ������� SPACE, � ��� ���������� - Enter", WS_VISIBLE | WS_CHILD | ES_WANTRETURN | ES_MULTILINE | WS_VSCROLL | ES_READONLY, 30, 100, 680, 400, hWnd, NULL, NULL, NULL);
}

void AddText(HWND& hWnd, int index, std::string text)
{
    text = "\r\n" + text;
    SetFocus(hWnd);                                               // set focus
    SendMessageA(hWnd, EM_SETSEL, (WPARAM)index, (LPARAM)index);  // set selection - end of text
    SendMessageA(hWnd, EM_REPLACESEL, 0, (LPARAM)text.c_str()); // append!
}