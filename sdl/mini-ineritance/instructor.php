<?php
require_once 'user.php';

class Instructor extends User {
    private $employeeId;

    public function __construct($username, $email, $employeeId) {
        parent::__construct($username, $email);
        $this->employeeId = $employeeId;
    }

    public function getEmployeeId() {
        return $this->employeeId;
    }
}
?>