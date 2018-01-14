/* initialize variables to act as time-keepers and variables to hold 
 * converted time units.
 */
  int second = 0, minute = 0, hour = 0, min_num = 0, hour_num = 0;

void setup() {
  // set inputs
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
  // set outputs
  for (int k = 1; k <= 12; k++){
    pinMode(k, OUTPUT);
  } 
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
}

void loop() {
  // initialize a variable to keep track of the program's place
  static unsigned long time_keep = 0;

  // add a second per every 1000 milliseconds
  if(millis() - time_keep == 1000){
    time_keep = millis();
    second++;
  }

  // add a minute per every 60 seconds and resets the second count
  if(second >= 60){
    minute++;
    second = 0;
  }

  // add an hour per every 60 minutes and resets the minute count
  if(minute >= 60){
    hour++;
    minute = 0;
  }

  /* puts minutes and hours into single-digit numbers to be easily
   *  displayed in either a "10"s or "1"s column.
   */
  min_num = minute % 10;
  hour_num = hour % 10;

  // first column minute LEDs
  if(min_num == 1 || min_num == 3 || min_num == 5 || min_num == 7 || min_num == 9){
    digitalWrite(2, HIGH);
  }
  else{
    digitalWrite(2, LOW);
  }
  if(min_num == 2 || min_num == 3 || min_num == 6 || min_num == 7){
    digitalWrite(3, HIGH);
  }
  else{
    digitalWrite(3, LOW);
  }
  if(min_num == 4 || min_num == 5 || min_num == 6 || min_num == 7){
    digitalWrite(4, HIGH);
  }
  else{
    digitalWrite(4, LOW);
  }
  if(min_num == 8 || min_num == 9){
    digitalWrite(5, HIGH);
  }
  else{
    digitalWrite(5, LOW);
  }

  // second column minute LEDs
  if((10 >= minute < 20) || (30 >= minute < 40) || (50 >= minute < 60)){
    digitalWrite(6, HIGH);
  }
  else{
    digitalWrite(6, LOW);
  }
  if(20 >= minute < 40){
    digitalWrite(7, HIGH);
  }
  else{
    digitalWrite(7, LOW);
  }
  if(40 >= minute < 60){
    digitalWrite(8, HIGH);
  }
  else{
    digitalWrite(8, LOW);
  }


  // first colum hour LEDs
  if(hour_num == 1 || hour_num == 3 || hour_num == 5 || hour_num == 7 || hour_num == 9){
    digitalWrite(9, HIGH);
  }
  else{
    digitalWrite(9, LOW);
  }
  if(hour_num == 2 || hour_num == 3 || hour_num == 6 || hour_num == 7){
    digitalWrite(10, HIGH);
  }
  else{
    digitalWrite(10, LOW);
  }
  if(hour_num == 4 || hour_num == 5 || hour_num == 6 || hour_num == 7){
    digitalWrite(11, HIGH);
  }
  else{
    digitalWrite(11, LOW);
  }
  if(hour_num == 8 || hour_num == 9){
    digitalWrite(12, HIGH);
  }
  else{
    digitalWrite(12, LOW);
  }
  
  // second column hour LEDs
  if(10 >= hour < 20){
    digitalWrite(14, HIGH);
  }
  else{
    digitalWrite(14, LOW);
  }
  if(20 >= hour < 24){
    digitalWrite(15, HIGH);
  }
  else{
    digitalWrite(15, LOW);
  }

  // add code for buttons here 

  // adds a minute per every time the button is pushed
  delay(1000); // rereads the button input every second
  if(digitalRead(A6) == 1){
    min_num = min_num + 1;
  }

  // adds an hour per every time the button is pushed
  delay(1000);
  if(digitalRead(A5) == 1){
    hour_num = hour_num + 1;
  }
  
}

