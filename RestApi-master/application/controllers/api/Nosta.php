<?php

defined('BASEPATH') OR exit('No direct script access allowed');

// This can be removed if you use __autoload() in config.php OR use Modular Extensions
/** @noinspection PhpIncludeInspection */
require APPPATH . 'libraries/REST_Controller.php';

/**
 * This is an example of a RestApi based on PHP and CodeIgniter 3.
 * 
 *
 * @package         CodeIgniter
 * @subpackage      Rest Server
 * @category        Controller
 * @author          Pekka Alaluukas (edited the version made by Phil Sturgeon & Chris Kacerguis)
 * @license         MIT
 * @link            https://github.com/chriskacerguis/codeigniter-restserver
 */
class Nosta extends REST_Controller {

    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: POST");
        // Construct the parent class
        parent::__construct();

        $this->load->model('Nosta_model');
    }

    public function nosta_post()
    {
        
        $add_data=array(
          'Summa'=>$this->post('Summa'),
          'idTili'=>$this->post('idTili')
        );
        $message=$this->Nosta_model->Nosta_call($add_data);       
        
        $this->set_response(NULL, REST_Controller::HTTP_OK); // CREATED (201) being the HTTP response code
       
        echo json_encode($message);

    }


}
