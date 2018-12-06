using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TerrainSpawn : MonoBehaviour {
    public GameObject[] obstacles;
    private GameObject clone;
    public bool spawn;
    // Use this for initialization
    void Start () {
        spawn = true;
    }

    //Spawns random terrain
    void Update()
    {
        if (spawn)
        {
            clone = Instantiate(obstacles[Random.Range(0, 6)], transform.position, Quaternion.Euler(0, 0, 0));
            spawn = false;
        }
    }
}
