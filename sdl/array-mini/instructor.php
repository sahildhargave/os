<?php
class Instructor{
	private $username;
	private $email;
	private $employeeId;
	
	public function __constructor($username,$email,$employeeId){
		$this->username= $username;
		$this->email= $email;
		$this->employeeId= $employeeId;
	}
		public function getUsername(){
			return $this->username;
		}

		public function getEmail(){
			return $this->email;
		}

		public function getEmployeeId(){
			return $this->employeeId;
		}
	
}
?>