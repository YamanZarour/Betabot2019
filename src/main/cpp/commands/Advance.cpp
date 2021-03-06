/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Advance.h"
#include <Robot.h>


Advance::Advance(double targetDist) {
  mPIDptr = new LinearPID(targetDist);
  Requires(&Robot::m_driveTrain);
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void Advance::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Advance::Execute() {
  wPower = mPIDptr->ReturnPIDOutput();
  Robot::m_driveTrain.Drive(0,-wPower*0.25,0);
}

// Make this return true when this Command no longer needs to run execute()
bool Advance::IsFinished() { return mPIDptr->OnTarget(); }

// Called once after isFinished returns true
void Advance::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Advance::Interrupted() {}
