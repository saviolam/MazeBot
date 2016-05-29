#pragma config(Sensor, S2,     rearSound,           sensorSoundDB)
#pragma config(Sensor, S3,     frontSonar,          sensorSONAR)
#pragma config(Motor,  motorB,          rightMotor,    tmotorNormal, PIDControl, )
#pragma config(Motor,  motorC,          leftMotor,     tmotorNormal, PIDControl, )
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
_________________________________Global variables_______________________________________
*/

int deadWall[5];

/*
____________________________________Functions___________________________________________
*/

void adVance(){

	nMotorEncoder[leftMotor] = 0;

	while ( nMotorEncoder[leftMotor] < 480 )
	{
		motor[leftMotor] = 10;
		motor[rightMotor] = 10;
	}
	  motor[leftMotor] = 0;
		motor[rightMotor] = 0;

		wait10Msec(100);
}

void scanWall(){

	for ( int i = 0; i < 4; ++i ){

		nMotorEncoder[leftMotor] = 0;

		while ( nMotorEncoder[leftMotor] < 101 )
		{
			motor[leftMotor] = 10;
			motor[rightMotor] = -10;
		}

	    motor[leftMotor] = 0;
		  motor[rightMotor] = 0;

		  wait10Msec(100);

		if ( SensorValue[frontSonar] > 10 )
	  {
      deadWall[i] = 0;
    }
    else
    {
      deadWall[i] = 1;
    }

	}
}

void turn(){

		nMotorEncoder[leftMot or] = 0;

		while ( nMotorEncoder[leftMotor] < 101 )
		{
			motor[leftMotor] = 10;
			motor[rightMotor] = -10;
		}

	    motor[leftMotor] = 0;
		  motor[rightMotor] = 0;

		  wait10Msec(100);

}

/*
_____________________________________Main Task__________________________________________
*/

task main()
{

	wait10Msec(100);
	while(SensorValue[rearSound] < 70){
	}

  while (1)
  {

	  scanWall();

	  if ( deadWall[1] == 1 ){
	  	turn();
	  }
	  else if ( deadWall[2] == 1 ){
	  	turn();
	  }
	  else if ( deadWall[3] == 1 ){
	  	turn();
	  }
	  else if ( deadWall[4] == 1 ){
	  	turn();
	  }
	  else{
	  	adVance();
	  }

	}
}
