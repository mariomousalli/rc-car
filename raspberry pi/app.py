from flask import Flask, render_template_string, request
import serial
import time

# --- Configuration ---
# IMPORTANT: You might need to change '/dev/ttyACM0' to match the port of your Pico
# You can find the port by running 'ls /dev/tty*' in the Pi's terminal after connecting the Pico.
SERIAL_PORT = '/dev/ttyACM0'
BAUD_RATE = 115200

# --- Flask App Initialization ---
app = Flask(__name__)

# --- Serial Connection Setup ---
# We use a try-except block to handle cases where the Pico is not connected
try:
    pico = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
    print(f"Successfully connected to Pico on {SERIAL_PORT}")
except serial.SerialException as e:
    pico = None
    print(f"Could not connect to Pico on {SERIAL_PORT}. Running in dummy mode.")
    print(f"Error: {e}")

# --- HTML Template for the Web Interface ---
# This is the webpage that will be shown on your iPhone's browser.
HTML_TEMPLATE = """
<!DOCTYPE html>
<html>
<head>
    <title>RC Car Control</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body { font-family: Arial, sans-serif; text-align: center; background-color: #282c34; color: white; }
        .title { margin-top: 20px; }
        .grid-container {
            display: grid;
            grid-template-columns: repeat(3, 1fr);
            grid-template-rows: repeat(3, 1fr);
            gap: 10px;
            max-width: 300px;
            margin: 30px auto;
        }
        button {
            width: 100%;
            height: 80px;
            font-size: 24px;
            color: white;
            background-color: #61afef;
            border: none;
            border-radius: 10px;
            cursor: pointer;
        }
        button:active {
            background-color: #c678dd;
        }
        #forward { grid-column: 2; grid-row: 1; }
        #left { grid-column: 1; grid-row: 2; }
        #stop { grid-column: 2; grid-row: 2; background-color: #e06c75; }
        #right { grid-column: 3; grid-row: 2; }
        #backward { grid-column: 2; grid-row: 3; }
    </style>
</head>
<body>
    <h1 class="title">Robot Control</h1>
    <form method="post" action="/control">
        <div class="grid-container">
            <button id="forward" name="direction" value="F">▲</button>
            <button id="left" name="direction" value="L">◄</button>
            <button id="stop" name="direction" value="S">■</button>
            <button id="right" name="direction" value="R">►</button>
            <button id="backward" name="direction" value="B">▼</button>
        </div>
    </form>
</body>
</html>
"""

# --- Web Routes ---
@app.route('/')
def index():
    return render_template_string(HTML_TEMPLATE)

@app.route('/control', methods=['POST'])
def control():
    command = request.form.get('direction')
    if command and pico:
        print(f"Sending command: {command}")
        pico.write(command.encode('utf-8')) # Send command to Pico
    elif command:
        print(f"DUMMY MODE: Received command '{command}', but Pico is not connected.")
    return render_template_string(HTML_TEMPLATE)

# --- Main Execution ---
if __name__ == '__main__':
    # '0.0.0.0' makes the server accessible from any device on your network (like your iPhone)
    app.run(host='0.0.0.0', port=5000, debug=True)

