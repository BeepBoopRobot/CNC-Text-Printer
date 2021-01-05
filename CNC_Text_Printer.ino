#include <Stepper.h>

const int totalSteps = 200;
Stepper motor1(totalSteps,4,5,6,7);
Stepper motor2(totalSteps,8,9,10,11);

static const struct {const char letter, *data;} motorInstructs[] =
{
    { 'A', "beep"},
    { 'B', "boop"}//2l100, 1r30, 2r75, 1r50" }
};

void setup() {
  motor1.setSpeed(150);
  motor2.setSpeed(150);
  Serial.begin(9600);
  Serial.println("Enter your text");
  while(Serial.available() == 0);
}

void loop() {
  String input = "A";
  while(Serial.available() > 0)
  {
    input = Serial.readString();
  }

  Serial.println("Your String is " + input);
  Serial.println("Processing...");
  char mem[input.length()];
  input.toCharArray(mem,input.length()+1);
  
 // Serial.println(mem);
  Serial.println(encode( mem ));
  while(true);
  }

String encode(const char *string)
{
  size_t i, j;
  String morseWord = "";
  
  for( i = 0; string[i]; ++i )
  {
    for( j = 0; j < sizeof motorInstructs / sizeof *motorInstructs; ++j )
    {
      if( toupper(string[i]) == motorInstructs[j].letter )
      {
        morseWord += motorInstructs[j].data;
        break;
      }
    }
    morseWord += " "; //Add tailing space to seperate the chars
  }
  Serial.println(morseWord);
  return morseWord;  
}




