import pygame
import serial
import time

ser = serial.Serial('COM11', 115200)
time.sleep(2)

pygame.init()
pygame.joystick.init()
joystick = pygame.joystick.Joystick(0)
joystick.init()

def scale(val):
    return int(val * 255)

def send_pwm(left_pwm, right_pwm):
    msg = f"{left_pwm},{right_pwm}\n"
    ser.write(msg.encode())

try:
    while True:
        pygame.event.pump()
        x = joystick.get_axis(0)
        y = -joystick.get_axis(1)  # invert if needed

        left = scale(y + x)
        right = scale(y - x)

        left = max(-255, min(255, left))
        right = max(-255, min(255, right))

        send_pwm(left, right)
        print(f"Sent -> L: {left}, R: {right}")
        time.sleep(0.05)

except KeyboardInterrupt:
    send_pwm(0, 0)
    ser.close()
