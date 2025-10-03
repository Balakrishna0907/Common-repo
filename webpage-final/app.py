from flask import Flask, request, render_template, redirect, url_for
import sqlite3

app = Flask(__name__)

DB_NAME = "Registration.db"

# ----------------- Initialize Database -----------------
def init_db():
    conn = sqlite3.connect(DB_NAME)
    c = conn.cursor()
    c.execute('''
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT, 
            name TEXT NOT NULL,
            email TEXT UNIQUE NOT NULL,
            password TEXT NOT NULL,
            dob TEXT NOT NULL,
            contact TEXT NOT NULL,
            age INTEGER NOT NULL,
            gender TEXT NOT NULL
        )
    ''')
    conn.commit()
    conn.close()

init_db()

# ----------------- Routes -----------------

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        name = request.form["name"]
        email = request.form["email"]
        password = request.form["password"]
        dob = request.form["dob"]
        contact = request.form["contact"]
        age = request.form["age"]
        gender = request.form["gender"]

        conn = sqlite3.connect(DB_NAME)
        c = conn.cursor()
        try:
            c.execute("INSERT INTO users (name, email, password, dob, contact, age, gender) VALUES (?, ?, ?, ?, ?, ?, ?)",
                      (name, email, password, dob, contact, age, gender))
            conn.commit()
        except sqlite3.IntegrityError:
            conn.close()
            return "Error: Email already exists!"
        conn.close()
        return redirect(url_for("login"))

    return render_template("register.html")

@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        email = request.form["email"]
        password = request.form["password"]

        conn = sqlite3.connect(DB_NAME)
        c = conn.cursor()
        c.execute("SELECT * FROM users WHERE email=? AND password=?", (email, password))
        user = c.fetchone()
        conn.close()

        if user:
            return redirect(url_for("profile", email=email))
        else:
            return "Invalid email or password! If you dont have an account Register first!"
    return render_template("login.html")

@app.route("/profile")
def profile():
    email = request.args.get("email")
    if not email:
        return "No user specified!"

    conn = sqlite3.connect(DB_NAME)
    c = conn.cursor()
    c.execute("SELECT id, name, email, dob, contact, age, gender FROM users WHERE email=?", (email, ))
    user = c.fetchone()
    conn.close()

    if not user:
        return "User not found!"
    return render_template("profile.html", user=user)


# Static pages
@app.route("/academic")
def academic():
    email = request.args.get("email")
    if not email:
        return "No user specified!"

    conn = sqlite3.connect(DB_NAME)
    c = conn.cursor()
    c.execute("SELECT id, name, email, dob, contact, age, gender FROM users WHERE email=?", (email,))
    user = c.fetchone()
    conn.close()

    if not user:
        return "User not found!"
    return render_template("academic.html", user=user)


@app.route("/hostel")
def hostel():
    email = request.args.get("email")
    if not email:
        return "No user specified!"

    conn = sqlite3.connect(DB_NAME)
    c = conn.cursor()
    c.execute("SELECT id, name, email, dob, contact, age, gender FROM users WHERE email=?", (email,))
    user = c.fetchone()
    conn.close()

    if not user:
        return "User not found!"
    return render_template("hostel.html", user=user)

@app.route("/finance")
def finance():
    email = request.args.get("email")
    if not email:
        return "No user specified!"

    conn = sqlite3.connect(DB_NAME)
    c = conn.cursor()
    c.execute("SELECT id, name, email, dob, contact, age, gender FROM users WHERE email=?", (email,))
    user = c.fetchone()
    conn.close()

    if not user:
        return "User not found!"
    return render_template("finance.html", user=user)


if __name__ == "__main__":
    app.run(debug=True)
