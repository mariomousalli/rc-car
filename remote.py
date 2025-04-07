import serial
import keyboard

# Change 'COM5' to your actual Bluetooth serial port
bluetooth = serial.Serial("COM6", 9600)  # Ensure this matches your Bluetooth COM port
print("Bluetooth connected.")
print("Press 'w' to move forward, 's' to move backward, 'a' to turn left, 'd' to turn right, and 'esc' to exit.")

try:
    while True:
        if keyboard.is_pressed('w'):
            print("Moving Forward (w)")
            bluetooth.write(b'w')  # Send 'w' to Arduino when 'w' is pressed

        elif keyboard.is_pressed('s'):
            print("Moving Backward (s)")
            bluetooth.write(b's')  # Send 's' to Arduino when 's' is pressed

        elif keyboard.is_pressed('a'):
            print("Turning Left (a)")
            bluetooth.write(b'a')  # Send 'a' to Arduino when 'a' is pressed

        elif keyboard.is_pressed('d'):
            print("Turning Right (d)")
            bluetooth.write(b'd')  # Send 'd' to Arduino when 'd' is pressed

        else:
            # If no key is pressed, stop the car
            bluetooth.write(b' ')  # Send a stop signal when no key is pressed

        if keyboard.is_pressed('esc'):
            print("Exiting...")
            bluetooth.write(b' ')  # Send a stop signal when exiting
            break  # Exit the loop when ESC is pressed

except KeyboardInterrupt:
    print("Program interrupted by user.")
