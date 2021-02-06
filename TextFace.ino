#include <Watchy.h>
#include <Fonts/FreeMonoOblique24pt7b.h>

//arrays holding the time words
char* const ones[] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
char* const tens[] = {"Ten","Eleven","Twelve","Thirt","Four","Fith","Six","Seven","Eight","Nine"};

//extension of the Watchy class
class FirstWatchFace : public Watchy
{
  public:
  //converts the current hour number into text and prints it to the display
    void hourToText(int inputHour)
    {
      //SINGLE DIGIT HOURS
      if(inputHour < 10) //prints out single digit minutes
      {
        display.println(" ");
        display.println(ones[inputHour%10]);
      }
      //TEN HOURS
      else if(inputHour >=10 && inputHour < 13) //deals with the special cases in the teens 10 11 12
      {
        if(inputHour == 10)
        {
          display.println(" ");
          display.println("Ten");
        }
        else if(inputHour == 11)
        {
          display.println(" ");
          display.println("Eleven");
        }
        else
        {
          display.println(" ");
          display.println("Twelve");
        }
      }
      else if(inputHour >= 13 && inputHour < 20)
      {
        int secondPlace = inputHour%10; // finds how far from ten it is and chooses that number from the array
        //display.println("Ten");
        display.println(tens[secondPlace]);
        display.println("Teen");
      }
      //TWENTY HOURS
      else if(inputHour >= 20 && inputHour < 25)
      {
        if(inputHour == 20)
        {
          display.println("Twenty");
        }
        else
        {
          int secondPlace = inputHour%20;
          display.println("Twenty");
          display.println(ones[secondPlace]);
        }
      }
    }


  //converts the current minute to text and prints it to the display
    void minuteToText(int inputMinute)
    {
      //ZERO MINUTES
      if(inputMinute == 0)
      {
        display.println("o'");
        display.println("Clock");
      }
      else if(inputMinute < 10) //prints out single digit minutes
      {
        display.println("o'");
        display.println(ones[inputMinute%10]);
      }
      //TEN MINUTES
      else if(inputMinute >=10 && inputMinute < 13) //deals with the special cases in the teens 10 11 12
      {
        if(inputMinute == 10)
        {
          display.print("Ten");
        }
        else if(inputMinute == 11)
        {
          display.print("Eleven");
        }
        else
        {
          display.print("Twelve");
        }
      }
      else if(inputMinute >= 13 && inputMinute < 20) // rest of the teen numbers
      {
        int secondPlace = inputMinute%10; // finds how far from ten it is and chooses that number from the array
        //display.println("Ten");
        display.println(tens[secondPlace]);
        display.println("Teen");
      }
      //TWENTY MINUTES
      else if(inputMinute >= 20 && inputMinute < 30)
      {
        if(inputMinute == 20)
        {
          display.println("Twenty");
        }
        else
        {
          int secondPlace = inputMinute%20;
          display.println("Twenty");
          display.println(ones[secondPlace]);
        }
      }
      //THIRTY MINUTES
      else if(inputMinute >= 30 && inputMinute < 40)
      {
        if(inputMinute == 30)
        {
          display.println("Thirty");
        }
        else
        {
          int secondPlace = inputMinute%30;
          display.println("Thirty");
          display.println(ones[secondPlace]);
        }
      }
      //FORTY MINUTES
      else if(inputMinute >= 40 && inputMinute < 50)
      {
        if(inputMinute == 40)
        {
          display.println("Forty");
        }
        else
        {
          int secondPlace = inputMinute%40;
          display.println("Forty");
          display.println(ones[secondPlace]);
        }
      }
      //FIFTY MINUTES
      else if(inputMinute >= 50 && inputMinute < 60)
      {
        if(inputMinute == 50)
        {
          display.println("Fifty");
        }
        else
        {
          int secondPlace = inputMinute%50;
          display.println("Fifty");
          display.println(ones[secondPlace]);
        }
      }
    }

    
    //overriden drawWatchFace function
    void drawWatchFace()
    {
      display.setFont(&FreeMonoOblique24pt7b);
      display.setCursor(1,34);
      hourToText(currentTime.Hour);
      minuteToText(currentTime.Minute);
    }

};

FirstWatchFace m;

void setup() {
  // put your setup code here, to run once:
  m.init();
}

void loop() {
  // put your main code here, to run repeatedly:

}
