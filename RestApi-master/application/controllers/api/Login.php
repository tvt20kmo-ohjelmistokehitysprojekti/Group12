<?php
defined('BASEPATH') OR exit('No direct script access allowed');

require APPPATH . 'libraries/REST_Controller.php';

class Login extends Rest_Controller {

    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: POST");
        // Construct the parent class
        parent::__construct();

        $this->load->model('User_model');
    }
    
    
    public function index_post(){
        $KorttiID=$this->input->post('KorttiID');
        $Tunnusluku=$this->input->post('Tunnusluku');       
        
        if ($KorttiID===NULL || $Tunnusluku ===NULL){
            $this->response([
                'status' => FALSE,
                'message' => 'Bad Reguest'
            ], REST_Controller::HTTP_BAD_REQUEST);
        }
        else{ 
            $encrypted_password=$this->User_model->check_login($KorttiID);

            if(password_verify($Tunnusluku,$encrypted_password)){
            
                $result = TRUE;
            }
            else{
            $result = FALSE;
            }
            echo json_encode($result);
        }

    }
}
