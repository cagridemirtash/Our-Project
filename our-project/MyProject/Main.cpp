#include <iostream>
#include "icb_gui.h"

int FRM;
ICBYTES draw;
void DrawRect(void *draw);
void Exit();
bool isStart = false;
#pragma region Seven Segment Matrixleri

ICBYTES sevenSegmentDisplay{
	{1,1,1,0,1,1,1},
	{0,0,1,0,0,1,0},
	{1,0,1,1,1,0,1},
	{1,0,1,1,0,1,1},
	{0,1,1,1,0,1,0},
	{1,1,0,1,0,1,1},
	{1,1,0,1,1,1,1},
	{1,0,1,0,0,1,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};
#pragma endregion
#pragma region Sekil Matrixleri
ICBYTES ilkSekil = {
	{50, 25, 125, 25},
	{50, 50, 25, 100},
	{150, 50, 25, 100},
	{75, 150, 75, 25},
	{50, 175, 25, 100},
	{150, 175, 25, 100},
	{50, 275, 125, 25}
};

ICBYTES ikinciSekil = {
	{200, 25, 125, 25 },
	{200, 50, 25, 100},
	{300, 50, 25, 100},
	{225, 150, 75, 25},
	{200, 175, 25, 100},
	{300, 175, 25, 100},
	{200, 275, 125, 25}
};
ICBYTES ucuncuSekil = {
	{400, 25, 125, 25 },
	{400, 50, 25, 100},
	{500, 50, 25, 100},
	{425, 150, 75, 25},
	{400, 175, 25, 100},
	{500, 175, 25, 100},
	{400, 275, 125, 25}
};
ICBYTES dorduncuSekil = {
	{550, 25, 125, 25 },
	{550, 50, 25, 100},
	{650, 50, 25, 100},
	{575, 150, 75, 25},
	{550, 175, 25, 100},
	{650, 175, 25, 100},
	{550, 275, 125, 25}
};

#pragma endregion


void ICGUI_Create()
{
	ICG_MWColor(100, 100, 100);
	ICG_MWSize(820, 420);
	ICG_MW_RemoveTitleBar();
}

#pragma region Kademe Olayýnýn Deðiþken olarak alýndýðý kýsým
//void KademeFonk(int kademe)
//{
//	ICG_SetWindowText(SLE1, "");
//	//ICG_printf(SLE1, "%d", kademe);
//	draw = 0xff00 + kademe * 2.55;
//	DisplayImage(FRM1, draw);
//}
#pragma endregion

void ICGUI_main()
{
	CreateImage(draw, 800, 400, ICB_UINT);
#pragma region Kademe Kodu
	/*SLE1 = ICG_SLEditBorder(5, 5, 125, 25, "");
	ICG_TrackBarH(5, 45, 125, 40, "", KademeFonk);
	FRM1 = ICG_FrameMedium(150, 20, 200, 200);
	draw = 0xff00;
	DisplayImage(FRM1, draw);*/
#pragma endregion
	FRM = ICG_FrameMedium(5, 5, 400, 200);
	draw = 0xc00;
	/*FillRect(draw, 50, 25, 125, 25, 0xffaa);
	FillRect(draw, 150, 50, 25, 100, 0xffaa);
	FillRect(draw, 150, 175, 25, 100, 0xffaa);*/
#pragma region ExitButton
	int ExitButton;
	ExitButton = ICG_BitmapButton(785, 8, 25, 25, Exit);
	Line(draw, 785, 785, 810, 810, 0xff);
	SetButtonBitmap(ExitButton, draw);
#pragma endregion

#pragma region Boþ Þekil
	Rect(draw, 50, 25, 125, 25, 0xffff);
	Rect(draw, 50, 50, 25, 100, 0xffff);
	Rect(draw, 150, 50, 25, 100, 0xffff);

	Rect(draw, 75, 150, 75, 25, 0xffff);

	Rect(draw, 50, 175, 25, 100, 0xffff);
	Rect(draw, 150, 175, 25, 100, 0xffff);
	Rect(draw, 50, 275, 125, 25, 0xffff);
#pragma endregion
#pragma region Boþ Þekil 2
	Rect(draw, 200, 25, 125, 25, 0xffff);
	Rect(draw, 200, 50, 25, 100, 0xffff);
	Rect(draw, 300, 50, 25, 100, 0xffff);

	Rect(draw, 225, 150, 75, 25, 0xffff);

	Rect(draw, 200, 175, 25, 100, 0xffff);
	Rect(draw, 300, 175, 25, 100, 0xffff);
	Rect(draw, 200, 275, 125, 25, 0xffff);
#pragma endregion
#pragma region Orta Noktalar
	Rect(draw, 350, 125, 25, 25, 0xffff);
	Rect(draw, 350, 175, 25, 25, 0xffff);
#pragma endregion
#pragma region Boþ Þekil 3
	Rect(draw, 400, 25, 125, 25, 0xffff);
	Rect(draw, 400, 50, 25, 100, 0xffff);
	Rect(draw, 500, 50, 25, 100, 0xffff);

	Rect(draw, 425, 150, 75, 25, 0xffff);

	Rect(draw, 400, 175, 25, 100, 0xffff);
	Rect(draw, 500, 175, 25, 100, 0xffff);
	Rect(draw, 400, 275, 125, 25, 0xffff);
#pragma endregion
#pragma region Boþ Þekil 4
	Rect(draw, 550, 25, 125, 25, 0xffff);
	Rect(draw, 550, 50, 25, 100, 0xffff);
	Rect(draw, 650, 50, 25, 100, 0xffff);

	Rect(draw, 575, 150, 75, 25, 0xffff);

	Rect(draw, 550, 175, 25, 100, 0xffff);
	Rect(draw, 650, 175, 25, 100, 0xffff);
	Rect(draw, 550, 275, 125, 25, 0xffff);
#pragma endregion
	ICG_Button(700,50,60,40,"Baþlat",DrawRect,(void*)&draw);
	DisplayImage(FRM, draw);
}

void DrawRect(void *draw){
	for (int i = 1; i < 8; i++) {
		if (sevenSegmentDisplay.I(i, 1) == 1) {
			int x1 = ilkSekil.I(1, i);
			int y1 = ilkSekil.I(2, i);
			int width = ilkSekil.I(3, i);
			int height = ilkSekil.I(4, i);
			FillRect(*(ICBYTES*)draw, x1, y1, width, height, 0xffaa);
		}
	}for (int i = 1; i < 8; i++) {
		if (sevenSegmentDisplay.I(i, 2) == 1) {
			int x1 = ikinciSekil.I(1, i);
			int y1 = ikinciSekil.I(2, i);
			int width = ikinciSekil.I(3, i);
			int height = ikinciSekil.I(4, i);
			FillRect(*(ICBYTES*)draw, x1, y1, width, height, 0xffaa);
		}
	}for (int i = 1; i < 8; i++) {
		if (sevenSegmentDisplay.I(i, 4) == 1) {
			int x1 = ucuncuSekil.I(1, i);
			int y1 = ucuncuSekil.I(2, i);
			int width = ucuncuSekil.I(3, i);
			int height = ucuncuSekil.I(4, i);
			FillRect(*(ICBYTES*)draw, x1, y1, width, height, 0xffaa);
		}
	}for (int i = 1; i < 8; i++) {
		if (sevenSegmentDisplay.I(i, 1) == 1) {
			int x1 = dorduncuSekil.I(1, i);
			int y1 = dorduncuSekil.I(2, i);
			int width = dorduncuSekil.I(3, i);
			int height = dorduncuSekil.I(4, i);
			FillRect(*(ICBYTES*)draw, x1, y1, width, height, 0xffaa);
		}
	}
	int ExitButton;
	ExitButton = ICG_BitmapButton(785, 8, 25, 25, Exit);
	Line(*(ICBYTES*)draw, 785, 785, 810, 810, 0xff);
	SetButtonBitmap(ExitButton, *(ICBYTES*)draw);
	DisplayImage(FRM, *(ICBYTES*)draw);

	if (isStart) {
		ICG_Button(700, 50, 60, 40, "Baþlat", DrawRect, (void*)&draw);
		isStart = false;
	}
	else {
		ICG_Button(700, 50, 60, 40, "Durdur", DrawRect, (void*)&draw);
		isStart = true;
	}
}

void Exit() {
	exit(0);
}



