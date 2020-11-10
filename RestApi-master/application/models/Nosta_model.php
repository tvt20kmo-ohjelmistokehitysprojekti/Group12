<?php
/**
 *
 */
class Nosta_model extends CI_model
{
  
  function Nosta_call($add_data){
    $sql = 'Call Nosto(?,?)';
    $query = $this->db->query($sql, $add_data);
    return $query->row();
}
}
