using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BirdSpawner : MonoBehaviour {

    public Stage stage;
    public GameObject Bird;
    private GameObject clone;
    public bool spawn = true;
    public int maxBird = 0;
    // Use this for initialization
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        //Checks if the stage is currently attached to the camera, if it is then it spawns the bird
        if (spawn && stage.stop)
        {
            clone = Instantiate(Bird, transform.position, Quaternion.Euler(0, 0, 0));
            maxBird++;
            StartCoroutine("holdUP");
            spawn = false;
        }

        if (maxBird >= 3)
        {
            stage.stop = false;
        }
    }

    IEnumerator holdUP() //Has is wait before the birds attack
    {
        Debug.Log("Co Routine start");
        yield return new WaitForSeconds(.35f); 
        spawn = true;
        Debug.Log("Co Routine end");

    }

}
