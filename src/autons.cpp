#include "main.h"



const int DRIVE_SPEED = 110;

const int TURN_SPEED = 90;

const int SWING_SPEED = 90;



// Ports for functions below

pros::Motor right_intake(5);

pros::Motor left_intake(-4);

pros::ADIDigitalOut horiz_left('G', false);

pros::ADIDigitalOut horiz_right('H', false);

pros::Motor kicker(11);



pros::Rotation rotation_sensor(8);



pros::Motor left1(-17);

pros::Motor left2(-18);

pros::Motor left3(-19);



pros::Motor right1(8);

pros::Motor right2(7);

pros::Motor right3(6);





// Intake

void runIntake()

{

  right_intake.move_velocity(-600);

  left_intake.move_velocity(600);

}



void stopIntake(){

  right_intake.move_velocity(0);

  left_intake.move_velocity(0);

}



void runOuttake()

{

  right_intake.move_velocity(600);

  left_intake.move_velocity(-600);

}



// Wings

void wingsUp()

{

  wings.set_value(true);

}



void wingsDown()

{

  wings.set_value(false);

}



// Horizontal Wings

void horiz_wingsDown()

{

  horiz_left.set_value(true);

  horiz_right.set_value(true);

}

void IntakeUp(){

  horiz_left.set_value(true);
}

void IntakeDown(){
  horiz_left.set_value(false);


}



void horiz_wingsUp()

{

  horiz_left.set_value(false);

  horiz_right.set_value(false);

}

void DoinkerDown()

{

  horiz_right.set_value(true);

  

}

void DoinkerUp()

{

  horiz_right.set_value(false);

  

}



void horiz_leftDown()

{

  horiz_left.set_value(true);

}



void horiz_leftUp()

{

  horiz_left.set_value(false);

}



void horiz_rightDown()

{

  horiz_right.set_value(true);

}



void horiz_rightUp()

{

  horiz_right.set_value(false);

}



// Kicker

void runKicker()

{

  // Max Speed

  kicker.move_velocity(105);

}



void stopKicker()

{

  kicker.move_velocity(0);

}



// Braking

void chassisBrake(pros::motor_brake_mode_e_t M)

{

  left1.set_brake_mode(M);

  left2.set_brake_mode(M);

  left3.set_brake_mode(M);



  right1.set_brake_mode(M);

  right2.set_brake_mode(M);

  right3.set_brake_mode(M);

}

//Chassis Side Velocity Functions(used for swerve)

void swerve_left(int left_power) {
  left1.move_velocity(left_power);
  left2.move_velocity(left_power);
  left3.move_velocity(left_power);
}

void swerve_right(int Right_power) {
  right1.move_velocity(Right_power);
  right2.move_velocity(Right_power);
  right3.move_velocity(Right_power);
}



void RunSwerve(int x, int y){
  swerve_left(x);
  swerve_right(y);
  

}


// run at the start of each auton

void auto_initialize()

{

  kicker.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

} // comment trap //*/



// AUTONS:



void auton_close_wp()

{

  auto_initialize();

  chassis.set_drive_pid(8.4, 30, true);

  runKicker();

  pros::delay(1750);

  kicker.move_velocity(-127);

  pros::delay(560);

  chassis.set_turn_pid(20, 40);

  chassis.wait_drive();

  stopKicker();

  wings.set_value(true);

  chassis.set_drive_pid(-43, 65, true);
  

  

  chassis.wait_drive();

  pros::delay(50);

  wings.set_value(false);

  pros::delay(50);

  chassis.wait_drive();

  chassis.set_drive_pid(8, 80, true);

  chassis.wait_drive();

  chassis.set_turn_pid(142, 100);

  runIntake();

  pros::delay(100);

  chassis.wait_drive();

  chassis.set_drive_pid(25, 80, true);

  chassis.wait_drive();

  pros::delay(100);

  chassis.set_drive_pid(-15, 80, true);

  pros::delay(300);

  stopIntake;

  chassis.wait_drive();

  chassis.set_turn_pid(201, 110);

  runIntake();

  chassis.wait_drive();

  chassis.set_drive_pid(21.85, 50, true);

  chassis.wait_drive();

  pros::delay(300);

  chassis.set_drive_pid(-15.75, 70, true);

  chassis.wait_drive();

  chassis.set_turn_pid(177, 80);

  chassis.wait_drive();

  chassis.set_drive_pid(19.79, 50, true);

  chassis.wait_drive();

  pros::delay(300);

  chassis.set_drive_pid(-23, 50, true);

  chassis.wait_drive();

  chassis.set_turn_pid(300, 110);

  chassis.wait_drive();

  chassis.set_drive_pid(28, 70, true);

  chassis.wait_drive();

  

}



void auton_close_wp_safe()

{

 auto_initialize();
 
 
 
 
  wingsUp();
  chassis.set_turn_pid(-30,90);
  chassis.wait_drive();
  chassis.set_drive_pid(10.6,70,true);
  chassis.wait_drive();
  pros::delay(20);
  horiz_leftDown();
  pros::delay(80);
  runIntake();
  pros::delay(550);
  stopIntake();
  chassis.set_drive_pid(-9.3,127,true);
  chassis.wait_drive();
  chassis.set_turn_pid(6,60);
  chassis.wait_drive();
  chassis.set_drive_pid(18,60,true);
  chassis.wait_drive();
  chassis.set_drive_pid(-2.5,60,true);
  chassis.wait_drive();
  chassis.set_turn_pid(88.3,60);
  //chassis.set_swing_pid(RIGHT_SWING,-80,110);
  chassis.wait_drive();
  blocker.move_velocity(300);
  chassis.set_drive_pid(4,80,true);
  chassis.wait_drive();
  kicker.move_velocity(600);
  pros::delay(800);
  kicker.move_velocity(-600);
  blocker.move_velocity(-600);
  pros::delay(600);
  chassis.set_drive_pid(-7,80,true);
  chassis.wait_drive();
  chassis.set_turn_pid(50,90);
  chassis.wait_drive();
  chassis.set_drive_pid(-34,50,true);
  stopKicker();
  chassis.wait_drive();
  wingsDown();
  pros::delay(50);
  wingsUp();
  pros::delay(100);
  wingsDown();
  pros::delay(450);
  runIntake();
  pros::delay(300);
  chassis.set_turn_pid(177,70);
  chassis.wait_drive();
  chassis.set_drive_pid(25,90,true);
  chassis.wait_drive();
  pros::delay(400);
  chassis.set_turn_pid(250,90);
  chassis.wait_drive();
  chassis.set_drive_pid(17.7,127,true);
  chassis.wait_drive();
  pros::delay(100);
  chassis.set_drive_pid(-7,80,true);
  chassis.wait_drive();
  chassis.set_turn_pid(-24,90);
  chassis.wait_drive();
  chassis.set_drive_pid(20,80,true);

  /*chassis.set_turn_pid(-80,90);
  chassis.wait_drive();
  chassis.set_drive_pid(7.5,90,true);
  chassis.wait_drive();
  pros::delay(200);
  chassis.set_swing_pid(RIGHT_SWING,-18,110);
  chassis.wait_drive();
  chassis.set_drive_pid(25,127,true);
  chassis.wait_drive();
  */

  // SKILLS AUTON AS OF NOW

  /*chassis.set_drive_pid(-0.5, 5, true);

  kicker.move_velocity(-127);

  pros::delay(500);

  chassis.set_drive_pid(5,10,true);

  chassis.wait_drive();

  kicker.move_velocity(127);

  chassis.set_drive_pid(-5,10,true)

  chassis.wait_drive();

  chassis.set_turn_pid(90,90);

  chassis.wait_drive();

  chassis.set_drive_pid()

*/
/*
  // Puts the mogule up

  wingsDown();

  pros::delay(200);

  // Moving backward to align with the stake to put the ring in

  chassis.set_drive_pid(-4, 6, true);

  chassis.wait_drive();

  // Outtaking the ring onto the stake

  runOuttake();

  pros::delay(500);

  // stops the intake

  stopIntake();

  // Moving forward from the stake to go to the first ring

  chassis.set_drive_pid(4, 10, true);

  chassis.wait_drive();

  chassis.set_turn_pid(90, TURN_SPEED);

  // turning 90 degrees to face the mogo clamp

  chassis.wait_drive();

  chassis.set_drive_pid(-15, 30, true);

  chassis.wait_drive();

  // Clamps on to the mogule

  wingsUp();



  pros::delay(100);

  chassis.set_drive_pid(4, 40, true);

  chassis.wait_drive();

  // turn the robot and proceeds to run the outtake and and take in the rings

  chassis.set_turn_pid(0, TURN_SPEED);

  chassis.wait_drive();

  runOuttake();

  chassis.set_drive_pid(13, 60, true);

  pros::delay(500);

  chassis.wait_drive();

  chassis.set_turn_pid(90, TURN_SPEED);

  chassis.wait_drive();

  chassis.set_drive_pid(15, 60, true);

  pros::delay(500);

  chassis.wait_drive();

  chassis.set_turn_pid(180, TURN_SPEED);

  chassis.wait_drive();

  chassis.set_drive_pid(20, 30, true);

  chassis.wait_drive();

  pros::delay(100);

  chassis.set_drive_pid(-10, 100, true);

  chassis.wait_drive();

  chassis.set_turn_pid(160, TURN_SPEED);

  chassis.wait_drive();

  chassis.set_drive_pid(10, 70, true);

  chassis.wait_drive();

  pros::delay(50);

  stopIntake();

  chassis.set_turn_pid(-30, TURN_SPEED);

  runOuttake();

  pros::delay(100);

  stopIntake();

  chassis.set_drive_pid(-5, 70, true);

  chassis.wait_drive();

  // releases the mogo into the postive side

  wingsDown();

  pros::delay(70);

  // Moves forward after placing the mogul and turn to the left to go get the next mogul

  chassis.set_drive_pid(5, 70, true);

  chassis.wait_drive();

  // Turning before it goes to the other mogo goal 

  chassis.set_turn_pid(90, TURN_SPEED);

  chassis.wait_drive();

  chassis.set_drive_pid(-50, 127, true);

  chassis.wait_drive();

  chassis.set_drive_pid(-5, 30, true);

  chassis.wait_drive();

  // Clamps on to the mogo goal

  wingsUp();

  pros::delay(100);

  chassis.set_drive_pid(5, 30, true);

  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);

  chassis.wait_drive();

  runOuttake();

  chassis.set_drive_pid(14, 80, true);

  pros::delay(600);

  chassis.wait_drive();

  chassis.set_turn_pid(-90, 127);

  chassis.wait_drive();

  chassis.set_drive_pid(10, 80, true);

  chassis.wait_drive();

  pros::delay(400);

  chassis.set_turn_pid(180, TURN_SPEED);

  chassis.wait_drive();

  chassis.set_drive_pid(8, 40, true);

  chassis.wait_drive();

  runOuttake();

  chassis.wait_drive();
*/
}



  void auton_blue_neg_qual_risk_wp()

  {

  auto_initialize();
  /*
  wingsUp();
  DoinkerDown();
  pros::delay(100);
  DoinkerUp();
  chassis.set_turn_pid(30,95);
  chassis.wait_drive();
  chassis.set_drive_pid(10.6,70,true);
  chassis.wait_drive();
  //pros::delay(20);
  //horiz_leftDown();
  pros::delay(5);
  runIntake();
  pros::delay(400);
  chassis.set_drive_pid(8,60,true);
  chassis.wait_drive();
  pros::delay(200);
  stopIntake();
  // Orignial chassis.set_drive_pid(-9.3,127,true);
  chassis.set_drive_pid(-17.3,100,true);
  chassis.wait_drive();
  chassis.set_turn_pid(-6,60);
  chassis.wait_drive();
  chassis.set_drive_pid(19,90,true);
  chassis.wait_drive();
  chassis.set_drive_pid(-2.6,90,true);
  chassis.wait_drive();
  chassis.set_turn_pid(-90,70);
  //chassis.set_swing_pid(RIGHT_SWING,-80,110);
  chassis.wait_drive();
  blocker.move_velocity(-300);
  chassis.set_drive_pid(1.2,90,true);
  chassis.wait_drive();
  kicker.move_velocity(600);
  pros::delay(800);
  kicker.move_velocity(-600);
  pros::delay(600);
  chassis.set_drive_pid(-4.8,90,true);
  chassis.wait_drive();
  chassis.set_turn_pid(-50.5,90);
  chassis.wait_drive();
  chassis.set_drive_pid(-31,127,true);
  stopKicker();
  chassis.wait_drive();
  chassis.set_drive_pid(-3,24,true);
  chassis.wait_drive();
  //pros::delay(70);
  wingsDown();
  pros::delay(150);
  runIntake();
  pros::delay(300);
  chassis.set_turn_pid(-191,70);
  chassis.wait_drive();
  chassis.set_drive_pid(24,90,true);
  chassis.wait_drive();
  pros::delay(120);
  chassis.wait_drive();
  //chassis.set_turn_pid(97.4,90);
  chassis.set_turn_pid(-254.6,90);

  chassis.wait_drive();


   
  chassis.set_drive_pid(13,90,true);
  chassis.wait_drive();
  pros::delay(100);
  runIntake();
  chassis.set_drive_pid(-9,90,true);
  chassis.wait_drive();
  //chassis.set_turn_pid(74,90);
  chassis.set_turn_pid(-278,90);
  
  chassis.wait_drive();
  chassis.set_drive_pid(11.3,90,true);
  chassis.wait_drive();
  
  //chassis.set_drive_pid(-7,80,true);
  //chassis.wait_drive();
  chassis.set_turn_pid(-350,90);
  chassis.wait_drive();
  //kicker.move_absolute(2190, 200);
  chassis.set_drive_pid(9,80,true);
  chassis.wait_drive();
  chassis.set_turn_pid(-330,90);
  */
  
  horiz_leftDown();
  wingsUp();
  RunSwerve(170,180);
  pros::delay(480);
  RunSwerve(130,75);
  pros::delay(425);
  DoinkerDown();
  pros::delay(50);
  RunSwerve(0,0);
  pros::delay(5);
  //RunSwerve(-130,-75);
  //pros::delay(300);
  chassis.wait_drive();

  //after doinker pull from rush
  //pros::delay(380);
  chassis.set_drive_pid(-7,90, true);
  chassis.wait_drive();
  chassis.set_turn_pid(70,90);
  chassis.wait_drive();
  DoinkerUp();
  chassis.set_drive_pid(-8.5,95,true);
  chassis.wait_drive();
  //old place doinker up went 
  wingsDown();
  runIntake();
  pros::delay(400);
  chassis.set_turn_pid(85,70);
  chassis.wait_drive();
  pros::delay(100);
  
  wingsUp();
  //stopIntake();
  
  //right_intake.move_velocity(-200);
  //left_intake.move_velocity(90);
  chassis.set_drive_pid(19.5,90,true);
  chassis.wait_drive();
  pros::delay(150);
  stopIntake();
  chassis.set_turn_pid(170,70);
  chassis.wait_drive();
  chassis.set_drive_pid(-12,70,true);
  chassis.wait_drive();
  pros::delay(200);

  wingsDown();
  pros::delay(300);
  runIntake();
  pros::delay(600);
  chassis.set_turn_pid(-130,60);
  chassis.wait_drive();
  //horiz_leftUp();
  stopIntake();
  chassis.set_drive_pid(50.13694,100,true);
  chassis.wait_drive();
  DoinkerDown();
  //horiz_leftDown();
  pros::delay(650);
  chassis.set_turn_pid(-250,90);
  DoinkerUp(); 
  chassis.wait_drive();
  chassis.set_drive_pid(49,90,true);
  chassis.wait_drive();
  stopIntake();
  DoinkerDown();
  chassis.set_turn_pid(-0,90);
  chassis.wait_drive();
  chassis.set_drive_pid(5,80,true);
  chassis.wait_drive();
  DoinkerUp();
  
  
  


//

  
}



void auton_far_elim()

{
 
  auto_initialize();
  
  horiz_leftDown();
  wingsUp();
  /* THIS IS THE ORGINAL PUSH WHICH WORKED BUT SLOW
  chassis.set_drive_pid(37,127,true);
  chassis.wait_drive();
  chassis.wait_drive(10,50,true);
  */
  chassis.wait_drive();
  pros::delay(150);
  DoinkerDown(); 
  pros::delay(100);
  chassis.set_turn_pid(-45,90);
  chassis.wait_drive();
  chassis.set_drive_pid(-4,95,true);
  chassis.wait_drive();
  DoinkerUp();
  chassis.set_drive_pid(-15,95,true);
  chassis.wait_drive();
  wingsDown();
  runIntake();
  pros::delay(400);
  chassis.set_turn_pid(-80,70);
  chassis.wait_drive();
  pros::delay(100);
  wingsUp();
  //stopIntake();
  //right_intake.move_velocity(-200);
  //left_intake.move_velocity(90);
  chassis.set_drive_pid(19.9,90,true);
  chassis.wait_drive();
  pros::delay(150);
  
  stopIntake();
  chassis.set_turn_pid(165,70);
  chassis.wait_drive();
  chassis.set_drive_pid(-12,70,true);
  chassis.wait_drive();
  pros::delay(200);

  wingsDown();
  pros::delay(300);
  runIntake();
  pros::delay(600);
  chassis.set_turn_pid(143.4,60);
  chassis.wait_drive();
  //horiz_leftUp();
  chassis.set_drive_pid(48.6,80,true);
  chassis.wait_drive();
  stopIntake();
  pros::delay(100);
  DoinkerDown();
  //horiz_leftDown();
  pros::delay(650);
  //chassis.set_turn_pid(115,60);
  chassis.wait_drive();
  pros::delay(100);
  
  //chassis.set_turn_pid(110,60);
  chassis.set_swing_pid(LEFT_SWING,45,SWING_SPEED);
  
  chassis.wait_drive();
  runIntake();
  DoinkerUp();
  chassis.set_drive_pid(10,70,true);
  chassis.wait_drive();
  pros::delay(400);
  chassis.set_turn_pid(20,60);
  chassis.wait_drive();
  chassis.set_drive_pid(18,70,true);
  chassis.wait_drive();





  //chassis.set_turn_pid(250,90);
  //CORNER PUSH TAKEN OUT FOR SAFE
  /*
  chassis.wait_drive();
  chassis.set_drive_pid(49,90,true);
  chassis.wait_drive();
  stopIntake();
  DoinkerDown();
  chassis.set_turn_pid(0,90);
  chassis.wait_drive();
  chassis.set_drive_pid(5,80,true);
  chassis.wait_drive();
  DoinkerUp();
  */


  

  

 
  
  




  /*

    // Blue Elim auto Mogo Rush

    // Small drive back

    chassis.set_drive_pid(-10, 60, true);

    chassis.wait_drive();

    // Turns left to avoid rings

    chassis.set_swing_pid(LEFT_SWING, -20, SWING_SPEED);

    chassis.wait_drive();

    // Drives back to corner

    chassis.set_drive_pid(-25, 60, true);
,
    chassis.wait_drive();

    // Turns to angle of Mogo

    chassis.set_swing_pid(RIGHT_SWING, 35, SWING_SPEED);

    // Opens Clamp

    wingsDown();

    chassis.wait_drive();

    // Drives back to Mogo

    chassis.set_drive_pid(-14.2, 50, true);

    chassis.wait_drive();

    // Clamps Mogo

    wingsUp();

    pros::delay(400);

    // Intake the Rings onto the Mogo

    runIntake();

    chassis.wait_drive();

    // Drives Forward a little bit to get in clear position.

    chassis.set_drive_pid(9, 50, true);

    chassis.wait_drive();

    // Turns towards the corner

    chassis.set_turn_pid(10, 127);

    chassis.wait_drive();

    // Drives towards the corner

    chassis.set_drive_pid(31, 110, true);

    chassis.wait_drive();

    // Turns to the ring stack

    chassis.set_turn_pid(180, TURN_SPEED);

    chassis.wait_drive();

    // Releases Mogo

    wingsDown();

    chassis.wait_drive();

    stopIntake();

    chassis.wait_drive();

    runIntake();

    chassis.set_drive_pid(27, 110, true);

    chassis.wait_drive();

    chassis.set_turn_pid(270, TURN_SPEED);

    chassis.wait_drive();

    chassis.set_drive_pid(14.2, 110, true);

    chassis.wait_drive();

    pros::delay(50);

    stopIntake();

    chassis.set_turn_pid(90, TURN_SPEED);

    chassis.wait_drive();

    chassis.set_drive_pid(-21, 60, true);

    chassis.wait_drive();

    wingsUp();

    pros::delay(300);

    runIntake();

    pros::delay(400);

    chassis.set_turn_pid(210, 50);

    chassis.wait_drive();

    pros::delay(100);

    chassis.set_drive_pid(-30, 100, true);

/*

  /*chassis.set_turn_pid(-35,TURN_SPEED);

  chassis.wait_drive();

  runIntake();

  pros::delay(100);

  chassis.set_drive_pid(35,60,true);

  chassis.wait_drive();

  pros::delay(300);

  chassis.set_turn_pid(0,TURN_SPEED);

  chassis.wait_drive();

  chassis.set_drive_pid(35,60,true);

  */

}



void auton_blue_neg_qual_SAFE_wp()


{

  auto_initialize();
  wingsDown();
  DoinkerDown();
  pros::delay(100);
  DoinkerUp();
  chassis.set_turn_pid(30,95);
  chassis.wait_drive();
  chassis.set_drive_pid(10.6,70,true);
  chassis.wait_drive();
  //pros::delay(20);
  //horiz_leftDown();
  pros::delay(5);
  runIntake();
  pros::delay(400);
  chassis.set_drive_pid(8,60,true);
  chassis.wait_drive();
  pros::delay(300);
  stopIntake();
  // Orignial chassis.set_drive_pid(-9.3,127,true);
  chassis.set_drive_pid(-17.3,100,true);
  chassis.wait_drive();
  chassis.set_turn_pid(-6,60);
  chassis.wait_drive();
  chassis.set_drive_pid(19,90,true);
  chassis.wait_drive();
  chassis.set_drive_pid(-2.6,90,true);
  chassis.wait_drive();
  chassis.set_turn_pid(90,70);
  //chassis.set_swing_pid(RIGHT_SWING,-80,110);
  chassis.wait_drive();
  chassis.set_drive_pid(-1.2,90,true);
  chassis.wait_drive();
  runIntake();
  pros::delay(700);
  stopIntake();
  chassis.set_drive_pid(4.8,90,true);
  chassis.wait_drive();
  chassis.set_turn_pid(175,90);
  chassis.wait_drive();
  chassis.set_drive_pid(21,100,true);
  runIntake();
  pros::delay(150);
  stopIntake();
  chassis.wait_drive();
  chassis.set_turn_pid(-86,90);
  chassis.wait_drive();
  chassis.set_drive_pid(-15,90,true);
  chassis.wait_drive();
  chassis.set_drive_pid(-4,24,true);
  //pros::delay(70);
  wingsUp();
  pros::delay(150);
  runIntake();
  pros::delay(300);
  chassis.set_turn_pid(-191,70);
  chassis.wait_drive();
  chassis.set_drive_pid(24,90,true);
  chassis.wait_drive();
  pros::delay(120);
  chassis.wait_drive();
  chassis.set_turn_pid(-320,90);
  chassis.wait_drive();
  chassis.set_drive_pid(24,90,true);
  //chassis.set_turn_pid(97.4,90);
  /*chassis.set_turn_pid(-254.6,90);

  chassis.wait_drive();


   
  chassis.set_drive_pid(13,90,true);
  chassis.wait_drive();
  pros::delay(100);
  runIntake();
  chassis.set_drive_pid(-9,90,true);
  chassis.wait_drive();
  
  //chassis.set_turn_pid(74,90);
  chassis.set_turn_pid(-278,90);
  
  chassis.wait_drive();
  chassis.set_drive_pid(11.3,90,true);
  chassis.wait_drive();
  
  //chassis.set_drive_pid(-7,80,true);
  //chassis.wait_drive();
  chassis.set_turn_pid(-350,90);
  chassis.wait_drive();
  */
  //kicker.move_absolute(2190, 200);
  
  
  /*
  chassis.set_turn_pid(18,90);
  chassis.wait_drive();
  chassis.set_drive_pid(24,40,true);
  chassis.wait_drive();
*/

  //2nd PART OF OLD CODE 12/20/2024 GOING TO CENTER RINGS FIRST
  /*
  chassis.set_drive_pid(22,127,true);
  chassis.wait_drive();
  chassis.set_turn_pid(172,70);
  chassis.wait_drive();
  chassis.set_drive_pid(12,127,true);
  pros::delay(100);
  chassis.wait_drive();
  //chassis.set_swing_pid(RIGHT_SWING,260,90);
  chassis.set_turn_pid(272,90);
  chassis.wait_drive();
  chassis.set_drive_pid(18,127,true);
  pros::delay(300);
  chassis.wait_drive();
chassis.set_turn_pid(382,70);
  chassis.wait_drive();
  chassis.set_drive_pid(28,127,true);
*/





  






  
  
  





  /* SUMDA PEN 12/16/24 NEWER ONE THAN LAST TIME
  wingsDown();
  chassis.set_drive_pid(11,127,true);
  chassis.wait_drive();
  chassis.set_turn_pid(90,90);
  chassis.wait_drive();
  chassis.set_drive_pid(-0.2,100,true);
  chassis.wait_drive();
  runIntake();
  pros::delay(700);
  stopIntake();
  chassis.set_drive_pid(4,100,true);
  chassis.wait_drive();
  horiz_leftDown();
  runIntake();
  pros::delay(260);
  stopIntake();
  chassis.set_turn_pid(-53,90);
  chassis.wait_drive();
  chassis.set_drive_pid(-35,100,true);
  chassis.wait_drive();
  wingsUp();
  pros::delay(400);
  chassis.set_turn_pid(180,60);
  chassis.wait_drive();
  runIntake();
  chassis.set_drive_pid(28,127,true);
  chassis.wait_drive();
  chassis.set_turn_pid(110,90);
  chassis.wait_drive();
  chassis.set_drive_pid(15,127,true);
  chassis.wait_drive();
  chassis.set_turn_pid(80,90);
  chassis.wait_drive();
  chassis.set_drive_pid(13,127,true);
  chassis.wait_drive();
  chassis.set_turn_pid(-5,90);
  chassis.wait_drive();
  chassis.set_drive_pid(55,127,true);
*/



  








  /*runIntake();
  chassis.set_drive_pid(-8,30,true);
  chassis.wait_drive();
  stopIntake();
  chassis.set_turn_pid(32.5,90);
  runIntake();
  chassis.wait_drive();
  chassis.set_drive_pid(35,125,true);
  chassis.wait_drive();
  chassis.set_drive_pid(5,30,true);
  chassis.wait_drive();
  pros::delay(100);
  stopIntake();
  chassis.set_swing_pid(LEFT_SWING,45,SWING_SPEED);
  chassis.wait_drive();
*/


/*
  horiz_wingsDown();
  chassis.set_drive_pid(8, 30, true);

  runKicker(); 

  pros::delay(1750);

  kicker.move_velocity(-127);

  pros::delay(560);

  chassis.set_turn_pid(-20, 40);

  chassis.wait_drive();

  wings.set_value(true);

  stopKicker();

  chassis.set_drive_pid(-43, 65, true);

  chassis.wait_drive();

  pros::delay(50);

  wings.set_value(false);

  pros::delay(50);

  chassis.wait_drive();

  chassis.set_drive_pid(7, 80, true);

  chassis.wait_drive();

  chassis.set_turn_pid(-145, 100);

  runIntake();

  pros::delay(100);

  chassis.wait_drive();

  chassis.set_drive_pid(25, 80, true);

  chassis.wait_drive();

  pros::delay(100);

  chassis.set_drive_pid(-15, 80, true);

  pros::delay(300);

  stopIntake;

  chassis.wait_drive();

  chassis.set_turn_pid(-205, 110);

  runIntake();

  chassis.wait_drive();

  chassis.set_drive_pid(21.85, 50, true);

  chassis.wait_drive();

  pros::delay(300);

  chassis.set_drive_pid(-15.75, 70, true);

  chassis.wait_drive();

  chassis.set_turn_pid(-180, 80);

  chassis.wait_drive();

  chassis.set_drive_pid(20.34, 50, true);

  chassis.wait_drive();

  pros::delay(300);

  chassis.set_drive_pid(-23.56, 50, true);

  chassis.wait_drive();

  chassis.set_turn_pid(-312, 110);

  chassis.wait_drive();

  chassis.set_drive_pid(28, 70, true);

  chassis.wait_drive();
*/
//LAST WORKING CLOSE ELIM CODE ON 12/16/2024 $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$4
/*
wingsUp();
runIntake();
horiz_leftDown();//Intake Piston 
pros::delay(500);
chassis.set_drive_pid(3,50,true);
chassis.wait_drive();
pros::delay(300);
stopIntake();
chassis.set_drive_pid(-8,50,true);
chassis.wait_drive();
kicker.move_velocity(150);
chassis.set_turn_pid(-75,60);
chassis.wait_drive();
chassis.set_drive_pid(17,125,true);
chassis.wait_drive();
pros::delay(400);
kicker.move_velocity(-600);
pros::delay(50);
chassis.wait_drive();
chassis.set_drive_pid(-16,125,true);
chassis.wait_drive();
chassis.set_turn_pid(-115, 90);
chassis.wait_drive();
stopKicker();
chassis.set_drive_pid(-35, 70, true);
chassis.wait_drive();
wingsUp();
pros::delay(600);
runIntake();
chassis.set_turn_pid(-236,90);
chassis.wait_drive();
chassis.set_drive_pid(16.5,90,true);
chassis.wait_drive();
chassis.set_turn_pid(-205,90);
chassis.wait_drive();
chassis.set_drive_pid(13,60,true);
chassis.wait_drive();
chassis.set_turn_pid(-93, 90);
chassis.wait_drive();
chassis.set_drive_pid(12.5, 90,true);
chassis.wait_drive();
chassis.set_turn_pid(-10,90);
chassis.wait_drive();
chassis.set_drive_pid(36,127,true);
*/
/*
chassis.set_drive_pid(13.5,90,true);
chassis.wait_drive();
chassis.set_drive_pid(-10,90,true);
chassis.wait_drive();
chassis.set_turn_pid(220,90);
chassis.set_drive_pid(14,90,true);
chassis.wait_drive();
chassis.set_turn_pid(-110,90);
chassis.wait_drive();
chassis.set_drive_pid(20,125,true);
chassis.wait_drive();
chassis.set_turn_pid(-10,90);
chassis.wait_drive();
chassis.set_drive_pid(40,125,true);
*/



}




void skills_auton()

{

  runIntake();
  pros::delay(200);
  chassis.wait_drive();
  chassis.set_drive_pid(3, 80, true);
  chassis.wait_drive();
  wingsDown();
  stopIntake();
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, -90, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-25, 70, true);
  chassis.wait_drive();
  wingsUp();
  pros::delay(100);
  chassis.set_turn_pid(0, 60);
  chassis.wait_drive();
  runIntake();
  chassis.set_drive_pid(20, 90, true);
  chassis.wait_drive();
  chassis.set_turn_pid(26, 60);
  chassis.wait_drive();

  chassis.set_drive_pid(55,90, true);
  chassis.wait_drive();
  
chassis.set_turn_pid(156, 50);

  chassis.wait_drive();
  //might need to comment
  kicker.move_absolute(400, 200);
  chassis.set_drive_pid(21.5, 90, true); 
  chassis.wait_drive();
  chassis.set_drive_pid(-6.5, 90, true);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, 90, SWING_SPEED);
  //might need to comment
  stopIntake();
  kicker.move_absolute(2400, 200);
  pros::delay(450);
  chassis.wait_drive();
  chassis.set_drive_pid(-9,60,true);
  //might need to comment
  kicker.move_velocity(-600);
  chassis.wait_drive();
  chassis.set_turn_pid(180, 60);
  chassis.wait_drive();
 runIntake();
 chassis.set_drive_pid(57,50,true);
 chassis.wait_drive();
 //pros::delay(200);
 chassis.set_turn_pid(45,60);
 chassis.wait_drive();
 chassis.set_drive_pid(10,90,true);
 //pros::delay(200);
 chassis.wait_drive();
 chassis.set_turn_pid(-40,60);
 chassis.wait_drive();
 chassis.set_drive_pid(-9,70,true);
 runOuttake();
 wingsDown();
 chassis.wait_drive();
 chassis.set_drive_pid(9.5,90,true);
 chassis.wait_drive();
 chassis.set_turn_pid(88,90);
 chassis.wait_drive();
 chassis.set_drive_pid(-70,100,true);
 chassis.wait_drive();
  chassis.set_drive_pid(-10,60,true);
 chassis.wait_drive();
 chassis.set_drive_pid(+2,60,true);
 chassis.wait_drive();
 wingsUp();
 chassis.set_turn_pid(0,90);
 runIntake();
 pros::delay(200);
 chassis.wait_drive();
 chassis.set_drive_pid(25,60,true);
 chassis.wait_drive();
 chassis.set_turn_pid(45,90);
 chassis.wait_drive();
 chassis.set_drive_pid(32,90,true);
 chassis.wait_drive();
 stopIntake();
 chassis.set_drive_pid(-32,90,true);
 chassis.wait_drive();
 runIntake();
 chassis.set_turn_pid(-90,90);
 chassis.wait_drive();
 chassis.set_drive_pid(26,90,true);
 chassis.wait_drive();
 pros::delay(200);
 chassis.set_turn_pid(-176,70);
 chassis.wait_drive();
 chassis.set_drive_pid(45,50,true);
 chassis.wait_drive();
 chassis.set_turn_pid(-50,90);
 chassis.wait_drive();
 chassis.set_drive_pid(10,90,true);
 pros::delay(500);

 chassis.wait_drive();
 chassis.set_turn_pid(45,90);
 chassis.wait_drive();
 chassis.set_drive_pid(-10,50);
 chassis.wait_drive();
 stopIntake();
 wingsDown();
 
 chassis.set_turn_pid(20,90);
 chassis.wait_drive();
  //kicker.move_absolute(400, 200);
 runIntake();
 chassis.set_drive_pid(94,90,true);
 chassis.wait_drive();
 stopIntake();
  chassis.wait_drive();
 chassis.set_turn_pid(220, 60);
  chassis.wait_drive();
  chassis.set_drive_pid(-31, 70,true);
  chassis.wait_drive();
 wingsUp();
 chassis.set_drive_pid(15, 70,true);
 chassis.wait_drive();
 runIntake();
 chassis.set_turn_pid(-95, 60);
 chassis.wait_drive();
 chassis.set_drive_pid(15, 125,true);
 chassis.wait_drive();
 chassis.set_drive_pid(-17, 100,true);
 chassis.wait_drive();
 chassis.set_turn_pid(35, 60);
 chassis.wait_drive();
 chassis.set_drive_pid(14, 125,true);
 chassis.wait_drive();
 chassis.set_drive_pid(-8,90,true);
 chassis.wait_drive();
 chassis.set_turn_pid(-145,90);
 chassis.wait_drive();
 chassis.set_drive_pid(25,90,true);
 chassis.wait_drive();
 chassis.set_turn_pid(-155,90);
 chassis.set_drive_pid(27,90,true);



 //can delte after this
 /*
 runIntake();
  chassis.wait_drive();
  chassis.set_drive_pid(30,90,true);
  pros::delay(500);
  stopIntake();
  chassis.set_turn_pid(-140,90);
  chassis.wait_drive();
  chassis.set_drive_pid(-20,90,true);
  chassis.wait_drive();
 //kicker.move_absolute(2500, 200);
 //pros::delay(400);
 */
  
  //third mogo
  
  
  //This is right before catching frist mogo on third side
  
  wingsUp();
  runIntake();
  chassis.set_turn_pid(-135, 80);
  chassis.wait_drive();
  chassis.set_drive_pid(15,110, true);
  chassis.wait_drive();
  chassis.set_turn_pid(-75, 80);
  chassis.wait_drive();
  chassis.set_drive_pid(20,110, true);
  chassis.wait_drive();
  chassis.set_drive_pid(-10,110, true);
  chassis.wait_drive();
  chassis.set_turn_pid(-39, 80);
  chassis.wait_drive();
  chassis.set_drive_pid(20,110, true);
  chassis.wait_drive();
  chassis.set_turn_pid(-125,110);
  chassis.wait_drive();
  chassis.set_drive_pid(25,110, true);
  chassis.wait_drive();
  chassis.set_drive_pid(-30,90, true);
  chassis.wait_drive();
  chassis.set_turn_pid(130, 80);
  chassis.wait_drive();
  chassis.set_drive_pid(27.5,110, true);
  chassis.wait_drive();
  chassis.set_turn_pid(38.5, 80);
  chassis.wait_drive();
  chassis.set_drive_pid(17,110, true);
  chassis.wait_drive(); 
  chassis.set_turn_pid(-162, 80);
  chassis.wait_drive();
  chassis.set_drive_pid(-20,110, true);
  /*



 







  /*

  chassis.wait_drive();

  chassis.set_drive_pid(-5, 60, true);

  chassis.wait_drive();

  chassis.set_turn_pid(150, 60);

  chassis.wait_drive();

  chassis.set_drive_pid(11.5, 40, true);

  chassis.wait_drive();

  chassis.set_turn_pid(180, 60);

  chassis.wait_drive();

  chassis.set_drive_pid(45.5, 40, true);

  chassis.wait_drive();

  chassis.set_turn_pid(-135, 60);

  chassis.wait_drive();

  chassis.set_drive_pid(13, 40, true);

  chassis.wait_drive();

  chassis.set_turn_pid(145, 60);

  chassis.wait_drive();

  pros::delay(600);

  runOuttake();

  pros::delay(200);

  wingsDown();

  chassis.set_drive_pid(-10, 60, true);

  stopIntake();

  chassis.wait_drive();

  chassis.set_drive_pid(7, 60, true);

  // Pesudo Code after the main one

  chassis.set_turn_pid(-83, 70);

  chassis.wait_drive();

  pros::delay(10);

  chassis.set_drive_pid(-77, 80, true);

  chassis.wait_drive();

  wingsUp();

  pros::delay(200);

  chassis.set_turn_pid(180, 60);

  chassis.wait_drive();

  runIntake();

  chassis.set_drive_pid(25, 60, true);

  chassis.wait_drive();

  chassis.set_turn_pid(122, 60);

  chassis.wait_drive();

  chassis.set_drive_pid(39, 60, true);

  chassis.wait_drive();

  chassis.set_turn_pid(-28, 60);

  chassis.wait_drive();

  chassis.set_drive_pid(18, 60, true);

  chassis.wait_drive();

  chassis.set_turn_pid(0, 60);

  chassis.wait_drive();

  chassis.set_drive_pid(43, 60, true);

  chassis.wait_drive();

  pros::delay(400);

  chassis.set_turn_pid(135, 60);

  chassis.wait_drive();

  chassis.set_drive_pid(13, 60, true);

  chassis.wait_drive();

  chassis.set_turn_pid(-135, 60);

  chassis.wait_drive();

  stopIntake();

  pros::delay(600);

  runOuttake();

  pros::delay(200);

  wingsDown();

  pros::delay(100);

  stopIntake();

  chassis.set_drive_pid(-10, 60, true); 

  chassis.wait_drive();

  */  

  /*

  chassis.set_turn_pid(225,40);

  chassis.set_drive_pid(78.67,90,true);

  chassis.wait_drive();

  pros::delay(400);

  runIntake();

  pros::delay(400);

  stopIntake();

  chassis.set_turn_pid(162,60);

  chassis.wait_drive();

  chassis.set_drive_pid(21,90,true);

  chassis.wait_drive();

  chassis.set_turn_pid(45,60);

  chassis.wait_drive();

  chassis.set_drive_pid(-16,90,true);

  chassis.wait_drive();

  wingsUp();

  pros::delay(300);

  runIntake();

  chassis.set_turn_pid(48,60);

  chassis.wait_drive();

  chassis.set_drive_pid(25,90,true);

  chassis.wait_drive();

  chassis.set_turn_pid(93,60);

  chassis.wait_drive();

  chassis.set_drive_pid(24,90,true);

  chassis.wait_drive();

  chassis.set_turn_pid(145,60);

  chassis.wait_drive();

  chassis.wait_drive();

  chassis.set_drive_pid(25,40,true);

  chassis.wait_drive();

  chassis.set_drive_pid(-15,60,true);

  chassis.wait_drive();

  stopIntake();

  pros::delay(100);

  runOuttake();

  chassis.set_drive_pid(20,80,true);

  chassis.wait_drive();

  chassis.set_turn_pid(270,60);

  chassis.wait_drive();

  stopIntake();

  pros::delay(100);

  runIntake();

  chassis.set_drive_pid(13,80,true);

  chassis.wait_drive();

  pros::delay(130);

  chassis.set_drive_pid(-12,80,true);

  chassis.wait_drive();

  chassis.set_turn_pid(235,60);

  chassis.wait_drive();

  runIntake();

  chassis.set_drive_pid(13,80,true);

  chassis.wait_drive();

  pros::delay(130);

  chassis.set_drive_pid(-12,80,true);

  chassis.wait_drive();

*/

}



// Constants



void default_constants()

{

  chassis.set_slew_min_power(80, 80);

  chassis.set_slew_distance(7, 7);

  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);

  // default: chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);

  chassis.set_pid_constants(&chassis.forward_drivePID, .75, 0.0, 6, 0);

  chassis.set_pid_constants(&chassis.backward_drivePID, .75, 0.0, 6, 0);

  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);

  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);

}



void one_mogo_constants()

{

  chassis.set_slew_min_power(80, 80);

  chassis.set_slew_distance(7, 7);

  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);

  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);

  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);

  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);

  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);

}



void two_mogo_constants()

{

  chassis.set_slew_min_power(80, 80);

  chassis.set_slew_distance(7, 7);

  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);

  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);

  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);

  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);

  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);

}



void exit_condition_defaults()

{

  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);

  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);

  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);

}



void modified_exit_condition()

{

  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);

  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);

  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);

}



void wait_until_change_speed()

{ 

  // wait_until will wait until the robot gets to a desired position



  // When the robot gets to 6 inches, the robot will travel the remaining distance at a max speed of 40

  chassis.set_drive_pid(24, DRIVE_SPEED, true);

  chassis.wait_until(6);

  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed

  chassis.wait_drive();



  chassis.set_turn_pid(45, TURN_SPEED);

  chassis.wait_drive();



  chassis.set_turn_pid(-45, TURN_SPEED);

  chassis.wait_drive();



  chassis.set_turn_pid(0, TURN_SPEED);

  chassis.wait_drive();



  // When the robot gets to -6 inches, the robot will travel the remaining distance at a max speed of 40

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);

  chassis.wait_until(-6);

  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed

  chassis.wait_drive();

}



// Interference example

void tug(int attempts)

{

  for (int i = 0; i < attempts - 1; i++)

  {

    // Attempt to drive backwards

    printf("i - %i", i);

    chassis.set_drive_pid(-12, 127);

    chassis.wait_drive();



    // If failsafed...

    if (chassis.interfered)

    {

      chassis.reset_drive_sensor();

      chassis.set_drive_pid(-2, 20);

      pros::delay(1000);

    }

    // If robot successfully drove back, return

    else

    {

      return;

    }

  }

}



// If there is no interference, robot will drive forward and turn 90 degrees.

// If interfered, robot will drive forward and then attempt to drive backwards.

void interfered_example()

{

  chassis.set_drive_pid(24, DRIVE_SPEED, true);

  chassis.wait_drive();



  if (chassis.interfered)

  {

    tug(3);

    return;

  }



  chassis.set_turn_pid(90, TURN_SPEED);

  chassis.wait_drive();

}