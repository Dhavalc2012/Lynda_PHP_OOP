<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of Address
 *
 * @author dhaval
 */
class Address {
    //put your code here
    const ADDRESS_TYPE_RESIDENCE = 1;
    const ADDRESS_TYPE_BUSINESS = 2;
    const ADDRESS_TYPE_PARK = 3;
    
    
    public $street_address_1 ;
    public $street_address_2;
    
    public static $valid_address_types = array(
        Address::ADDRESS_TYPE_RESIDENCE => "Residence",
        Address::ADDRESS_TYPE_BUSINESS => "Business",
        Address::ADDRESS_TYPE_PARK => "Park"
    ); 
    
    //Name of the city
    public $city;
    
    //Name of the subdivision
    public $subdivision_name;
    
    //Postal Code
    protected $_postal_code;
    
    //Name of the Country
    public $country_name;
    
    
    //Primary key of the address
    protected $_address_id;
    
    //When the record was last created and updated
    protected $_time_created;
    protected $_time_updated;
    
    /*
     * Constructor
     * @param type array @data. Optional array of property names and values.
     */
    public function __construct($data = array()) {
        $this->_time_created = time();
        //Ensure that the Address can be populated. Just a sanity check.
        if(!is_array($data))
            trigger_error ("Unable to construct address with a" . get_class($name));
        if(count($data) > 0 ){
            foreach ($data as $name => $value){
                //Special case for protected properties.
                if(in_array($name, array('time_created','time_updated'))){
                $name = '_' . $name;
            }
            $this->$name = $value;
        }
            
    }
    }

    /*Magic __get
     * @param string @name
     * @return mixed
     */
    function __get($name) {
        //Postal code lookup if unset.
        if(!$this->_postal_code){
            $this->_postal_code = $this->_postal_code_guess();
        }
        //Attempt to return the protected String.
        $protected_property_name = '_' . $name;
        if(property_exists($this, $protected_property_name)){
            return $this->$protected_property_name;
        }
        //Unable to access the property. Trigger the php error and return null.
        trigger_error("Undefined property accessed via __get ;" . $name);
        return NULL;
    }
    
    
    /*
     * Magic __set method.
     * @param string $name
     * @param mixded value
     * @return set value
     */
    public function __set($name, $value) {
        if ("postal_code" == $name) {
            $this->_postal_code = $value;
             return;
        }
       //Unable to access the properties
       trigger_error("Undefined or unallowed property via __set" . $name);
        
    }
    
    public function __toString() {
        return $this->display();
    }
    
    /*
     * Guess the postal code given and the subdivision.
     * @todo    Replace with database postal lookup.
     * @return string
     */
    protected function _postal_code_guess() {
        return 'LOOKUP';
    }

    /*
     * Displaying an address in HTML
     * @return string
     */
    function display(){
        $output = '';
        $output .= $this->street_address_1;
        if ($this->street_address_2) {
            $output .= '<br>' . $this->street_address_2;
        }
        //City, Subdivision Postal.
        $output .= '<br/>';
        $output .= $this->city . " . " . $this->subdivision_name ." , " . $this->postal_code;
        
        //Coutry Addition
        $output .= "<br/>" . $this->postal_code;
        
        return $output;
    }
    
}

