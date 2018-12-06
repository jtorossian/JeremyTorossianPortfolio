using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Spawner : MonoBehaviour {
    public GameObject[] obstacles;
    public bool spawn;
    public float speed;
    private GameObject clone;
    public GameObject cloneDestory;
    public int obstacleNum;
	// Use this for initialization
	void Start () {
        spawn = true;
        cloneDestory = clone;
        obstacleNum = 0;

    }
	
	// Update is called once per frame
	void Update () {
        //Spawns stage
        if (spawn)
        {
            spawn = false;
            cloneDestory = clone;
            clone = Instantiate(obstacles[Random.Range(0, 6)], transform.position, Quaternion.Euler(0, 0, 0));
            clone.transform.position = new Vector3(transform.position.x, transform.position.y, 0);
        }
	}
}
