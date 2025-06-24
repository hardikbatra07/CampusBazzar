# 🛒 Campus Bazzar

**Campus Bazzar** is a full-stack, student-centric marketplace built to help over **2,500+ university students** securely buy, sell, and browse pre-owned items on campus. The platform features a responsive interface, efficient search capabilities, and secure transactions — all powered by a robust backend API.

---

## 🚀 Features

- 🛍️ **Marketplace for Students** — List, discover, and purchase items within your campus network.
- 🔒 **User Authentication** — Secure login and registration functionality.
- ⚡ **Optimized Performance** — Fast loading and responsive UI across devices.
- 🔍 **Search and Filters** — Browse items by category, price, or keyword.
- 📦 **Transaction Workflow** — Simple and secure item listing and inquiry process.

---

## 🛠️ Tech Stack

| Technology     | Description                                  |
|----------------|----------------------------------------------|
| **JavaScript** | Core programming language for both frontend and backend |
| **Node.js**    | Backend runtime environment                  |
| **Express.js** | RESTful API development                      |
| **SQL**        | Relational database for storing users/items  |
| **HTML/CSS**   | UI and layout                                |

---

## 📁 Folder Structure

```bash
campus-bazzar/
├── client/                 # Frontend (optional)
├── server/                 # Node.js backend
│   ├── routes/
│   ├── controllers/
│   ├── models/
│   └── config/
├── database/
│   └── schema.sql
├── .env
├── package.json
└── README.md

⚙️ Setup Instructions
1. Clone the Repository
git clone https://github.com/hardikbatra07/CampusBazzar.git
cd CampusBazzar


2. Set Up Environment Variables
DB_USER=your_database_user
DB_PASSWORD=your_database_password
DB_NAME=campus_bazzar
DB_HOST=localhost
PORT=4000


3. Install Dependencies
# From the root folder
cd server
npm install


4. Run the Server
npm run start

