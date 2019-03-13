#pragma config(Motor,  port1,           motorLEFT,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           motorCLAW,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           motorARM,      tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port4,           motorFOOT,     tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port5,           motorEXTENTION, tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port6,           motorLEFT_SHOOTER, tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port7,           motorRIGHT_SHOOTER, tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port8,           motoreMOVE_SHOOTER, tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port9,           motorROTATE,   tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port10,          motorRIGHT,    tmotorVex393_HBridge, openLoop)


/*------------------------------ AUTHOR ANDRZEJ SWIETEK -----------------------------*/
#define MAXacc 2
#define MINacc 0.5

//footUP,FootDOWN, EXTEND, -EXTEND, 

bool stopkaKlikniety = false;
bool extentionArmKlikniety = false;
	float moznikPrzyspieszenia=1;
void footDown()
{
					while(vexRT[Btn5U]==1) //wykonaj komende positive direction
					{
							motor[motorFOOT]=90;
							if (vexRT[Btn5U]==0){break;}
					}
					while(vexRT[Btn5U]==0) 
					{
							motor[motorFOOT]=0;
							if (vexRT[Btn5U]==1){break;}
					}
}



void footUp()
{
			while(vexRT[Btn5D]==1) //wykonaj komende negative direction
					{
							motor[motorFOOT]=-90;
							if (vexRT[Btn5D]==0){break;}
					}
					while(vexRT[Btn5D]==0) //nie wykonuj nic
					{
							motor[motorFOOT]=0;
							if (vexRT[Btn5D]==0){break;}
					}
}



void speedUp()
{
				if(vexRT[Btn6U]==1)
					{
						moznikPrzyspieszenia=MAXacc;
				  }

				  else if(vexRT[Btn6D]==1)
					{
						moznikPrzyspieszenia=MINacc;
				  }
				else
				  {
				  	moznikPrzyspieszenia=1;
				  }
}

task main()
{
	
  	motor[motorLEFT]=vexRT[Ch2];//tylko lewy ale do innego programu
  	motor[motorRIGHT]=vexRT[Ch3];//tylko prawya ale do innego prigramu tu nie przeszkadza
	while(true)
	{
//Przyspieszenie

speedUp();

						int lewy=(getJoystickValue(Ch2) + getJoystickValue(Ch3))/2;
						int prawy = (getJoystickValue(Ch2) - getJoystickValue(Ch3))/2;
						motor[motorLEFT]=lewy*moznikPrzyspieszenia;
						motor[motorRIGHT]=prawy*moznikPrzyspieszenia;



			if(vexRT[Btn7U]==1)
					{
					motor[port3]=90;
		 			}

		  		else if(vexRT[Btn7D]==1)
					{
						motor[port3]=-90;
		  		}
		  		else
		  			{
		  				motor[port3]=0;
		  			}


			if(vexRT[Btn7L]==1)
					{
						motor[motorCLAW]=90;
				  }

				  else if(vexRT[Btn7R]==1)
					{
						motor[motorCLAW]=-90;
				  }
				  else{motor[motorCLAW]=0;}


footUp();
footDown();
			
			

			

			



}//loop










}//The end of the program
