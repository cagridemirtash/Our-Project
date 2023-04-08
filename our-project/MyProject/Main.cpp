#include <iostream>
#include "icb_gui.h"
#include <vector>
int MLE;
void OnClickButton();
void SevenSegmentDisplay(HWND hwnd, int x, int y, int segmentSize, int value);
void DrawSegment(HDC hdc, int x, int y, int width, int height);
void CustomPaintFunction(HWND hwnd);

void ICGUI_Create() {

}

void ICGUI_main()
{
    ICG_MWSize(400, 300);
    ICG_MWPosition(100, 100);
    ICG_MWTitle(TEXT("Seven-Segment Display Example"));
    MLE = ICG_MLEditSunken(5, 80, 400, 400, "", SCROLLBAR_V);
    ICG_Button(150, 50, 100, 30, "Update",OnClickButton);
}

void OnClickButton() 
{
    CustomPaintFunction(ICG_GetHWND(MLE));
}

void SevenSegmentDisplay(HWND hwnd, int x, int y, int segmentSize, int value)
{
    HDC hdc = GetDC(hwnd);
    SetBkMode(hdc, TRANSPARENT);
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
    SelectObject(hdc, hPen);
    SelectObject(hdc, hBrush);

    int segmentWidth = segmentSize;
    int segmentHeight = segmentSize / 4;
    int gap = segmentHeight / 2;

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

    std::vector<int> segmentsToDraw = segmentValues[value];

    // Draw segments
    if (segmentsToDraw[0]) DrawSegment(hdc, x + gap, y, segmentWidth - 2 * gap, segmentHeight); // A
    if (segmentsToDraw[1]) DrawSegment(hdc, x + segmentWidth - segmentHeight, y + gap, segmentHeight, segmentWidth - gap); // B
    if (segmentsToDraw[2]) DrawSegment(hdc, x + segmentWidth - segmentHeight, y + segmentWidth + gap, segmentHeight, segmentWidth - gap); // C
    if (segmentsToDraw[3]) DrawSegment(hdc, x + gap, y + 2 * segmentWidth, segmentWidth - 2 * gap, segmentHeight); // D
    if (segmentsToDraw[4]) DrawSegment(hdc, x, y + segmentWidth + gap, segmentHeight, segmentWidth - gap); // E
    if (segmentsToDraw[5]) DrawSegment(hdc, x, y + gap, segmentHeight, segmentWidth - gap); // F
    if (segmentsToDraw[6]) DrawSegment(hdc, x + gap, y + segmentWidth, segmentWidth - 2 * gap, segmentHeight); // G

    // Clean up GDI objects
    DeleteObject(hBrush);
    DeleteObject(hPen);
    ReleaseDC(hwnd, hdc);
}

void DrawSegment(HDC hdc, int x, int y, int width, int height) {
    Rectangle(hdc, x, y, x + width, y + height);
}

void CustomPaintFunction(HWND hwnd) {
    SevenSegmentDisplay(hwnd, 200, 200, 100, 8);
}