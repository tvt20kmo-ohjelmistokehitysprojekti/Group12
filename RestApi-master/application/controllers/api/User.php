<?php

defined('BASEPATH') OR exit('No direct script access allowed');

require APPPATH . 'libraries/REST_Controller.php';


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
    public function update_password_post() //ei valmis user päivitys
    {
        // Update the user
        $clear_password=$this->post('Tunnusluku');
        $encrypted_pass = password_hash($clear_password,PASSWORD_DEFAULT);
        $update_data=array(
          'Tunnusluku'=>$encrypted_pass,
          'KorttiID'=> $this->post('KorttiID')
        );
        $result=$this->User_model->update_password($update_data);

        if($result)
        {
          $message = 'succes';

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
    
    public function fetch_accounts_post(){  //palautaa kaikki korttiid vastaavat tilit tyyppeineen
        
        $KorttiID = $this->post('KorttiID');

        if ($KorttiID==NULL){
            $this->response([
                'status' => FALSE,
                'message' => 'Bad Reguest'
            ], REST_Controller::HTTP_BAD_REQUEST);
        }
        else{

        $idaccount_array=$this->User_model->fetch_accounts($KorttiID);

        echo json_encode($idaccount_array); 
        }
    }

}
    

