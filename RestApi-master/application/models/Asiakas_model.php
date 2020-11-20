<?php
/**
 *
 */
class Asiakas_model extends CI_model
{
  function get_asiakas($id){
    $this->db->select('*');
    $this->db->from('Asiakas');
    if($id !== NULL) {
      $this->db->where('KorttiID',$id);
    }
    return $this->db->get()->result_array();
  }
  function add_asiakas($add_data){
    $this->db->insert('Asiakas',$add_data);
    if($this->db->insert_id()!==NULL){
      return $this->db->insert_id();
    }
    else {
      return FALSE;
    }
  }
  function update_asiakas($id, $update_data){
    $this->db->where('KorttiID',$id);
    $this->db->update('Asiakas',$update_data);
    if($this->db->affected_rows()>0){
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  function delete_asiakas($id){
    $this->db->where('KorttiID',$id);
    $this->db->delete('Asiakas');
    if($this->db->affected_rows()>0){
      return TRUE;
    }
    else {
      return FALSE;
    }
  }


}
