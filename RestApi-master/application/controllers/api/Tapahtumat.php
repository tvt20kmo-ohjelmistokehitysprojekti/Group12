<?php

defined('BASEPATH') OR exit('No direct script access allowed');

// This can be removed if you use autoload() in config.php OR use Modular Extensions
/** @noinspection PhpIncludeInspection */
require APPPATH . 'libraries/REST_Controller.php';


class Tapahtumat extends REST_Controller {

    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: POST");
        // Construct the parent class
        parent::__construct();

        $this->load->model('Tapahtumat_model');
    }

    public function Tapahtumat_post()
    {
        $idTili = $this->post('idTili');

        $message=$this->Tapahtumat_model->Tapahtumat($idTili);


        echo json_encode($message);

    }


}
