from flask import Flask, request, render_template
import sqlite3

app = Flask(__name__)

# Home page
@app.route('/')
def home():
    return render_template('index.html')

# Login page
@app.route('/login')
def login():
    return render_template('login.html')

# Signup page
@app.route('/signup')
def signup():
    return render_template('signup.html')

# Handle login form
@app.route('/login_submit', methods=['POST'])
def login_submit():
    # Print all form data
    print("Login form data:", request.form, flush=True)

    # Get values safely
    email = request.form.get('email')
    password = request.form.get('password')

    return f"<h2>Login Successful!</h2><p>Email: {email}</p><p>Password: {password}</p>"

# Handle signup form
@app.route('/signup_submit', methods=['POST'])
def signup_submit():
    print("Signup form data:", request.form, flush=True)

    name = request.form.get('signupname')
    email = request.form.get('signupemail')
    password = request.form.get('signuppassword')
    mobile = request.form.get('mobileno')
    age = request.form.get('age')
    gender = request.form.get('gender')

    return f"<h2>Signup Successful!</h2><p>Name: {name}</p><p>Email: {email}</p><p>Password: {password}</p>"
    conn = sqlite3.connect("signup.db")
    cursor = conn.cursor()

    cursor.execute("""
CREATE TABLE IF NOT EXISTS student (
    name TEXT )
""")

if __name__ == "__main__":
    app.run(debug=True, use_reloader=False, host="192.168.17.145", port="5000")
