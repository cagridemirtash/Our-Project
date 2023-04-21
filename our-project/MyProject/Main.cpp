#include <iostream>
#include "icb_gui.h"

int FRM;
ICBYTES draw;
void DrawRect();
void butonfonk1();

#pragma region Seven Segment Matrixi

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
	ExitButton = ICG_BitmapButton(785, 8, 25, 25, butonfonk1);
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
	ICG_Button(700,50,60,40,"Baþlat",DrawRect);
	DisplayImage(FRM, draw);
}

void DrawRect(){

}

void butonfonk1() {
	exit(0);
}



