using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BackgroundSpawner : MonoBehaviour {
    //Background Objects
    public GameObject bot;
    public GameObject mid;
    public GameObject back;
    //Checks for the spawn
    public bool botSpawn;
    public bool midSpawn;
    public bool backSpawn;
    //speed of background
    public float botSpeed;
    public float midSpeed;
    // the initially spawned clones
    private GameObject botclone;
    private GameObject midclone;
    private GameObject backclone;
    // The second layer of backgrounds that will be the next to be destroyed and will also spawn the next clone
    public GameObject botcloneDestoryBackup;
    public GameObject midcloneDestoryBackup;
    public GameObject backcloneDestoryBackup;
    //The final layer that will be destroyed
    public GameObject botcloneDestory;    
    public GameObject midcloneDestory;
    public GameObject backcloneDestory;
    //Checks if layer is ready to be destroyed
    public BackgroudDespawn killCheck;
    public WorldScript world;
    // Use this for initialization
    void Start()
    {
        botSpawn = false;
        midSpawn = false;
        backSpawn = false;

        world = GameObject.FindGameObjectWithTag("world").GetComponent<WorldScript>();

        //Sets a specific spawn point for the initial background parts.
        botclone = Instantiate(bot, transform.position, Quaternion.Euler(0, 0, 0));
        botclone.transform.position = new Vector3(8.516859f,-.69f, 0);
        midclone = Instantiate(mid, transform.position, Quaternion.Euler(0, 0, 0));
        midclone.transform.position = new Vector3(5.41f, -.4362f, 0);
        backclone = Instantiate(back, transform.position, Quaternion.Euler(0, 0, 0));
        backclone.transform.position = new Vector3(45.37f, -2.76f, 0);
    }

    // Update is called once per frame
    void Update()
    {
        //Spawns all of the background parts.
        if (botSpawn)
        {
            botSpawn = false; //Makes sure only one spawns
            botcloneDestory = botcloneDestoryBackup;
            botcloneDestoryBackup = botclone;
            botclone = Instantiate(bot, transform.position, Quaternion.Euler(0, 0, 0));
            botclone.transform.position = new Vector3(transform.position.x + 15.28f, transform.position.y - .616f, 0);
        }

        if (midSpawn)
        {
            midSpawn = false;//Makes sure only one spawns
            midcloneDestory = midcloneDestoryBackup;
            midcloneDestoryBackup = midclone;
            midclone = Instantiate(mid, transform.position, Quaternion.Euler(0, 0, 0));
            midclone.transform.position = new Vector3(transform.position.x + 14.1f, transform.position.y-.616f, 0);
        }

        if (backSpawn)
        {
            backSpawn = false;//Makes sure only one spawns
            backcloneDestory = backcloneDestoryBackup;
            backcloneDestoryBackup = backclone;
            backclone = Instantiate(back, transform.position, Quaternion.Euler(0, 0, 0));
            backclone.transform.position = new Vector3(transform.position.x + 53.90f, transform.position.y -2.78f, 0);
        }

        //Removes background
            if (killCheck.killTop)
            {
                Destroy(midcloneDestory);
            }

            if (killCheck.killBot)
            {
                Destroy(botcloneDestory);
            }

            if (killCheck.killBack)
            {
                Destroy(backcloneDestory);
            }

    }
}
