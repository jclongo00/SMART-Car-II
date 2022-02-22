# File:      main_controller.py
# Date:      2/22/2022
# Version:   1.1
# Motor:
#   Frequency:     93-93.3Hz
#   Motor forward: 13% - 16%
#   Motor Reverse: %
#   Motor idle:    14.9%
# Servo:
#   Frequency:     187.5Hz
#   Left:          20%
#   Right:         35%
#   Idle:          27.5%


import RPi.GPIO as GPIO
from time import sleep

motorPin = 12     # PWM pin connected to Motor
servoPin = 16     # PWM pin connected to Servo


def setup():
    GPIO.setwarnings(False)          #disable warnings
    GPIO.setmode(GPIO.BOARD)         #set pin numbering system
    GPIO.setup(motorPin,GPIO.OUT)
    GPIO.setup(servoPin,GPIO.OUT)
    print('setup')


def motor():
    
    for dc in range(20, 36):                 # Loop 20 to 36 stepping dc by 1 each loop
        motor_pwm.ChangeDutyCycle(dc/2)      # Uses the loop to increment the motor duty cycle
        sleep(0.05)                          # wait .05 seconds at current LED brightness
    for dc in range(36, 20):                 # Loop 0 to 100 stepping dc by 5 each loop
        motor_pwm.ChangeDutyCycle(dc/2)      #
        sleep(0.05)                          # wait .05 seconds at current LED brightness

def servo():
    for dc in range(40, 72):    # Loop 20 to 35 stepping dc by .5 each loop
        servo_pwm.ChangeDutyCycle(dc/2)
        sleep(0.5)             # wait .05 seconds at current LED brightness
    for dc in range(70, 38, -1):    # Loop 20 to 35 stepping dc by .5 each loop
        servo_pwm.ChangeDutyCycle(dc/2)
        sleep(0.5)             # wait .05 seconds at current LED brightness


def loop():
    #motor()
    servo()
    #sleep(.001)
 
def destroy():
    GPIO.cleanup()
 
if __name__ == '__main__':
    print('program start')
    setup()
    try:
        motor_pwm = GPIO.PWM(motorPin,93.3) #create PWM instance with frequency
        motor_pwm.start(14.9)
        servo_pwm = GPIO.PWM(servoPin,187.5) #create PWM instance with frequency
        servo_pwm.start(20)
        loop()
    except KeyboardInterrupt:
        destroy()



