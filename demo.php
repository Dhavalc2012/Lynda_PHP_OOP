<?php

/*
 * * Define Autoloader string.className
 */
function __autoload($class_name) {
    include 'class.'.$class_name .'.inc';
}

echo '<h2>Instantiating AddressResidence</h2>';
$address_residence = new AddressResidence();

echo '<h2>Setting properties...</h2>';
$address_residence->street_address_1 = '555 Fake Street';
$address_residence->city = 'Townsville';
$address_residence->subdivision_name = 'State';
$address_residence->country_name = 'United States of America';
echo $address_residence;

echo '<h2>Testing Address __construct with an array</h2>';
$address_business = new AddressBusiness(array(
  'street_address_1' => '123 Phony Ave',
  'city' => 'Villageland',
  'subdivision_name' => 'Region',
  'country_name' => 'Canada',
));
echo $address_business;
echo "<pre>" .var_dump($address_business) ."</pre>";
