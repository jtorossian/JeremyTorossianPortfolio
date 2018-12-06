using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Ground : MonoBehaviour {
    public bool explodeMe;


    // Use this for initialization
    void Start () {
        explodeMe = false;
    }
	
	// Update is called once per frame
	void Update () {
        //Destroys stage
        if (explodeMe)
            Destroy(gameObject);
	}
}
