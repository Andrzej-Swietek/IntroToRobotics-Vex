#pragma config(Motor,  port1,           motorLEFT,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           motorCLAW,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           motorARM,      tmotorNone, openLoop)
#pragma config(Motor,  port10,          motorRIGHT,    tmotorVex393_HBridge, openLoop)


/*------------------------------ AUTHOR ANDRZEJ SWIETEK -----------------------------*/




bool stopkaKlikniety = false;
bool extentionArmKlikniety = false;


task main()
{
		float moznikPrzyspieszenia=1;
  	motor[motorLEFT]=vexRT[Ch2];//tylko lewy ale do innego programu
  	motor[motorRIGHT]=vexRT[Ch3];//tylko prawya ale do innego prigramu tu nie przeszkadza
	while(true)
	{
//Przyspieszenie
			if(vexRT[Btn6U]==1)
					{
						moznikPrzyspieszenia=2;
				  }

				  else if(vexRT[Btn6D]==1)
					{
						moznikPrzyspieszenia=0.5;
				  }
				  else{moznikPrzyspieszenia=1;}

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
				  
				  
				  
				  //stopka true/false
			if(VexRT[Btn7D]==1)
				{
					if(!stopkaKlikniety)//jesli nie podniesione to podnies
						{
							stopkaKlikniety=true;
						}
						else if (stopkaKlikniety)
						{
						stopkaKlikniety=fasle;	// jak ta to opusc
						}
				}		  
				
					if(stopkaKlikniety) //wyko
				{
					
				}		  
}










}
