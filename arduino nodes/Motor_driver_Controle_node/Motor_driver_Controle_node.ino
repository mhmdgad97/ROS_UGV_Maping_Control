#include <ros.h>
#include <geometry_msgs/Twist.h>

//Creating Nodehandle
ros::NodeHandle nh;


float throttle, direction;

//Defining callback just read from topic and save to inx,angz
void filterVelocityCallback(const geometry_msgs::Twist& msg) {
  //Using the callback function just for subscribing
  //Subscribing the message and storing it in 'linx' and 'angZ'
  throttle = msg.linear.x;      direction = msg.angular.z;

}

//Defining Subscriber
ros::Subscriber<geometry_msgs::Twist> sub("/cmd_vel", filterVelocityCallback);


//------------------------------------------------------

const byte controllerFA = 3; //PWM FORWARD PIN for OSMC Controller A (left motor)
const byte controllerRA = 2;  //PWM DIRECTION PIN for OSMC Controller A (left motor)
const byte controllerFB = 5;  //PWM FORWARD PIN for OSMC Controller B (right motor)
const byte controllerRB = 4;  //PWM DIRECTION PIN for OSMC Controller B (right motor)

int leftMotor, leftMotorScaled = 0; //left Motor helper variables
int rightMotor, rightMotorScaled = 0; //right Motor helper variables
int deadZone = 10; //jostick dead zone


void setup() {
  //Initializing node
  nh.initNode();
  //Start subscribing
  nh.subscribe(sub);

  pinMode(controllerFA, OUTPUT);
  pinMode(controllerRA, OUTPUT);
  pinMode(controllerFB, OUTPUT);
  pinMode(controllerRB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //mix throttle and direction
  leftMotor = throttle - direction;
  rightMotor = throttle + direction;

  leftMotorScaled = constrain(leftMotor, -255, 255);
  rightMotorScaled = constrain(rightMotor, -255, 255);

  //apply the results to appropriate uC PWM outputs for the LEFT motor:
  if (abs(leftMotorScaled) > deadZone)
  {
    if (leftMotorScaled > 0)
    {
      digitalWrite(controllerRA, LOW);
      analogWrite(controllerFA, abs(leftMotorScaled));
    }
    else
    {
      digitalWrite(controllerRA, HIGH);
      analogWrite(controllerFA, abs(leftMotorScaled));
    }
  }
  else
  {
    analogWrite(controllerFA, 0);
    digitalWrite(controllerRA, LOW);
  }


  //apply the results to appropriate uC PWM outputs for the RIGHT motor:
  if (abs(rightMotorScaled) > deadZone)
  {

    if (rightMotorScaled > 0)
    {
      digitalWrite(controllerRB, LOW);
      analogWrite(controllerFB, abs(rightMotorScaled));
    }
    else
    {
      digitalWrite(controllerRB, HIGH);
      analogWrite(controllerFB, abs(rightMotorScaled));
    }
  }
  else
  {
    analogWrite(controllerFB, 0);
    digitalWrite(controllerRB, LOW);
  }

  //nh.loginfo("nsocb")
  //rate.sleep();
  nh.spinOnce();
  delay(3);
}
