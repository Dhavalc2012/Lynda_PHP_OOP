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
    public $street_address_1 ;
    public $street_address_2;
    
    //Name of the city
    public $city;
    
    //Name of the subdivision
    public $subdivision_name;
    
    //Postal Code
    public $postal_code;
    
    //Name of the Country
    public $country_name;
    
    
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

