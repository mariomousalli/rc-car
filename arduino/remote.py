import serial
import keyboard

# Change 'COM5' to your actual Bluetooth serial port
bluetooth = serial.Serial("COM6", 9600)  # Ensure this matches your Bluetooth COM port
print("Bluetooth connected.")
print("Press 'w' to move forward, 's' to move backward, 'a' to turn left, 'd' to turn right, and 'esc' to exit.")

try:
    while True:
        command = ""  # Start with an empty command

        # Check which keys are pressed
        if keyboard.is_pressed('w'):
            command += "w"  # Add 'w' for forward
        if keyboard.is_pressed('s'):
            command += "s"  # Add 's' for backward
        if keyboard.is_pressed('a'):
            command += "a"  # Add 'a' for left
        if keyboard.is_pressed('d'):
            command += "d"  # Add 'd' for right

        # If no keys are pressed, send a stop signal
        if command == "":
            bluetooth.write(b' ')  # Send a space to stop
        else:
            bluetooth.write(command.encode())  # Send the combined command

        # Exit condition
        if keyboard.is_pressed('esc'):
            print("Exiting...")
            bluetooth.write(b' ')  # Send a stop signal when exiting
            break  # Exit the loop when ESC is pressed

except KeyboardInterrupt:
    print("Program interrupted by user.")