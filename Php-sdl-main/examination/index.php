<?php
session_start();

if(!isset($_SESSION['id']) || (trim($_SESSION['id'])=='')){
    header('location:register.html');
    exit();
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Examination Form</title>
</head>
<body>
    <a href="logout.php">logout</a>
    <br>
    <br>
    <?php echo $_SESSION['id']?>
    <br>
    <br>
    <form action="exam.php" method="post">
        <label for="subject">Subject</label>
        <input type="text" name="subject" id="subject">
        <label for="mark">Marks</label>
        <input type="number" name="mark" id="mark">
        <label for="prn">PRN</label>
        <input type="text" name="prn" id="prn">
        <input type="submit" name="add">
    </form>
</body>
</html>

