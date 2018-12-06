using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Giblets : MonoBehaviour {
    public GameObject[] giblets;
    public bool spawn;
    private GameObject clone;
    public GameObject cloneDestory;
    public int obstacleNum;
    private Vector3 updatedPosition;
    public float speed;
    private bool gSpawn;

    // Use this for initialization
    void Start () {
        gSpawn = true;
        
    }
	
	// Update is called once per frame
	void Update () {
        //Spawns a random giblet
        if (gSpawn)
        {
            clone = Instantiate(giblets[Random.Range(0, 3)], transform.position, Quaternion.Euler(0, 0, 0));
            gSpawn = false;
        }


    }
}
