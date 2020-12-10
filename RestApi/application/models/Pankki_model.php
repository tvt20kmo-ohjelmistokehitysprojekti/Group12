<?php

class Pankki_model extends CI_model
{
  
    public function Otto($add_data){
        $sql = 'Call Otto(?,?,@viesti)';
        $this->db->query($sql, $add_data);
        $query = $this->db->query("Select @viesti as viesti");
        $result = $query->result_array();
        return $result[0];
    }

    public function Saldo($idTili)
    {
        $sql = 'select Saldo from Tili where idTili=?';
        $query = $this->db->query($sql,$idTili);
        $result = $query->result_array();
        if (isset( $result[0]['Saldo'])){
            return $result[0];
        }
        else {
            return false;
        }
    }

        public function Nostettavissa($idTili)
    {
        $sql = 'select Luottoraja, Saldo from Tili where idTili=?';
        $query = $this->db->query($sql,$idTili);
        $result = $query->result_array();
    
        if (isset( $result[0]['Saldo'])){
           $result = $result[0]['Saldo']-$result[0]['Luottoraja'];
           $result = array('Nostettavissa'=>json_encode($result));
        
           
           return $result;
        }
        else {
            return false;
        }
    }

    public function Tapahtumat($idTili)
    {
        $sql = 'select Pvm, Selite, Summa from Tapahtumat where idTili =? order by Pvm desc limit 6';
        $query = $this->db->query($sql,$idTili);
        $result = $query->result_array();
        if (isset($result[0])){
            return $result;
        }
        else{
        
            return false;
        }
    }

    public function check_login($KorttiID){
        $this->db->select('Tunnusluku');
        $this->db->from('Asiakas');
        $this->db->where('KorttiID',$KorttiID);
        return $this->db->get()->row('Tunnusluku');
    }

    public function fetch_accounts($add_data)
    {   
        $sql = 'SELECT idTili FROM Tili WHERE KorttiID = ? AND Tyyppi = ?';
        $query = $this->db->query($sql,$add_data);
        $result = $query->result_array();
        if (isset($result[0]['idTili'])){
            return $result[0];
        }
        else{
        
            return false;
        }
    }

    public function update_password($update_data)
    { 
    
        $sql = 'Update Asiakas SET Tunnusluku=? WHERE KorttiID = ?';
        $query = $this->db->query($sql,$update_data);
        
        if($this->db->affected_rows()>0){
            return TRUE;
        }
        else {
            return FALSE;
        }
    }

    public function name($KorttiID){
         $sql = 'Select Nimi, Sukunimi FROM Asiakas WHERE KorttiID = ?';
         $query = $this->db->query($sql,$KorttiID);
         $result = $query->result_array();

         if (isset($result[0])){
            return $result[0];
        }
        else{
            return FALSE;
        }
    }

}


