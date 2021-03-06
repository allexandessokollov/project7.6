//---------------------------------------------------------------------------
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

        fingIntegerNumber(str);
    }        
}
//---------------------------------------------------------------------------


void TForm1::fingIntegerNumber(String str)
{

    int counter = 0, tmpCounter = 0, strLength = str.Length();

    const char *chArr = str.c_str();

    String num;

    for(int i = 0; i < strLength; i++)
    {

        if(isNumber(chArr[i]))
        {
            if(i > 0 && chArr[i - 1] == '-')
            {
                num += chArr[i - 1];
            }
            
            num += chArr[i];
            counter++;
        }

        if( (counter > 0) && (i == strLength - 1 || !isNumber(chArr[i])))
        {
            break;
        }
    }

    answer->Caption = num;
     if(counter == 0)
    {
      ShowMessage("\n\nthere is no integer number\n\n");
    }
}

bool TForm1::isNumber(char ch)
{
    return (ch >= '0'  && ch <= '9');
}

