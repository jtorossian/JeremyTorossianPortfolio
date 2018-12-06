using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BotBackground : MonoBehaviour {
    public float speed;
    private Vector3 updatedPosition;
    public GameObject location;
    public WorldScript world;

    // Use this for initialization
    void Start () {
        world = GameObject.FindGameObjectWithTag("world").GetComponent<WorldScript>(); //Gets world gameobject
    }
	
	// Update is called once per frame
	void FixedUpdate() {
        if (world.gameOver) //Stops background on game over
            speed = 0;

        //Moves background
        updatedPosition = new Vector2(location.transform.position.x, transform.position.y);
        transform.position = Vector2.MoveTowards(new Vector2(transform.position.x, transform.position.y), updatedPosition, speed * Time.deltaTime);
    }

}
