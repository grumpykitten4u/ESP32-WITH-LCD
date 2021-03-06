  
#include <SPI.h>
#include <TFT_eSPI.h> // Hardware-specific library
TFT_eSPI LcdTouch = TFT_eSPI();

int numbers[4] = {-1,-1,-1,-1};
int i;
String str;
 uint16_t x, y;

void setup() {
  i = 0;
  Serial.begin(115200);
  LcdTouch.init();
  LcdTouch.setRotation(0);
  clibriat();
  LcdTouch.fillScreen(ILI9341_BLACK);
  LcdTouch.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
  LcdTouch.drawRect(10, 10, 145, 56, ILI9341_BLUE); //first line
  LcdTouch.drawRect(160, 10, 70, 56, ILI9341_BLUE); //first line X
  LcdTouch.drawRect(10, 71, 70, 56, ILI9341_BLUE); //second line 1
  LcdTouch.drawRect(85, 71, 70, 56, ILI9341_BLUE); //second line 2
  LcdTouch.drawRect(160, 71, 70, 56, ILI9341_BLUE); //second line 3
  LcdTouch.drawRect(10, 132, 70, 56, ILI9341_BLUE); //third line 4
  LcdTouch.drawRect(85, 132, 70, 56, ILI9341_BLUE); //third line 5
  LcdTouch.drawRect(160, 132, 70, 56, ILI9341_BLUE); //third line 6
  LcdTouch.drawRect(10, 193, 70, 56, ILI9341_BLUE); //forth line 7
  LcdTouch.drawRect(85, 193, 70, 56, ILI9341_BLUE); //forth line 8
  LcdTouch.drawRect(160, 193, 70, 56, ILI9341_BLUE); //forth line 9
  LcdTouch.drawRect(10, 254, 70, 56, ILI9341_BLUE); //fifth line 0
  LcdTouch.drawRect(85, 254, 145, 56, ILI9341_BLUE); //fifth line "ENTER"
 
  LcdTouch.drawString ("1", 35, 85, 4);
  LcdTouch.drawString ("2", 110, 85, 4);
  LcdTouch.drawString ("3", 185, 85, 4);
  LcdTouch.drawString ("4", 35, 145, 4);
  LcdTouch.drawString ("5", 110, 145, 4);
  LcdTouch.drawString ("6", 185, 145, 4);
  LcdTouch.drawString ("7", 35, 205, 4);
  LcdTouch.drawString ("8", 110, 205, 4);
  LcdTouch.drawString ("9", 185, 205, 4);
  LcdTouch.drawString ("0",35, 265, 4);
  LcdTouch.drawString ("ENTER", 100, 267, 4);
  LcdTouch.drawString ("X", 185, 25, 4);
  
  //LcdTouch.print (27, 25, "1", 4, ILI9341_WHITE); //numbers location 
  //LcdTouch.print (57, 25, "4", 4, ILI9341_WHITE); //numbers location
  //LcdTouch.print (87, 25, "9", 4, WHITE); //numbers location
  //LcdTouch.print (117, 25, "6", 4, WHITE); //numbers location

  





  
  //LcdTouch.set(3780, 372, 489, 3811);
  //LcdTouch.print (5, 100, " Avi Hayun  ", 4, YELLOW, BLACK);
  //delay(2000);
  //Test_Color();
  //Test_shape();
  //English_Font_test();
  //delay(2000);
  //LcdTouch.fillScreen(BLACK);
  //LcdTouch.print (5, 100, " Press Touch Screen ", 2, YELLOW, BLACK);
  //240 320
}

void loop() {
  LcdTouch.getTouch (&x , &y );
  if (LcdTouch.getTouch(&x , &y))
  {
    //LcdTouch.print (27, 25, "1", 4, WHITE);
    //LcdTouch.readTouch();
   // x = LcdTouch.xTouch;
    //y = LcdTouch.yTouch;
    //Serial.print("x = ");
    //Serial.print(x);
    //Serial.print(", y = ");
    //Serial.println(y);
    //delay(1000);
    
     if ((x >= 160) && (x <= 230) && (y >= 10) && (y <= 66)) 
      {
        Serial.println("X");
                if (i>0)
        {
          //LcdTouch.drawRect(85, 254, 145, 56, DARKGREY); //fifth line "ENTER
         // LcdTouch.print (100, 267, "ENTER", 4, DARKGREY);
          switch(i)
          {
            case 1:
            LcdTouch.fillRect(26, 20, 25, 35, ILI9341_BLACK);
            break;
            case 2:
            LcdTouch.fillRect(56, 20, 25, 35, ILI9341_BLACK);
            break;
            case 3:
            LcdTouch.fillRect(86, 20, 25, 35, ILI9341_BLACK);
            break;
            case 4:
            LcdTouch.fillRect(116, 20, 25, 35,ILI9341_BLACK);
            break;
          }
          i--;
          numbers[i] = -1;
          if (i==0)
          {
           // LcdTouch.drawRect(160, 10, 70, 56, DARKGREY);
           // LcdTouch.print (185, 25, "X", 4, DARKGREY);
          }
        }
      }
      else if ((x >= 10) && (x <= 80) && (y >= 71) && (y <= 127))
      {
        Serial.println("1");
        LcdTouch.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
        // LcdTouch.drawString ("1", 26, 25, 4);
         if (i<4)
        {
          numbers[i] = 1;
          i++;
          switch(i)
          {
            case 1:
            
            LcdTouch.drawString ("1", 26, 25, 4);
            break;
            case 2:
            LcdTouch.drawString ("1", 56, 25, 4);
            break;
            case 3:
            LcdTouch.drawString ("1", 86, 25, 4);
            break;
            case 4:
            LcdTouch.drawString ("1", 116, 25, 4);
           // LcdTouch.drawRect(85, 254, 145, 56, BLUE); //fifth line "ENTER"
            //LcdTouch.print (100, 267, "ENTER", 4, WHITE);
            break;
          }
         // LcdTouch.drawRect(160, 10, 70, 56, BLUE); //first line X
          //LcdTouch.print (185, 25, "X", 4, WHITE);
        }
        
      }
      else if ((x >= 85) && (x <= 155) && (y >= 71) && (y <= 127))
      {
        Serial.println("2");
         if (i<4)
        {
          numbers[i] = 2;
          i++;
          switch(i)
          {
            case 1:
            LcdTouch.drawString ("2", 26, 25, 4);
            break;
            case 2:
            LcdTouch.drawString ("2", 56, 25, 4);
            break;
            case 3:
            LcdTouch.drawString ("2", 86, 25, 4);
            break;
            case 4:
            LcdTouch.drawString ("2", 116, 25, 4);
       
            //LcdTouch.drawRect(85, 254, 145, 56, BLUE); //fifth line "ENTER"
           // LcdTouch.print (100, 267, "ENTER", 4, WHITE);
            break;
          }
         // LcdTouch.drawRect(160, 10, 70, 56, BLUE); //first line X
          //LcdTouch.print (185, 25, "X", 4, WHITE);
        }
      }
      else if ((x >= 160) && (x <= 230) && (y >= 71) && (y <= 127))
      {
        Serial.println("3");
        if (i<4)
        {
          numbers[i] = 3;
          i++;
          switch(i)
          {
            case 1:
            LcdTouch.drawString ("3", 26, 25, 4);
            break;
            case 2:
            LcdTouch.drawString ("3", 56, 25, 4);
            break;
            case 3:
            LcdTouch.drawString ("3", 86, 25, 4);
            break;
            case 4:
            LcdTouch.drawString ("3", 116, 25, 4);
           // LcdTouch.drawRect(85, 254, 145, 56, BLUE); //fifth line "ENTER"
            //LcdTouch.print (100, 267, "ENTER", 4, WHITE);
            break;
          }
          //LcdTouch.drawRect(160, 10, 70, 56, BLUE); //first line X
          //LcdTouch.print (185, 25, "X", 4, WHITE);
        }
      }
      else if ((x >= 10) && (x <= 80) && (y >= 132) && (y <= 188))
      {
        Serial.println("4");
         if (i<4)
        {
          numbers[i] = 4;
          i++;
          switch(i)
          {
            case 1:
            LcdTouch.drawString ("4", 26, 25, 4);
            break;
            case 2:
           LcdTouch.drawString ("4", 56, 25, 4);
            break;
            case 3:
           LcdTouch.drawString ("4", 86, 25, 4);
            break;
            case 4:
            LcdTouch.drawString ("4", 116, 25, 4);
           // LcdTouch.drawRect(85, 254, 145, 56, BLUE); //fifth line "ENTER"
           // LcdTouch.print (100, 267, "ENTER", 4, WHITE);
            break;
          }
         // LcdTouch.drawRect(160, 10, 70, 56, BLUE); //first line X
          //LcdTouch.print (185, 25, "X", 4, WHITE);
        }
      }
      else if ((x >= 85) && (x <= 155) && (y >= 132) && (y <= 188))
      {
        Serial.println("5");
        if (i<4)
        {
          numbers[i] = 5;
          i++;
          switch(i)
          {
            case 1:
             LcdTouch.drawString ("5", 26, 25, 4);
            break;
            case 2:
             LcdTouch.drawString ("5", 56, 25, 4);
            break;
            case 3:
            LcdTouch.drawString ("5", 86, 25, 4);
            break;
            case 4:
            LcdTouch.drawString ("5", 116, 25, 4);
            //LcdTouch.drawRect(85, 254, 145, 56, BLUE); //fifth line "ENTER"
            //LcdTouch.print (100, 267, "ENTER", 4, WHITE);
            break;
          }
          //LcdTouch.drawRect(160, 10, 70, 56, BLUE); //first line X
          //LcdTouch.print (185, 25, "X", 4, WHITE);
        }
      }
      else if ((x >= 160) && (x <= 230) && (y >= 132) && (y <= 188))
      {
        Serial.println("6");
        if (i<4)
        {
          numbers[i] = 6;
          i++;
          switch(i)
          {
            case 1:
            LcdTouch.drawString ("6", 26, 25, 4);
            break;
            case 2:
            LcdTouch.drawString ("6", 56, 25, 4);
            break;
            case 3:
            LcdTouch.drawString ("6", 86, 25, 4);
            break;
            case 4:
            LcdTouch.drawString ("6", 116, 25, 4);
           // LcdTouch.drawRect(85, 254, 145, 56, BLUE); //fifth line "ENTER"
           // LcdTouch.print (100, 267, "ENTER", 4, WHITE);
            break;
          }
          //LcdTouch.drawRect(160, 10, 70, 56, BLUE); //first line X
         // LcdTouch.print (185, 25, "X", 4, WHITE);
        }
      }
      else if ((x >= 10) && (x <= 80) && (y >= 193) && (y <= 249))
      {
        Serial.println("7");
        if (i<4)
        {
          numbers[i] = 7;
          i++;
          switch(i)
          {
            case 1:
            LcdTouch.drawString ("7", 26, 25, 4);
            break;
            case 2:
            LcdTouch.drawString ("7", 56, 25, 4);
            break;
            case 3:
            LcdTouch.drawString ("7", 86, 25, 4);
            break;
            case 4:
            LcdTouch.drawString ("7", 116, 25, 4);
            //LcdTouch.drawRect(85, 254, 145, 56, BLUE); //fifth line "ENTER"
            //LcdTouch.print (100, 267, "ENTER", 4, WHITE);
            break;
          }
         // LcdTouch.drawRect(160, 10, 70, 56, BLUE); //first line X
        //  LcdTouch.print (185, 25, "X", 4, WHITE);
        }
      }
      else if ((x >= 85) && (x <= 160) && (y >= 193) && (y <= 249))
      {
        Serial.println("8");
        if (i<4)
        {
          numbers[i] = 8;
          i++;
          switch(i)
          {
            case 1:
            LcdTouch.drawString ("8", 26, 25, 4);
            break;
            case 2:
            LcdTouch.drawString ("8", 56, 25, 4);
            break;
            case 3:
            LcdTouch.drawString ("8", 86, 25, 4);
            break;
            case 4:
            LcdTouch.drawString ("8", 116, 25, 4);
            //LcdTouch.drawRect(85, 254, 145, 56, BLUE); //fifth line "ENTER"
            //LcdTouch.print (100, 267, "ENTER", 4, WHITE);
            break;
          }
         // LcdTouch.drawRect(160, 10, 70, 56, BLUE); //first line X
          //LcdTouch.print (185, 25, "X", 4, WHITE);
        }
      }
      else if ((x >= 160) && (x <= 230) && (y >= 193) && (y <= 249))
      {
        Serial.println("9");
        if (i<4)
        {
          numbers[i] = 9;
          i++;
          switch(i)
          {
            case 1:
            LcdTouch.drawString ("9", 26, 25, 4);
            break;
            case 2:
            LcdTouch.drawString ("9", 56, 25, 4);
            break;
            case 3:
            LcdTouch.drawString ("9", 86, 25, 4);
            break;
            case 4:
            LcdTouch.drawString ("9", 116, 25, 4);
            //LcdTouch.drawRect(85, 254, 145, 56, BLUE); //fifth line "ENTER"
            //LcdTouch.print (100, 267, "ENTER", 4, WHITE);
            break;
          }
          //LcdTouch.drawRect(160, 10, 70, 56, BLUE); //first line X
          //LcdTouch.print (185, 25, "X", 4, WHITE);
        }
      }
      else if ((x >= 10) && (x <= 80) && (y >= 254) && (y <= 310))
      {
        Serial.println("0");
        if (i<4)
        {
          numbers[i] = 0;
          i++;
          switch(i)
          {
            case 1:
            LcdTouch.drawString ("0", 26, 25, 4);
            break;
            case 2:
            LcdTouch.drawString ("0", 56, 25, 4);
            break;
            case 3:
            LcdTouch.drawString ("0", 86, 25, 4);
            break;
            case 4:
            LcdTouch.drawString ("0", 116, 25, 4);
            //LcdTouch.drawRect(85, 254, 145, 56, BLUE); //fifth line "ENTER"
            //LcdTouch.print (100, 267, "ENTER", 4, WHITE);
            break;
          }
          //LcdTouch.drawRect(160, 10, 70, 56, BLUE); //first line X
         //LcdTouch.print (185, 25, "X", 4, WHITE);
        }
      }
      else if ((x >= 85) && (x <= 230) && (y >= 254) && (y <= 310))
      {
        Serial.println("ENTER");
        {
          Serial.print("ENTER ");
        Serial.print(numbers[0]);
        Serial.print(numbers[1]);
        Serial.print(numbers[2]);
        Serial.println(numbers[3]);
        }
      }
      delay(250);
      
      while (!LcdTouch.getTouch(&x , &y));
    
  }
  
}

void clibriat()
{
    uint16_t calData[5];
    LcdTouch.fillScreen(TFT_BLACK);
  LcdTouch.setCursor(20, 0);
  LcdTouch.setTextFont(2);
  LcdTouch.setTextSize(1);
  LcdTouch.setTextColor(TFT_WHITE, TFT_BLACK);
  LcdTouch.println("Touch corners as indicated");
  LcdTouch.setTextFont(1);
  LcdTouch.println();
  LcdTouch.calibrateTouch(calData, TFT_MAGENTA, TFT_BLACK, 15);
  Serial.println();
  Serial.println();
  Serial.print("  uint16_t calData[5] = ");
  Serial.print("{ ");
  
  for (uint8_t i = 0; i < 5; i++)
  {
    Serial.print(calData[i]);
    
    if (i < 4) 
      Serial.print(", ");
  }
  
}
   
  
