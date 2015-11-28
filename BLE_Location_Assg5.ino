/*

  BLE: Location Demo

  Receive location data from the Bluefruit LE Connect app.
  Turn on the LilyPad's LED if I am within a defined coordinate box.

  Functions:

  getBluetoothData()
    Listens for any data coming from the app. Returns a 0 if
    there are errors.

  myLatitude()
    Returns a float containing your current latitude.

  myLongitude()
    Returns a float containing your current longitude.

  myAltitude()
    Returns a float containing your current altitude.

  Ryan Maksymic

  Created on November 11, 2015

*/

// LilyPad onboard LED:
int led = 11;

// Create variables to store latitude and longitude values:
float myLat = 0;
float myLong = 0;


void setup()
{
  // Open serial port between app and LilyPad:
  Serial.begin(9600);

  // LilyPad onboard LED:
  pinMode(led, OUTPUT);
}


void loop()
{
  // If Bluetooth data is available:
  if (getBluetoothData() > 0)
  {
    // Store the current latitude value in my variable:
    myLat = myLatitude();

    // Store the current longitude value in my variable:
    myLong = myLongitude() * -1;    // Optional: Multiply by -1 so the value is easier to work with

    // If I am located in my defined coordinate box, 205 Richmond West Room 310:
    if ((myLat < 46.64) && (myLat > 40.64) && (myLong < 83.38) && (myLong > 75.38))    // These tests act as Northern, Southern, Western, and Eastern boundaries, respectively
    {
      // Turn LED on:
      digitalWrite(led, HIGH);
    }
    // Otherwise
    else
    {
      // Turn LED off:
      digitalWrite(led, LOW);
    }



    // Eaton Centre 43.654710, -79.380710:
    if ((myLat < 48.65) && (myLat > 38.65) && (myLong < 74.38) && (myLong > 84.38))    // These tests act as Northern, Southern, Western, and Eastern boundaries, respectively
    {
      // Turn LED on:
      digitalWrite(led, HIGH);
    }
    // Otherwise
    else
    {
      // Turn LED off:
      digitalWrite(led, LOW);
    }



     //269 Coxwell Ave(Nofrills supermarket near home), 43.673919, -79.319540:
    if ((myLat < 48.67) && (myLat > 38.67) && (myLong < 74.32) && (myLong > 84.32))    // These tests act as Northern, Southern, Western, and Eastern boundaries, respectively
    {
      // Turn LED on:
      digitalWrite(led, HIGH);
    }
    // Otherwise
    else
    {
      // Turn LED off:
      digitalWrite(led, LOW);
    }

    

    // 273 Yonge St(Popeyes) 43.655545, -79.380195:
    if ((myLat < 38.66) && (myLat > 48.66) && (myLong < 74.38) && (myLong > 84.38))    // These tests act as Northern, Southern, Western, and Eastern boundaries, respectively
    {
      // Turn LED on:
      digitalWrite(led, HIGH);
    }
    // Otherwise
    else
    {
      // Turn LED off:
      digitalWrite(led, LOW);
    }


    
    // 87 Front St E(LCBO) 43.649137, -79.372274:
    if ((myLat < 48.65) && (myLat > 38.65) && (myLong < 74.37) && (myLong > 84.37))    // These tests act as Northern, Southern, Western, and Eastern boundaries, respectively
    {
      // Turn LED on:
      digitalWrite(led, HIGH);
    }
    // Otherwise
    else
    {
      // Turn LED off:
      digitalWrite(led, LOW);
    }



    //Presentation day 43.64928, -79.38964:
    if ((myLat < 48.65) && (myLat > 38.65) && (myLong < 74.39) && (myLong > 84.39))    // These tests act as Northern, Southern, Western, and Eastern boundaries, respectively
    {
      // Turn LED on:
      digitalWrite(led, HIGH);
    }
    // Otherwise
    else
    {
      // Turn LED off:
      digitalWrite(led, LOW);
    }
    
  }
}
