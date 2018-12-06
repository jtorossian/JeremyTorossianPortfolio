using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Pause : MonoBehaviour {
    public Stage Stage;
    void OnTriggerEnter2D(Collider2D collision)
    {
        //Checks if collision is made, if so, attaches stage to camera track
        if (collision.gameObject.tag == "Catch")
        {
            Debug.Log("Wowie");
            Stage.stop = true;
        }
    }
    // Use this for initialization
    void Start () {
    }
	
	// Update is called once per frame
	void Update () {
    
        
    }
}
