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
class User extends REST_Controller {

    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: GET, POST, OPTIONS, PUT, DELETE");
        // Construct the parent class
        parent::__construct();

        $this->load->model('User_model');
    }
    public function user_put() //ei valmis user päivitys
    {
        // Update the user
        $id=$this->get('id');
        $clear_password=$this->post('password');
        $encrypted_pass = password_hash($clear_password,PASSWORD_DEFAULT);
        $update_data=array(
          'username'=>$this->post('username'),
          'password'=>$encrypted_pass
        );
        $result=$this->User_model->update_user($id, $update_data);

        if($result)
        {
          $message = [
              'id_user' => $insert_id,
              'username' => $this->post('username'),
              'password' => $this->post('password'),
              'message' => 'Added a resource'
          ];

            $this->set_response($message, REST_Controller::HTTP_CREATED); // CREATED (201) being the HTTP response code
        }
        else
        {
            // Set the response and exit
            $this->response([
                'status' => FALSE,
                'message' => 'Can not update data'
            ], REST_Controller::HTTP_CONFLICT); // CAN NOT CREATE (409) being the HTTP response code
        }
    }
    public function has_accounts_post(){
        //palautaa true jos useampi tili
    }

    public function fech_idTili_post(){
        //palauttaa idTili ottaa vastaan korttiID ja tilin tyypin

    }
    

