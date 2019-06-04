#include <Tic.h>

TicI2C tic;

void waitForPosition(int32_t targetPosition)
{
  do
  {
    tic.resetCommandTimeout();
  } while (tic.getCurrentPosition() != targetPosition);
}

void setup()
{
  // Set up I2C.
  Wire.begin();

  //Setup push button pin.
  
  pinMode(7, INPUT_PULLUP);

  // Give the Tic some time to start up.
  delay(20);

  // Configure the Tic
  tic.setProduct(TicProduct::T825);
  tic.setStepMode(TicStepMode::Microstep32);
  tic.setCurrentLimit(400);
  tic.setDecayMode(TicDecayMode::Fast);
  tic.setMaxSpeed(64000000);
  tic.setMaxAccel(640000);
  tic.setMaxDecel(640000);

  // Zero the motor positioin and start the motor drive.
  tic.haltAndSetPosition(0);
  tic.exitSafeStart();
}

void loop()
{
  // Keep the tic board alive
  tic.resetCommandTimeout();
  
  if (digitalRead(7) == LOW)
  {
    // Tell the Tic to move four revolutions and wait for it to get there.
    tic.setTargetPosition(6400*4);
    waitForPosition(6400*4);

    // Tell the Tic to move back to zero and wait for it to get there.
    tic.setTargetPosition(0);
    waitForPosition(0);
  }
}
