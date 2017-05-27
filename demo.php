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


//Displaying Aaddress
echo '<h2>Displaying the Address</h2>';
echo $address->display();

echo '<h2> Testing the magic method __get and __set';
unset($address->postal_code);
$address->postal_code = '';
echo $address->display();


echo '<h2> Testing __construct with the Address </h2>';
$address2 = new Address([
    'street_address_1' => '123 LinkedIn Avenue NY',
    'city' => 'Mew York',
    'subdivision_name' => 'State',
    'postal_code' => '999',
    'country_name' => 'Canada'
]);

echo $address2->display();

echo '<h2> Testing of the __toString Method </h2>';

echo $address2;