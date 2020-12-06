//---------------------------------------------------------------------------
/*
 Èç ñòðîêè, ñîñòîÿùåé èç áóêâ, öèôð, çàïÿòûõ, òî÷åê, çíàêîâ + è - ,
 âûäåëèòü ïîäñòðîêó, êîòîðàÿ ñîîòâåòñòâóåò çàïèñè öåëîãî ÷èñëà.
*/
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <string.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::enterTextKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    
    if(Key == 13)
    {
        ListBox1->Items->Add("Your string:");
        ListBox1->Items->Add(enterText->Text);
        ListBox1->Items->Add("counting...");


        String str;
        str =  enterText->Text;

        countAnswer(str);
    }        
}
//---------------------------------------------------------------------------


int TForm1::countAnswer(String str)
{

    int counter = 0, tmpCounter = 0, strLength = str.Length();
    String strAnswer;


    const char *chArr = str.c_str();
    char num[128];
    for(int i = 0; i < 128; i++)
    {
        num[i] = ' ';
    }

    for(int i = 0; i < strLength; i++)
    {

        if(isNumber(chArr[i]))
        {
            num[counter] = chArr[i];
            counter++;

            if(i > 0)
            {
               if(chArr[i - 1] == '-')
               {
                   num[counter] = num[counter - 1];
                   num[counter - 1] = chArr[i - 1];
                   counter++;
               }

            }
        }

        if( (counter > 0) && (!isNumber(chArr[i])) )
        {
            strAnswer = num;

            answer->Caption = strAnswer;
            return 1;
        }

    }


    return -999999;
}

bool TForm1::isNumber(char ch)
{
    switch (ch)
    {
        case '0':
        return true;

        case '1':
        return true;

        case '2':
        return true;

        case '3':
        return true;

        case '4':
        return true;

        case '5':
        return true;

        case '6':
        return true;

        case '7':
        return true;

        case '8':
        return true;

        case '9':
        return true;

        default:
        return false;
    }
}

