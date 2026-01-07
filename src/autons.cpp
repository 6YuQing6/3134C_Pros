#include "main.h"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;
const int SWING_SPEED = 110;

///
// Constants
///
void default_constants() {
  // P, I, D, and Start I
  chassis.drive_imu_scaler_set(1.013);

  chassis.pid_drive_constants_set(9.2, 0.0, 65.0); //20,110  17, 110      // Fwd/rev constants, used for odom and non odom motions
  chassis.pid_heading_constants_set(11.0, 0.0, 20.0);        // Holds the robot straight while going forward without odom
 // chassis.pid_turn_constants_set(3.4, 0.0, 3.75, 0.0); //(3.90, 0.0, 37.15, 15.0);   180 grados  // Turn in place constants
  //(3.90, 0.0, 20.90, 15.0); 30 grados //(3.70, 0.0, 28.15, 15.0); 90 grados    - nuevo 2.8, 0.0, 13.75, 
  chassis.pid_swing_constants_set(4.0, 0.0, 49.0);           // Swing constants
  chassis.pid_odom_angular_constants_set(6.5, 0.0, 52.5);    // Angular control for odom motions
  chassis.pid_odom_boomerang_constants_set(5.8, 0.0, 32.5);  // Angular control for boomerang motions
 
  chassis.pid_turn_constants_set(3.0, 0.05, 21.0, 15.0);     // Turn in place constants

// chassis.drive_imu_scaler_set(1.0035);
//   chassis.pid_drive_constants_set(8.0, 0.0, 50.0);         // Fwd/rev constants, used for odom and non odom motions
//   chassis.pid_heading_constants_set(11.0, 0.0, 20.0);        // Holds the robot straight while going forward without odom
  //chassis.pid_turn_constants_set(3.0, 0.0, 20.90, 15.0);     // Turn in place constants
//   chassis.pid_swing_constants_set(4.0, 0.0, 49.0);           // Swing constants
//   chassis.pid_odom_angular_constants_set(6.5, 0.0, 52.5);    // Angular control for odom motions
//   chassis.pid_odom_boomerang_constants_set(5.8, 0.0, 32.5);  // Angular control for boomerang motions

  // Exit conditions
  chassis.pid_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 50_ms, 50_ms);
  chassis.pid_swing_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 50_ms, 3_in, 50_ms, 500_ms);
  //   chassis.pid_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  // chassis.pid_swing_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  // chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);


  chassis.pid_odom_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 750_ms);
  chassis.pid_odom_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 750_ms);
  chassis.pid_turn_chain_constant_set(3_deg);//3
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  // Slew constants
  chassis.slew_turn_constants_set(3_deg, 70);
  chassis.slew_drive_constants_set(3_in, 70);
  chassis.slew_swing_constants_set(3_in, 80);

  // The amount that turns are prioritized over driving in odom motions
  // - if you have tracking wheels, you can run this higher.  1.0 is the max
  chassis.odom_turn_bias_set(0.1);

  chassis.odom_look_ahead_set(7_in);           // This is how far ahead in the path the robot looks at
  chassis.odom_boomerang_distance_set(16_in);  // This sets the maximum distance away from target that the carrot point can be
  chassis.odom_boomerang_dlead_set(0.625);     // This handles how aggressive the end of boomerang motions are

  chassis.pid_angle_behavior_set(ez::shortest);  // Changes the default behavior for turning, this defaults it to the shortest path there
}

// 21.5 
// 17
// 14.1

void drive_example() 
{
  // chassis.pid_turn_set(3600_deg, 40, ez::raw);
  // chassis.pid_wait();

// chassis.pid_wait();
  // MatchLoad.set_value(true);
  // Intake1.move(127);
  // Intake2.move(127);
  // chassis.pid_drive_set(36_in, DRIVE_SPEED,true);//30
  // chassis.pid_wait_until(15_in);
  // chassis.pid_speed_max_set(40);
  // chassis.pid_wait_until(25_in);
  // chassis.pid_speed_max_set(DRIVE_SPEED);
  // pros::delay(1600);
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater than the slew distance + a few inches
//IMU SCALER
  // chassis.pid_turn_set(3600_deg, 40, ez::raw);
// chassis.pid_wait();

//   chassis.pid_drive_set(50_in, DRIVE_SPEED,true);
//  // pros::delay(10000);
//   chassis.pid_wait();
  //RightSideSuperRush();
 // LeftSideSuperRush();

//.LeftSideRushPush();
//LeftSideRush();
//RightSideRushPush();
//SoloAWP();

    chassis.pid_turn_set(90_deg, TURN_SPEED);
   chassis.pid_wait();
   


  // chassis.pid_swing_set(ez::LEFT_SWING, 45_deg, SWING_SPEED, 45);
  // chassis.pid_wait();

  // chassis.pid_swing_set(ez::RIGHT_SWING, 0_deg, SWING_SPEED, 45);
  // chassis.pid_wait();

  // chassis.pid_swing_set(ez::RIGHT_SWING, 45_deg, SWING_SPEED, 45);
  // chassis.pid_wait();

  // chassis.pid_swing_set(ez::LEFT_SWING, 0_deg, SWING_SPEED, 45);
  // chassis.pid_wait();


// //Turn to face 12, 12 forward
// chassis.pid_turn_set({24, 24}, fwd,  90);
// chassis.pid_wait();
// // Drive forward to (0, 36) forward
// chassis.pid_odom_set({{24_in, 24_in}, fwd, 110});
// chassis.pid_wait();

// chassis.pid_turn_set(0_deg, TURN_SPEED);
// chassis.pid_wait();

// chassis.pid_turn_set({0, 0}, rev,  90);
// chassis.pid_wait();
// chassis.pid_odom_set({{0_in, 0_in}, rev, 110});
// chassis.pid_wait();
// chassis.pid_turn_set(0_deg, TURN_SPEED);
// chassis.pid_wait();




// Drive forward to (0, 36) forward, end at 45 degrees
// chassis.pid_odom_set({{0_in, 36_in, 45_deg}, fwd, 110});
// chassis.pid_wait();

// // Drive back to (0, 0) backward, end at 0 degrees
// chassis.pid_odom_set({{0_in, 0_in, 0_deg}, rev, 110});
// chassis.pid_wait();

// chassis.pid_odom_set({{{0_in, 24_in, 45_deg}, fwd, 110},
//                       {{24_in, 24_in}, fwd, 110}},
//                       true);
// chassis.pid_wait();




// // Turn to 0, 24 forward
// chassis.pid_turn_set({0_in, 24_in}, fwd, 90);
// chassis.pid_wait();

// // Turn to face 12, 12 backward
// chassis.pid_turn_set({24, 24}, rev,  90);
// chassis.pid_wait();

// // Turn to 0, 24 backward
// chassis.pid_turn_set({0_in, 24_in}, rev, 90);
// chassis.pid_wait();


  // chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  // chassis.pid_wait();

  // chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  // chassis.pid_wait();
}

void pushToLongGoal()
{
  chassis.pid_targets_reset();             
  chassis.drive_imu_reset();        
  chassis.drive_sensor_reset();
  pros::delay(20);
  Descore.set_value(true);
  chassis.pid_drive_set(15_in, DRIVE_SPEED);
  chassis.pid_wait_until(13_in);
  chassis.pid_turn_set(38_deg, TURN_SPEED);
  chassis.pid_wait_until(36_deg);
  chassis.pid_drive_set(-17_in, DRIVE_SPEED);//19
  chassis.pid_wait_until(-15_in);//17
  chassis.pid_turn_set(-3_deg, TURN_SPEED);//-3
  chassis.pid_wait_until(-1_deg);
  Descore.set_value(false);
  chassis.pid_drive_set(-17_in, 80);
  chassis.pid_wait_quick_chain();
  pros::delay(500);
  chassis.drive_set(0, 0);
}

// starts on the right black corner of parking zone, faces to the right perpendicular 
void HalfSoloAWP()
{
  // drives to loader 
  chassis.pid_drive_set(35_in, DRIVE_SPEED);
  chassis.pid_wait();
  // runs intake
  Intake1.move(127);
  Intake2.move(-40); 
  // turns toward loader
  MatchLoad.set_value(true);
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait_until(90_deg);
  // drives forward into loader 
  chassis.pid_drive_set(18.5_in, 50);//90 SPEED DRIVE SPEED
  chassis.pid_wait_until(1_in);
  pros::delay(139); // delays a bit for the matchloader balls to come in

  // drives backwards to the long goal
  chassis.pid_speed_max_set(DRIVE_SPEED);
  pros::delay(900);//MEJOR METER UNA ROJA POR SI ACASO 1300
  chassis.pid_drive_set(-32_in, DRIVE_SPEED);//30
  pros::delay(900);//  1100
  chassis.drive_set(-30, -30);
  // outakes balls into long goal
  Intake2.move(127);
  Descore.set_value(true);
  pros::delay(900);///////////////
  MatchLoad.set_value(false);

  // moves forward to be away from long goal
  chassis.pid_drive_set(10_in, DRIVE_SPEED); // 7
  chassis.pid_wait_until(7_in); //6
  Intake2.move(-40);
  // rotates to face 3 red balls on the right
  chassis.pid_turn_set(213_deg, TURN_SPEED);//203
  chassis.pid_wait();
  // moves forward to intake 3 red balls on the right 
  chassis.pid_drive_set(35_in, DRIVE_SPEED);//80 SPEED
  chassis.pid_wait_until(20_in);//27 NO HE PROBADO
  chassis.pid_speed_max_set(20);//70
  chassis.pid_wait_until(20_in);//27 NO HE PROBADO
  chassis.pid_speed_max_set(DRIVE_SPEED);//70
  chassis.pid_wait_until(35_in);//36

  // moves forward to the left 3 balls 
  Intake1.move(127);////////////////////////////////
  chassis.pid_turn_set(179_deg, TURN_SPEED);
  chassis.pid_wait_until(179_deg);  //178
  chassis.pid_drive_set(47_in, DRIVE_SPEED);//35
  chassis.pid_wait_until(45_in);// 30
  // MatchLoad.set_value(true);
  // chassis.pid_wait_until(40_in);//32
  // sets matchloader up
  // MatchLoad.set_value(false);
  // turns toward top middle goal
  chassis.pid_turn_set(133_deg, TURN_SPEED);//135
  chassis.pid_wait_until(135_deg);///130
  chassis.pid_drive_set(-16_in, DRIVE_SPEED);

  Intake2.move(127);//////////////
  chassis.pid_wait_until(-16_in);////////////////////////////////////
  // Intake1.move(0);///////////////////////////////////
  CenterGoal.set_value(true);//////////////////////
  chassis.pid_wait_until(-9_in);   //11
  // Intake1.move(127);
  // Intake2.move(30);
  pros::delay(700);//600
}

void SoloAWP()
{
  HalfSoloAWP();
  Intake1.move(127);//0
  Intake2.move(-40);//0
  CenterGoal.set_value(false);
  chassis.pid_drive_set(52.5_in, DRIVE_SPEED);//51
  chassis.pid_wait_until(51.5_in);//50//48
  MatchLoad.set_value(true);
  chassis.pid_turn_set(89_deg, TURN_SPEED);
  chassis.pid_wait_until(91_deg); //89
  Intake1.move(127);
  Intake2.move(-40);
  chassis.pid_drive_set(21_in, 50);//90 SPEED DRIVE SPEED
  chassis.pid_wait_until(4_in);             //////////// 3 
  chassis.pid_speed_max_set(DRIVE_SPEED);
  pros::delay(900);//MEJOR METER UNA ROJA POR SI ACASO 1300
 chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_drive_set(-35_in, DRIVE_SPEED);
  pros::delay(900);
  chassis.drive_set(-20, -20);
  Intake2.move(127);
  pros::delay(1300);

}
//BACKUP
// void HalfSoloAWP()
// {
//   chassis.pid_drive_set(28_in, DRIVE_SPEED);
//   chassis.pid_wait_until(26_in);
//   Intake1.move(127);
//   Intake2.move(-40); 
//   MatchLoad.set_value(true);
//   chassis.pid_turn_set(90_deg, TURN_SPEED);
//   chassis.pid_wait_until(88_deg);
//   chassis.pid_drive_set(21_in, 50);//90 SPEED DRIVE SPEED
//   chassis.pid_wait_until(2_in);
//   chassis.pid_speed_max_set(DRIVE_SPEED);
//   pros::delay(900);//MEJOR METER UNA ROJA POR SI ACASO 1300
//   chassis.pid_drive_set(-35_in, DRIVE_SPEED);//30
//   pros::delay(900);//  1100
//   chassis.drive_set(-30, -30);
//   Intake2.move(127);
//   Descore.set_value(true);
//   pros::delay(900);///////////////
//   MatchLoad.set_value(false);
//   chassis.pid_drive_set(7_in, DRIVE_SPEED);
//   chassis.pid_wait_until(6_in); //6
//   Intake2.move(-40);
//   chassis.pid_turn_set(203_deg, TURN_SPEED);//203
//   chassis.pid_wait();
//   chassis.pid_drive_set(38_in, DRIVE_SPEED);//80 SPEED
//   chassis.pid_wait_until(16_in);//27 NO HE PROBADO
//   chassis.pid_speed_max_set(20);//70
//   chassis.pid_wait_until(20_in);//27 NO HE PROBADO
//   chassis.pid_speed_max_set(DRIVE_SPEED);//70
//   chassis.pid_wait_until(37_in);//36
//   chassis.pid_turn_set(179_deg, TURN_SPEED);
//   chassis.pid_wait_until(179_deg);  //178
//   chassis.pid_drive_set(35_in, DRIVE_SPEED);//34
//   chassis.pid_wait_until(23_in);// 30
//   MatchLoad.set_value(true);
//   chassis.pid_wait_until(33_in);//32
//   MatchLoad.set_value(false);
//   chassis.pid_turn_set(133_deg, TURN_SPEED);//135
//   chassis.pid_wait_until(135_deg);///130
//   chassis.pid_drive_set(-16_in, DRIVE_SPEED);
//   Intake1.move(-127);////////////////////////////////
//   chassis.pid_wait_until(-1_in);////////////////////////////////////
//   Intake1.move(0);///////////////////////////////////
//   CenterGoal.set_value(true);//////////////////////
//   chassis.pid_wait_until(-9_in);   //11
//   Intake1.move(127);
//   Intake2.move(30);
//   pros::delay(700);//600
// }

// void SoloAWP()
// {
//   HalfSoloAWP();
//   Intake1.move(127);//0
//   Intake2.move(-40);//0
//   CenterGoal.set_value(false);
//   chassis.pid_drive_set(53.5_in, DRIVE_SPEED);//51
//   chassis.pid_wait_until(51.5_in);//50//48
//   MatchLoad.set_value(true);
//   chassis.pid_turn_set(89_deg, TURN_SPEED);
//   chassis.pid_wait_until(91_deg); //89
//   Intake1.move(127);
//   Intake2.move(-40);
//   chassis.pid_drive_set(21_in, 50);//90 SPEED DRIVE SPEED
//   chassis.pid_wait_until(4_in);             //////////// 3 
//   chassis.pid_speed_max_set(DRIVE_SPEED);
//   pros::delay(900);//MEJOR METER UNA ROJA POR SI ACASO 1300
//  chassis.pid_turn_set(90_deg, TURN_SPEED);
//   chassis.pid_drive_set(-35_in, DRIVE_SPEED);
//   pros::delay(900);
//   chassis.drive_set(-20, -20);
//   Intake2.move(127);
//   pros::delay(1300);

// }

// Alternative autonomous path (simplified / approximate)
// Goal: Rush forward, reposition across the field, collect, and prep for scoring
void jerryio_path_3134c_simple_auton() {

  // Step 1: Initial rush forward to collect early game objects
  // Drive forward while running intakes to secure objects quickly
  Intake1.move(127);
  Intake2.move(-40); 
  chassis.pid_drive_set(31_in, DRIVE_SPEED);
  chassis.pid_wait_until(14_in);//27 NO HE PROBADO
  chassis.pid_speed_max_set(20);//70
  chassis.pid_wait_until(19_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);//70
  chassis.pid_wait_until(31_in);
  // chassis.pid_drive_set(24.5_in, DRIVE_SPEED); // 16.7
  // chassis.pid_wait_until(16.5_in);
  // chassis.pid_speed_max_set(20);//70
  // chassis.pid_wait_until(24.5_in);
  // chassis.pid_speed_max_set(DRIVE_SPEED);//7
  // chassis.pid_wait_until(24.5);

  // pros::delay(5000);


  // // Step 2: Turn and traverse diagonally across the field
  // // Reposition toward the next lane while temporarily stopping intakes
  chassis.pid_turn_set(125_deg, TURN_SPEED);
  chassis.pid_wait_until(125_deg);
  chassis.pid_wait();
  Intake1.move(0);
  Intake2.move(0);
  chassis.pid_drive_set(41.5_in, DRIVE_SPEED);
  chassis.pid_wait_until(41.5_in);
   MatchLoad.set_value(true);
  // chassis.pid_heading_constants_set(0);
  chassis.pid_turn_set(173_deg, TURN_SPEED);
  chassis.pid_wait_until(173_deg);
  // chassis.pid_wait();s
  Intake1.move(127);
  Intake2.move(0);
  chassis.pid_drive_set(13_in, 127);
  chassis.pid_wait_until(13_in);
  pros::delay(500);
  Intake1.move(0);
  Intake2.move(0);
  chassis.pid_drive_set(-29.8_in, DRIVE_SPEED);
  chassis.pid_wait_until(-29.8_in);
  Intake1.move(127);
  Intake2.move(127);

  // // Step 3: Fine alignment and short advance for match loading / pickup
  // // Face left, re-enable intakes, and activate match loader while moving forward
  // chassis.pid_turn_set(-120_deg, TURN_SPEED);
  // chassis.pid_wait();
  // Intake1.move(127);
  // Intake2.move(-40);
  // MatchLoad.set_value(true);
  // chassis.pid_drive_set(9.8_in, DRIVE_SPEED);
  // pros::delay(130);

  // // Step 4: Final turn and forward adjustment
  // // Rotate toward scoring or next interaction zone and move into position
  // chassis.pid_turn_set(-170_deg, TURN_SPEED);
  // pros::delay(50);
  // chassis.pid_drive_set(23.8_in, DRIVE_SPEED);
  // pros::delay(50);
}


void RightSideSuperRush(){
  Intake1.move(127);
  Intake2.move(-40);
  // chassis.pid_drive_set(31_in, DRIVE_SPEED);///////NUEVO ERA 80
  // chassis.pid_wait_until(21_in);
  // MatchLoad.set_value(true);
  // chassis.pid_wait_until(31_in);
  chassis.pid_drive_set(31_in, DRIVE_SPEED);
  chassis.pid_wait_until(14_in);//27 NO HE PROBADO
  chassis.pid_speed_max_set(20);//70
  chassis.pid_wait_until(19_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);//70
  chassis.pid_wait_until(31_in);

  chassis.pid_turn_set(100_deg, TURN_SPEED);
  chassis.pid_wait_until(99_deg);
  chassis.pid_drive_set(31_in, DRIVE_SPEED);
  chassis.pid_wait_until(30_in);
  chassis.pid_turn_set(162_deg, TURN_SPEED);
  chassis.pid_wait_until(160_deg);

  chassis.pid_drive_set(-33_in, 127);
  pros::delay(500);
  chassis.drive_set(-30, -30);
  Intake2.move(127);
  pros::delay(1000);
  Intake1.move(0);
  Intake2.move(0);
  pushToLongGoal();
}

void RightSideRush()
{
  Intake1.move(127);
  Intake2.move(-40);

  // chassis.pid_drive_set(30_in, 80);
  // chassis.pid_wait_until(22_in);

  // MatchLoad.set_value(true);

  // chassis.pid_wait_until(30_in);

  chassis.pid_drive_set(30_in, DRIVE_SPEED);
  chassis.pid_wait_until(13_in);//27 NO HE PROBADO
  chassis.pid_speed_max_set(20);//70
  chassis.pid_wait_until(21_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);//70
  chassis.pid_wait_until(30_in);

  // MIRROR: antes -111°, ahora +111°
  chassis.pid_turn_set(111_deg, TURN_SPEED);
  chassis.pid_wait();
  // chassis.pid_wait_until(110_deg);

  Intake1.move(0);
  Intake2.move(0);

  chassis.pid_drive_set(36_in, DRIVE_SPEED);
  chassis.pid_wait();
  //chassis.pid_wait_until(34_in);
  MatchLoad.set_value(true);
  // MIRROR: antes -162°, ahora +162°
  chassis.pid_turn_set(162_deg, TURN_SPEED);
  chassis.pid_wait_until(160_deg);

  Intake1.move(127);
  Intake2.move(-40);


  // chassis.pid_drive_set(23_in, 65);
  // pros::delay(1600);

  chassis.pid_drive_set(21_in, 50);//90 SPEED DRIVE SPEED
  chassis.pid_wait_until(6_in);             //////////// 4

  chassis.pid_speed_max_set(DRIVE_SPEED);
  pros::delay(900);//MEJOR METER UNA ROJA POR SI ACASO 1300


  chassis.pid_drive_set(-35_in, DRIVE_SPEED);
  pros::delay(1250);

  chassis.drive_set(-30, -30);
  Intake2.move(127);
  pros::delay(1800);

  MatchLoad.set_value(false);
  
  Intake1.move(0);
  Intake2.move(0);
}

void RightSideRushPush()
{
  RightSideRush();
  pushToLongGoal();
}


void LeftSideSuperRush()
{
  Intake1.move(127);
  Intake2.move(-40);

  // chassis.pid_drive_set(31_in, 80);
  // chassis.pid_wait_until(21_in);//20

  // MatchLoad.set_value(true);

  // chassis.pid_wait_until(31_in);

  chassis.pid_drive_set(31_in, DRIVE_SPEED);
  chassis.pid_wait_until(14_in);//27 NO HE PROBADO
  chassis.pid_speed_max_set(20);//70
  chassis.pid_wait_until(19_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);//70
  chassis.pid_wait_until(31_in);

  // Giro espejeado (antes era +100°)
  chassis.pid_turn_set(-100_deg, TURN_SPEED);
  chassis.pid_wait_until(-99_deg);

  chassis.pid_drive_set(26_in, DRIVE_SPEED);
  chassis.pid_wait_until(24_in);

  // Giro espejeado (antes era +162°)
  chassis.pid_turn_set(-162_deg, TURN_SPEED);
  chassis.pid_wait_until(-160_deg);

  //MatchLoad.set_value(false);

  chassis.pid_drive_set(-33_in, 127);
  pros::delay(500);

  chassis.drive_set(-10, -10);
  Intake2.move(127);
  pros::delay(1000);
  Intake1.move(0);
  Intake2.move(0);
  pushToLongGoal();
}

void LeftSideMiddle()
{
  Intake1.move(127);
  Intake2.move(-40);

  chassis.pid_drive_set(30_in, DRIVE_SPEED);
  chassis.pid_wait_until(13_in);//27 NO HE PROBADO
  chassis.pid_speed_max_set(20);//70
  chassis.pid_wait_until(21_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);//70
  chassis.pid_wait_until(30_in);


  Intake1.move(-127);
  pros::delay(50);
  chassis.pid_turn_set(-111_deg, TURN_SPEED);
  Intake1.move(0);
  chassis.pid_wait_until(-111_deg);

  chassis.pid_drive_set(-19_in, DRIVE_SPEED);
  CenterGoal.set_value(true);
  //Intake1.move(0);
  chassis.pid_wait_until(-14_in);//
  Intake1.move(127);
  Intake2.move(30);

  CenterGoal.set_value(true);
  pros::delay(800);//900

  Intake1.move(0);
  Intake2.move(0);
  CenterGoal.set_value(false);

  chassis.pid_drive_set(52_in, DRIVE_SPEED);//53
  chassis.pid_wait_until(50_in);//51

  chassis.pid_turn_set(-162_deg, TURN_SPEED);
  chassis.pid_wait_until(-160_deg); 
  
  MatchLoad.set_value(true);

  Intake1.move(127);
  Intake2.move(-40);

  // chassis.pid_drive_set(22_in, 60);//MENOS GOLPE//21
  // pros::delay(1600);//1700

  chassis.pid_drive_set(21_in, 40);//90 SPEED DRIVE SPEED
  chassis.pid_wait_until(10_in);             //////////// 6

  chassis.pid_speed_max_set(DRIVE_SPEED);
  pros::delay(700);//MEJOR METER UNA ROJA POR SI ACASO 900



  chassis.pid_drive_set(-35_in, DRIVE_SPEED);
  pros::delay(1250);

  chassis.drive_set(-20, -20);
  Intake2.move(127);
  pros::delay(1300);
  MatchLoad.set_value(false);
  Intake1.move(0);
  Intake2.move(0);
}

void LeftSideMiddlePush()
{
  LeftSideMiddle();
  pushToLongGoal();
}



void LeftSideRush()
{
  Intake1.move(127);
  Intake2.move(-40);


  chassis.pid_drive_set(30_in, DRIVE_SPEED);
  chassis.pid_wait_until(13_in);//27 NO HE PROBADO
  chassis.pid_speed_max_set(20);//70
  chassis.pid_wait_until(21_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);//70
  chassis.pid_wait_until(30_in);


  chassis.pid_turn_set(-111_deg, TURN_SPEED);
  chassis.pid_wait_until(-110_deg);
  Intake1.move(0);
  Intake2.move(0);
  chassis.pid_drive_set(34_in, DRIVE_SPEED);//36
  chassis.pid_wait_until(32_in);//34

  chassis.pid_turn_set(-162_deg, TURN_SPEED);
  chassis.pid_wait_until(-160_deg); 
  MatchLoad.set_value(true);
  Intake1.move(127);
  Intake2.move(-40);

  // chassis.pid_drive_set(23_in, 65);//MENOS GOLPE//21
  // pros::delay(1600);//1700


  chassis.pid_drive_set(21_in, 50);//90 SPEED DRIVE SPEED
  chassis.pid_wait_until(6_in);             //////////// 4

  chassis.pid_speed_max_set(DRIVE_SPEED);
  pros::delay(900);//MEJOR METER UNA ROJA POR SI ACASO 1300


  chassis.pid_drive_set(-35_in, DRIVE_SPEED);
  pros::delay(1250);

  chassis.drive_set(-30, -30);
  Intake2.move(127);
  pros::delay(1600);
  MatchLoad.set_value(false);
  Intake1.move(0);
  Intake2.move(0);
}

void LeftSideRushPush()
{
  LeftSideRush();
  pushToLongGoal();
}

void Skills()
{
  chassis.pid_drive_set(30_in, DRIVE_SPEED);
  chassis.pid_wait();

  Intake1.move(127);
  Intake2.move(-40); 
  MatchLoad.set_value(true);
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait_until(90_deg);
  chassis.pid_drive_set(21_in, 50);
  chassis.pid_wait_until(2_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);
  pros::delay(2000);


  chassis.pid_drive_set(-18_in, DRIVE_SPEED);
  chassis.pid_wait_until(-18_in); 
  Intake1.move(0);
  Intake2.move(0); 

  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait_until(180_deg); 

  chassis.pid_drive_set(96_in, DRIVE_SPEED);
  chassis.pid_wait();
  //chassis.pid_wait_until(97_in);

   chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait_until(90_deg); 

  chassis.pid_drive_set(-25_in, DRIVE_SPEED);
  pros::delay(500);//700
  chassis.drive_set(-20, -20);
  Intake1.move(127);
  Intake2.move(127);  
  pros::delay(1600);
  Intake2.move(-40);


  // chassis.pid_drive_set(34_in, DRIVE_SPEED);//30
  // chassis.pid_wait_until(20_in);
  // chassis.pid_speed_max_set(40);
  // chassis.pid_wait_until(25_in);
  // chassis.pid_speed_max_set(DRIVE_SPEED);
  // pros::delay(1800);
  chassis.pid_drive_set(36_in, DRIVE_SPEED,true);//30
  chassis.pid_wait_until(15_in);
  chassis.pid_speed_max_set(40);
  chassis.pid_wait_until(25_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);
  pros::delay(2000);


  chassis.pid_drive_set(-35_in, DRIVE_SPEED);
  pros::delay(1250);
  chassis.drive_set(-20, -20);
  Intake1.move(127);
  Intake2.move(127);  
  pros::delay(1600);
  Intake1.move(0);
  Intake2.move(0);  
  MatchLoad.set_value(false);
  chassis.pid_drive_set(15_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-18_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-72_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait(); 
  chassis.pid_drive_set(13_in, DRIVE_SPEED);//15
  chassis.pid_wait();

  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();  
  MatchLoad.set_value(true);
  Intake1.move(127);
  Intake2.move(-40); 
  
  chassis.pid_drive_set(21_in, 40);//90 SPEED DRIVE SPEED
   chassis.pid_wait();
  chassis.pid_wait_until(10_in);             //////////// 6

  chassis.pid_speed_max_set(DRIVE_SPEED);
  pros::delay(2000);//MEJOR METER UNA ROJA POR SI ACASO 900

//////////////////

  chassis.pid_drive_set(-18_in, DRIVE_SPEED);
  chassis.pid_wait_until(-18_in); 
 chassis.pid_wait();

  Intake1.move(0);
  Intake2.move(0); 

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait_until(0_deg);  
  chassis.pid_drive_set(94_in, DRIVE_SPEED);
  chassis.pid_wait();
  // chassis.pid_wait_until(96_in);
   chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait_until(-90_deg); 

  chassis.pid_drive_set(-25_in, DRIVE_SPEED);
  pros::delay(700);

  chassis.drive_set(-20, -20);

  Intake1.move(127);
  Intake2.move(127);  
  pros::delay(1600);
  Intake2.move(-40);


  // chassis.pid_drive_set(34_in, DRIVE_SPEED);//30
  // chassis.pid_wait_until(20_in);
  // chassis.pid_speed_max_set(40);
  // chassis.pid_wait_until(25_in);
  // chassis.pid_speed_max_set(DRIVE_SPEED);
  // pros::delay(1600);
  chassis.pid_drive_set(36_in, DRIVE_SPEED,true);//30
  chassis.pid_wait_until(15_in);
  chassis.pid_speed_max_set(40);
  chassis.pid_wait_until(25_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);
  pros::delay(2000);

  chassis.pid_drive_set(-35_in, DRIVE_SPEED);
  pros::delay(1250);

  chassis.drive_set(-20, -20);

  Intake1.move(127);
  Intake2.move(127);  
  pros::delay(1600);
  // Intake1.move(0);
  // Intake2.move(0);  
  MatchLoad.set_value(false);
 Intake2.move(-40);  

  chassis.pid_drive_set(15_in, DRIVE_SPEED);//30
  chassis.pid_wait();
  chassis.pid_turn_set(135_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(37_in, DRIVE_SPEED);//30
  // chassis.pid_wait_until(37_in);
 chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  // chassis.pid_wait_until(90_deg);
 chassis.pid_wait();
   chassis.pid_drive_set(48_in, DRIVE_SPEED);//30
  // chassis.pid_wait_until(48_in);
 chassis.pid_wait();
   chassis.pid_turn_set(180_deg, TURN_SPEED);
  // chassis.pid_wait_until(180_deg); 
 chassis.pid_wait();


   chassis.pid_drive_set(51_in, DRIVE_SPEED);//50
  // chassis.pid_wait_until(50_in);
 chassis.pid_wait();
   chassis.pid_turn_set(135_deg, TURN_SPEED);
  chassis.pid_wait(); 

  Intake1.move(-127);
  pros::delay(50);

  chassis.pid_drive_set(-28_in, DRIVE_SPEED);//-23
  CenterGoal.set_value(true);
  Intake1.move(0);

  chassis.pid_wait_until(-20_in);//
  Intake1.move(127);
  Intake2.move(30);
  CenterGoal.set_value(true);
  pros::delay(1600);//900
  Intake2.move(127);
  CenterGoal.set_value(false);

  
   chassis.pid_drive_set(30_in, DRIVE_SPEED);//30
    chassis.pid_wait();

  // chassis.pid_wait_until(30_in);
  chassis.pid_turn_set(90_deg, TURN_SPEED);
   chassis.pid_wait();
  // chassis.pid_wait_until(90_deg);
  chassis.pid_drive_set(23_in, DRIVE_SPEED);//30
   chassis.pid_wait();
  // chassis.pid_wait_until(24_in); 
 chassis.pid_swing_set(ez::RIGHT_SWING, 0_deg, SWING_SPEED, 0);
 chassis.pid_wait();
  // Intake1.move(-127);
  // Intake2.move(-127);

//   chassis.pid_drive_set(10_in, DRIVE_SPEED);//30
//   chassis.pid_wait_until(7_in); 
//   MatchLoad.set_value(true);
  
//  chassis.drive_set(80, 80);

//  pros::delay(500);
// MatchLoad.set_value(false);
// pros::delay(600);
//   chassis.drive_set(0, 0);

  chassis.pid_drive_set(40_in, 40);//30
  chassis.pid_wait_until(7_in); 
  MatchLoad.set_value(true);
  chassis.pid_speed_max_set(DRIVE_SPEED);
  chassis.pid_wait_until(13_in);
  // MatchLoad.set_value(false); 
  chassis.pid_wait_until(40_in); 
  MatchLoad.set_value(false);
//  pros::delay(500);
}



///
// Turn Example
///
void turn_example() {
  // The first parameter is the target in degrees
  // The second parameter is max speed the robot will drive at

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
}

///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // pid_wait_until will wait until the robot gets to a desired position

  // When the robot gets to 6 inches slowly, the robot will travel the remaining distance at full speed
  chassis.pid_drive_set(24_in, 30, true);
  chassis.pid_wait_until(6_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);  // After driving 6 inches at 30 speed, the robot will go the remaining distance at DRIVE_SPEED
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  // When the robot gets to -6 inches slowly, the robot will travel the remaining distance at full speed
  chassis.pid_drive_set(-24_in, 30, true);
  chassis.pid_wait_until(-6_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);  // After driving 6 inches at 30 speed, the robot will go the remaining distance at DRIVE_SPEED
  chassis.pid_wait();
}

///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is the target in degrees
  // The third parameter is the speed of the moving side of the drive
  // The fourth parameter is the speed of the still side of the drive, this allows for wider arcs

  chassis.pid_swing_set(ez::LEFT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();
}

///
// Motion Chaining
///
void motion_chaining() {
  // Motion chaining is where motions all try to blend together instead of individual movements.
  // This works by exiting while the robot is still moving a little bit.
  // To use this, replace pid_wait with pid_wait_quick_chain.
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  // Your final motion should still be a normal pid_wait
  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Auto that tests everything
///
void combining_movements() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, -45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Interference example
///
void tug(int attempts) {
  for (int i = 0; i < attempts - 1; i++) {
    // Attempt to drive backward
    printf("i - %i", i);
    chassis.pid_drive_set(-12_in, 127);
    chassis.pid_wait();

    // If failsafed...
    if (chassis.interfered) {
      chassis.drive_sensor_reset();
      chassis.pid_drive_set(-2_in, 20);
      pros::delay(1000);
    }
    // If the robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, the robot will drive forward and turn 90 degrees.
// If interfered, the robot will drive forward and then attempt to drive backward.
void interfered_example() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  if (chassis.interfered) {
    tug(3);
    return;
  }

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
}

///
// Odom Drive PID
///
void odom_drive_example() {
  // This works the same as pid_drive_set, but it uses odom instead!
  // You can replace pid_drive_set with pid_odom_set and your robot will
  // have better error correction.

  chassis.pid_odom_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_odom_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_odom_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();
}

///
// Odom Pure Pursuit
///
void odom_pure_pursuit_example() {
  // Drive to 0, 30 and pass through 6, 10 and 0, 20 on the way, with slew
  chassis.pid_odom_set({{{6_in, 10_in}, fwd, DRIVE_SPEED},
                        {{0_in, 20_in}, fwd, DRIVE_SPEED},
                        {{0_in, 30_in}, fwd, DRIVE_SPEED}},
                       true);
  chassis.pid_wait();

  // Drive to 0, 0 backwards
  chassis.pid_odom_set({{0_in, 0_in}, rev, DRIVE_SPEED},
                       true);
  chassis.pid_wait();
}

///
// Odom Pure Pursuit Wait Until
///
void odom_pure_pursuit_wait_until_example() {
  chassis.pid_odom_set({{{0_in, 24_in}, fwd, DRIVE_SPEED},
                        {{12_in, 24_in}, fwd, DRIVE_SPEED},
                        {{24_in, 24_in}, fwd, DRIVE_SPEED}},
                       true);
  chassis.pid_wait_until_index(1);  // Waits until the robot passes 12, 24
  // Intake.move(127);  // Set your intake to start moving once it passes through the second point in the index
  chassis.pid_wait();
  // Intake.move(0);  // Turn the intake off
}

///
// Odom Boomerang
///
void odom_boomerang_example() {
  chassis.pid_odom_set({{0_in, 24_in, 45_deg}, fwd, DRIVE_SPEED},
                       true);
  chassis.pid_wait();

  chassis.pid_odom_set({{0_in, 0_in, 0_deg}, rev, DRIVE_SPEED},
                       true);
  chassis.pid_wait();
}

///
// Odom Boomerang Injected Pure Pursuit
///
void odom_boomerang_injected_pure_pursuit_example() {
  chassis.pid_odom_set({{{0_in, 24_in, 45_deg}, fwd, DRIVE_SPEED},
                        {{12_in, 24_in}, fwd, DRIVE_SPEED},
                        {{24_in, 24_in}, fwd, DRIVE_SPEED}},
                       true);
  chassis.pid_wait();

  chassis.pid_odom_set({{0_in, 0_in, 0_deg}, rev, DRIVE_SPEED},
                       true);
  chassis.pid_wait();
}

///
// Calculate the offsets of your tracking wheels
///
void measure_offsets() {
  // Number of times to test
  int iterations = 10;

  // Our final offsets
  double l_offset = 0.0, r_offset = 0.0, b_offset = 0.0, f_offset = 0.0;

  // Reset all trackers if they exist
  if (chassis.odom_tracker_left != nullptr) chassis.odom_tracker_left->reset();
  if (chassis.odom_tracker_right != nullptr) chassis.odom_tracker_right->reset();
  if (chassis.odom_tracker_back != nullptr) chassis.odom_tracker_back->reset();
  if (chassis.odom_tracker_front != nullptr) chassis.odom_tracker_front->reset();
  
  for (int i = 0; i < iterations; i++) {
    // Reset pid targets and get ready for running an auton
    chassis.pid_targets_reset();
    chassis.drive_imu_reset();
    chassis.drive_sensor_reset();
    chassis.drive_brake_set(MOTOR_BRAKE_HOLD);
    chassis.odom_xyt_set(0_in, 0_in, 0_deg);
    double imu_start = chassis.odom_theta_get();
    double target = i % 2 == 0 ? 90 : 270;  // Switch the turn target every run from 270 to 90

    // Turn to target at half power
    chassis.pid_turn_set(target, 63, ez::raw);
    chassis.pid_wait();
    pros::delay(250);

    // Calculate delta in angle
    double t_delta = util::to_rad(fabs(util::wrap_angle(chassis.odom_theta_get() - imu_start)));

    // Calculate delta in sensor values that exist
    double l_delta = chassis.odom_tracker_left != nullptr ? chassis.odom_tracker_left->get() : 0.0;
    double r_delta = chassis.odom_tracker_right != nullptr ? chassis.odom_tracker_right->get() : 0.0;
    double b_delta = chassis.odom_tracker_back != nullptr ? chassis.odom_tracker_back->get() : 0.0;
    double f_delta = chassis.odom_tracker_front != nullptr ? chassis.odom_tracker_front->get() : 0.0;

    // Calculate the radius that the robot traveled
    l_offset += l_delta / t_delta;
    r_offset += r_delta / t_delta;
    b_offset += b_delta / t_delta;
    f_offset += f_delta / t_delta;
  }

  // Average all offsets
  l_offset /= iterations;
  r_offset /= iterations;
  b_offset /= iterations;
  f_offset /= iterations;

  // Set new offsets to trackers that exist
  if (chassis.odom_tracker_left != nullptr) chassis.odom_tracker_left->distance_to_center_set(l_offset);
  if (chassis.odom_tracker_right != nullptr) chassis.odom_tracker_right->distance_to_center_set(r_offset);
  if (chassis.odom_tracker_back != nullptr) chassis.odom_tracker_back->distance_to_center_set(b_offset);
  if (chassis.odom_tracker_front != nullptr) chassis.odom_tracker_front->distance_to_center_set(f_offset);
}

// . . .
// Make your own autonomous functions here!
// . . .