using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DeathByShark : MonoBehaviour {

    public WorldScript world;
    //If kills fish if collision is made
    void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Fish")
        {
            world.gameOver = true;
        }
    }

    // Use this for initialization
    void Start () {
        world = GameObject.FindGameObjectWithTag("world").GetComponent<WorldScript>();
    }
	
	// Update is called once per frame
	void Update () {
		
	}
}
