<?php
/**
 *
 */
class User_model extends CI_model
{
    public function check_login($KorttiID){
        $this->db->select('Tunnusluku');
        $this->db->from('Asiakas');
        $this->db->where('KorttiID',$KorttiID);
        return $this->db->get()->row('Tunnusluku');
      }



    public function fech_idtili($data){




    }
    function update_user($id, $update_data){ // ei valmis
      $this->db->where('id_user',$id);
      $this->db->update('user',$update_data);
      if($this->db->affected_rows()>0){
        return TRUE;
      }
      else {
        return FALSE;
      }
    }

    public function has_multiple_accounts($data){
      //palautaa onko vai credit tiliä
    }

}