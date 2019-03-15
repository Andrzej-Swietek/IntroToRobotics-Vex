#pragma config(Motor,  port1,           motorLEFT,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           motorCLAW,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           motorARM,      tmotorNone, openLoop)
#pragma config(Motor,  port10,          motorRIGHT,    tmotorVex393_HBridge, openLoop)


/*------------------------------ For Peyton -----------------------------*/

void drivetrain()
{
	int left=(getJoystickValue(Ch2) + getJoystickValue(Ch3))/2;
	int right = (getJoystickValue(Ch2) - getJoystickValue(Ch3))/2;
	motor[motorLEFT]=left*acceleration;
	motor[motorRIGHT]=right*acceleration;	
}

short speedValue = 90;

task main()
{
	float acceleration=1;
	//setting joystic
  	motor[motorLEFT]=vexRT[Ch2];
  	motor[motorRIGHT]=vexRT[Ch3];
	while(true)
	{
//Acceleration
			if(vexRT[Btn6U]==1)
			{
				acceleration=2;
			}
			else if(vexRT[Btn6D]==1)
			{
				acceleration=0.5;
			}
			else
			{
				acceleration=1;
			}
//Getting Joystic Values and Drivetrain
				drivetrain();		
//Moving Arm
			if(vexRT[Btn7U]==1)
			{
				motor[port3]=speedValue*acceleration;
		 	}

		  	else if(vexRT[Btn7D]==1)
			{
				motor[port3]=-speedValue*acceleration;
		  	}
		 	else
			{
				motor[port3]=0;
			}


			
}










}
