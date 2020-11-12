<?php
/**
 *
 */
class Otto_model extends CI_model
{
  
  function Otto_call($add_data){
    $sql = 'Call Otto(?,?,@viesti)';
    $query = $this->db->query($sql, $add_data);
    $query = $this->db->query("Select @viesti as viesti");
    $query = $query->result_array();
    $query = $query[0]['viesti']; 
    return $query;
}
}
