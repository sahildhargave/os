<?php
// Check if the form was submitted using POST method
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Retrieve form data using $_POST
    $name = isset($_POST['name']) ? $_POST['name'] : '';
    $phone = isset($_POST['phone']) ? $_POST['phone'] : '';
    $email = isset($_POST['email']) ? $_POST['email'] : '';
    $need = isset($_POST['need']) ? $_POST['need'] : '';

    // Validate required fields
    if (empty($name) || empty($phone) || empty($email) || empty($need)) {
        echo "Error: Please fill out all required fields.";
    } else {
        // Database connection settings
        $host = 'localhost';
        $username = 'root'; // Database username
        $password = ''; // Database password (leave empty for localhost)
        $dbname = 'test'; // Database name

        // Create connection
        $conn = new mysqli($host, $username, $password, $dbname);

        // Check connection
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }

        // Prepare and execute SQL query to insert form data into database
        $sql = "INSERT INTO `form` (`id`, `name`, `phone`, `email`, `need`) VALUES (NULL, '$name', '$phone', '$email', '$need')";
        if ($conn->query($sql) === TRUE) {
            // Form data inserted successfully
            echo "Form submitted successfully.";

            // Additional code for sending email goes here
            // Ensure your mail configuration is set up correctly
        } else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }

        // Close database connection
        $conn->close();
    }
} else {
    // If form was not submitted via POST method, display an error message
    echo "Error: Invalid form submission.";
}
?>