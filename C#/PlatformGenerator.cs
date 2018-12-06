using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlatformGenerator : MonoBehaviour {
    private Vector2 startPosition;
    public float speed;
    public WorldScript world;
    void Start () {
        startPosition = transform.position;
        world = GameObject.FindGameObjectWithTag("world").GetComponent<WorldScript>();
    }
	
    //Moves camera to the right
	void FixedUpdate () {

        if (!world.gameOver)
            transform.position += Vector3.right * speed * Time.deltaTime;
	}
}
