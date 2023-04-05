#include"icb_gui.h"
int MLE; //Çok Satýrlý metin düzenleyici penceresi kulpu (handle)
void ButonFonksiyonu(); //Buton fonksiyonu deklare edildi
void ICGUI_Create()//Ana pencere yaratýldý
{ }
void ICGUI_main()//C++ olmazsa olmazý main
{
	ICG_Button(5, 5, 120, 25, "BUTON", ButonFonksiyonu);
	MLE = ICG_MLEditSunken(5, 80, 400, 400, "", SCROLLBAR_V);
}
void ButonFonksiyonu()//Buton’a basýnca olacaklar
{
	for (int x = 1; x < 11; x++)
		ICG_printf(MLE, "%d-Merhaba Dünya!\n");
}