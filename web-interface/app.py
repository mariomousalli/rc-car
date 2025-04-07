from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/forward', methods=['GET'])
def move_forward():
    print("Moving forward")
    return "Moving forward", 200

@app.route('/backward', methods=['GET'])
def move_backward():
    print("Moving backward")
    return "Moving backward", 200

@app.route('/left', methods=['GET'])
def move_left():
    print("Turning left")
    return "Turning left", 200

@app.route('/right', methods=['GET'])
def move_right():
    print("Turning right")
    return "Turning right", 200

@app.route('/stop', methods=['GET'])
def stop():
    print("Stopping")
    return "Stopping", 200

if __name__ == "__main__":
    app.run(debug=True)
    