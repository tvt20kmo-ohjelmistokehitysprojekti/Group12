<?php
/**
 *
 */
class Otto_model extends CI_model
{
  
  function Otto_call($add_data){
    $sql = 'Call Otto(?,?,@viesti)';
    $this->db->query($sql, $add_data);
    $query = $this->db->query("Select @viesti as viesti");
    $result = $query->result_array();
    return $result[0]['viesti'];
}
}
