<?php


class User_model extends CI_model
{
    public function check_login($KorttiID){
        $this->db->select('Tunnusluku');
        $this->db->from('Asiakas');
        $this->db->where('KorttiID',$KorttiID);
        return $this->db->get()->row('Tunnusluku');
      }



    public function fetch_accounts($KorttiID){   //OK
      $sql = 'SELECT idTili,Tyyppi FROM Tili WHERE KorttiID = ?';
      $query = $this->db->query($sql,$KorttiID);
      $result = $query->result_array();
      return $result;
    }




    
    function update_password($update_data){ // ei valmis
      $sql = 'Update Asiakas SET Tunnusluku=? WHERE KorttiID = ?';
      $query = $this->db->query($sql,$update_data);
      
      if($this->db->affected_rows()>0){
        return TRUE;
      }
      else {
        return FALSE;
      }
    }

    
}