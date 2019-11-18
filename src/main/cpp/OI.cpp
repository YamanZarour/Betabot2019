/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <frc/WPILib.h>
#include <commands/PistonPulse.h>

OI::OI() {
  mJoystickPtr = new frc::Joystick(kJoystick);
  m1ButtonPtr = new frc::JoystickButton(mJoystickPtr, k1Button);

  m1ButtonPtr->WhenPressed(new PistonPulse());
}

double OI::GetXJoystick() 
{
  return mJoystickPtr->GetRawAxis(kJoystickX) * GetSlider();
}

double OI::GetYJoystick() 
{
  return -mJoystickPtr->GetRawAxis(kJoystickY) * GetSlider();
}

double OI::GetZJoystick()
{
  return -mJoystickPtr->GetRawAxis(kJoystickZ) * GetSlider();
}

double OI::GetSlider()
{
  return (1-mJoystickPtr->GetRawAxis(kJoystickSlider))/2;
}