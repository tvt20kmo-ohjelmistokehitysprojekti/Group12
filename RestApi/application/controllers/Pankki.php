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
    public function Otto_post() //Ottaa tililtä rahaa post metodista summan ja tilin numeron mukaan.
    // Palauttta 1 onnistuessa ja 0 epäonnistuessa viesti : 0 tai 1
    {
        $add_data=array(
          'Summa'=>$this->post('Summa'),
          'idTili'=>$this->post('idTili')
        );
        if ($add_data["Summa"]==NULL || $add_data["idTili"]==NULL){
            $this->response([
                'status' => FALSE,
                'message' => 'Bad Reguest'
            ], REST_Controller::HTTP_BAD_REQUEST);
        }
        else{

        $message=$this->Pankki_model->Otto($add_data); 
       
                    
        $this->response($message, REST_Controller::HTTP_OK);
        }
    }

    public function Nostettavissa_post() 
    {
        $idTili = $this->post('idTili');

        $message=$this->Pankki_model->Nostettavissa($idTili);  
        if(!$message){
            $this->response([
                'status' => FALSE,
                'message' => 'Bad Reguest'
                ], REST_Controller::HTTP_BAD_REQUEST);
        }
        else{
            $this->response($message, REST_Controller::HTTP_OK);
        }
        
    }
    public function Saldo_post() //Hakee post metodilla lähetetyn tilin saldon ja palutaa sen.  
    {
        $idTili = $this->post('idTili');

        $message=$this->Pankki_model->Saldo($idTili);  
        if(!$message){
            $this->response([
                'status' => FALSE,
                'message' => 'Bad Reguest'
                ], REST_Controller::HTTP_BAD_REQUEST);
        }
        else{
            $this->response($message, REST_Controller::HTTP_OK);
        }
    }
    public function Tapahtumat_post()   //Hakee post metodilla lähetetyn tilin tapahtumat ja palutaa kuusi(6) viimeistä 
    { 
        $idTili = $this->post('idTili'); 
            $message=$this->Pankki_model->Tapahtumat($idTili);
            if(!$message){
                $this->response([
                    'status' => FALSE,
                    'message' => 'Bad Reguest'
                ], REST_Controller::HTTP_BAD_REQUEST);
            }
            else{
            $this->response($message, REST_Controller::HTTP_OK);
            }
    }
    public function Login_post(){ //Tarkistaa löytyykö tietokanssata post metodilla lähetettyä Kortti Tunnusluku yhdistelmää
        //Palautaa true onnistuessa ja false epäonnistuessa.
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
            $this->response($result, REST_Controller::HTTP_OK);
        }

    }

    public function Update_pwd_post() //Päivittää post metodilla lähetetyn korttiid tunnusluvun tallentaa sen tietokantaan.
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
    
    public function Fetch_account_post()
    {  //palautaa post metodilla lähetetyn kortti idn ja tyyppiä vastaavan tilinumeron. 

        $add_data=array(
        'KorttiID' => $this->post('KorttiID'),
        'Tyyppi' => $this->post('Tyyppi')
        );
        $idaccount=$this->Pankki_model->fetch_accounts($add_data);

        if(!$idaccount){
            $this->response([
                'status' => FALSE,
                'message' => 'Bad Reguest'
            ], REST_Controller::HTTP_BAD_REQUEST);
        }
        else{
        $this->response($idaccount, REST_Controller::HTTP_OK);
        }
        
    }

    public function Name_post(){ //Hakee asikastaulusta etunimen ja sukunimen
        $KorttiID = $this->post('KorttiID');

        $name=$this->Pankki_model->name($KorttiID);
        if(!$name){
            $this->response([
                'status' => FALSE,
                'message' => 'Bad Reguest'
            ], REST_Controller::HTTP_BAD_REQUEST);
        }
        else{
        $this->response($name, REST_Controller::HTTP_OK);
        }
    }
}

