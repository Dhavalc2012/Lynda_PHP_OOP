<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of demo
 *
 * @author dhava
 */
require 'class.Address.inc';
echo '<h2> Instantiing Address Class</h2>';
$address = new Address;
var_dump($address) ;
echo   '<h2> Setting properties </h2>';
$address->street_address_1 = '201 Baker Street';
$address->city = 'London';
$address->subdivision_name = 'State';
$address->postal_code = '12233';
$address->country_name = 'UK';
var_dump($address);

echo '<h2>Displaying the Address</h2>';
echo $address->display();