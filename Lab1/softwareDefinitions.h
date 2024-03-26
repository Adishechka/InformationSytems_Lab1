#pragma once
#include <windows.h>
#include <string>
#include <ctime>

#define EVENT_COUNT 10

// Статус игры
bool gameStatus = 0, needToPress = 0;

// correctPress - кол-во корректных нажатий; 
// totalPress - всего нажатий за игру
int correctPress, totalPress;
float timerReactionTotal, timerReactionNow;

std::string endingMessage;

int keyPressed;

RECT rect1, rect2, rect3, rect4, rect5, rect6, rect7, rect8, rect9, rect0;
// Раскраска горизонтального цифрового блока 
HBRUSH
    brushRect1 = CreateSolidBrush(RGB(96, 200, 209)),
    brushRect2 = CreateSolidBrush(RGB(96, 200, 209)),
    brushRect3 = CreateSolidBrush(RGB(96, 200, 209)),
    brushRect4 = CreateSolidBrush(RGB(96, 200, 209)),
    brushRect5 = CreateSolidBrush(RGB(96, 200, 209)),
    brushRect6 = CreateSolidBrush(RGB(96, 200, 209)),
    brushRect7 = CreateSolidBrush(RGB(96, 200, 209)),
    brushRect8 = CreateSolidBrush(RGB(96, 200, 209)),
    brushRect9 = CreateSolidBrush(RGB(96, 200, 209)),
    brushRect0 = CreateSolidBrush(RGB(96, 200, 209));


RECT rectNum1, rectNum2, rectNum3, rectNum4, rectNum5, rectNum6, rectNum7, rectNum8, rectNum9, rectNum0;
// Раскраска NumPad
HBRUSH
    brushRectNum1 = CreateSolidBrush(RGB(96, 200, 209)),
    brushRectNum2 = CreateSolidBrush(RGB(96, 200, 209)),
    brushRectNum3 = CreateSolidBrush(RGB(96, 200, 209)),
    brushRectNum4 = CreateSolidBrush(RGB(96, 200, 209)),
    brushRectNum5 = CreateSolidBrush(RGB(96, 200, 209)),
    brushRectNum6 = CreateSolidBrush(RGB(96, 200, 209)),
    brushRectNum7 = CreateSolidBrush(RGB(96, 200, 209)),
    brushRectNum8 = CreateSolidBrush(RGB(96, 200, 209)),
    brushRectNum9 = CreateSolidBrush(RGB(96, 200, 209)),
    brushRectNum0 = CreateSolidBrush(RGB(96, 200, 209));

PAINTSTRUCT ps;
HFONT fontRect = CreateFontA(30, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_ROMAN, "MyFont");

int randIntervalTimer, randIntervalNumber, reactionInterval;

const int TIMER_SECOND_COUNTER = 0;

int SECOND_COUNTER_INTERVAL = 1000;

LRESULT CALLBACK softwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS newWindowClass(HBRUSH bGColor, HCURSOR cursor, HINSTANCE hInst, HICON icon, LPCWSTR name, WNDPROC procedure);

void AddText(HWND& hWnd, int index, std::string text);
void MainWndAddWidgets(HWND hWnd);

HWND hEditControl;
std::string buffer;
int index;
HWND button1, button2, button3, button4, button5, button6, button7, button8, button9, button0;
HWND num1, num2, num3, num4, num5, num6, num7, num8, num9, num0;


clock_t t0;
//что-нить делаем
clock_t t1;