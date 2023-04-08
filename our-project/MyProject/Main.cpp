#include <iostream>
#include "icb_gui.h"
#include <vector>
#include <random>

int MLE;
void OnClickButton();
void SevenSegmentDisplay(HWND hwnd, int x, int y, int segmentSize, int value);
void DrawSegment(HDC hdc, int x, int y, int width, int height);
void CustomPaintFunction(HWND hwnd, int value);
void SegmentDisplay(HDC hdc, int gap, int segmentWidth, int segmentHeight, std::vector<int> segmentsToDraw);
void ClearSegment(HWND hwnd, int x, int y, int segmentSize, int value, std::vector<int> segmentsToDraw);
VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
VOID CALLBACK TimerProcClean(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);

int currentValue = 0;
int x = 200;
int y = 200;
int height = 300;
int start_thread = 0;
int start_thread_end_time = 1000;
std::vector<std::vector<int>> segmentValues = {
        {1, 1, 1, 0, 1, 1, 1}, // 0
        {0, 1, 1, 0, 0, 0, 0}, // 1
        {1, 1, 0, 1, 1, 0, 1}, // 2
        {1, 1, 1, 1, 0, 0, 1}, // 3
        {0, 1, 1, 1, 0, 1, 0}, // 4
        {1, 0, 1, 1, 0, 1, 1}, // 5
        {1, 0, 1, 1, 1, 1, 1}, // 6
        {1, 1, 1, 0, 0, 0, 0}, // 7
        {1, 1, 1, 1, 1, 1, 1}, // 8
        {1, 1, 1, 1, 0, 1, 1}  // 9
};

void ICGUI_Create() {

}

void ICGUI_main()
{
    ICG_MWSize(400, 300);
    ICG_MWPosition(100, 100);
    ICG_MWTitle(TEXT("Seven-Segment Display Example"));
    ICG_Button(150, 50, 100, 30, "Update",OnClickButton);
}

UINT random_interval() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1000, 1050);
    return distrib(gen);
}

void OnClickButton() 
{
    SetTimer(NULL, 0, random_interval(), TimerProcClean);
    SetTimer(NULL, 0, 1000, TimerProc);
}

void SevenSegmentDisplay(HWND hwnd, int x, int y, int segmentSize, int value)
{
    HDC hdc = GetDC(hwnd);
    SetBkMode(hdc, TRANSPARENT);
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hPen);
    SelectObject(hdc, hBrush);

    int segmentWidth = segmentSize;
    int segmentHeight = segmentSize / 4;
    int gap = segmentHeight / 2;

    std::vector<int> segmentsToDraw = segmentValues[value];

    // Draw segments
    SegmentDisplay(hdc, gap, segmentWidth, segmentHeight, segmentsToDraw);

    // Clean up GDI objects
    DeleteObject(hBrush);
    DeleteObject(hPen);
    ReleaseDC(hwnd, hdc);
}

void SegmentDisplay(HDC hdc, int gap, int segmentWidth, int segmentHeight, std::vector<int> segmentsToDraw) {
    if (segmentsToDraw[0]) DrawSegment(hdc, x + gap, y, segmentWidth - 2 * gap, segmentHeight); // A
    if (segmentsToDraw[1]) DrawSegment(hdc, x + segmentWidth - segmentHeight, y + gap, segmentHeight, segmentWidth - gap); // B
    if (segmentsToDraw[2]) DrawSegment(hdc, x + segmentWidth - segmentHeight, y + segmentWidth + gap, segmentHeight, segmentWidth - gap); // C
    if (segmentsToDraw[3]) DrawSegment(hdc, x + gap, y + 2 * segmentWidth, segmentWidth - 2 * gap, segmentHeight); // D
    if (segmentsToDraw[4]) DrawSegment(hdc, x, y + segmentWidth + gap, segmentHeight, segmentWidth - gap); // E
    if (segmentsToDraw[5]) DrawSegment(hdc, x, y + gap, segmentHeight, segmentWidth - gap); // F
    if (segmentsToDraw[6]) DrawSegment(hdc, x + gap, y + segmentWidth, segmentWidth - 2 * gap, segmentHeight); // G
}

void DrawSegment(HDC hdc, int x, int y, int width, int height) {
    Rectangle(hdc, x, y, x + width, y + height);
}

void CustomPaintFunction(HWND hwnd, int value) {
    SevenSegmentDisplay(hwnd, x, y, height, value);
}

void ClearPaintFunction(HWND hwnd, int value)
{
    std::vector<int> segmentsToDraw = segmentValues[value];
    ClearSegment(hwnd, x, y, height, value, segmentsToDraw);
}

void ClearSegment(HWND hwnd, int x, int y, int segmentSize,int value, std::vector<int> segmentsToDraw)
{
    int segmentWidth = segmentSize;
    int segmentHeight = segmentSize / 4;
    int gap = segmentHeight / 2;
    HDC hdc = GetDC(hwnd);
    SetBkMode(hdc, TRANSPARENT);
    HPEN hWPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    HBRUSH hWBrush = CreateSolidBrush(RGB(255, 0, 0));
    SelectObject(hdc, hWPen);
    SelectObject(hdc, hWBrush);
    SegmentDisplay(hdc, gap, segmentWidth, segmentHeight, segmentsToDraw);
    DeleteObject(hWBrush);
    DeleteObject(hWPen);
    ReleaseDC(hwnd, hdc);
}

VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime) {
    CustomPaintFunction(ICG_GetMainWindow(), currentValue);
    currentValue += 1;
    if (currentValue == 10) {
        exit(0);
    }
}

VOID CALLBACK TimerProcClean(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime) {
    ClearPaintFunction(ICG_GetMainWindow(), currentValue);
    if (currentValue == 10) {
        exit(0);
    }
}
