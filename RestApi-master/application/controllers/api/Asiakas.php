<?php

defined('BASEPATH') OR exit('No direct script access allowed');

// This can be removed if you use __autoload() in config.php OR use Modular Extensions
/** @noinspection PhpIncludeInspection */
require APPPATH . 'libraries/REST_Controller.php';

/**
 * This is an example of a RestApi based on PHP and CodeIgniter 3.
 *
 *
 * @package         CodeIgniter
 * @subpackage      Rest Server
 * @category        Controller
 * @author          Pekka Alaluukas (edited the version made by Phil Sturgeon & Chris Kacerguis)
 * @license         MIT
 * @link            https://github.com/chriskacerguis/codeigniter-restserver
 */
class Asiakas extends REST_Controller {

    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: GET, POST, OPTIONS, PUT, DELETE");
        // Construct the parent class
        parent::__construct();

        $this->load->model('Asiakas_model');
    }

    public function index_get()
    {
        // asiakas from a data store e.g. database

        $id = $this->get('id');

        // If the id parameter doesn't exist return all asiakass
        if ($id === NULL)
        {
            $asiakas=$this->Asiakas_model->get_asiakas(NULL);
            // Check if the asiakas data store contains asiakas (in case the database result returns NULL)
            if ($asiakas)
            {
                // Set the response and exit
                $this->response($asiakas, REST_Controller::HTTP_OK); // OK (200) being the HTTP response code
            }
            else
            {
                // Set the response and exit
                $this->response([
                    'status' => FALSE,
                    'message' => 'No asiakas were found'
                ], REST_Controller::HTTP_NOT_FOUND); // NOT_FOUND (404) being the HTTP response code
            }
        }

         // Find and return a single record for a particular asiakas.
        else {
            // Validate the id.
            if ($id <= 0)
            {
                // Invalid id, set the response and exit.
                $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST); // BAD_REQUEST (400) being the HTTP response code
            }

            // Get the asiakas from the database, using the id as key for retrieval.
            $asiakas=$this->asiakas_model->get_asiakas($id);
            if (!empty($asiakas))
            {
                $this->set_response($asiakas, REST_Controller::HTTP_OK); // OK (200) being the HTTP response code
            }
            else
            {
                $this->set_response([
                    'status' => FALSE,
                    'message' => 'asiakas could not be found'
                ], REST_Controller::HTTP_NOT_FOUND); // NOT_FOUND (404) being the HTTP response code
            }
        }

    }

    public function index_post()
    {
        // Add a new asiakas
        $add_data=array(
          'Tunnusluku'=>$this->post('Tunnusluku'),
          'Nimi'=>$this->post('Nimi'),
          'Sukunimi'=>$this->post('Sukunimi')
        );
        $insert_id=$this->asiakas_model->add_asiakas($add_data);
        if($insert_id)
        {
            $message = [
                'KorttiID' => $insert_id,
                'Tunnusluku' => $this->post('Tunnusluku'),
                'Nimi' => $this->post('Nimi'),
                'Sukunimi'=>$this->post('Sukunimi'),
                'message' => 'Added a resource'
            ];
            $this->set_response($message, REST_Controller::HTTP_CREATED); // CREATED (201) being the HTTP response code
        }
        else
        {
            // Set the response and exit
            $this->response([
                'status' => FALSE,
                'message' => 'Can not add data'
            ], REST_Controller::HTTP_CONFLICT); // CAN NOT CREATE (409) being the HTTP response code
        }

    }
    public function index_put()
    {
        // Update the asiakas
        $id=$this->get('id');
        $update_data=array(
          'Tunnusluku'=>$this->put('Tunnusluku'),
          'author'=>$this->put('author'),
          'isbn'=>$this->put('isbn')
        );
        $result=$this->asiakas_model->update_asiakas($id, $update_data);

        if($result)
        {
            $message = [
                'KorttiID' => $id,
                'Tunnusluku' => $this->put('Tunnusluku'),
                'author'=>$this->put('author'),
                'isbn'=>$this->put('isbn'),
                'message' => 'Updates a resource'
            ];

            $this->set_response($message, REST_Controller::HTTP_CREATED); // CREATED (201) being the HTTP response code
        }
        else
        {
            // Set the response and exit
            $this->response([
                'status' => FALSE,
                'message' => 'Can not update data'
            ], REST_Controller::HTTP_CONFLICT); // CAN NOT CREATE (409) being the HTTP response code
        }
    }

    public function index_delete()
    {
        $id = $this->get('id');

        // Validate the id.
        if ($id <= 0)
        {
            // Set the response and exit
            $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST); // BAD_REQUEST (400) being the HTTP response code
        }
        $result=$this->asiakas_model->delete_asiakas($id);
        if ($result)
        {
          $message = [
              'KorttiID' => $id,
              'message' => 'Deleted the resource'
          ];
          $this->set_response($message, REST_Controller::HTTP_OK);
        }
        else
        {
            // Set the response and exit
            $this->response([
                'status' => FALSE,
                'message' => 'Can not delete data'
            ], REST_Controller::HTTP_CONFLICT); // CAN NOT CREATE (409) being the HTTP response code
        }
    }



}
