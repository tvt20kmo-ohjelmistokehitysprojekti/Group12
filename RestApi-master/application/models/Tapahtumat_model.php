<?php

class Tapahtumat_model extends CI_model
{

    function Tapahtumat($idTili)
    {
        $sql = 'select Pvm, Selite, Summa from Tapahtumat where idTili =? order by Pvm desc limit 6';
        $query = $this->db->query($sql,$idTili);
        $result = $query->result_array();
        return $result;

    }




}
