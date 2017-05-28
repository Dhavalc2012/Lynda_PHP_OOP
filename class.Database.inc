<?php

/*
 * MySQLi Database Connection.Only one connection allowed.
 */
class Database {
    private $_connection ;
    //Store the single instance
    private static $_instance ;
    
    
    
    /*
     * Get instance of the database.
     * Return type database.
     */
    public static function getInstance(){
        if(!self::$_instance){
          self::$_instance = new self();  
        }
        return self::$_instance;
    }
    
    /*
     * Define the construct for database object.
     */
    public function __construct() {
        $this->_connection = new mysqli('localhost', 'root', '', 'sandbox');
        //error handling
        if(mysqli_connect_error()){
            trigger_error("Failed to connect to sql" .mysqli_connect_error() , E_USER_ERROR);
        }
    }
    
    /*
     * Empty clone method to prevent duplication
     */
    
    private function __clone() {
        
    }
    
    /*
     * Get the mysqli connection
     */

    public function getConnection() {
        return $this->_connection;
    }
}