<?php
session_start();
include 'db.php';

// Check if the user is logged in
if (!isset($_SESSION['user_id'])) {
    // Redirect to the login page if not logged in
    header("Location: login.php");
    exit();
}

// Get the user ID from the session
$user_id = $_SESSION['user_id'];

// Validate the incoming data
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $title = $_POST['title'];
    $description = $_POST['description'];
    $status = $_POST['status'];

    // Insert the complaint into the database
    $sql = "INSERT INTO complaints (user_id, title, description, status) VALUES ('$user_id', '$title', '$description', '$status')";

    if ($conn->query($sql) === TRUE) {
        // Redirect to a success page or display a success message
        echo "Complaint submitted successfully";
    } else {
        // Redirect to an error page or display an error message
        echo "Error: " . $sql . "<br>" . $conn->error;
    }

    $conn->close();
} else {
    // Redirect to the complaint submission page if accessed directly
    header("Location: complain.html");
    exit();
}
?>
