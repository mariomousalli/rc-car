from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/forward')
def move_forward():
    print("Moving forward")
    return "Forward command sent"

@app.route('/backward')
def move_backward():
    print("Moving backward")
    return "Backward command sent"

@app.route('/left')
def turn_left():
    print("Turning left")
    return "Left command sent"

@app.route('/right')
def turn_right():
    print("Turning right")
    return "Right command sent"

@app.route('/stop')
def stop():
    print("Stop")
    return "Stop command sent"

if __name__ == '__main__':
    app.run(debug=True)
