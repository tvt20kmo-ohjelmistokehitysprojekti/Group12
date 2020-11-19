<?php

defined('BASEPATH') OR exit('No direct script access allowed');

// This can be removed if you use autoload() in config.php OR use Modular Extensions
/** @noinspection PhpIncludeInspection */
require APPPATH . 'libraries/REST_Controller.php';


class Saldo extends REST_Controller {

    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: POST");
        // Construct the parent class
        parent::__construct();

        $this->load->model('Saldo_model');
    }

    public function Saldo_post()
    {
        $idTili = $this->post('idTili');

        $message=$this->Saldo_model->Saldo($idTili);  

        echo json_encode($message);

    }


}