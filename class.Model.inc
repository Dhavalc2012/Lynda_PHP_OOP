<?php

/*
 * Shared Interface for interaction. 
 */

interface Model {
    
    
/*
 * Load A Model
 * @param int $address_id
 */    
static function load($address_id);

/* 
 * Save a model 
 * 
 */
function save();
}
