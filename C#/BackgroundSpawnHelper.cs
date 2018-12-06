using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BackgroundSpawnHelper : MonoBehaviour {
    public BackgroundSpawner spawner;

    //If the background objects hit the collider, it spawns the next one/
    void OnTriggerEnter2D(Collider2D collision)
    {

        if (collision.gameObject.tag == "Top")
        {
            spawner.midSpawn = true;
        }

        if (collision.gameObject.tag == "Bot")
        {
            spawner.botSpawn = true;
        }

        if (collision.gameObject.tag == "Back")
        {
            spawner.backSpawn = true;
        }

    }

    // Use this for initialization
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {

    }
}
