// Controller Decoder Functions

// *** VARIABLES *** //

// Incoming data packet; we set aside 20 bytes of data:
uint8_t packetBuffer[21];

// Size of the incoming data packet:
uint16_t packetSize = 0;

// Number of milliseconds LilyPad will listen for data from app before moving on:
uint16_t timeout = 500;
uint16_t origTimeout = 500;


// *** FUNCTIONS *** //

// Provide students with something like this:
uint8_t getBluetoothData()
{
  // Reset timer:
  origTimeout = timeout;

  // Reset size counter:
  packetSize = 0;

  // Set all bytes of 'packetBuffer' to 0:
  memset(packetBuffer, 0, 20);

  // Loop until the timer has run out:
  while (timeout--)
  {
    // If the incoming data packet is too big:
    if (packetSize >= 20)
    {
      // Exit the 'while' loop:
      break;
    }

    // If a complete Button data packet was received:
    if ((packetBuffer[1] == 'B') && (packetSize == 5))
    {
      // Exit the 'while' loop:
      break;
    }
    // If a complete Location data packet was received:
    if ((packetBuffer[1] == 'L') && (packetSize == 15))
    {
      // Exit the 'while' loop:
      break;
    }

    // If there is a data packet available:
    while (Serial.available())
    {
      // Store the incoming byte:
      char c = Serial.read();

      // If this is the first byte of the packet (indicated by '!'):
      if (c == '!')
      {
        // Reset the size counter to 0:
        packetSize = 0;
      }

      // Store the current byte in 'packetBuffer':
      packetBuffer[packetSize] = c;

      // Increment the size counter:
      packetSize++;

      // Reset the timer:
      timeout = origTimeout;
    }

    // If the timer has run out:
    if (timeout == 0)
    {
      // Exit the 'while' loop:
      break;
    }

    // Quick delay to be safe:
    delay(1);
  }

  // Null term:
  packetBuffer[packetSize] = 0;

  // If data was not successfully received:
  if (!packetSize)
  {
    // Return null:
    return 0;
  }

  // If the data packet is incomplete:
  if (packetBuffer[0] != '!')
  {
    // Return null:
    return 0;
  }

  // Perform a checksum - a type of error detection:
  uint8_t xsum = 0;
  uint8_t checksum = packetBuffer[packetSize - 1];
  for (uint8_t i = 0; i < packetSize - 1; i++)
  {
    xsum += packetBuffer[i];
  }
  xsum = ~xsum;

  // If checksume failed:
  if (xsum != checksum)
  {
    // Return null:
    return 0;
  }

  return packetSize;
}


// Cast the four bytes at the specified address to a float:
float parsefloat(uint8_t * buffer)
{
  float f = ((float *) buffer)[0];
  return f;
}


// Return your current latitude:
float myLatitude()
{
  // If Location data is received:
  if (packetBuffer[1] == 'L')
  {
    // Extract latitude data:
    return parsefloat(packetBuffer + 2);
  }
  else
  {
    return 0;
  }
}


// Return your current longitude:
float myLongitude()
{
  // If Location data is received:
  if (packetBuffer[1] == 'L')
  {
    // Extract longitude data:
    return parsefloat(packetBuffer + 6);
  }
  else
  {
    return 0;
  }
}


// Return your current altitude:
float myAltitude()
{
  // If Location data is received:
  if (packetBuffer[1] == 'L')
  {
    // Extract altitude data:
    return parsefloat(packetBuffer + 10);
  }
  else
  {
    return 0;
  }
}
