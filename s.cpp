This is pro.ejs 
product page : 
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Products Available</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
    <style>
       html, body {
    height: 100%;  /* Ensure the body takes full height */
    margin: 0;  /* Remove default margin */
}

body {
    display: flex;
    flex-direction: column;
    background-color: white;
    color: rgb(59, 10, 69);
}

main {
    flex-grow: 1;  /* Main content area will take up available space */
}

footer {
    background-color: rgb(59, 10, 69);
    color: white;
    padding: 10px 0;
    font-size: 0.9em;
    text-align: center;
}

        body {
            background-image: url('campus2.jpg');
           background-size: cover;
            background-color: white;
            color: rgb(59, 10, 69);
        }
        h2 {
            color: rgb(59, 10, 69);
            text-align: center;
            margin-top: 20px;
            font-weight: bold;
        }
        .card {
            border: 1px solid rgb(59, 10, 69);
            background-color: white;
            color: rgb(59, 10, 69);
            display: flex;
            align-items: center;
            padding: 15px;
            flex-direction: row;
        }
        .post img {
            width: 150px;
            height: auto;
            margin-right: 20px;
            border-radius: 8px;
        }
        .post-content {
            flex-grow: 1;
        }
        .post-actions {
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
        }
        .post-actions .btn {
            width: 100px;
            margin: 5px 0;
        }
        .btn-primary {
            background-color: rgb(59, 10, 69);
            border-color: rgb(59, 10, 69);
        }
        .btn-danger {
            background-color: rgb(165, 218, 240);
            border-color: rgb(165, 218, 240);
        }
        footer {
            background-color: rgb(59, 10, 69);
            color: white;
            padding: 10px 0;
            font-size: 0.9em;
        }
        .ca{
          margin-bottom: 20px;
          color: rgb(59, 10, 69);
          text-decoration: solid;
          font-family: Georgia, 'Times New Roman', Times, serif;
          font-size: 50px;
        }
        .caa{
          text-align: center;
          font-family: 'Gill Sans', 'Gill Sans MT', Calibri, 'Trebuchet MS', sans-serif;
          font-size: 25px;
        }
    </style>
</head>
<body>
    <header class="p-3 mb-3 border-bottom">
        
        <div class="container">

            <div class="d-flex flex-wrap align-items-center justify-content-center justify-content-lg-start">
                <a href="/" class="d-flex align-items-center mb-2 mb-lg-0 text-decoration-none" style="color: rgb(59, 10, 69);">
                    <svg class="bi me-2" width="40" height="32" role="img" aria-label="Bootstrap"><use xlink:href="#bootstrap"></use></svg>
                </a>

                <form class="col-12 col-lg-auto mb-3 mb-lg-0 me-lg-3" role="search" action="/search" method="GET">
                    <input type="search" class="form-control" placeholder="Search..." aria-label="Search" name="q">
                </form>

                <ul class="nav col-12 col-lg-auto me-lg-auto mb-2 justify-content-center mb-md-0">
                    <li><a href="/create" class="nav-link px-2" style="color: rgb(59, 10, 69);"> <b>Add Product</b></a></li>
                </ul>

                <div class="dropdown text-end">
                    <a href="#" class="d-block text-decoration-none dropdown-toggle" data-bs-toggle="dropdown" aria-expanded="false" style="color: rgb(59, 10, 69);">
                        <img src="https://static.vecteezy.com/system/resources/thumbnails/009/734/564/small/default-avatar-profile-icon-of-social-media-user-vector.jpg"  width="32" height="32" class="rounded-circle">
                    </a>
                    <ul class="dropdown-menu text-small">
                        
                        <% if (userRole === 'admin') { %>
                            <li><a class="dropdown-item" href="/admin/users">Users data</a></li>
                          <% } %>
                          <% if (userRole === 'admin') { %>
                            <li><a class="dropdown-item" href="/admin/products">Products</a></li>
                          <% } %>
                        <li><a class="dropdown-item" href="/up">Profile</a></li>
                        <li><hr class="dropdown-divider"></li>
                        <li><a class="dropdown-item" href="/">Sign out</a></li>
                    </ul>
                </div>
            </div>
        </div>
    </header>

    <main>
        <h2 class="ca">Products Available </h2>
        <div class="container">
            <% if (posts && posts.length === 0) { %>
                <p class="caa">No products available at present.</p>
            <% } else { %>
                <% posts.forEach(post => { %>
                    <div class="post card mb-3">
                        <% if (post.image_url) { %>
                            <img src="<%= post.image_url %>" alt="<%= post.title %>">
                        <% } %>
                        <div class="post-content">
                            <h3 class="card-title"><%= post.title %></h3>
                            <p class="card-text"><%= post.content %></p>
                            <p><strong>Mobile Number:</strong> <%= post.mobile_number %></p>
                        <p><strong>Email Address:</strong> <%= post.email_address %></p>
                        <p><strong>Expected Amount:</strong> $<%= post.expected_amount %></p>
                        </div>
                        <div class="post-actions">
                            <a href="/edit/<%= post.id %>" class="btn btn-primary">Edit</a>
                            <form action="/delete/<%= post.id %>" method="POST" style="display:inline;">
                                <button type="submit" class="btn btn-danger">Delete</button>
                            </form>
                        </div>
                    </div>
                <% }) %>
            <% } %>
        </div>
    </main>

     <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz" crossorigin="anonymous"></script>
     
</body>
<footer class="text-center mt-4">
    <p>&copy; 2024 College Bazaar</p>
  </footer>
</html>

this is create post.ejs
create post page
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Create New Post</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
    <style>
        body {
            background-color: white;
            color: rgb(59, 10, 69);
            font-family: Arial, sans-serif;
            background-image: url('campus2.jpg');
            background-size: cover;
            background-attachment: fixed;
        }
        h2 {
            text-align: center;
            color: rgb(59, 10, 69);
            margin-top: 50px;
            font-weight: bold;
        }
        main {
            max-width: 500px;
            margin: 20px auto;
            background-color: rgba(255, 255, 255, 0.9);
            padding: 30px;
            border-radius: 8px;
            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
            color: rgb(59, 10, 69);
        }
        label {
            font-weight: bold;
            color: rgb(59, 10, 69);
            margin-top: 10px;
        }
        input[type="text"], input[type="email"], input[type="number"], textarea, input[type="file"] {
            width: 100%;
            padding: 8px;
            margin-top: 5px;
            border: 1px solid #d8bfd8;
            border-radius: 4px;
            background-color: #fff0f5;
            color: rgb(59, 10, 69);
        }
        button[type="submit"] {
            width: 100%;
            padding: 10px;
            margin-top: 20px;
            background-color: rgb(59, 10, 69);
            color: white;
            border: none;
            border-radius: 4px;
            font-size: 16px;
            font-weight: bold;
            cursor: pointer;
        }
        button[type="submit"]:hover {
            background-color: #d2a4d2;
        }
        footer {
            text-align: center;
            margin-top: 30px;
            color: rgb(59, 10, 69);
        }
    </style>
    <script>
        function validateForm() {
            const email = document.getElementById("email").value;
            const mobile = document.getElementById("mobile").value;
            const amount = document.getElementById("amount").value;

            // Validate email
            const emailPattern = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
            if (!emailPattern.test(email)) {
                alert("Please enter a valid email address.");
                return false;
            }

            // Validate mobile number (10-digit number)
            const mobilePattern = /^\d{10}$/;
            if (!mobilePattern.test(mobile)) {
                alert("Please enter a valid 10-digit mobile number.");
                return false;
            }

            // Check if amount is a positive number
            if (amount <= 0 || isNaN(amount)) {
                alert("Please enter a valid amount greater than zero.");
                return false;
            }

            return true;
        }
    </script>
</head>
<body>
    <main>
        <h2>Add Product to Sell</h2>
        <form action="/create" method="POST" enctype="multipart/form-data" onsubmit="return validateForm()">
            <label for="title">Product:</label>
            <input type="text" id="title" name="title" required>

            <label for="content">Description:</label>
            <textarea id="content" name="content" required rows="4"></textarea>

            <label for="email">Email Address:</label>
            <input type="email" id="email" name="email" required>

            <label for="mobile">Mobile Number:</label>
            <input type="text" id="mobile" name="mobile" required>

            <label for="amount">Expected Amount:</label>
            <input type="number" id="amount" name="amount" required>

            <label for="image">Upload Image:</label>
            <input type="file" id="image" name="image" accept="image/*" required>
            
            <button type="submit">Add Product</button>
        </form>
    </main>

    <footer>
        <p>&copy; 2024 College Bazaar</p>
    </footer>
</body>
</html>

this is javascript file 


import express from "express";
import bodyParser from "body-parser";
import multer from "multer";
import path from "path";
import { fileURLToPath } from 'url';
import { dirname } from 'path';
import pg from "pg";
import nodemailer from "nodemailer";
import session from "express-session";
import fs from "fs";

const app = express();
const port = 3000;

const __filename = fileURLToPath(import.meta.url);
const __dirname = dirname(__filename);

const db = new pg.Client({
  user: "postgres",
  host: "localhost",
  database: "world",
  password: "nityajungra",
  port: 4000,
});
db.connect();

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
 app.use(express.static("public"));
//app.use("/uploads", express.static("public/uploads"));

// Configure multer for file uploads
const storage = multer.diskStorage({
  destination: "public/uploads/",
  filename: (req, file, cb) => {
      cb(null, Date.now() + path.extname(file.originalname)); // Save with unique timestamp filename
  }
});
const upload = multer({ storage: storage });
const maill="";


app.use(session({
  secret: "your_secret_key",
  resave: false,
  saveUninitialized: true,
  cookie: { maxAge: 600000 } // 10-minute expiry
}));

app.set("view engine", "ejs");

// Nodemailer setup
const transporter = nodemailer.createTransport({
  service: "gmail",
  auth: {
     user: "collegebazaar4@gmail.com",
    pass: "gnnqubmaxclpamla"
    // user: "shraddhasri743@gmail.com",
    // pass: "twbyzemqisnvyvri"
  }
});

// Function to generate a random 6-digit OTP
function generateOTP() {
  return Math.floor(100000 + Math.random() * 900000).toString();
}

// Middleware to check if the user is an admin
function isAdmin(req, res, next) {
  if (req.session.userEmail) {
    db.query("SELECT role FROM userinfo WHERE email = $1", [req.session.userEmail])
      .then(result => {
        if (result.rows[0].role === "admin") {
          next();
        } else {
          res.status(403).send("Access denied");
        }
      })
      .catch(err => {
        console.error("Error checking admin role:", err);
        res.status(500).send("Server error");
      });
  } else {
    res.status(403).send("Not authenticated");
  }
}
// Route to view all users
app.get("/admin/users", isAdmin, async (req, res) => {
  try {
    const usersResult = await db.query("SELECT * FROM userinfo");
    const users = usersResult.rows;
    res.render("adminUsers.ejs", { users });
  } catch (err) {
    console.error("Error fetching users:", err);
    res.status(500).send("Error fetching users");
  }
});

// Route to view all products
app.get("/admin/products", isAdmin, async (req, res) => {
  try {
    const postsResult = await db.query("SELECT * FROM posts ORDER BY created_at DESC");
    const posts = postsResult.rows;
    res.render("adminProducts.ejs", { posts });
  } catch (err) {
    console.error("Error fetching posts:", err);
    res.status(500).send("Error fetching posts");
  }
});
app.post("/admin/delete-user/:id", isAdmin, async (req, res) => {
  const { id } = req.params;
  try {
    await db.query("DELETE FROM userinfo WHERE id = $1", [id]);
    res.redirect("/admin/users");
  } catch (err) {
    console.error("Error deleting user:", err);
    res.status(500).send("Error deleting user");
  }
});
app.post("/admin/delete-product/:id", isAdmin, async (req, res) => {
  const { id } = req.params;
  try {
    const postResult = await db.query("SELECT * FROM posts WHERE id = $1", [id]);
    const post = postResult.rows[0];
    if (post && fs.existsSync(path.join(__dirname, "public", post.image_url))) {
      fs.unlinkSync(path.join(__dirname, "public", post.image_url)); // Delete the image file
    }
    await db.query("DELETE FROM posts WHERE id = $1", [id]);
    res.redirect("/admin/products");
  } catch (err) {
    console.error("Error deleting product:", err);
    res.status(500).send("Error deleting product");
  }
});
app.get("/", (req, res) => {
  res.render("home.ejs");
});

app.get("/login", (req, res) => {
  res.render("login.ejs");
});

app.get("/register", (req, res) => {
  res.render("register.ejs");
});

// Route to render Features page
app.get("/features", (req, res) => {
  res.render("features.ejs");
});

// Route to render About Us page
app.get("/about", (req, res) => {
  res.render("about.ejs");
});


// Registration Route
app.post("/register", async (req, res) => {
  const email = req.body.username;
  const password = req.body.password;
  

  try {
    const checkResult = await db.query("SELECT * FROM userinfo WHERE email = $1", [email]);
    if (checkResult.rows.length > 0) {
      res.send("Email already exists. Try logging in.");
    } else {
      await db.query("INSERT INTO userinfo (email, password) VALUES ($1, $2)", [email, password]);
      req.session.userEmail = email;
      const postsResult = await db.query("SELECT * FROM posts ORDER BY created_at DESC");
        const posts = postsResult.rows;
        const userRole='user';
      res.render("pro.ejs",{posts,userRole});
    }
  } catch (err) {
    console.log(err);
  }
});


// Login Route
app.post("/login", async (req, res) => {
  const email = req.body.username;
  const password = req.body.password;
  //maill=email;

  try {

    const result = await db.query("SELECT * FROM userinfo WHERE email = $1", [email]);
    if (result.rows.length > 0) {
      const user = result.rows[0];
      if (password === user.password) {
        req.session.userEmail = email; // Store user_id in session
        
        const userRoleResult = await db.query("SELECT role FROM userinfo WHERE email = $1", [req.session.userEmail]);
        const userRole = userRoleResult.rows[0]?.role;
        const postsResult = await db.query("SELECT * FROM posts ORDER BY created_at DESC");
        const posts = postsResult.rows;
        res.render("pro.ejs", { posts ,userRole});
      } else {
        res.render("fp.ejs");
      }
    } else {
      res.send("User not found");
    }
  } catch (err) {
    console.log(err);
  }
});


// Forget Password Route
app.get("/forget-password", (req, res) => {
  res.render("forget-password.ejs");
});

// Send OTP
app.post("/send-otp", async (req, res) => {
  const email = req.body.email;  // Email entered by the user
  const otp = generateOTP();  // Generate a random 6-digit OTP
  
  // Store email and OTP in session
  req.session.email = email;
  req.session.otp = otp;

  // Configure the email details
  const mailOptions = {
    from: "shraddhasri743@gmail.com", // Replace with your email
    to: email,
    subject: "Your OTP for Password Reset",
    text: `Your OTP is: ${otp}`
  };

  try {
    // Send the OTP via email
    await transporter.sendMail(mailOptions);
    res.json({ success: true, message: "OTP sent to your email." });
  } catch (error) {
    console.error("Error sending email:", error);
    res.json({ success: false, message: "Error sending OTP. Try again." });
  }
});


// Verify OTP
app.post("/verify-otp", (req, res) => {
  const { otp } = req.body;

  if (req.session.otp === otp) {
    req.session.otp = null;
    res.json({ success: true, message: "OTP verified. Proceed to reset password." });
  } else {
    res.json({ success: false, message: "Incorrect OTP. Try again." });
  }
});

// Reset Password
app.post("/reset-password", async (req, res) => {
  const newPassword = req.body.newPassword;
  const email = req.session.email;

  try {
    await db.query("UPDATE userinfo SET password = $1 WHERE email = $2", [newPassword, email]);
    req.session.destroy();
    res.render("home.ejs");
    // res.json({ success: true, message: "Password successfully reset." });
  } catch (err) {
    console.log(err);
    res.json({ success: false, message: "Error resetting password. Try again." });
  }
});


// Get products page

// Route to get all posts and render the index page
app.get("/pro", async (req, res) => {
  const userRole='user';
  try {
      const result = await db.query("SELECT * FROM posts ORDER BY created_at DESC");
      const posts = result.rows;
      res.render("pro.ejs", { posts,userRole });
  } catch (err) {
      console.error("Error fetching posts:", err);
      res.status(500).send("Error fetching posts");
  }
});

// Route to render the create post page
app.get("/create", (req, res) => {
  res.render("createPost.ejs");
});

// Route to handle post creation with image upload
app.post("/create", upload.single("image"), async (req, res) => {
  const { title, content, mobile_number, email_address, expected_amount } =
    req.body;
  const imageUrl = `/uploads/${req.file.filename}`;
  const userEmail = req.session.userEmail;

  try {
    await db.query(
      "INSERT INTO posts (title, content, image_url, user_email, mobile_number, email_address, expected_amount) VALUES ($1, $2, $3, $4, $5, $6, $7)",
      [
        title,
        content,
        imageUrl,
        userEmail,
        mobile_number,
        email_address,
        expected_amount,
      ]
    );
    res.redirect("/pro");
  } catch (err) {
    console.error("Error creating post:", err);
    res.status(500).send("Error creating post");
  }
});

// Route to render the edit post page with the specified id
app.get("/edit/:id", async (req, res) => {
  const { id } = req.params;
  const userEmail = req.session.userEmail; // Get the logged-in user's email
  
  try {
      const result = await db.query("SELECT * FROM posts WHERE id = $1", [id]);
      const post = result.rows[0];

      if (post) {
        if (post.user_email === userEmail) { // Check if the post belongs to the logged-in user
          res.render("editPost.ejs", { post });
        } else {
          res.status(403).send("You can only edit your own posts");
        }
      } else {
          res.status(404).send("Post not found");
      }
  } catch (err) {
      console.error("Error fetching post:", err);
      res.status(500).send("Error fetching post");
  }
});

// Route to handle updating a post with a new image if provided
app.post("/edit/:id", upload.single("image"), async (req, res) => {
  const { id } = req.params;
  const { title, content } = req.body;

  try {
      const result = await db.query("SELECT * FROM posts WHERE id = $1", [id]);
      const post = result.rows[0];


      if (post) {
          let imageUrl = post.image_url;

          // Update the image if a new file is uploaded
          if (req.file) {
              if (fs.existsSync(path.join(__dirname, 'public', imageUrl))) {
                  fs.unlinkSync(path.join(__dirname, 'public', imageUrl));
              }
              imageUrl = `/uploads/${req.file.filename}`;
          }

          // Update the post in the database
          await db.query("UPDATE posts SET title = $1, content = $2, image_url = $3 WHERE id = $4", [title, content, imageUrl, id]);
  
          res.redirect("/pro");
      } else {
          res.status(404).send("Post not found");
      }
  } catch (err) {
      console.error("Error updating post:", err);
      res.status(500).send("Error updating post");
  }
});

// Route to delete a post
app.post("/delete/:id", async (req, res) => {
  const { id } = req.params;
  const userEmail = req.session.userEmail; // Get the logged-in user's email

  try {
      const result = await db.query("SELECT * FROM posts WHERE id = $1", [id]);
      const post = result.rows[0];

      if (post) {
        if (post.user_email === userEmail) { // Check if the post belongs to the logged-in user
          if (fs.existsSync(path.join(__dirname, "public", post.image_url))) {
            fs.unlinkSync(path.join(__dirname, "public", post.image_url)); // Delete the image file
          }
          await db.query("DELETE FROM posts WHERE id = $1", [id]); // Delete the post from the database
          res.redirect("/pro");
        } else {
          res.status(403).send("You can only delete your own posts");
        }
         
      } else {
          res.status(404).send("Post not found");
      }
  } catch (err) {
      console.error("Error deleting post:", err);
      res.status(500).send("Error deleting post");
  }
});

// Route to view profile (Display user profile information)
app.get("/up", async (req, res) => {
  const userEmail = req.session.userEmail ; // Assuming the user's email is stored in session after login
  
  try {
    const result = await db.query("SELECT * FROM userinfo WHERE email = $1", [userEmail]);
    if (result.rows.length > 0) {
      const userProfile = result.rows[0];
      res.render("up.ejs", { userProfile });
    } else {
      res.send("Profile not found");
    }
  } catch (err) {
    console.error("Error fetching user profile:", err);
    res.status(500).send("Error fetching profile");
  }
});

// Route to edit profile (display the form with current profile data)
app.get("/edit-profile", async (req, res) => {
  const userEmail = req.session.userEmail;
  
  try {
    const result = await db.query("SELECT * FROM userinfo WHERE email = $1", [userEmail]);
    if (result.rows.length > 0) {
      const userProfile = result.rows[0];
      res.render("editProfile.ejs", { userProfile });
    } else {
      res.send("Profile not found");
    }
  } catch (err) {
    console.error("Error fetching user profile for edit:", err);
    res.status(500).send("Error fetching profile");
  }
});

// Route to update profile information (handle form submission)
app.post("/update-profile", upload.single("profilePhoto"), async (req, res) => {
  const userEmail = req.session.userEmail; // User's email from session
  const { name, enroll_no, contact, room_no } = req.body;
  const profilePhoto = req.file ? `/uploads/${req.file.filename}` : null;

  try {
    // Update profile details in userinfo table
    await db.query(
      "UPDATE userinfo SET name = $1, enroll_no = $2, contact = $3, room_no = $4, profile_photo = $5 WHERE email = $6",
      [name, enroll_no, contact, room_no, profilePhoto, userEmail]
    );
    res.redirect("/up"); // Redirect to view updated profile
  } catch (err) {
    console.error("Error updating profile:", err);
    res.status(500).send("Error updating profile");
  }
});

// Search Route
app.get("/search", async (req, res) => {
  const searchQuery = req.query.q; // Get the search query from the URL parameter

  try {
    const result = await db.query(
      "SELECT * FROM posts WHERE title ILIKE $1 OR content ILIKE $1 ORDER BY created_at DESC",
      [`%${searchQuery}%`]
    );
    const posts = result.rows;
    res.render("pro.ejs", { posts });
  } catch (err) {
    console.error("Error fetching search results:", err);
    res.status(500).send("Error fetching search results");
  }
});


app.listen(port, () => {
  console.log(`Server running on port ${port}`);
});

modify accordingly so that all columns added in create post page transfers to product page correctky with values filled 