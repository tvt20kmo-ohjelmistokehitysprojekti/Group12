<?php

class Saldo_model extends CI_model
{

    function Saldo($idTili)
    {
        $sql = 'select Saldo from tili where idTili=?';
        $query = $this->db->query($sql,$idTili);
        $result = $query->result_array();
        return $result[0]['Saldo'];


















    }










}