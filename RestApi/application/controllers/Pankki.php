<?php

defined('BASEPATH') OR exit('No direct script access allowed');


require APPPATH . 'libraries/REST_Controller.php';


class Pankki extends REST_Controller {

    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: POST");
        // Construct the parent class
        parent::__construct();

        $this->load->model('Pankki_model');
    }
    public function Otto_post()
    {
        
        $add_data=array(
          'Summa'=>$this->post('Summa'),
          'idTili'=>$this->post('idTili')
        );
        $message=$this->Pankki_model->Otto($add_data);    //palautaa 0 epäonnistuessa & 1 onnistuessa
                     
        echo json_encode($message);

    }
    public function Saldo_post()
    {
        $idTili = $this->post('idTili');

        $message=$this->Pankki_model->Saldo($idTili);  

        echo json_encode($message);

    }
    public function Tapahtumat_post()
    {
        $idTili = $this->post('idTili');

        $message=$this->Pankki_model->Tapahtumat($idTili);


        echo json_encode($message);

    }
    public function Login_post(){
        $KorttiID=$this->post('KorttiID');
        $Tunnusluku=$this->post('Tunnusluku');
               
        
        if ($KorttiID===NULL || $Tunnusluku ===NULL){
            $this->response([
                'status' => FALSE,
                'message' => 'Bad Reguest'
            ], REST_Controller::HTTP_BAD_REQUEST);
        }
        else{ 
            $encrypted_password=$this->Pankki_model->check_login($KorttiID);

            if(password_verify($Tunnusluku,$encrypted_password)){
            
                $result = TRUE;
            }
            else{
            $result = FALSE;
            }
            echo json_encode($result);
        }

    }

    public function Update_pwd_post() 
    {
        // Update the user
        $clear_password=$this->post('Tunnusluku');
        $encrypted_pass = password_hash($clear_password,PASSWORD_DEFAULT);
        $update_data=array(
          'Tunnusluku'=>$encrypted_pass,
          'KorttiID'=> $this->post('KorttiID')
        );
        $result=$this->Pankki_model->update_password($update_data);

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
    
    public function Fetch_accounts_post(){  //palautaa kaikki korttiid vastaavat tilit tyyppeineen
        
        $KorttiID = $this->post('KorttiID');

        if ($KorttiID==NULL){
            $this->response([
                'status' => FALSE,
                'message' => 'Bad Reguest'
            ], REST_Controller::HTTP_BAD_REQUEST);
        }
        else{

        $idaccount_array=$this->Pankki_model->fetch_accounts($KorttiID);

        echo json_encode($idaccount_array); 
        }
    }
}