void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(115200); 

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
}

String command;

void loop() {
  
  if (Serial.available()){

    char c = Serial.read(); //get the character

    if (c == '\n'){
      
      parseCommand(command); 
      command = "";
      
    }
    else{

      command += c;
      
    }
  }
}

//parser function
void parseCommand(String com){

  String part1;
  String part2;
  /* 
  Examples of accepted commands
  PINON 3
  Pinoff 3
  */

  //split the string
  part1 = com.substring(0, com.indexOf(" ")); //command
  part2 = com.substring(com.indexOf(" ") + 1); //pin number

  if(part1.equalsIgnoreCase("pinon")){

    int pin = part2.toInt();
    digitalWrite(pin, HIGH); 
  }
  else if (part1.equalsIgnoreCase("pinoff")){

    int pin = part2.toInt();
    digitalWrite(pin, LOW);
  }

  //turn all LEDs off 
  else if (part1.equalsIgnoreCase("off")){
    int i = 3;
    while(i <= 5){
      digitalWrite(i, LOW);
      ++i;
    }
  }

  //default case
  else{
    Serial.println("COMMAND NOT RECOGNIZED");
  }
  
}

