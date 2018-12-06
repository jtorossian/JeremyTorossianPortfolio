using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Despawner : MonoBehaviour {

    public Ground ground;

    void OnTriggerEnter2D(Collider2D collision)
    {
        //Destroys stage
        if (collision.gameObject.tag == "Ground")
        {
            ground = GameObject.FindGameObjectWithTag("Ground").GetComponent<Ground>();
            ground.explodeMe = true;
        }

    }

    // Use this for initialization
    void Start () {
    }
	
	// Update is called once per frame
	void Update () {
		
	}
}
