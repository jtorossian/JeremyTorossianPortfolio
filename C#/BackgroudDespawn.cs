using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BackgroudDespawn : MonoBehaviour {
    public BackgroundSpawner spawner;
    public bool killTop;
    public bool killBot;
    public bool killBack;
    public int startDestory;

    //When the parts make contact with the collider, tells BackgroundSpawner to destroy that part.
    void OnTriggerEnter2D(Collider2D collision)
    {

        if (collision.gameObject.tag == "Top")
        {
            killTop = true;
        }

        if (collision.gameObject.tag == "Bot")
        {
            killBot = true;
        }

        if (collision.gameObject.tag == "Back")
        {
            killBack = true;
        }

    }

    // Use this for initialization
    void Start () {
        killTop = false;
        killBot = false;
        killBack = false;
        startDestory = 0;
    }
	
	// Update is called once per frame
	void Update () {
		
	}
}
