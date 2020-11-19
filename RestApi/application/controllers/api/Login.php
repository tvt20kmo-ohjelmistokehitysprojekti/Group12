<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Login extends CI_Controller {
    
    
    public function index_post($KorttiID,$Tunnusluku){
        $this->load->model('User_model'); 
        $KorttiID=$this->input->post('KorttiID');
        $Tunnusluku=$this->input->post('Tunnusluku');       
        $encrypted_password=$this->User_model->check_login($KorttiID);

        if(password_verify($Tunnusluku,$encrypted_password)){
          
            $result= TRUE;
        }
        else{
          $result=FALSE;
        }
        return $result;
    }

}
