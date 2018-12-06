using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SwordFishSpawner : MonoBehaviour
{
    public Stage stage; 
    public GameObject swordFish;
    private GameObject clone;
    public bool spawn = true;
    public int maxFish = 0;

    // Use this for initialization
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        //Checks if stage is on the same track as the camera and spawns the sword fish
        if (spawn && stage.stop)
        {
            clone = Instantiate(swordFish, transform.position, Quaternion.Euler(0, 0, 0));
            maxFish++;
            spawn = false;
        }
        
        //Once all swordfishes are spawn it removes the stage from the camera track
        if(maxFish >= 6)
        {
            stage.stop = false;
        }
    }

}